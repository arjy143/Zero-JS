#pragma once

#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip>

namespace zero_js
{

// ============================================================================
// Chart Data Structures
// ============================================================================

struct DataPoint {
    double x, y;
    std::string label;
    std::string color;

    DataPoint(double x_val = 0, double y_val = 0, const std::string& lbl = "", const std::string& col = "")
        : x(x_val), y(y_val), label(lbl), color(col) {}
};

struct ChartSeries {
    std::string name;
    std::vector<DataPoint> data;
    std::string color;

    ChartSeries(const std::string& n = "", const std::vector<DataPoint>& d = {}, const std::string& c = "")
        : name(n), data(d), color(c) {}
};

// ============================================================================
// Base Chart Component
// ============================================================================

class Chart : public Component {
public:
    int width_ = 400;
    int height_ = 300;
    std::string title_;
    bool show_grid_ = true;
    bool show_legend_ = true;
    std::vector<ChartSeries> series_;

    Chart() = default;

    Chart& width(int w) { width_ = w; return *this; }
    Chart& height(int h) { height_ = h; return *this; }
    Chart& title(const std::string& t) { title_ = t; return *this; }
    Chart& showGrid(bool show = true) { show_grid_ = show; return *this; }
    Chart& showLegend(bool show = true) { show_legend_ = show; return *this; }
    Chart& addSeries(const ChartSeries& series) { series_.push_back(series); return *this; }
    Chart& id(const std::string& i) { id_ = i; return *this; }
    Chart& classes(const std::string& c) { classes_ = c; return *this; }

    std::string render() const override {
        return generateSVG("<text x='50%' y='50%' text-anchor='middle' fill='var(--ew-text-muted)'>Chart implementation required</text>");
    }

protected:
    std::string generateSVG(const std::string& chart_content) const {
        std::ostringstream svg;
        svg << "<div class=\"ew-chart-container";
        if (!classes_.empty()) svg << " " << classes_;
        svg << "\"" << render_attributes() << ">";

        if (!title_.empty()) {
            svg << "<div class=\"ew-chart-title\">" << title_ << "</div>";
        }

        svg << "<svg width=\"" << width_ << "\" height=\"" << height_
            << "\" viewBox=\"0 0 " << width_ << " " << height_
            << "\" class=\"ew-chart\">";

        // Background (only border, no fill to avoid covering chart)
        svg << "<rect width=\"100%\" height=\"100%\" fill=\"transparent\" stroke=\"var(--ew-border)\" stroke-width=\"1\" rx=\"4\"/>";

        // Chart content (implemented by subclasses)
        svg << chart_content;

        svg << "</svg>";

        if (show_legend_ && !series_.empty()) {
            svg << generateLegend();
        }

        svg << "</div>";
        return svg.str();
    }

    std::string generateLegend() const {
        std::ostringstream legend;
        legend << "<div class=\"ew-chart-legend\">";
        for (const auto& series : series_) {
            if (!series.name.empty()) {
                legend << "<div class=\"ew-chart-legend-item\">"
                       << "<div class=\"ew-chart-legend-color\" style=\"background-color: " << (series.color.empty() ? "var(--ew-primary)" : series.color) << "\"></div>"
                       << "<span>" << series.name << "</span>"
                       << "</div>";
            }
        }
        legend << "</div>";
        return legend.str();
    }

    std::pair<double, double> findDataRange() const {
        if (series_.empty()) return {0, 100};

        double min_x = std::numeric_limits<double>::max();
        double max_x = std::numeric_limits<double>::lowest();
        double min_y = std::numeric_limits<double>::max();
        double max_y = std::numeric_limits<double>::lowest();

        bool has_data = false;
        for (const auto& series : series_) {
            if (!series.data.empty()) {
                has_data = true;
                for (const auto& point : series.data) {
                    min_x = std::min(min_x, point.x);
                    max_x = std::max(max_x, point.x);
                    min_y = std::min(min_y, point.y);
                    max_y = std::max(max_y, point.y);
                }
            }
        }

        if (!has_data) return {0, 100};

        // Handle case where all values are the same
        if (min_x == max_x) {
            min_x -= 1;
            max_x += 1;
        }
        if (min_y == max_y) {
            min_y -= 1;
            max_y += 1;
        }

        // Add some padding
        double x_padding = (max_x - min_x) * 0.1;
        double y_padding = (max_y - min_y) * 0.1;

        return {min_x - x_padding, max_x + x_padding};
    }

