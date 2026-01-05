#include "../../zero_js.hpp"
#include <iostream>

using namespace zero_js;

// Helper function to create system monitoring content
App create_system_monitor_content() {
    App app;

    // Advanced header with system status
    app.add(
        Row().classes("ew-center-content")
            .add(Column().classes("ew-center")
                .add(Spacer().lg())
                .add(Text("🖥️ SysMonitor Pro").h1())
                .add(Text("Advanced Infrastructure Monitoring & Management Platform").secondary())
                .add(Spacer())
                .add(Row().gap("sm")
                    .add(Badge("24 Systems Online").success())
                    .add(Badge("3 Alerts Active").warning())
                    .add(Badge("99.97% Uptime").success())
                )
                .add(Spacer().xl())
            )
    );

    // Quick Status Bar
    app.add(
        Card().classes("ew-card-accent")
            .add(Row()
                .add(Text("System Status:").secondary())
                .add(Spacer())
                .add(Badge("All Systems Operational").success())
                .add(Spacer())
                .add(Text("Last Updated: 14:32:15 UTC").muted())
                .add(Spacer())
                .add(Button("🔄 Refresh").outline().classes("ew-button-sm"))
            )
    );

    app.add(Spacer());

    // Main Control Panel
    app.add(
        Grid().columns(3)
            .add(Card().title("🚀 Quick Actions")
                .add(Column().gap("sm")
                    .add(Button("Deploy Update").classes("ew-button-lg"))
                    .add(Button("Run Health Check").outline())
                    .add(Button("Backup Systems").ghost())
                    .add(Button("Scale Resources").ghost())
                )
            )
            .add(Card().title("📊 Key Metrics")
                .add(Grid().columns(2)
                    .add(Stat().label("CPU Load").value("42%").change("-5%", true))
                    .add(Stat().label("Memory").value("6.8GB").change("+200MB", false))
                    .add(Stat().label("Network").value("1.2Gbps").change("+0.1Gbps", true))
                    .add(Stat().label("Storage").value("78%").change("-2%", true))
                )
            )
            .add(Card().title("⚙️ Active Configuration")
                .add(Column().gap("sm")
                    .add(Row().add(Text("Auto-scaling:").classes("ew-flex-grow")).add(Badge("Enabled").success()))
                    .add(Row().add(Text("Load Balancing:").classes("ew-flex-grow")).add(Badge("Active").success()))
                    .add(Row().add(Text("Monitoring:").classes("ew-flex-grow")).add(Badge("Prometheus").success()))
                    .add(Row().add(Text("Logging:").classes("ew-flex-grow")).add(Badge("ELK Stack").success()))
                )
            )
    );

    app.add(Spacer());

    // Server Topology Visualization (simplified)
    app.add(
        Card().title("🌐 Infrastructure Topology")
            .add(Text("Load Balancer → Web Servers → Database Cluster → Cache Layer").secondary())
            .add(Spacer().sm())
            .add(Grid().columns(5)
                .add(Card().compact().classes("ew-center")
                    .add(Text("🌐").h3())
                    .add(Text("LB-01").muted())
                    .add(Badge("100%").success())
                )
                .add(Text("→").classes("ew-center"))
                .add(Card().compact().classes("ew-center")
                    .add(Text("🖥️").h3())
                    .add(Text("Web-01").muted())
                    .add(Badge("95%").success())
                )
                .add(Text("→").classes("ew-center"))
                .add(Card().compact().classes("ew-center")
                    .add(Text("🗄️").h3())
                    .add(Text("DB-01").muted())
                    .add(Badge("87%").warning())
                )
                .add(Text("→").classes("ew-center"))
                .add(Card().compact().classes("ew-center")
                    .add(Text("💾").h3())
                    .add(Text("Cache").muted())
                    .add(Badge("92%").success())
                )
            )
    );

    app.add(Spacer());

    // Advanced Monitoring Panels
    app.add(
        Grid().columns(2)
            .add(Card().title("📈 Performance Graphs (Last Hour)")
                .add(Column().gap("sm")
                    .add(Text("CPU Usage: ▁▂▃▄▅▆▇█▇▆▅▄▃▂▁").classes("ew-code"))
                    .add(Text("Memory: ▁▂▃▄▅▆▇███████▇▆").classes("ew-code"))
                    .add(Text("Network: ▂▃▄▅▆▇█▇▆▅▄▃▂▁▂▃").classes("ew-code"))
                    .add(Spacer().sm())
                    .add(Row().gap("sm")
                        .add(Button("View Details").outline().classes("ew-button-sm"))
                        .add(Button("Export Data").ghost().classes("ew-button-sm"))
                    )
                )
            )
            .add(Card().title("🔍 System Search & Filter")
                .add(Form()
                    .post("/api/search")
                    .target("#search-results")
                    .add(Row().gap("sm")
                        .add(Input("query").placeholder("Search servers, services, logs...").classes("ew-flex-grow"))
                        .add(Button("🔍 Search").outline())
                    )
                    .add(Spacer().sm())
                    .add(Row().gap("sm")
                        .add(Input("filter-status").label("Status").placeholder("All").classes("ew-flex-grow"))
                        .add(Input("filter-type").label("Type").placeholder("All").classes("ew-flex-grow"))
                        .add(Input("time-range").label("Time Range").placeholder("Last Hour").classes("ew-flex-grow"))
                    )
                )
                .add(Box().id("search-results"))
            )
    );

    app.add(Spacer());

    // Real-time Log Stream
    app.add(
        Card().title("📋 Live System Logs")
            .add(Column().gap("sm")
                .add(Text("[14:32:15] INFO: User authentication successful - user_id: 12345").classes("ew-code"))
                .add(Text("[14:32:12] WARN: High memory usage detected on web-02 (87%)").classes("ew-code"))
                .add(Text("[14:32:10] INFO: Database backup completed successfully").classes("ew-code"))
                .add(Text("[14:32:08] ERROR: Connection timeout to payment-service").classes("ew-code"))
                .add(Text("[14:32:05] INFO: Auto-scaling triggered - adding 2 web instances").classes("ew-code"))
                .add(Text("[14:32:03] INFO: SSL certificate renewed for api.domain.com").classes("ew-code"))
                .add(Text("[14:32:01] WARN: Disk space low on db-01 (15% remaining)").classes("ew-code"))
                .add(Text("[14:31:58] INFO: Security scan completed - 0 vulnerabilities found").classes("ew-code"))
            )
            .add(Spacer().sm())
            .add(Row().gap("sm")
                .add(Button("Pause Stream").outline().classes("ew-button-sm"))
                .add(Button("Clear Logs").ghost().classes("ew-button-sm"))
                .add(Button("Export Logs").ghost().classes("ew-button-sm"))
            )
    );

    app.add(Spacer());

    // Alert Management Console
    app.add(
        Card().title("🚨 Alert Management Console")
            .add(Grid().columns(3)
                .add(Card().border("#f85149")
                    .add(Badge("CRITICAL").error())
                    .add(Text("Database Connection Failed").h3())
                    .add(Text("DB-01 is unresponsive. Automatic failover initiated.").secondary())
                    .add(Spacer().sm())
                    .add(Row().gap("sm")
                        .add(Button("Acknowledge").outline().classes("ew-button-sm"))
                        .add(Button("Resolve").classes("ew-button-sm"))
                    )
                )
                .add(Card().border("#f0b400")
                    .add(Badge("WARNING").warning())
                    .add(Text("High CPU Usage").h3())
                    .add(Text("Web-02 CPU at 89% for 15 minutes.").secondary())
                    .add(Spacer().sm())
                    .add(Row().gap("sm")
                        .add(Button("Investigate").outline().classes("ew-button-sm"))
                        .add(Button("Silence").ghost().classes("ew-button-sm"))
                    )
                )
                .add(Card().border("#40a9ff")
                    .add(Badge("INFO"))
                    .add(Text("Backup Completed").h3())
                    .add(Text("Daily backup finished successfully.").secondary())
                    .add(Spacer().sm())
                    .add(Row().gap("sm")
                        .add(Button("View Report").outline().classes("ew-button-sm"))
                        .add(Button("Dismiss").ghost().classes("ew-button-sm"))
                    )
                )
            )
    );

    app.add(Spacer());

    // Service Configuration Panel
    app.add(
        Card().title("⚙️ Service Configuration")
            .add(Grid().columns(2)
                .add(Card().title("Database Settings")
                    .add(Form()
                        .post("/api/config/db")
                        .add(Input("db-host").label("Database Host").placeholder("db-01.internal"))
                        .add(Input("db-port").label("Port").placeholder("5432"))
                        .add(Input("db-pool-size").label("Connection Pool").placeholder("20"))
                        .add(Spacer().sm())
                        .add(Button("Update Configuration").outline())
                    )
                )
                .add(Card().title("Monitoring Settings")
                    .add(Form()
                        .post("/api/config/monitoring")
                        .add(Input("alert-threshold").label("CPU Alert Threshold").placeholder("85%"))
                        .add(Input("retention-days").label("Log Retention").placeholder("30"))
                        .add(Input("notification-email").label("Alert Email").placeholder("admin@company.com"))
                        .add(Spacer().sm())
                        .add(Button("Save Settings").outline())
                    )
                )
            )
    );

    app.add(Spacer());

    // System Health Summary
    app.add(
        Card().title("🏥 System Health Overview")
            .add(Grid().columns(4)
                .add(Column().classes("ew-center")
                    .add(Text("Web Services").h3())
                    .add(Text("5/5").secondary())
                    .add(Badge("Healthy").success())
                )
                .add(Column().classes("ew-center")
                    .add(Text("Databases").h3())
                    .add(Text("3/4").secondary())
                    .add(Badge("Degraded").warning())
                )
                .add(Column().classes("ew-center")
                    .add(Text("APIs").h3())
                    .add(Text("8/8").secondary())
                    .add(Badge("Healthy").success())
                )
                .add(Column().classes("ew-center")
                    .add(Text("Storage").h3())
                    .add(Text("6/6").secondary())
                    .add(Badge("Healthy").success())
                )
            )
    );

    return app;
}

