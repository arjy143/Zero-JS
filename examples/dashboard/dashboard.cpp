#include "../../zero_js.hpp"
#include <iostream>

using namespace zero_js;

// Helper function to create the dashboard content
App create_dashboard_content() {
    App app;

    // Navbar
    app.navbar(
        Navbar()
            .brand("ZeroJS")
            .add(NavItem("Dashboard").href("#").active())
            .add(NavItem("Projects").href("#projects"))
            .add(NavItem("Analytics").href("#analytics"))
            .add(NavItem("Team").href("#team"))
            .add(NavItem("Settings").href("#settings"))
            .addAction(Button("New Project").classes("ew-button-sm"))
    );

    // Sidebar
    app.sidebar(
        Sidebar()
            .add(SidebarSection("Overview")
                .add(SidebarItem("Dashboard").active())
                .add(SidebarItem("Analytics"))
                .add(SidebarItem("Reports"))
            )
            .add(SidebarSection("Projects")
                .add(SidebarItem("All Projects"))
                .add(SidebarItem("Active"))
                .add(SidebarItem("Completed"))
                .add(SidebarItem("On Hold"))
            )
            .add(SidebarSection("Team")
                .add(SidebarItem("Members"))
                .add(SidebarItem("Roles"))
                .add(SidebarItem("Permissions"))
            )
            .add(SidebarSection("System")
                .add(SidebarItem("Settings"))
                .add(SidebarItem("Integrations"))
                .add(SidebarItem("Security"))
            )
    );

    // Main content - Header
    app.add(
        Row()
            .add(Column().classes("ew-flex-grow")
                .add(Text("Project Dashboard").h1())
                .add(Text("Monitor project progress, team activity, and system metrics").secondary())
            )
            .add(Row().gap("sm")
                .add(Button("Export Report").secondary())
                .add(Button("Create Project"))
            )
    );

    app.add(Spacer());

    // Stats grid with colored borders
    app.add(
        Grid().columns(4)
            .add(Card().compact().border("#4ec968")
                .add(Stat()
                    .label("Total Projects")
                    .value("24")
                    .change("12%", true)
                )
            )
            .add(Card().compact().border("#40a9ff")
                .add(Stat()
                    .label("Active Users")
                    .value("1,247")
                    .change("8%", true)
                )
            )
            .add(Card().compact().border("#f0b400")
                .add(Stat()
                    .label("Pending Reviews")
                    .value("8")
                    .change("3%", false)
                )
            )
            .add(Card().compact().border("#a855f7")
                .add(Stat()
                    .label("Completion Rate")
                    .value("94%")
                    .change("5%", true)
                )
            )
    );

    app.add(Spacer());

    // Main content grid
    app.add(
        Grid().columns(3)
            .add(Card().title("Recent Activity").accent()
                .add(Column().gap("sm")
                    .add(Row()
                        .add(Text("Project ZeroJS v1.0 deployed").classes("ew-flex-grow"))
                        .add(Badge("Success").success())
                    )
                    .add(Row()
                        .add(Text("New user onboarded").classes("ew-flex-grow"))
                        .add(Badge("New"))
                    )
                    .add(Row()
                        .add(Text("Payment processed").classes("ew-flex-grow"))
                        .add(Badge("Success").success())
                    )
                    .add(Row()
                        .add(Text("Server maintenance scheduled").classes("ew-flex-grow"))
                        .add(Badge("Warning").warning())
                    )
                    .add(Row()
                        .add(Text("Build pipeline failed").classes("ew-flex-grow"))
                        .add(Badge("Error").error())
                    )
                )
            )
            .add(Card().title("Quick Actions")
                .add(Column()
                    .add(Button("Create New Project").classes("ew-button-lg"))
                    .add(Button("View Analytics").outline())
                    .add(Button("Manage Team").ghost())
                    .add(Button("System Settings").ghost())
                )
            )
            .add(Card().title("Team Members")
                .add(Column().gap("sm")
                    .add(Row()
                        .add(Text("Sarah Chen").classes("ew-flex-grow"))
                        .add(Text("Lead Developer").muted())
                    )
                    .add(Row()
                        .add(Text("Marcus Rodriguez").classes("ew-flex-grow"))
                        .add(Text("UI/UX Designer").muted())
                    )
                    .add(Row()
                        .add(Text("Elena Petrov").classes("ew-flex-grow"))
                        .add(Text("Backend Engineer").muted())
                    )
                    .add(Row()
                        .add(Text("James Wilson").classes("ew-flex-grow"))
                        .add(Text("DevOps").muted())
                    )
                )
            )
    );

    app.add(Spacer());

    // Form card
    app.add(
        Card().title("Project Request Form")
            .add(Form()
                .post("/api/submit")
                .target("#form-result")
                .add(Grid().columns(2)
                    .add(Input("name").label("Project Name").placeholder("My Awesome Project"))
                    .add(Input("email").type("email").label("Contact Email").placeholder("team@company.com"))
                )
                .add(Input("description").label("Description").placeholder("Brief project description..."))
                .add(Spacer().sm())
                .add(Row()
                    .add(Button("Submit Request"))
                    .add(Button("Cancel").ghost())
                )
            )
            .add(Box().id("form-result"))
    );

    return app;
}

int main() {
    // ========================================
    // DARK MODE - High contrast, angular
    // ========================================
    {
        Page page("ZeroJS Dashboard - Dark Mode");
        page.dark_mode();
        page.add(create_dashboard_content());
        page.render_to_file("examples/dashboard/dashboard-dark.html");
        std::cout << "Generated dashboard-dark.html" << std::endl;
    }

    // ========================================
    // LIGHT MODE - Sharp, modern
    // ========================================
    {
        Page page("ZeroJS Dashboard - Light Mode");
        page.light_mode();
        page.add(create_dashboard_content());
        page.render_to_file("examples/dashboard/dashboard-light.html");
        std::cout << "Generated dashboard-light.html" << std::endl;
    }

    // ========================================
    // CREAM MODE - Technical document style
    // ========================================
    {
        Page page("ZeroJS Dashboard - Cream Mode");
        page.cream_mode();
        page.add(create_dashboard_content());
        page.render_to_file("examples/dashboard/dashboard-cream.html");
        std::cout << "Generated dashboard-cream.html" << std::endl;
    }

    std::cout << "\nOpen any of the HTML files in your browser:" << std::endl;
    std::cout << "  - dashboard-dark.html  (Dark high contrast)" << std::endl;
    std::cout << "  - dashboard-light.html (Light high contrast)" << std::endl;
    std::cout << "  - dashboard-cream.html (Cream technical style)" << std::endl;

    return 0;
}