    std::pair<double, double> findYRange() const {
        if (series_.empty()) return {0, 100};

        double min_y = std::numeric_limits<double>::max();
        double max_y = std::numeric_limits<double>::lowest();

        bool has_data = false;
        for (const auto& series : series_) {
            if (!series.data.empty()) {
                has_data = true;
                for (const auto& point : series.data) {
                    min_y = std::min(min_y, point.y);
                    max_y = std::max(max_y, point.y);
                }
            }
        }

        if (!has_data) return {0, 100};

        // Handle case where all values are the same
        if (min_y == max_y) {
            min_y -= 1;
            max_y += 1;
        }

        // Add some padding
        double padding = (max_y - min_y) * 0.1;
        return {min_y - padding, max_y + padding};
    }

    double scaleX(double x, double min_x, double max_x) const {
        const int margin = 60;
        double chart_width = width_ - 2 * margin;
        return margin + (x - min_x) / (max_x - min_x) * chart_width;
    }

    double scaleY(double y, double min_y, double max_y) const {
        const int margin = 40;
        double chart_height = height_ - 2 * margin;
        return height_ - margin - (y - min_y) / (max_y - min_y) * chart_height;
    }
};

// ============================================================================
// Line Chart Component
// ============================================================================

class LineChart : public Chart {
public:
    bool smooth_lines_ = false;
    bool show_points_ = true;
    int point_radius_ = 3;

    LineChart() = default;

    LineChart& smoothLines(bool smooth = true) { smooth_lines_ = smooth; return *this; }
    LineChart& showPoints(bool show = true) { show_points_ = show; return *this; }
    LineChart& pointRadius(int radius) { point_radius_ = radius; return *this; }

    std::string render() const override {
        auto [min_x, max_x] = findDataRange();
        auto [min_y, max_y] = findYRange();

        std::ostringstream content;

        // Grid lines
        if (show_grid_) {
            content << generateGrid(min_x, max_x, min_y, max_y);
        }

        // Axes
        content << generateAxes(min_x, max_x, min_y, max_y);

        // Data lines
        for (size_t i = 0; i < series_.size(); ++i) {
            const auto& series = series_[i];
            if (!series.data.empty()) {
                content << generateLine(series, min_x, max_x, min_y, max_y, i);
            }
        }

        return generateSVG(content.str());
    }

private:
    std::string generateGrid(double min_x, double max_x, double min_y, double max_y) const {
        std::ostringstream grid;
        const int margin = 60;
        double chart_width = width_ - 2 * margin;
        double chart_height = height_ - 2 * margin;

        // Vertical grid lines
        for (int i = 0; i <= 5; ++i) {
            double x = margin + (chart_width * i) / 5;
            grid << "<line x1=\"" << x << "\" y1=\"" << margin
                 << "\" x2=\"" << x << "\" y2=\"" << height_ - margin
                 << "\" stroke=\"var(--ew-border)\" stroke-width=\"0.5\" opacity=\"0.3\"/>";
        }

        // Horizontal grid lines
        for (int i = 0; i <= 5; ++i) {
            double y = margin + (chart_height * i) / 5;
            grid << "<line x1=\"" << margin << "\" y1=\"" << y
                 << "\" x2=\"" << width_ - margin << "\" y2=\"" << y
                 << "\" stroke=\"var(--ew-border)\" stroke-width=\"0.5\" opacity=\"0.3\"/>";
        }

        return grid.str();
    }

