#include "../../zero_js.hpp"
#include <iostream>

using namespace zero_js;

// Helper function to create portfolio content
App create_portfolio_content() {
    App app;

    // Navbar
    app.navbar(
        Navbar()
            .brand("Arjun Parmar")
            .add(NavItem("Home").href("#").active())
            .add(NavItem("About").href("#about"))
            .add(NavItem("Projects").href("#projects"))
            .add(NavItem("Experience").href("#experience"))
            .add(NavItem("Contact").href("#contact"))
            .addAction(Button("Download CV").outline().classes("ew-button-sm"))
    );

    // Hero Section
    app.add(
        Row().classes("ew-center-content")
            .add(Column().classes("ew-center")
                .add(Spacer())
                .add(Text("Arjun Parmar").h1())
                .add(Text("Full-Stack Developer & UI/UX Designer").secondary())
                .add(Text("Passionate about creating beautiful, functional web applications with modern technologies.").muted())
                .add(Spacer())
                .add(Row().gap("sm").classes("ew-center-content")
                    .add(Button("View My Work").classes("ew-button-lg"))
                    .add(Button("Get In Touch").outline().classes("ew-button-lg"))
                )
                .add(Spacer().xl())
            )
    );

    // About Section
    app.add(
        Row().id("about")
            .add(Column().classes("ew-flex-grow")
                .add(Text("About Me").h2())
                .add(Spacer().sm())
                .add(Text("I'm a passionate full-stack developer with 5+ years of experience building web applications. I specialize in React, Node.js, and modern web technologies, with a keen eye for design and user experience."))
                .add(Spacer())
                .add(Grid().columns(2)
                    .add(Card().compact()
                        .add(Text("5+").h3())
                        .add(Text("Years Experience").muted())
                    )
                    .add(Card().compact()
                        .add(Text("50+").h3())
                        .add(Text("Projects Completed").muted())
                    )
                    .add(Card().compact()
                        .add(Text("30+").h3())
                        .add(Text("Happy Clients").muted())
                    )
                    .add(Card().compact()
                        .add(Text("15+").h3())
                        .add(Text("Technologies").muted())
                    )
                )
            )
    );

    app.add(Spacer().xl());

    // Skills Section
    app.add(
        Row()
            .add(Column().classes("ew-flex-grow")
                .add(Text("Skills & Technologies").h2())
                .add(Spacer().sm())
                .add(Grid().columns(3)
                    .add(Card().title("Frontend")
                        .add(Column().gap("sm")
                            .add(Row().add(Badge("React").success()).add(Badge("TypeScript").success()))
                            .add(Row().add(Badge("Next.js").success()).add(Badge("Tailwind CSS").success()))
                            .add(Row().add(Badge("Vue.js").success()).add(Badge("Svelte").success()))
                        )
                    )
                    .add(Card().title("Backend")
                        .add(Column().gap("sm")
                            .add(Row().add(Badge("Node.js").success()).add(Badge("Python").success()))
                            .add(Row().add(Badge("PostgreSQL").success()).add(Badge("MongoDB").success()))
                            .add(Row().add(Badge("GraphQL").success()).add(Badge("REST APIs").success()))
                        )
                    )
                    .add(Card().title("Tools & Others")
                        .add(Column().gap("sm")
                            .add(Row().add(Badge("Docker").success()).add(Badge("AWS").success()))
                            .add(Row().add(Badge("Git").success()).add(Badge("Figma").success()))
                            .add(Row().add(Badge("Jest").success()).add(Badge("Cypress").success()))
                        )
                    )
                )
            )
    );

    app.add(Spacer().xl());

    // Projects Section
    app.add(
        Row().id("projects")
            .add(Column().classes("ew-flex-grow")
                .add(Text("Featured Projects").h2())
                .add(Spacer().sm())
                .add(Grid().columns(2)
                    .add(Card().title("E-Commerce Platform").accent()
                        .add(Text("A full-stack e-commerce solution built with React and Node.js, featuring payment integration, inventory management, and admin dashboard."))
                        .add(Spacer().sm())
                        .add(Row().gap("sm")
                            .add(Badge("React").success())
                            .add(Badge("Node.js").success())
                            .add(Badge("Stripe").success())
                        )
                        .add(Spacer().sm())
                        .add(Row().gap("sm")
                            .add(Button("Live Demo").outline().classes("ew-button-sm"))
                            .add(Button("Source Code").ghost().classes("ew-button-sm"))
                        )
                    )
                    .add(Card().title("Task Management App")
                        .add(Text("A collaborative task management application with real-time updates, team management, and project tracking capabilities."))
                        .add(Spacer().sm())
                        .add(Row().gap("sm")
                            .add(Badge("Vue.js").success())
                            .add(Badge("Firebase").success())
                            .add(Badge("Socket.io").success())
                        )
                        .add(Spacer().sm())
                        .add(Row().gap("sm")
                            .add(Button("Live Demo").outline().classes("ew-button-sm"))
                            .add(Button("Source Code").ghost().classes("ew-button-sm"))
                        )
                    )
                    .add(Card().title("Weather Dashboard")
                        .add(Text("A responsive weather application with location-based forecasts, interactive maps, and weather alerts."))
                        .add(Spacer().sm())
                        .add(Row().gap("sm")
                            .add(Badge("JavaScript").success())
                            .add(Badge("OpenWeather API").success())
                            .add(Badge("Chart.js").success())
                        )
                        .add(Spacer().sm())
                        .add(Row().gap("sm")
                            .add(Button("Live Demo").outline().classes("ew-button-sm"))
                            .add(Button("Source Code").ghost().classes("ew-button-sm"))
                        )
                    )
                    .add(Card().title("Portfolio Website")
                        .add(Text("A modern, responsive portfolio website built with cutting-edge web technologies and beautiful animations."))
                        .add(Spacer().sm())
                        .add(Row().gap("sm")
                            .add(Badge("Next.js").success())
                            .add(Badge("Framer Motion").success())
                            .add(Badge("Three.js").success())
                        )
                        .add(Spacer().sm())
                        .add(Row().gap("sm")
                            .add(Button("Live Demo").outline().classes("ew-button-sm"))
                            .add(Button("Source Code").ghost().classes("ew-button-sm"))
                        )
                    )
                )
            )
    );

    app.add(Spacer().xl());

    // Experience Section
    app.add(
        Row().id("experience")
            .add(Column().classes("ew-flex-grow")
                .add(Text("Work Experience").h2())
                .add(Spacer().sm())
                .add(Card().title("Senior Full-Stack Developer").accent()
                    .add(Text("TechCorp Inc.").secondary())
                    .add(Text("2022 - Present").muted())
                    .add(Spacer().sm())
                    .add(Column().gap("sm")
                        .add(Text("• Led development of microservices architecture serving 100K+ users"))
                        .add(Text("• Implemented CI/CD pipelines reducing deployment time by 60%"))
                        .add(Text("• Mentored junior developers and conducted code reviews"))
                        .add(Text("• Collaborated with design team to improve UX metrics by 40%"))
                    )
                )
                .add(Spacer())
                .add(Card().title("Full-Stack Developer")
                    .add(Text("StartupXYZ").secondary())
                    .add(Text("2020 - 2022").muted())
                    .add(Spacer().sm())
                    .add(Column().gap("sm")
                        .add(Text("• Built and maintained multiple client-facing web applications"))
                        .add(Text("• Integrated third-party APIs and payment systems"))
                        .add(Text("• Optimized database queries improving performance by 50%"))
                        .add(Text("• Participated in agile development processes"))
                    )
                )
                .add(Spacer())
                .add(Card().title("Junior Developer")
                    .add(Text("WebSolutions Ltd.").secondary())
                    .add(Text("2019 - 2020").muted())
                    .add(Spacer().sm())
                    .add(Column().gap("sm")
                        .add(Text("• Developed responsive web interfaces using modern frameworks"))
                        .add(Text("• Assisted in backend API development and database design"))
                        .add(Text("• Contributed to open-source projects and technical blogs"))
                        .add(Text("• Learned and implemented best practices in software development"))
                    )
                )
            )
    );

    app.add(Spacer().xl());

    // Testimonials Section
    app.add(
        Row()
            .add(Column().classes("ew-flex-grow")
                .add(Text("What Clients Say").h2())
                .add(Spacer().sm())
                .add(Grid().columns(2)
                    .add(Card()
                        .add(Text("\"Alex delivered exceptional work on our e-commerce platform. His attention to detail and technical expertise helped us achieve our goals ahead of schedule.\"").classes("ew-text-secondary"))
                        .add(Spacer().sm())
                        .add(Row()
                            .add(Text("Sarah Johnson").classes("ew-flex-grow"))
                            .add(Text("CEO, RetailCorp").muted())
                        )
                    )
                    .add(Card()
                        .add(Text("\"Working with Alex was a pleasure. He understood our requirements perfectly and delivered a solution that exceeded our expectations.\"").classes("ew-text-secondary"))
                        .add(Spacer().sm())
                        .add(Row()
                            .add(Text("Michael Chen").classes("ew-flex-grow"))
                            .add(Text("CTO, InnovateTech").muted())
                        )
                    )
                )
            )
    );

    app.add(Spacer().xl());

    // Contact Section
    app.add(
        Row().id("contact")
            .add(Column().classes("ew-flex-grow")
                .add(Text("Get In Touch").h2())
                .add(Spacer().sm())
                .add(Grid().columns(2)
                    .add(Card().title("Send a Message")
                        .add(Form()
                            .post("/api/contact")
                            .target("#contact-result")
                            .add(Input("name").label("Your Name").placeholder("John Doe"))
                            .add(Input("email").type("email").label("Email").placeholder("john@example.com"))
                            .add(Input("subject").label("Subject").placeholder("Project Inquiry"))
                            .add(Input("message").type("textarea").label("Message").placeholder("Tell me about your project..."))
                            .add(Spacer().sm())
                            .add(Button("Send Message"))
                        )
                        .add(Box().id("contact-result"))
                    )
                    .add(Column()
                        .add(Card().title("Contact Information")
                            .add(Column().gap("md")
                                .add(Row().gap("sm")
                                    .add(Text("📧").classes("ew-text-accent"))
                                    .add(Text("alex.morgan@email.com"))
                                )
                                .add(Row().gap("sm")
                                    .add(Text("📱").classes("ew-text-accent"))
                                    .add(Text("+1 (555) 123-4567"))
                                )
                                .add(Row().gap("sm")
                                    .add(Text("📍").classes("ew-text-accent"))
                                    .add(Text("San Francisco, CA"))
                                )
                                .add(Row().gap("sm")
                                    .add(Text("🔗").classes("ew-text-accent"))
                                    .add(Text("linkedin.com/in/alexmorgan"))
                                )
                            )
                        )
                        .add(Spacer())
                        .add(Card().title("Let's Connect")
                            .add(Text("I'm always interested in new opportunities and exciting projects. Feel free to reach out if you'd like to work together!"))
                        )
                    )
                )
            )
    );

    app.add(Spacer().xl());

    // Footer
    app.add(
        Row().classes("ew-center")
            .add(Column()
                .add(Text("© 2024 Arjun Parmar. Built with ZeroJS.").muted())
                .add(Spacer().sm())
                .add(Row().gap("lg")
                    .add(Text("Privacy Policy"))
                    .add(Text("Terms of Service"))
                    .add(Text("Sitemap"))
                )
            )
    );

    return app;
}

