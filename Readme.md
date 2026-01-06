# Zero-JS

I wanted to see if I could make beautiful websites without having to mess around with HTML, CSS, and JavaScript, and also without having to touch any web frameworks with a billion dependencies. That's what this project aims to do.

## Features

- **Component-based architecture** - Build UIs with reusable components
- **Zero dependencies** - Pure C++ to HTML/CSS generation
- **Theme support** - Dark, Light, and Cream themes
- **Responsive design** - Mobile-friendly layouts
- **Chart components** - SVG-based data visualisation
- **HTMX integration** - Dynamic interactions without JavaScript

## Themes

ZeroJS supports three built-in themes:
- **Dark** - Modern dark theme for technical applications
- **Light** - Clean light theme for professional UIs
- **Cream** - Warm technical documentation-style theme

## Examples

- An example dashboard using the technical document style theme
![alt text](design/image.png)

- A diagram using the dark mode theme
![alt text](design/image2.png)

- A system monitor page using the light mode theme
![alt text](design/image3.png)

See the `examples/` directory for complete static websites:

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



