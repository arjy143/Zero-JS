#include "../../zero_js.hpp"
#include <iostream>

using namespace zero_js;

// Helper to create a code block with syntax highlighting styling
Card create_code_block(const std::string& code, const std::string& language = "cpp") {
    return Card().compact().classes("ew-code-block")
        .add(Row()
            .add(Text(language).muted().classes("ew-flex-grow"))
            .add(Button("Copy").ghost().classes("ew-button-xs"))
        )
        .add(Text(code).classes("ew-code"));
}

// Create documentation content
App create_doc_content() {
    App app;

    // Navbar
    app.navbar(
        Navbar()
            .brand("ZeroJS Docs")
            .add(NavItem("Guide").href("#guide").active())
            .add(NavItem("API Reference").href("#api"))
            .add(NavItem("Examples").href("#examples"))
            .add(NavItem("GitHub").href("#github"))
            .addAction(Button("v1.0.0").ghost().classes("ew-button-sm"))
    );

    // Sidebar - Documentation navigation
    app.sidebar(
        Sidebar()
            .add(SidebarSection("Getting Started")
                .add(SidebarItem("Introduction").active())
                .add(SidebarItem("Installation"))
                .add(SidebarItem("Quick Start"))
                .add(SidebarItem("Project Structure"))
            )
            .add(SidebarSection("Core Concepts")
                .add(SidebarItem("Components"))
                .add(SidebarItem("Layout System"))
                .add(SidebarItem("Styling"))
                .add(SidebarItem("Themes"))
            )
            .add(SidebarSection("Components")
                .add(SidebarItem("Text"))
                .add(SidebarItem("Button"))
                .add(SidebarItem("Card"))
                .add(SidebarItem("Form"))
                .add(SidebarItem("Grid"))
                .add(SidebarItem("Navbar"))
                .add(SidebarItem("Sidebar"))
            )
            .add(SidebarSection("Advanced")
                .add(SidebarItem("HTMX Integration"))
                .add(SidebarItem("Custom Styling"))
                .add(SidebarItem("Server-Side Rendering"))
            )
    );

    // Main content - Introduction section
    app.add(
        Row()
            .add(Column().classes("ew-flex-grow")
                .add(Text("Introduction").h1())
                .add(Text("Build beautiful static websites with C++ and HTMX").secondary())
            )
            .add(Row().gap("sm")
                .add(Button("Edit on GitHub").trigger("click").get("/api/click").swap("none"))
            )
    );

    app.add(Spacer().sm());

    // Feature badges
    app.add(
        Row().gap("sm").wrap()
            .add(Badge("C++17"))
            .add(Badge("Header-Only"))
            .add(Badge("No JavaScript").success())
            .add(Badge("HTMX Powered"))
    );

    app.add(Spacer());

    // Overview card
    app.add(
        Card().title("Overview").accent()
            .add(Text("ZeroJS is a header-only C++ library for generating elegant, responsive static websites without writing any JavaScript. It leverages HTMX for interactivity while keeping your codebase purely C++."))
            .add(Spacer().sm())
            .add(Text("Key Features:").h3())
            .add(Column().gap("sm")
                .add(Row()
                    .add(Text("•").accent())
                    .add(Text("Modern, responsive design out of the box"))
                )
                .add(Row()
                    .add(Text("•").accent())
                    .add(Text("Three built-in themes: Dark, Light, and Cream"))
                )
                .add(Row()
                    .add(Text("•").accent())
                    .add(Text("Chainable component API for clean, readable code"))
                )
                .add(Row()
                    .add(Text("•").accent())
                    .add(Text("HTMX integration for dynamic content without JavaScript"))
                )
            )
    );

    app.add(Spacer());

    // Installation section
    app.add(Text("Installation").h2());
    app.add(Text("Getting started with ZeroJS is simple - just include the header file.").secondary());

    app.add(Spacer().sm());

    app.add(
        create_code_block(
            "// Include the single header file\n"
            "#include \"zero_js.hpp\"\n"
            "\n"
            "// Use the namespace\n"
            "using namespace zero_js;",
            "cpp"
        )
    );

    app.add(Spacer());

    // Quick Start section
    app.add(Text("Quick Start").h2());
    app.add(Text("Create your first page in just a few lines of code.").secondary());

    app.add(Spacer().sm());

    app.add(
        create_code_block(
            "#include \"zero_js.hpp\"\n"
            "using namespace zero_js;\n"
            "\n"
            "int main() {\n"
            "    Page page(\"My Website\");\n"
            "    page.dark_mode();\n"
            "    \n"
            "    page.add(\n"
            "        Card().title(\"Hello World\")\n"
            "            .add(Text(\"Welcome to ZeroJS!\"))\n"
            "            .add(Button(\"Get Started\"))\n"
            "    );\n"
            "    \n"
            "    page.render_to_file(\"index.html\");\n"
            "    return 0;\n"
            "}",
            "cpp"
        )
    );

    app.add(Spacer());

    // Components Overview
    app.add(Text("Component Examples").h2());
    app.add(Text("Here are some of the components you can use to build your website.").secondary());

    app.add(Spacer().sm());

    // Component examples grid
    app.add(
        Grid().columns(2)
            .add(Card().title("Buttons")
                .add(Column().gap("sm")
                    .add(Button("Primary"))
                    .add(Button("Secondary").secondary())
                    .add(Button("Outline").outline())
                    .add(Button("Ghost").ghost())
                )
            )
            .add(Card().title("Badges")
                .add(Row().wrap().gap("sm")
                    .add(Badge("Default"))
                    .add(Badge("Success").success())
                    .add(Badge("Warning").warning())
                    .add(Badge("Error").error())
                )
            )
            .add(Card().title("Statistics")
                .add(Stat()
                    .label("Total Downloads")
                    .value("12,847")
                    .change("23%", true)
                )
            )
            .add(Card().title("Forms")
                .add(Input("email").label("Email").placeholder("you@example.com"))
                .add(Spacer().sm())
                .add(Button("Subscribe"))
            )
    );

    app.add(Spacer());

    // Layout section
    app.add(Text("Layout System").h2());
    app.add(Text("Use Grid, Row, and Column components for flexible layouts.").secondary());

    app.add(Spacer().sm());

    app.add(
        create_code_block(
            "// Create a 3-column grid\n"
            "app.add(\n"
            "    Grid().columns(3)\n"
            "        .add(Card().title(\"Column 1\"))\n"
            "        .add(Card().title(\"Column 2\"))\n"
            "        .add(Card().title(\"Column 3\"))\n"
            ");",
            "cpp"
        )
    );

    app.add(Spacer());

    // Theme selection
    app.add(Text("Themes").h2());
    app.add(Text("Choose from three built-in themes to match your style.").secondary());

    app.add(Spacer().sm());

    app.add(
        Grid().columns(3)
            .add(Card().compact().border("#22c55e")
                .add(Text("Dark Mode").h3())
                .add(Text("Terminal-inspired dark theme with green accents, perfect for developer tools.").muted())
            )
            .add(Card().compact().border("#18181b")
                .add(Text("Light Mode").h3())
                .add(Text("Clean, minimal design with dark accents for professional documentation.").muted())
            )
            .add(Card().compact().border("#8b2500")
                .add(Text("Cream Mode").h3())
                .add(Text("Warm, paper-like feel great for long-form content and reading.").muted())
            )
    );

    app.add(Spacer());

    // HTMX Integration
    app.add(Text("HTMX Integration").h2());
    app.add(Text("Add dynamic behavior without writing JavaScript.").secondary());

    app.add(Spacer().sm());

    app.add(
        create_code_block(
            "// Button with HTMX action\n"
            "Button(\"Load More\")\n"
            "    .get(\"/api/items\")\n"
            "    .target(\"#content\")\n"
            "    .swap(\"innerHTML\")\n"
            "\n"
            "// Form with HTMX submission\n"
            "Form()\n"
            "    .post(\"/api/submit\")\n"
            "    .target(\"#result\")\n"
            "    .add(Input(\"name\").label(\"Name\"))\n"
            "    .add(Button(\"Submit\"))",
            "cpp"
        )
    );

    app.add(Spacer());

    // API Reference preview
    app.add(
        Card().title("API Reference")
            .add(Text("Explore the complete component API documentation.").secondary())
            .add(Spacer().sm())
            .add(Grid().columns(4)
                .add(Column()
                    .add(Text("Layout").h3())
                    .add(Text("App").muted())
                    .add(Text("Page").muted())
                    .add(Text("Grid").muted())
                    .add(Text("Row").muted())
                    .add(Text("Column").muted())
                )
                .add(Column()
                    .add(Text("Display").h3())
                    .add(Text("Text").muted())
                    .add(Text("Card").muted())
                    .add(Text("Badge").muted())
                    .add(Text("Stat").muted())
                    .add(Text("Image").muted())
                )
                .add(Column()
                    .add(Text("Navigation").h3())
                    .add(Text("Navbar").muted())
                    .add(Text("Sidebar").muted())
                    .add(Text("NavItem").muted())
                    .add(Text("Link").muted())
                )
                .add(Column()
                    .add(Text("Interactive").h3())
                    .add(Text("Button").muted())
                    .add(Text("Input").muted())
                    .add(Text("Form").muted())
                    .add(Text("Box").muted())
                )
            )
    );

    app.add(Spacer());

    // Footer-like section
    app.add(Divider());
    app.add(
        Row()
            .add(Text("ZeroJS Documentation").muted().classes("ew-flex-grow"))
            .add(Row().gap("sm")
                .add(Link("GitHub", "#"))
                .add(Link("License", "#"))
                .add(Link("Contributing", "#"))
            )
    );

    return app;
}

