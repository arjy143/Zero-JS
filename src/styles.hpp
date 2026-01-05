#pragma once

#include <string>

namespace zero_js 
{
 
struct ColorScheme 
{
    const char* bg_page;
    const char* bg_card;
    const char* bg_card_hover;
    const char* bg_input;
    const char* bg_navbar;
    const char* bg_sidebar;
    const char* bg_button;
    const char* bg_button_hover;
    const char* bg_button_secondary;
    const char* bg_button_secondary_hover;
    const char* bg_accent;
    const char* text_primary;
    const char* text_secondary;
    const char* text_muted;
    const char* text_button;
    const char* text_accent;
    const char* text_link;
    const char* border;
    const char* border_subtle;
    const char* border_focus;
    const char* border_accent;
    const char* shadow;
    const char* shadow_lg;
    const char* success;
    const char* warning;
    const char* error;
    const char* info;
};

enum class ThemeMode 
{
    Dark,
    Light,
    Cream
};

struct Theme 
{
    ThemeMode mode = ThemeMode::Dark;

    static const ColorScheme dark_colors;
    static const ColorScheme light_colors;
    static const ColorScheme cream_colors;

    const ColorScheme& get_colors() const 
    {
        switch(mode) 
        {
            case ThemeMode::Dark: return dark_colors;
            case ThemeMode::Light: return light_colors;
            case ThemeMode::Cream: return cream_colors;
        }
        return dark_colors;
    }

    //boxy border
    static constexpr const char* radius_none = "0";
    static constexpr const char* radius_sm = "2px";
    static constexpr const char* radius_md = "3px";
    static constexpr const char* radius_lg = "4px";

    //tighter spacing
    static constexpr const char* spacing_xs = "4px";
    static constexpr const char* spacing_sm = "6px";
    static constexpr const char* spacing_md = "12px";
    static constexpr const char* spacing_lg = "16px";
    static constexpr const char* spacing_xl = "24px";
    static constexpr const char* spacing_2xl = "32px";