    std::string generateAxes(double min_x, double max_x, double min_y, double max_y) const {
        std::ostringstream axes;
        const int margin = 60;
        double chart_width = width_ - 2 * margin;
        double chart_height = height_ - 2 * margin;

        // X and Y axes
        axes << "<line x1=\"" << margin << "\" y1=\"" << height_ - margin
             << "\" x2=\"" << width_ - margin << "\" y2=\"" << height_ - margin
             << "\" stroke=\"var(--ew-text)\" stroke-width=\"1\"/>";

        axes << "<line x1=\"" << margin << "\" y1=\"" << margin
             << "\" x2=\"" << margin << "\" y2=\"" << height_ - margin
             << "\" stroke=\"var(--ew-text)\" stroke-width=\"1\"/>";

        // Y-axis labels (vertical)
        for (int i = 0; i <= 5; ++i) {
            double value = min_y + (max_y - min_y) * i / 5;
            double y = height_ - margin - (chart_height * i) / 5;
            
            // Grid line intersection
            axes << "<line x1=\"" << margin - 5 << "\" y1=\"" << y
                 << "\" x2=\"" << margin << "\" y2=\"" << y
                 << "\" stroke=\"var(--ew-text)\" stroke-width=\"1\"/>";
            
            // Label
            std::ostringstream label;
            label << std::fixed << std::setprecision(1) << value;
            axes << "<text x=\"" << (margin - 10) << "\" y=\"" << (y + 4)
                 << "\" text-anchor=\"end\" fill=\"var(--ew-text)\" font-size=\"11\">"
                 << label.str() << "</text>";
        }

        // X-axis labels (horizontal)
        for (int i = 0; i <= 5; ++i) {
            double value = min_x + (max_x - min_x) * i / 5;
            double x = margin + (chart_width * i) / 5;
            
            // Grid line intersection
            axes << "<line x1=\"" << x << "\" y1=\"" << height_ - margin
                 << "\" x2=\"" << x << "\" y2=\"" << height_ - margin + 5
                 << "\" stroke=\"var(--ew-text)\" stroke-width=\"1\"/>";
            
            // Label
            std::ostringstream label;
            label << std::fixed << std::setprecision(1) << value;
            axes << "<text x=\"" << x << "\" y=\"" << (height_ - margin + 20)
                 << "\" text-anchor=\"middle\" fill=\"var(--ew-text)\" font-size=\"11\">"
                 << label.str() << "</text>";
        }

        return axes.str();
    }

    std::string generateLine(const ChartSeries& series, double min_x, double max_x, double min_y, double max_y, size_t series_index) const {
        std::ostringstream line;
        std::string color = series.color.empty() ? "var(--ew-primary)" : series.color;

        if (series.data.size() < 2) return "";

        // Generate path
        std::ostringstream path_data;
        bool first = true;

        for (const auto& point : series.data) {
            double x = scaleX(point.x, min_x, max_x);
            double y = scaleY(point.y, min_y, max_y);

            if (first) {
                path_data << "M " << x << " " << y;
                first = false;
            } else {
                path_data << " L " << x << " " << y;
            }
        }

        line << "<path d=\"" << path_data.str()
             << "\" fill=\"none\" stroke=\"" << color
             << "\" stroke-width=\"2\"/>";

        // Points
        if (show_points_) {
            for (const auto& point : series.data) {
                double x = scaleX(point.x, min_x, max_x);
                double y = scaleY(point.y, min_y, max_y);

                line << "<circle cx=\"" << x << "\" cy=\"" << y
                     << "\" r=\"" << point_radius_
                     << "\" fill=\"" << color << "\"/>";
            }
        }

        return line.str();
    }
};

// ============================================================================
// Bar Chart Component
// ============================================================================

class BarChart : public Chart {
public:
    bool horizontal_ = false;
    int bar_width_ = 30;
    int bar_spacing_ = 10;

    BarChart() = default;

    BarChart& horizontal(bool h = true) { horizontal_ = h; return *this; }
    BarChart& barWidth(int w) { bar_width_ = w; return *this; }
    BarChart& barSpacing(int s) { bar_spacing_ = s; return *this; }

