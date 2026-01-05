#pragma once

#include "src/styles.hpp"
#include "src/htmx.hpp"
#include "src/renderer.hpp"
#include "src/components.hpp"
#include "src/charts.hpp"

//include this header in your project

namespace zero_js
{
    inline std::string Page::render() const 
    {

    ThemeMode mode = ThemeMode::Dark;
    if (theme_mode_ == 1)
    {
        mode = ThemeMode::Light;
    }
    else if (theme_mode_ == 2)
    {
         mode = ThemeMode::Cream;
    }

    return render_page_html(title_, render_children(children_), include_htmx_, mode);
    }

    inline void Page::render_to_file(const std::string& path) const 
    {
        write_to_file(path, render());
    }

}