    //font sizes
    static constexpr const char* font_size_xs = "11px";
    static constexpr const char* font_size_sm = "13px";
    static constexpr const char* font_size_base = "14px";
    static constexpr const char* font_size_lg = "16px";
    static constexpr const char* font_size_xl = "20px";
    static constexpr const char* font_size_2xl = "28px";
    static constexpr const char* font_size_3xl = "36px";
};

const ColorScheme Theme::dark_colors = 
{
    "#000000", // bg_page
    "#0c0c0c", // bg_card
    "#161616", // bg_card_hover
    "#0c0c0c", // bg_input
    "#000000", // bg_navbar
    "#0c0c0c", // bg_sidebar
    "#0078d4", // bg_button
    "#1e8ae6", // bg_button_hover
    "#252525", // bg_button_secondary
    "#333333", // bg_button_secondary_hover
    "#0078d4", // bg_accent
    "#ffffff", // text_primary
    "#b0b0b0", // text_secondary
    "#707070", // text_muted
    "#ffffff", // text_button
    "#40a9ff", // text_accent
    "#40a9ff", // text_link
    "#40a9ff", // border
    "#303030", // border_subtle
    "#0078d4", // border_focus
    "#40a9ff", // border_accent
    "none",    // shadow
    "0 0 0 1px #40a9ff", // shadow_lg
    "#4ec968", // success
    "#f0b400", // warning
    "#f85149", // error
    "#40a9ff"  // info
};

const ColorScheme Theme::light_colors = 
{
    "#ffffff", // bg_page
    "#ffffff", // bg_card
    "#f5f5f5", // bg_card_hover
    "#ffffff", // bg_input
    "#ffffff", // bg_navbar
    "#fafafa", // bg_sidebar
    "#0052cc", // bg_button
    "#0065ff", // bg_button_hover
    "#f0f0f0", // bg_button_secondary
    "#e0e0e0", // bg_button_secondary_hover
    "#0052cc", // bg_accent
    "#000000", // text_primary
    "#404040", // text_secondary
    "#606060", // text_muted
    "#ffffff", // text_button
    "#0052cc", // text_accent
    "#0052cc", // text_link
    "#000000", // border
    "#d0d0d0", // border_subtle
    "#0052cc", // border_focus
    "#0052cc", // border_accent
    "none",    // shadow
    "0 0 0 2px #000000", // shadow_lg
    "#1a7f37", // success
    "#9a6700", // warning
    "#cf222e", // error
    "#0052cc"  // info
};

const ColorScheme Theme::cream_colors = 
{
    "#fdf6e3", // bg_page
    "#fefcf6", // bg_card
    "#f5edd6", // bg_card_hover
    "#fefcf6", // bg_input
    "#fdf6e3", // bg_navbar
    "#f5edd6", // bg_sidebar
    "#2b4c3f", // bg_button
    "#3d6654", // bg_button_hover
    "#e8dfc9", // bg_button_secondary
    "#d9ccb0", // bg_button_secondary_hover
    "#2b4c3f", // bg_accent
    "#2c2416", // text_primary
    "#5c5040", // text_secondary
    "#8b8070", // text_muted
    "#fdf6e3", // text_button
    "#8b2500", // text_accent
    "#8b2500", // text_link
    "#2c2416", // border
    "#d4c9a8", // border_subtle
    "#2b4c3f", // border_focus
    "#8b2500", // border_accent
    "none",    // shadow
    "none",    // shadow_lg
    "#2b4c3f", // success
    "#b58900", // warning
    "#cb4b16", // error
    "#268bd2"  // info
};

//add more colour schemes if needed here, and update the switch case

inline std::string generate_css(const Theme& theme = Theme{}) 
{
    const auto& colors = theme.get_colors();

    // Select colors based on mode
    const char* bg_page = colors.bg_page;
    const char* bg_card = colors.bg_card;
    const char* bg_card_hover = colors.bg_card_hover;
    const char* bg_input = colors.bg_input;
    const char* bg_navbar = colors.bg_navbar;
    const char* bg_sidebar = colors.bg_sidebar;
    const char* bg_button = colors.bg_button;
    const char* bg_button_hover = colors.bg_button_hover;
    const char* bg_button_secondary = colors.bg_button_secondary;
    const char* bg_button_secondary_hover = colors.bg_button_secondary_hover;
    const char* bg_accent = colors.bg_accent;
    const char* text_primary = colors.text_primary;
    const char* text_secondary = colors.text_secondary;
    const char* text_muted = colors.text_muted;
    const char* text_button = colors.text_button;
    const char* text_accent = colors.text_accent;
    const char* text_link = colors.text_link;
    const char* border = colors.border;
    const char* border_subtle = colors.border_subtle;
    const char* border_focus = colors.border_focus;
    const char* border_accent = colors.border_accent;
    const char* shadow = colors.shadow;
    const char* shadow_lg = colors.shadow_lg;
    const char* success = colors.success;
    const char* warning = colors.warning;
    const char* error = colors.error;
    const char* info = colors.info;

    // Font selection based on theme
    std::string font_family = "'IBM Plex Mono', 'Consolas', 'Monaco', monospace";

    std::string font_import = "@import url('https://fonts.googleapis.com/css2?family=IBM+Plex+Mono:wght@400;500;600;700&display=swap');";

    return font_import + std::string(R"(

*, *::before, *::after {
    box-sizing: border-box;
    margin: 0;
    padding: 0;
}

html {
    font-family: )") + font_family + R"(;
    font-size: )" + Theme::font_size_base + R"(;
    line-height: 1.5;
    color: )" + text_primary + R"(;
    background-color: )" + bg_page + R"(;
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
    
    /* CSS Custom Properties for Components */
    --ew-bg-page: )" + bg_page + R"(;
    --ew-bg-card: )" + bg_card + R"(;
    --ew-bg-card-hover: )" + bg_card_hover + R"(;
    --ew-bg-input: )" + bg_input + R"(;
    --ew-bg-navbar: )" + bg_navbar + R"(;
    --ew-bg-sidebar: )" + bg_sidebar + R"(;
    --ew-bg-button: )" + bg_button + R"(;
    --ew-bg-button-hover: )" + bg_button_hover + R"(;
    --ew-bg-button-secondary: )" + bg_button_secondary + R"(;
    --ew-bg-button-secondary-hover: )" + bg_button_secondary_hover + R"(;
    --ew-bg-accent: )" + bg_accent + R"(;
    --ew-text: )" + text_primary + R"(;
    --ew-text-secondary: )" + text_secondary + R"(;
    --ew-text-muted: )" + text_muted + R"(;
    --ew-text-button: )" + text_button + R"(;
    --ew-text-accent: )" + text_accent + R"(;
    --ew-text-link: )" + text_link + R"(;
    --ew-border: )" + border + R"(;
    --ew-border-subtle: )" + border_subtle + R"(;
    --ew-border-focus: )" + border_focus + R"(;
    --ew-border-accent: )" + border_accent + R"(;
    --ew-shadow: )" + shadow + R"(;
    --ew-shadow-lg: )" + shadow_lg + R"(;
    --ew-success: )" + success + R"(;
    --ew-warning: )" + warning + R"(;
    --ew-error: )" + error + R"(;
    --ew-info: )" + info + R"(;
    
    /* Chart-specific colors */
    --ew-primary: )" + bg_button + R"(;
    --ew-secondary: )" + success + R"(;
}

body {
    min-height: 100vh;
}

/* ============================================
   LAYOUT COMPONENTS
   ============================================ */

.ew-app {
    display: flex;
    flex-direction: column;
    min-height: 100vh;
}

.ew-app-body {
    display: flex;
    flex: 1;
}

.ew-main {
    flex: 1;
    padding: )" + Theme::spacing_lg + R"(;
    overflow-y: auto;
}

.ew-page {
    max-width: 1400px;
    margin: 0 auto;
    padding: )" + Theme::spacing_lg + R"(;
}

/* ============================================
   NAVBAR - Angular
   ============================================ */

.ew-navbar {
    display: flex;
    align-items: center;
    justify-content: space-between;
    padding: )" + Theme::spacing_sm + " " + Theme::spacing_lg + R"(;
    background: )" + bg_navbar + R"(;
    border-bottom: 2px solid )" + border_subtle + R"(;
    position: sticky;
    top: 0;
    z-index: 100;
}

.ew-navbar-brand {
    font-size: )" + Theme::font_size_lg + R"(;
    font-weight: 700;
    color: )" + text_primary + R"(;
    text-decoration: none;
    text-transform: uppercase;
    letter-spacing: 0.1em;
    display: flex;
    align-items: center;
    gap: )" + Theme::spacing_sm + R"(;
}

.ew-navbar-nav {
    display: flex;
    align-items: center;
    gap: 0;
    list-style: none;
}

.ew-navbar-item {
    padding: )" + Theme::spacing_sm + " " + Theme::spacing_md + R"(;
    color: )" + text_secondary + R"(;
    text-decoration: none;
    font-weight: 600;
    font-size: )" + Theme::font_size_sm + R"(;
    text-transform: uppercase;
    letter-spacing: 0.05em;
    border-bottom: 2px solid transparent;
    transition: all 0.1s ease;
}

.ew-navbar-item:hover {
    color: )" + text_primary + R"(;
    background: )" + bg_card_hover + R"(;
}

.ew-navbar-item-active {
    color: )" + text_accent + R"(;
    border-bottom-color: )" + border_accent + R"(;
}

.ew-navbar-actions {
    display: flex;
    align-items: center;
    gap: )" + Theme::spacing_sm + R"(;
}

/* ============================================
   SIDEBAR - Angular
   ============================================ */

.ew-sidebar {
    width: 240px;
    min-width: 240px;
    background: )" + bg_sidebar + R"(;
    border-right: 2px solid )" + border_subtle + R"(;
    padding: )" + Theme::spacing_md + R"( 0;
    overflow-y: auto;
    height: calc(100vh - 49px);
    position: sticky;
    top: 49px;
}

.ew-sidebar-section {
    margin-bottom: )" + Theme::spacing_lg + R"(;
}

.ew-sidebar-title {
    font-size: )" + Theme::font_size_xs + R"(;
    font-weight: 700;
    text-transform: uppercase;
    letter-spacing: 0.1em;
    color: )" + text_muted + R"(;
    padding: )" + Theme::spacing_sm + " " + Theme::spacing_md + R"(;
    margin-bottom: )" + Theme::spacing_xs + R"(;
    border-left: 3px solid transparent;
}

.ew-sidebar-nav {
    list-style: none;
}

.ew-sidebar-item {
    display: flex;
    align-items: center;
    gap: )" + Theme::spacing_sm + R"(;
    padding: )" + Theme::spacing_sm + " " + Theme::spacing_md + R"(;
    color: )" + text_secondary + R"(;
    text-decoration: none;
    font-weight: 500;
    font-size: )" + Theme::font_size_sm + R"(;
    border-left: 3px solid transparent;
    transition: all 0.1s ease;
}

.ew-sidebar-item:hover {
    color: )" + text_primary + R"(;
    background: )" + bg_card_hover + R"(;
    border-left-color: )" + border_subtle + R"(;
}

.ew-sidebar-item-active {
    color: )" + text_accent + R"(;
    background: )" + bg_card_hover + R"(;
    border-left-color: )" + border_accent + R"(;
    font-weight: 600;
}

/* ============================================
   CARDS - Angular, Boxy
   ============================================ */

.ew-card {
    background: )" + bg_card + R"(;
    border: 2px solid )" + border_subtle + R"(;
    padding: )" + Theme::spacing_md + R"(;
    margin-bottom: )" + Theme::spacing_sm + R"(;
    transition: all 0.1s ease;
}

.ew-card:hover {
    border-color: )" + border + R"(;
}

.ew-card-title {
    font-size: )" + Theme::font_size_lg + R"(;
    font-weight: 700;
    margin-bottom: )" + Theme::spacing_md + R"(;
    color: )" + text_primary + R"(;
    text-transform: uppercase;
    letter-spacing: 0.05em;
    padding-bottom: )" + Theme::spacing_sm + R"(;
    border-bottom: 2px solid )" + border_subtle + R"(;
}

.ew-card-compact {
    padding: )" + Theme::spacing_md + R"(;
}

.ew-card-accent {
    border-left: 4px solid )" + border_accent + R"(;
}

/* ============================================
   BOX & CONTAINERS
   ============================================ */

.ew-box {
    padding: )" + Theme::spacing_md + R"(;
}

.ew-box-bordered {
    border: 2px solid )" + border_subtle + R"(;
}

/* ============================================
   TYPOGRAPHY - Angular
   ============================================ */

.ew-text {
    margin-bottom: )" + Theme::spacing_sm + R"(;
    color: )" + text_primary + R"(;
}

.ew-text-secondary {
    color: )" + text_secondary + R"(;
}

.ew-text-muted {
    color: )" + text_muted + R"(;
}

.ew-text-accent {
    color: )" + text_accent + R"(;
}

.ew-text-success {
    color: )" + success + R"(;
}

.ew-text-warning {
    color: )" + warning + R"(;
}

.ew-text-error {
    color: )" + error + R"(;
}

.ew-heading-1 {
    font-size: )" + Theme::font_size_3xl + R"(;
    font-weight: 700;
    margin-bottom: )" + Theme::spacing_md + R"(;
    letter-spacing: -0.01em;
    line-height: 1.1;
    text-transform: uppercase;
}

.ew-heading-2 {
    font-size: )" + Theme::font_size_2xl + R"(;
    font-weight: 700;
    margin-bottom: )" + Theme::spacing_md + R"(;
    line-height: 1.2;
    text-transform: uppercase;
    letter-spacing: 0.02em;
}

.ew-heading-3 {
    font-size: )" + Theme::font_size_xl + R"(;
    font-weight: 600;
    margin-bottom: )" + Theme::spacing_sm + R"(;
    line-height: 1.3;
}

/* ============================================
   BUTTONS - Angular, Sharp
   ============================================ */

.ew-button {
    display: inline-flex;
    align-items: center;
    justify-content: center;
    gap: )" + Theme::spacing_sm + R"(;
    padding: 10px 20px;
    font-size: )" + Theme::font_size_sm + R"(;
    font-weight: 700;
    font-family: inherit;
    text-transform: uppercase;
    letter-spacing: 0.05em;
    border: 2px solid transparent;
    cursor: pointer;
    transition: all 0.1s ease;
    text-decoration: none;
}

.ew-button:active {
    transform: translateY(1px);
}

.ew-button-primary {
    background-color: )" + bg_button + R"(;
    color: )" + text_button + R"(;
    border-color: )" + bg_button + R"(;
}

.ew-button-primary:hover {
    background-color: )" + bg_button_hover + R"(;
    border-color: )" + bg_button_hover + R"(;
}

.ew-button-secondary {
    background-color: )" + bg_button_secondary + R"(;
    color: )" + text_primary + R"(;
    border-color: )" + border_subtle + R"(;
}

.ew-button-secondary:hover {
    background-color: )" + bg_button_secondary_hover + R"(;
    border-color: )" + border + R"(;
}

.ew-button-outline {
    background-color: transparent;
    color: )" + text_accent + R"(;
    border-color: )" + border_accent + R"(;
}

.ew-button-outline:hover {
    background-color: )" + text_accent + R"(;
    color: )" + bg_page + R"(;
}

.ew-button-ghost {
    background-color: transparent;
    color: )" + text_secondary + R"(;
    border-color: transparent;
}

.ew-button-ghost:hover {
    background-color: )" + bg_card_hover + R"(;
    color: )" + text_primary + R"(;
    border-color: )" + border_subtle + R"(;
}

.ew-button-sm {
    padding: 6px 12px;
    font-size: )" + Theme::font_size_xs + R"(;
}

.ew-button-lg {
    padding: 14px 28px;
    font-size: )" + Theme::font_size_base + R"(;
}

/* ============================================
   CHART COMPONENTS
   ============================================ */

.ew-chart-container {
    display: flex;
    flex-direction: column;
    gap: )" + Theme::spacing_sm + R"(;
    padding: )" + Theme::spacing_md + R"(;
    background: var(--ew-bg-card);
    border: 1px solid var(--ew-border);
    border-radius: )" + Theme::radius_md + R"(;
}

.ew-chart-title {
    font-size: )" + Theme::font_size_lg + R"(;
    font-weight: 600;
    color: var(--ew-text);
    text-align: center;
    margin-bottom: )" + Theme::spacing_sm + R"(;
}

.ew-chart {
    width: 100%;
    height: auto;
    background: transparent;
}

.ew-chart-legend {
    display: flex;
    flex-wrap: wrap;
    gap: )" + Theme::spacing_md + R"(;
    justify-content: center;
    margin-top: )" + Theme::spacing_sm + R"(;
}

.ew-chart-legend-item {
    display: flex;
    align-items: center;
    gap: )" + Theme::spacing_xs + R"(;
    font-size: )" + Theme::font_size_sm + R"(;
    color: var(--ew-text);
}

.ew-chart-legend-color {
    width: 12px;
    height: 12px;
    border-radius: 2px;
}

/* ============================================
   LAYOUT UTILITIES
   ============================================ */

.ew-row {
    display: flex;
    flex-direction: row;
    gap: )" + Theme::spacing_md + R"(;
}

.ew-row-wrap {
    flex-wrap: wrap;
}

.ew-column {
    display: flex;
    flex-direction: column;
    gap: )" + Theme::spacing_md + R"(;
}

.ew-grid {
    display: grid;
    gap: )" + Theme::spacing_sm + R"(;
}

.ew-grid-2 { grid-template-columns: repeat(2, 1fr); }
.ew-grid-3 { grid-template-columns: repeat(3, 1fr); }
.ew-grid-4 { grid-template-columns: repeat(4, 1fr); }

/* ============================================
   FORM ELEMENTS - Angular
   ============================================ */

.ew-input {
    width: 100%;
    padding: 10px 12px;
    font-size: )" + Theme::font_size_sm + R"(;
    font-family: inherit;
    border: 2px solid )" + border_subtle + R"(;
    background: )" + bg_input + R"(;
    color: )" + text_primary + R"(;
    transition: all 0.1s ease;
}

.ew-input:focus {
    outline: none;
    border-color: )" + border_focus + R"(;
}

.ew-input::placeholder {
    color: )" + text_muted + R"(;
}

.ew-label {
    display: block;
    font-size: )" + Theme::font_size_xs + R"(;
    font-weight: 700;
    text-transform: uppercase;
    letter-spacing: 0.05em;
    margin-bottom: )" + Theme::spacing_xs + R"(;
    color: )" + text_secondary + R"(;
}

.ew-form-group {
    margin-bottom: )" + Theme::spacing_md + R"(;
}

/* ============================================
   UTILITIES
   ============================================ */

.ew-divider {
    border: none;
    border-top: 2px solid )" + border_subtle + R"(;
    margin: )" + Theme::spacing_lg + R"( 0;
}

.ew-spacer { height: )" + Theme::spacing_md + R"(; }
.ew-spacer-sm { height: )" + Theme::spacing_sm + R"(; }
.ew-spacer-lg { height: )" + Theme::spacing_lg + R"(; }
.ew-spacer-xl { height: )" + Theme::spacing_xl + R"(; }

.ew-link {
    color: )" + text_link + R"(;
    text-decoration: none;
    font-weight: 600;
    border-bottom: 1px solid transparent;
}

.ew-link:hover {
    border-bottom-color: )" + text_link + R"(;
}

.ew-image {
    max-width: 100%;
    height: auto;
}

.ew-center { text-align: center; }
.ew-right { text-align: right; }
.ew-flex-grow { flex-grow: 1; }
.ew-flex-shrink-0 { flex-shrink: 0; }

.ew-center-content { justify-content: center; }

.ew-gap-sm { gap: )" + Theme::spacing_sm + R"(; }
.ew-gap-lg { gap: )" + Theme::spacing_lg + R"(; }
.ew-gap-xl { gap: )" + Theme::spacing_xl + R"(; }

/* ============================================
   BADGE - Angular
   ============================================ */

.ew-badge {
    display: inline-flex;
    align-items: center;
    padding: 2px 8px;
    font-size: )" + Theme::font_size_xs + R"(;
    font-weight: 700;
    text-transform: uppercase;
    letter-spacing: 0.05em;
    border: 2px solid )" + border_accent + R"(;
    background: transparent;
    color: )" + text_accent + R"(;
}

.ew-badge-success {
    border-color: )" + success + R"(;
    color: )" + success + R"(;
}

.ew-badge-warning {
    border-color: )" + warning + R"(;
    color: )" + warning + R"(;
}

.ew-badge-error {
    border-color: )" + error + R"(;
    color: )" + error + R"(;
}

/* ============================================
   STAT CARD - Angular
   ============================================ */

.ew-stat {
    display: flex;
    flex-direction: column;
}

.ew-stat-label {
    font-size: )" + Theme::font_size_xs + R"(;
    font-weight: 700;
    text-transform: uppercase;
    letter-spacing: 0.1em;
    color: )" + text_muted + R"(;
    margin-bottom: )" + Theme::spacing_xs + R"(;
}

.ew-stat-value {
    font-size: )" + Theme::font_size_2xl + R"(;
    font-weight: 700;
    color: )" + text_primary + R"(;
    line-height: 1;
    font-variant-numeric: tabular-nums;
}

.ew-stat-change {
    font-size: )" + Theme::font_size_sm + R"(;
    font-weight: 700;
    margin-top: )" + Theme::spacing_sm + R"(;
}

.ew-stat-change-up {
    color: )" + success + R"(;
}

.ew-stat-change-down {
    color: )" + error + R"(;
}

/* ============================================
   CODE BLOCK (for cream/technical theme)
   ============================================ */

.ew-code {
    font-family: 'IBM Plex Mono', monospace;
    background: )" + bg_card_hover + R"(;
    padding: 2px 6px;
    border: 1px solid )" + border_subtle + R"(;
    font-size: )" + Theme::font_size_sm + R"(;
}

.ew-code-block {
    font-family: 'IBM Plex Mono', monospace;
    background: )" + bg_card_hover + R"(;
    padding: )" + Theme::spacing_md + R"(;
    border: 2px solid )" + border_subtle + R"(;
    font-size: )" + Theme::font_size_sm + R"(;
    overflow-x: auto;
    white-space: pre;
}

/* ============================================
   RESPONSIVE
   ============================================ */

@media (max-width: 1024px) {
    .ew-sidebar {
        display: none;
    }
}

@media (max-width: 768px) {
    .ew-grid-2, .ew-grid-3, .ew-grid-4 {
        grid-template-columns: 1fr;
    }

    .ew-row {
        flex-direction: column;
    }

    .ew-navbar {
        padding: )" + Theme::spacing_sm + " " + Theme::spacing_md + R"(;
    }

    .ew-navbar-nav {
        display: none;
    }
}
)";
}

}