    std::string render() const override {
        auto [min_x, max_x] = findDataRange();
        auto [min_y, max_y] = findYRange();

        std::ostringstream content;

        // Grid lines
        if (show_grid_) {
            content << generateGrid(min_x, max_x, min_y, max_y);
        }

        // Axes
        content << generateAxes(min_x, max_x, min_y, max_y);

        // Bars
        for (size_t i = 0; i < series_.size(); ++i) {
            const auto& series = series_[i];
            if (!series.data.empty()) {
                content << generateBars(series, min_x, max_x, min_y, max_y, i);
            }
        }

        return generateSVG(content.str());
    }

private:
    std::string generateGrid(double min_x, double max_x, double min_y, double max_y) const {
        std::ostringstream grid;
        const int margin = 60;

        // Horizontal grid lines
        for (int i = 0; i <= 5; ++i) {
            double y = margin + ((height_ - 2 * margin) * i) / 5;
            grid << "<line x1=\"" << margin << "\" y1=\"" << y
                 << "\" x2=\"" << width_ - margin << "\" y2=\"" << y
                 << "\" stroke=\"var(--ew-border)\" stroke-width=\"0.5\" opacity=\"0.3\"/>";
        }

        return grid.str();
    }

    std::string generateAxes(double min_x, double max_x, double min_y, double max_y) const {
        std::ostringstream axes;
        const int margin = 60;
        double chart_width = width_ - 2 * margin;
        double chart_height = height_ - 2 * margin;

        // X and Y axes
        axes << "<line x1=\"" << margin << "\" y1=\"" << height_ - margin
             << "\" x2=\"" << width_ - margin << "\" y2=\"" << height_ - margin
             << "\" stroke=\"var(--ew-text)\" stroke-width=\"1\"/>";

        axes << "<line x1=\"" << margin << "\" y1=\"" << margin
             << "\" x2=\"" << margin << "\" y2=\"" << height_ - margin
             << "\" stroke=\"var(--ew-text)\" stroke-width=\"1\"/>";

        // Y-axis labels (vertical)
        for (int i = 0; i <= 5; ++i) {
            double value = min_y + (max_y - min_y) * i / 5;
            double y = height_ - margin - (chart_height * i) / 5;
            
            // Grid line intersection
            axes << "<line x1=\"" << margin - 5 << "\" y1=\"" << y
                 << "\" x2=\"" << margin << "\" y2=\"" << y
                 << "\" stroke=\"var(--ew-text)\" stroke-width=\"1\"/>";
            
            // Label
            std::ostringstream label;
            label << std::fixed << std::setprecision(1) << value;
            axes << "<text x=\"" << (margin - 10) << "\" y=\"" << (y + 4)
                 << "\" text-anchor=\"end\" fill=\"var(--ew-text)\" font-size=\"11\">"
                 << label.str() << "</text>";
        }

        return axes.str();
    }

    std::string generateBars(const ChartSeries& series, double min_x, double max_x, double min_y, double max_y, size_t series_index) const {
        std::ostringstream bars;
        std::string color = series.color.empty() ? "var(--ew-primary)" : series.color;

        const int margin = 60;
        double chart_width = width_ - 2 * margin;
        double chart_height = height_ - 2 * margin;

        int total_bars = series.data.size();
        double total_width = total_bars * (bar_width_ + bar_spacing_) - bar_spacing_;
        double start_x = margin + (chart_width - total_width) / 2;

        for (size_t i = 0; i < series.data.size(); ++i) {
            const auto& point = series.data[i];
            double bar_height = (point.y - min_y) / (max_y - min_y) * chart_height;
            double x = start_x + i * (bar_width_ + bar_spacing_);
            double y = height_ - margin - bar_height;

            bars << "<rect x=\"" << x << "\" y=\"" << y
                 << "\" width=\"" << bar_width_ << "\" height=\"" << bar_height
                 << "\" fill=\"" << color << "\" rx=\"2\"/>";

            // Add value label on top of the bar
            std::ostringstream value_label;
            value_label << std::fixed << std::setprecision(1) << point.y;
            double label_x = x + bar_width_ / 2;
            double label_y = y - 5; // Position above the bar

            bars << "<text x=\"" << label_x << "\" y=\"" << label_y
                 << "\" text-anchor=\"middle\" fill=\"var(--ew-text)\" font-size=\"11\" font-weight=\"bold\">"
                 << value_label.str() << "</text>";
        }

        return bars.str();
    }
};

// ============================================================================
// Pie Chart Component
// ============================================================================

class PieChart : public Chart {
public:
    bool show_labels_ = true;
    int inner_radius_ = 0; // For donut charts

