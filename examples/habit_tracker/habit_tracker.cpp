#include "../../zero_js.hpp"
#include <iostream>

using namespace zero_js;

// Helper function to create habit tracker content
App create_habit_tracker_content() {
    App app;

    // Navbar
    app.navbar(
        Navbar()
            .brand("HabitFlow")
            .add(NavItem("Dashboard").href("#").active())
            .add(NavItem("Habits").href("#habits"))
            .add(NavItem("Analytics").href("#analytics"))
            .add(NavItem("Settings").href("#settings"))
            .addAction(Button("Add Habit").classes("ew-button-sm"))
    );

    // Header
    app.add(
        Row()
            .add(Column().classes("ew-flex-grow")
                .add(Text("Habit Dashboard").h1())
                .add(Text("Track your daily habits and build better routines").secondary())
            )
            .add(Row().gap("sm")
                .add(Button("Today's Progress").secondary())
                .add(Button("Weekly Report"))
            )
    );

    app.add(Spacer());

    // Stats Overview
    app.add(
        Grid().columns(4)
            .add(Card().compact().border("#4ec968")
                .add(Stat()
                    .label("Current Streak")
                    .value("12")
                    .change("days", true)
                )
            )
            .add(Card().compact().border("#40a9ff")
                .add(Stat()
                    .label("Habits Completed")
                    .value("8/10")
                    .change("80%", true)
                )
            )
            .add(Card().compact().border("#f0b400")
                .add(Stat()
                    .label("This Week")
                    .value("56/70")
                    .change("5%", false)
                )
            )
            .add(Card().compact().border("#a855f7")
                .add(Stat()
                    .label("Best Streak")
                    .value("28")
                    .change("days", true)
                )
            )
    );

    app.add(Spacer());

    // Today's Habits
    app.add(
        Row()
            .add(Column().classes("ew-flex-grow")
                .add(Text("Today's Habits").h2())
                .add(Spacer().sm())
                .add(Card()
                    .add(Column().gap("sm")
                        .add(Row()
                            .add(Text("Drink 8 glasses of water").classes("ew-flex-grow"))
                            .add(Badge("Completed").success())
                        )
                        .add(Row()
                            .add(Text("Read for 30 minutes").classes("ew-flex-grow"))
                            .add(Badge("Completed").success())
                        )
                        .add(Row()
                            .add(Text("Exercise for 45 minutes").classes("ew-flex-grow"))
                            .add(Badge("Completed").success())
                        )
                        .add(Row()
                            .add(Text("Meditate for 10 minutes").classes("ew-flex-grow"))
                            .add(Badge("Pending"))
                        )
                        .add(Row()
                            .add(Text("Write in journal").classes("ew-flex-grow"))
                            .add(Badge("Pending"))
                        )
                        .add(Row()
                            .add(Text("Learn something new").classes("ew-flex-grow"))
                            .add(Badge("Completed").success())
                        )
                        .add(Row()
                            .add(Text("No phone after 9 PM").classes("ew-flex-grow"))
                            .add(Badge("Failed").error())
                        )
                        .add(Row()
                            .add(Text("Healthy breakfast").classes("ew-flex-grow"))
                            .add(Badge("Completed").success())
                        )
                    )
                )
            )
    );

    app.add(Spacer());

    // Habit Categories
    app.add(
        Grid().columns(3)
            .add(Card().title("Health & Fitness").accent()
                .add(Column().gap("sm")
                    .add(Row()
                        .add(Text("Exercise").classes("ew-flex-grow"))
                        .add(Text("5/7").muted())
                    )
                    .add(Row()
                        .add(Text("Drink Water").classes("ew-flex-grow"))
                        .add(Text("7/7").muted())
                    )
                    .add(Row()
                        .add(Text("Healthy Eating").classes("ew-flex-grow"))
                        .add(Text("6/7").muted())
                    )
                )
            )
            .add(Card().title("Productivity")
                .add(Column().gap("sm")
                    .add(Row()
                        .add(Text("Deep Work").classes("ew-flex-grow"))
                        .add(Text("4/7").muted())
                    )
                    .add(Row()
                        .add(Text("Read").classes("ew-flex-grow"))
                        .add(Text("6/7").muted())
                    )
                    .add(Row()
                        .add(Text("Learn").classes("ew-flex-grow"))
                        .add(Text("5/7").muted())
                    )
                )
            )
            .add(Card().title("Mindfulness")
                .add(Column().gap("sm")
                    .add(Row()
                        .add(Text("Meditation").classes("ew-flex-grow"))
                        .add(Text("4/7").muted())
                    )
                    .add(Row()
                        .add(Text("Journal").classes("ew-flex-grow"))
                        .add(Text("3/7").muted())
                    )
                    .add(Row()
                        .add(Text("Gratitude").classes("ew-flex-grow"))
                        .add(Text("5/7").muted())
                    )
                )
            )
    );

    app.add(Spacer());

    // Weekly Progress Chart (simulated with cards)
    app.add(
        Card().title("Weekly Progress")
            .add(Grid().columns(7)
                .add(Card().compact().classes("ew-center")
                    .add(Text("Mon").muted())
                    .add(Text("8/10").h3())
                )
                .add(Card().compact().classes("ew-center")
                    .add(Text("Tue").muted())
                    .add(Text("9/10").h3())
                )
                .add(Card().compact().classes("ew-center")
                    .add(Text("Wed").muted())
                    .add(Text("7/10").h3())
                )
                .add(Card().compact().classes("ew-center")
                    .add(Text("Thu").muted())
                    .add(Text("8/10").h3())
                )
                .add(Card().compact().classes("ew-center")
                    .add(Text("Fri").muted())
                    .add(Text("9/10").h3())
                )
                .add(Card().compact().classes("ew-center")
                    .add(Text("Sat").muted())
                    .add(Text("6/10").h3())
                )
                .add(Card().compact().classes("ew-center")
                    .add(Text("Sun").muted())
                    .add(Text("8/10").h3())
                )
            )
    );

    app.add(Spacer());

    // Recent Activity
    app.add(
        Grid().columns(2)
            .add(Card().title("Recent Activity")
                .add(Column().gap("sm")
                    .add(Row()
                        .add(Text("Completed 'Exercise' habit").classes("ew-flex-grow"))
                        .add(Badge("2h ago"))
                    )
                    .add(Row()
                        .add(Text("Started 12-day streak").classes("ew-flex-grow"))
                        .add(Badge("1d ago"))
                    )
                    .add(Row()
                        .add(Text("Completed 'Read' habit").classes("ew-flex-grow"))
                        .add(Badge("3h ago"))
                    )
                    .add(Row()
                        .add(Text("Missed 'Meditation' habit").classes("ew-flex-grow"))
                        .add(Badge("5h ago"))
                    )
                    .add(Row()
                        .add(Text("New habit added: 'Learn Spanish'").classes("ew-flex-grow"))
                        .add(Badge("1d ago"))
                    )
                )
            )
            .add(Card().title("Quick Actions")
                .add(Column()
                    .add(Button("Mark All Complete").classes("ew-button-lg"))
                    .add(Button("Add New Habit").outline())
                    .add(Button("View Calendar").ghost())
                    .add(Button("Export Data").ghost())
                )
            )
    );

    app.add(Spacer());

    // Add New Habit Form
    app.add(
        Card().title("Add New Habit")
            .add(Form()
                .post("/api/add-habit")
                .target("#habit-result")
                .add(Grid().columns(2)
                    .add(Input("name").label("Habit Name").placeholder("e.g., Drink water"))
                    .add(Input("category").label("Category").placeholder("e.g., Health"))
                )
                .add(Input("description").label("Description").placeholder("Optional description..."))
                .add(Row().gap("sm")
                    .add(Input("frequency").label("Frequency").placeholder("Daily").classes("ew-flex-grow"))
                    .add(Input("target").label("Target").placeholder("8").classes("ew-flex-grow"))
                )
                .add(Spacer().sm())
                .add(Row()
                    .add(Button("Create Habit"))
                    .add(Button("Cancel").ghost())
                )
            )
            .add(Box().id("habit-result"))
    );

    return app;
}