int main() {
    // ========================================
    // DARK MODE - Professional portfolio
    // ========================================
    {
        Page page("Arjun Parmar - Portfolio (Dark)");
        page.dark_mode();
        page.add(create_portfolio_content());
        page.render_to_file("examples/personal_portfolio/portfolio-dark.html");
        std::cout << "Generated portfolio-dark.html" << std::endl;
    }

    // ========================================
    // LIGHT MODE - Clean and bright
    // ========================================
    {
        Page page("Arjun Parmar - Portfolio (Light)");
        page.light_mode();
        page.add(create_portfolio_content());
        page.render_to_file("examples/personal_portfolio/portfolio-light.html");
        std::cout << "Generated portfolio-light.html" << std::endl;
    }

    // ========================================
    // CREAM MODE - Technical document style
    // ========================================
    {
        Page page("Arjun Parmar - Portfolio (Cream)");
        page.cream_mode();
        page.add(create_portfolio_content());
        page.render_to_file("examples/personal_portfolio/portfolio-cream.html");
        std::cout << "Generated portfolio-cream.html" << std::endl;
    }

    std::cout << "\nOpen any of the HTML files in your browser:" << std::endl;
    std::cout << "  - portfolio-dark.html  (Dark professional)" << std::endl;
    std::cout << "  - portfolio-light.html (Light clean)" << std::endl;
    std::cout << "  - portfolio-cream.html (Cream technical)" << std::endl;

    return 0;
}