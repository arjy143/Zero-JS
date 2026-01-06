#include "../../zero_js.hpp"
#include <iostream>

using namespace zero_js;

int main() {
    // ========================================
    // CHART DEMO - Showcasing all chart types
    // ========================================
    {
        Page page("Chart Demo - ZeroJS Framework");
        page.cream_mode();

        App app;

        app.add(
            Row().classes("ew-center-content")
                .add(Column().classes("ew-center")
                    .add(Spacer().lg())
                    .add(Text("📊 ZeroJS Chart Components").h1())
                    .add(Text("Line Charts, Bar Charts, Pie Charts, and Diagrams").secondary())
                    .add(Spacer().xl())
                )
        );

        // Line Chart Demo
        LineChart lineChart;
        lineChart.width(500).height(300);
        lineChart.title("Server Performance Over Time");
        lineChart.addSeries(ChartSeries("CPU Usage %", {
            DataPoint(0, 45), DataPoint(1, 52), DataPoint(2, 48),
            DataPoint(3, 61), DataPoint(4, 55), DataPoint(5, 49),
            DataPoint(6, 42), DataPoint(7, 58), DataPoint(8, 63),
            DataPoint(9, 57), DataPoint(10, 51), DataPoint(11, 46)
        }, "var(--ew-primary)"));
        lineChart.addSeries(ChartSeries("Memory %", {
            DataPoint(0, 67), DataPoint(1, 71), DataPoint(2, 69),
            DataPoint(3, 89), DataPoint(4, 85), DataPoint(5, 82),
            DataPoint(6, 78), DataPoint(7, 84), DataPoint(8, 88),
            DataPoint(9, 83), DataPoint(10, 79), DataPoint(11, 75)
        }, "#40a9ff"));
        lineChart.addSeries(ChartSeries("Disk I/O", {
            DataPoint(0, 12), DataPoint(1, 28), DataPoint(2, 35),
            DataPoint(3, 42), DataPoint(4, 38), DataPoint(5, 31),
            DataPoint(6, 25), DataPoint(7, 45), DataPoint(8, 52),
            DataPoint(9, 48), DataPoint(10, 33), DataPoint(11, 29)
        }, "#f0b400"));

        app.add(Card().title("📈 Line Chart - Multi-Series Data").add(lineChart));

        app.add(Spacer());

        // Bar Chart Demo
        BarChart barChart;
        barChart.width(500).height(300);
        barChart.title("Monthly Revenue by Department");
        barChart.addSeries(ChartSeries("Revenue ($K)", {
            DataPoint(0, 125, "Engineering"),
            DataPoint(1, 89, "Sales"),
            DataPoint(2, 156, "Marketing"),
            DataPoint(3, 78, "Support"),
            DataPoint(4, 134, "Operations")
        }, "var(--ew-secondary)"));
        barChart.barWidth(35);

        app.add(Card().title("📊 Bar Chart - Categorical Data").add(barChart));

        app.add(Spacer());

        // Pie Chart Demo
        PieChart pieChart;
        pieChart.width(400).height(400);
        pieChart.title("Server Resource Allocation");
        pieChart.addSeries(ChartSeries("Resources", {
            DataPoint(0, 40, "Web Servers", "var(--ew-primary)"),
            DataPoint(1, 25, "Databases", "var(--ew-secondary)"),
            DataPoint(2, 15, "APIs", "#40a9ff"),
            DataPoint(3, 12, "Cache", "#f0b400"),
            DataPoint(4, 8, "Background Jobs", "#f85149")
        }));

        app.add(Card().title("🥧 Pie Chart - Proportional Data").add(pieChart));

        app.add(Spacer());

        // Diagram Demo - Hierarchical Layout (Workflow)
        Diagram workflowDiagram;
        workflowDiagram.width(600).height(200);
        workflowDiagram.layoutDirection(LayoutDirection::LeftToRight);
        workflowDiagram
            .node("input", "Input\nData")
            .node("process", "Process\nData")
            .node("validate", "Validate\nResults")
            .node("output", "Generate\nOutput")
            .edge("input", "process", "raw data")
            .edge("process", "validate", "processed")
            .edge("validate", "output", "validated");

        app.add(Card().title("🔀 Diagram - Hierarchical Workflow").add(workflowDiagram));

        app.add(Spacer());
        // Diagram Demo - Top to Bottom Layout
        Diagram verticalDiagram;
        verticalDiagram.width(300).height(500);
        verticalDiagram.layoutType(LayoutType::Hierarchical);
        verticalDiagram.layoutDirection(LayoutDirection::TopToBottom);
        verticalDiagram
            .node("plan", "Planning\nPhase")
            .node("design", "Design\nPhase")
            .node("develop", "Development\nPhase")
            .node("test", "Testing\nPhase")
            .node("deploy", "Deploy\nPhase")
            .edge("plan", "design")
            .edge("design", "develop")
            .edge("develop", "test")
            .edge("test", "deploy");

        app.add(Card().title("📈 Diagram - Top-to-Bottom Workflow").add(verticalDiagram));

        app.add(Spacer());

        // Responsive Grid Demo
        app.add(
            Card().title("🔄 Responsive Grid Layout")
                .add(Text("This grid automatically adapts to screen size").secondary())
                .add(Spacer().sm())
                .add(
                    Grid().responsive()
                        .add(Card().compact().title("Card 1").add(Text("Responsive content")))
                        .add(Card().compact().title("Card 2").add(Text("Adapts to screen")))
                        .add(Card().compact().title("Card 3").add(Text("Mobile-friendly")))
                        .add(Card().compact().title("Card 4").add(Text("Flexible layout")))
                        .add(Card().compact().title("Card 5").add(Text("Auto-fitting")))
                        .add(Card().compact().title("Card 6").add(Text("Grid system")))
                )
        );

        app.add(Spacer());
        // Diagram Demo - Circular Layout (Network)
        Diagram networkDiagram;
        networkDiagram.width(400).height(400);
        networkDiagram.layoutType(LayoutType::Circular);
        networkDiagram
            .node("web", "Web\nServer")
            .node("api", "API\nGateway")
            .node("db", "Database")
            .node("cache", "Cache")
            .node("auth", "Auth\nService")
            .edge("web", "api")
            .edge("api", "db")
            .edge("api", "cache")
            .edge("api", "auth")
            .edge("auth", "db");

        app.add(Card().title("🌐 Diagram - Circular Network Topology").add(networkDiagram));

        app.add(Spacer());

        // Features showcase
        app.add(
            Card().title("✨ Chart Features")
                .add(Column().gap("sm")
                    .add(Text("• SVG-based vector graphics").secondary())
                    .add(Text("• Theme-aware colors and styling").secondary())
                    .add(Text("• Responsive and scalable").secondary())
                    .add(Text("• Multiple series support").secondary())
                    .add(Text("• Customizable legends and labels").secondary())
                    .add(Text("• Grid lines and axes").secondary())
                    .add(Text("• Smooth animations ready").secondary())
                    .add(Text("• Interactive diagrams with multiple layouts").secondary())
                    .add(Text("• Hierarchical, circular, and manual positioning").secondary())
                    .add(Text("• Left-to-right, top-to-bottom, and other flow directions").secondary())
                    .add(Text("• Labeled edges and nodes").secondary())
                    .add(Text("• Fully responsive design for mobile and desktop").secondary())
                    .add(Text("• Touch-friendly buttons and interactions").secondary())
                    .add(Text("• Adaptive grids and layouts").secondary())
                )
        );

        page.add(app);
        page.render_to_file("chart_demo.html");
        std::cout << "Generated chart_demo.html" << std::endl;
    }

    std::cout << "\nOpen chart_demo.html in your browser to see the chart components!" << std::endl;

    return 0;
}