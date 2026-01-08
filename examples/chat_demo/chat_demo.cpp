#include "../../zero_js.hpp"
#include <iostream>

using namespace zero_js;

int main() {
    // Create a chat demo page with SSE support
    Page page;
    page.title("Chat Demo - ZeroJS")
        .dark_mode()
        .with_sse();

    // Main app container
    App app;

    // Navbar
    Navbar navbar;
    navbar.brand("ZeroJS Chat");
    navbar.add(Link("Home", "/"));
    navbar.add(Link("Docs", "/docs"));
    navbar.add(Link("GitHub", "https://github.com"));
    app.navbar(navbar);

    // Sidebar content - session management
    SidebarSection sessions_section;
    sessions_section.title("Sessions");
    sessions_section.add(SidebarItem("Session 1").href("#").active());
    sessions_section.add(SidebarItem("Session 2").href("#"));
    sessions_section.add(SidebarItem("Session 3").href("#"));

    SidebarSection settings_section;
    settings_section.title("Settings");
    settings_section.add(SidebarItem("System Prompt").href("#"));
    settings_section.add(SidebarItem("Max Tokens").href("#"));
    settings_section.add(SidebarItem("Temperature").href("#"));

    Sidebar sidebar;
    sidebar.add(sessions_section);
    sidebar.add(settings_section);
    app.sidebar(sidebar);

    // Main chat area
    Card chat_card;
    chat_card.title("Chat with AI");

    // Info text about the demo
    chat_card.add(Text("This is a demonstration of SSE streaming with HTMX. "
                       "Connect to a local-ai server to see real-time token streaming.")
        .secondary()
        .classes("ew-mb-lg"));

    // The chat container with SSE streaming
    // This connects to /chat/stream and listens for 'message' events
    ChatContainer chat;
    chat.session("demo-session")
        .chat_endpoint("/chat")
        .stream_endpoint("/chat/stream")
        .placeholder("Ask me anything...");

    // Add some example messages to show the UI
    chat.add_message(ChatMessage("Hello! How can I help you today?").assistant());

    chat_card.add(chat);
    app.add(chat_card);

    // Additional info card
    Card info_card;
    info_card.title("How it works");
    info_card.compact();

    Column info_list;
    info_list.gap("sm");
    info_list.add(Text("1. User sends a message via POST to /chat"));
    info_list.add(Text("2. Server establishes SSE connection to /chat/stream"));
    info_list.add(Text("3. Tokens stream in real-time via 'message' events"));
    info_list.add(Text("4. Connection closes on 'done' event"));
    info_card.add(info_list);
    app.add(info_card);

    // Server response format card
    Card format_card;
    format_card.title("Expected SSE Response Format");
    format_card.compact();

    // Show example SSE format as text
    Card code_example;
    code_example.classes("ew-code-block");
    code_example.add(Text("event: message").classes("ew-code-line"));
    code_example.add(Text("data: <span class=\"ew-token\">Hello</span>").classes("ew-code-line"));
    code_example.add(Text("").classes("ew-code-line"));
    code_example.add(Text("event: message").classes("ew-code-line"));
    code_example.add(Text("data: <span class=\"ew-token\"> world</span>").classes("ew-code-line"));
    code_example.add(Text("").classes("ew-code-line"));
    code_example.add(Text("event: done").classes("ew-code-line"));
    code_example.add(Text("data: <span></span>").classes("ew-code-line"));
    format_card.add(code_example);

    format_card.add(Text("Each 'message' event should contain valid HTML that will be appended to the chat.")
        .secondary());

    app.add(format_card);

    // HTML usage example
    Card html_card;
    html_card.title("HTML Usage");
    html_card.compact();

    Card html_example;
    html_example.classes("ew-code-block");
    html_example.add(Text("<div hx-ext=\"sse\"").classes("ew-code-line"));
    html_example.add(Text("     sse-connect=\"/chat/stream?session_id=demo\"").classes("ew-code-line"));
    html_example.add(Text("     sse-close=\"done\">").classes("ew-code-line"));
    html_example.add(Text("    <div sse-swap=\"message\" hx-swap=\"beforeend\">").classes("ew-code-line"));
    html_example.add(Text("        <!-- Tokens appear here -->").classes("ew-code-line"));
    html_example.add(Text("    </div>").classes("ew-code-line"));
    html_example.add(Text("</div>").classes("ew-code-line"));
    html_card.add(html_example);

    app.add(html_card);

    page.add(app);

    // Generate the page
    page.render_to_file("chat-demo.html");
    std::cout << "Generated: chat-demo.html" << std::endl;

    // Also generate a light mode version
    Page light_page;
    light_page.title("Chat Demo - ZeroJS (Light)")
              .light_mode()
              .with_sse();

    // Need to rebuild app for light mode
    App light_app;
    light_app.navbar(navbar);
    light_app.sidebar(sidebar);
    light_app.add(chat_card);
    light_app.add(info_card);
    light_app.add(format_card);
    light_app.add(html_card);

    light_page.add(light_app);
    light_page.render_to_file("chat-demo-light.html");
    std::cout << "Generated: chat-demo-light.html" << std::endl;

    return 0;
}