int main() {
    // ========================================
    // DARK MODE - Technical monitoring
    // ========================================
    {
        Page page("SysMonitor Pro - Dark Mode");
        page.dark_mode();
        page.add(create_system_monitor_content());
        page.render_to_file("system_monitor-dark.html");
        std::cout << "Generated system_monitor-dark.html" << std::endl;
    }

    // ========================================
    // LIGHT MODE - Clean data visualization
    // ========================================
    {
        Page page("SysMonitor Pro - Light Mode");
        page.light_mode();
        page.add(create_system_monitor_content());
        page.render_to_file("system_monitor-light.html");
        std::cout << "Generated system_monitor-light.html" << std::endl;
    }

    // ========================================
    // CREAM MODE - Technical documentation style
    // ========================================
    {
        Page page("SysMonitor Pro - Cream Mode");
        page.cream_mode();
        page.add(create_system_monitor_content());
        page.render_to_file("system_monitor-cream.html");
        std::cout << "Generated system_monitor-cream.html" << std::endl;
    }

    std::cout << "\nOpen any of the HTML files in your browser:" << std::endl;
    std::cout << "  - system_monitor-dark.html  (Dark technical)" << std::endl;
    std::cout << "  - system_monitor-light.html (Light clean)" << std::endl;
    std::cout << "  - system_monitor-cream.html (Cream docs)" << std::endl;

    return 0;
}