int main() {
    // ========================================
    // DARK MODE - Focused tracking
    // ========================================
    {
        Page page("HabitFlow - Dark Mode");
        page.dark_mode();
        page.add(create_habit_tracker_content());
        page.render_to_file("examples/habit_tracker/habit_tracker-dark.html");
        std::cout << "Generated habit_tracker-dark.html" << std::endl;
    }

    // ========================================
    // LIGHT MODE - Clean and motivating
    // ========================================
    {
        Page page("HabitFlow - Light Mode");
        page.light_mode();
        page.add(create_habit_tracker_content());
        page.render_to_file("examples/habit_tracker/habit_tracker-light.html");
        std::cout << "Generated habit_tracker-light.html" << std::endl;
    }

    // ========================================
    // CREAM MODE - Journal-like tracking
    // ========================================
    {
        Page page("HabitFlow - Cream Mode");
        page.cream_mode();
        page.add(create_habit_tracker_content());
        page.render_to_file("examples/habit_tracker/habit_tracker-cream.html");
        std::cout << "Generated habit_tracker-cream.html" << std::endl;
    }

    std::cout << "\nOpen any of the HTML files in your browser:" << std::endl;
    std::cout << "  - habit_tracker-dark.html  (Dark focused)" << std::endl;
    std::cout << "  - habit_tracker-light.html (Light clean)" << std::endl;
    std::cout << "  - habit_tracker-cream.html (Cream journal)" << std::endl;

    return 0;
}