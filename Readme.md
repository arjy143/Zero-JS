# Zero-JS

I wanted to see if I could make beautiful websites without having to mess around with HTML, CSS, and JavaScript, and also without having to touch any web frameworks with a billion dependencies. That's what this project aims to do.

## Features

- **Component-based architecture** - Build UIs with reusable components
- **Zero dependencies** - Pure C++ to HTML/CSS generation
- **Theme support** - Dark, Light, and Cream themes
- **Responsive design** - Mobile-friendly layouts
- **Chart components** - SVG-based data visualization
- **HTMX integration** - Dynamic interactions without JavaScript

## Responsive Design

ZeroJS is built mobile-first with comprehensive responsive design support:

### Breakpoints
- **Mobile**: < 576px
- **Tablet**: 576px - 1023px  
- **Desktop**: 1024px - 1199px
- **Large**: ≥ 1200px

### Responsive Components

#### Responsive Grid
```cpp
Grid().responsive()
    .add(Card().title("Item 1"))
    .add(Card().title("Item 2"))
    .add(Card().title("Item 3"));
```

#### Mobile-Friendly Rows
```cpp
Row().stack_mobile()  // Stacks vertically on mobile
    .add(component1)
    .add(component2);
```

#### Touch-Friendly Cards
```cpp
Card().mobile_full()  // Full-width on mobile
    .title("Mobile Card")
    .add(content);
```

### Responsive Utilities
- `.ew-hidden-mobile` - Hide on mobile
- `.ew-hidden-tablet` - Hide on tablet  
- `.ew-hidden-desktop` - Hide on desktop
- `.ew-btn-touch` - Touch-friendly button sizing
- `.ew-grid-responsive` - Auto-fitting responsive grid

## Components

### Layout Components
- `Row` - Horizontal flex container
- `Column` - Vertical flex container
- `Grid` - CSS Grid layout
- `Card` - Content container with optional title
- `Spacer` - Spacing utility

### Form Components
- `Input` - Text input fields
- `Button` - Interactive buttons (primary, secondary, outline, ghost)
- `Form` - Form container with POST/GET actions

### Data Display
- `Text` - Styled text with heading levels
- `Badge` - Status indicators
- `Stat` - Metric display with change indicators
- `Table` - Data tables (planned)

### Chart Components
- `LineChart` - Multi-series line graphs
- `BarChart` - Vertical bar charts
- `PieChart` - Circular proportional charts
- `Diagram` - Interactive node-link diagrams

## Chart Components

ZeroJS includes powerful SVG-based chart components for data visualization:

### LineChart
```cpp
LineChart chart;
chart.width(500).height(300);
chart.title("Performance Metrics");
chart.addSeries(ChartSeries("CPU %", {
    DataPoint(0, 45), DataPoint(1, 52), DataPoint(2, 48)
}, "var(--ew-primary)"));
```

### Diagram
```cpp
Diagram diagram;
diagram.width(600).height(400);
diagram.layoutType(LayoutType::Hierarchical);
diagram.layoutDirection(LayoutDirection::LeftToRight);
diagram
    .node("start", "Start")
    .node("process", "Process")
    .node("end", "End")
    .edge("start", "process")
    .edge("process", "end");
```

### BarChart
```cpp
BarChart chart;
chart.width(400).height(250);
chart.title("Revenue by Department");
chart.addSeries(ChartSeries("Revenue", {
    DataPoint(0, 125, "Engineering"),
    DataPoint(1, 89, "Sales")
}, "var(--ew-secondary)"));
chart.barWidth(30);
```

### PieChart
```cpp
PieChart chart;
chart.width(300).height(300);
chart.title("Resource Allocation");
chart.addSeries(ChartSeries("Resources", {
    DataPoint(0, 40, "Web", "#ff6b6b"),
    DataPoint(1, 30, "DB", "#4ecdc4")
}));
```

## Examples

See the `examples/` directory for complete applications:

- `dashboard/` - Business metrics dashboard
- `personal_portfolio/` - Developer portfolio
- `habit_tracker/` - Goal tracking app
- `system_monitor/` - Infrastructure monitoring (with charts)
- `chart_demo/` - Chart component showcase

## Building

```bash
# Compile an example
g++ -std=c++17 -I. examples/system_monitor/system_monitor.cpp -o system_monitor

# Run the application
./system_monitor
```

This generates HTML files for all themes that you can open in any browser.

## Architecture

- `src/components.hpp` - UI component definitions
- `src/charts.hpp` - Chart component implementations
- `src/styles.hpp` - CSS generation and theming
- `src/renderer.hpp` - HTML output generation
- `zero_js.hpp` - Main header to include

## Themes

ZeroJS supports three built-in themes:
- **Dark** - Modern dark theme for technical applications
- **Light** - Clean light theme for professional UIs
- **Cream** - Warm documentation-style theme

## Contributing

This is a learning project exploring C++ web development. Feel free to experiment and contribute improvements! 