    PieChart() = default;

    PieChart& showLabels(bool show = true) { show_labels_ = show; return *this; }
    PieChart& innerRadius(int radius) { inner_radius_ = radius; return *this; }

    // Override addSeries to handle pie chart legend properly
    PieChart& addSeries(const ChartSeries& series) {
        // For pie charts, create individual series for each data point for proper legend
        for (size_t i = 0; i < series.data.size(); ++i) {
            const auto& point = series.data[i];
            std::string color = point.color.empty() ? getDefaultColor(i) : point.color;
            std::string name = point.label.empty() ? ("Slice " + std::to_string(i + 1)) : point.label;
            
            ChartSeries individual_series(name, {point}, color);
            series_.push_back(individual_series);
        }
        return *this;
    }

    std::string render() const override {
        std::ostringstream content;

        if (series_.empty()) return generateSVG("");

        // Collect all data points from all series
        std::vector<DataPoint> all_data;
        for (const auto& series : series_) {
            if (!series.data.empty()) {
                all_data.push_back(series.data[0]); // Each series has one data point
            }
        }

        if (all_data.empty()) return generateSVG("");

        double total = 0;
        for (const auto& point : all_data) {
            total += point.y;
        }

        double center_x = width_ / 2;
        double center_y = height_ / 2;
        double radius = std::min(width_, height_) / 2 - 40;

        double current_angle = -M_PI / 2; // Start at top

        for (size_t i = 0; i < all_data.size(); ++i) {
            const auto& point = all_data[i];
            double percentage = point.y / total;
            double angle = percentage * 2 * M_PI;

            // Calculate start and end angles
            double start_angle = current_angle;
            double end_angle = current_angle + angle;

            // Calculate points
            double x1 = center_x + radius * cos(start_angle);
            double y1 = center_y + radius * sin(start_angle);
            double x2 = center_x + radius * cos(end_angle);
            double y2 = center_y + radius * sin(end_angle);

            // Determine if this is a large arc (angle > 180 degrees)
            int large_arc = (angle > M_PI) ? 1 : 0;

            std::string color = point.color.empty() ? getDefaultColor(i) : point.color;

            // Create pie slice path: move to center, line to start, arc to end, line back to center
            content << "<path d=\"M " << center_x << "," << center_y
                    << " L " << x1 << "," << y1
                    << " A " << radius << "," << radius << " 0 " << large_arc << ",1 " << x2 << "," << y2
                    << " Z\" fill=\"" << color << "\" stroke=\"var(--ew-bg-card)\" stroke-width=\"1\"/>";

            // Labels
            if (show_labels_ && percentage > 0.05) { // Only show labels for slices > 5%
                double label_angle = start_angle + angle / 2;
                double label_radius = radius * 0.7;
                double label_x = center_x + label_radius * cos(label_angle);
                double label_y = center_y + label_radius * sin(label_angle);

                content << "<text x=\"" << label_x << "\" y=\"" << label_y
                        << "\" text-anchor=\"middle\" dominant-baseline=\"middle\" "
                        << "fill=\"var(--ew-text)\" font-size=\"12\" font-weight=\"bold\">"
                        << std::fixed << std::setprecision(1) << (percentage * 100) << "%</text>";
            }

            current_angle = end_angle;
        }

        // Inner circle for donut chart
        if (inner_radius_ > 0) {
            content << "<circle cx=\"" << center_x << "\" cy=\"" << center_y
                    << "\" r=\"" << inner_radius_
                    << "\" fill=\"var(--ew-bg-card)\"/>";
        }

        return generateSVG(content.str());
    }

private:
    std::string getDefaultColor(size_t index) const {
        static const std::vector<std::string> colors = {
            "var(--ew-primary)",
            "var(--ew-secondary)",
            "#f85149", "#f0b400", "#40a9ff", "#a855f7",
            "#4ec968", "#f85149", "#f0b400", "#40a9ff"
        };
        return colors[index % colors.size()];
    }
};

} // namespace zero_js