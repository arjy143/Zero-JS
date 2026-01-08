#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include "styles.hpp"
#include "htmx.hpp"

namespace zero_js
{
    inline std::string render_page_html(
    const std::string& title,
    const std::string& body_content,
    bool include_htmx = true,
    ThemeMode mode = ThemeMode::Dark
) {
    Theme theme;
    theme.mode = mode;

    std::ostringstream html;

    html << "<!DOCTYPE html>\n";
    html << "<html lang=\"en\">\n";
    html << "<head>\n";
    html << "    <meta charset=\"UTF-8\">\n";
    html << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
    html << "    <title>" << title << "</title>\n";
    html << "    <style>\n";
    html << generate_css(theme);
    html << "    </style>\n";

    if (include_htmx) {
        html << R"(<script src="https://unpkg.com/htmx.org@1.9.10">\n)";
        html << get_htmx_script();
        html << "    </script>\n";
    }

    html << "</head>\n";
    html << "<body>\n";
    html << body_content;
    html << "</body>\n";
    html << "</html>\n";

    return html.str();
}

inline void write_to_file(const std::string& path, const std::string& content) {
    std::ofstream file(path);
    if (file.is_open()) {
        file << content;
        file.close();
    }
}
}