int main() {
    // Dark Mode - ideal for developer documentation
    {
        Page page("ZeroJS Documentation - Dark Mode");
        page.dark_mode();
        page.add(create_doc_content());
        page.render_to_file("examples/doc_website/doc_website-dark.html");
        std::cout << "Generated doc_website-dark.html" << std::endl;
    }

    // Light Mode - clean professional look
    {
        Page page("ZeroJS Documentation - Light Mode");
        page.light_mode();
        page.add(create_doc_content());
        page.render_to_file("examples/doc_website/doc_website-light.html");
        std::cout << "Generated doc_website-light.html" << std::endl;
    }

    // Cream Mode - warm readable style
    {
        Page page("ZeroJS Documentation - Cream Mode");
        page.cream_mode();
        page.add(create_doc_content());
        page.render_to_file("examples/doc_website/doc_website-cream.html");
        std::cout << "Generated doc_website-cream.html" << std::endl;
    }

    std::cout << "\nOpen any of the HTML files in your browser:" << std::endl;
    std::cout << "  - doc_website-dark.html  (Developer-focused dark theme)" << std::endl;
    std::cout << "  - doc_website-light.html (Clean professional theme)" << std::endl;
    std::cout << "  - doc_website-cream.html (Warm readable theme)" << std::endl;

    return 0;
}
