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

    // almost-flat borders 
    static constexpr const char* radius_none = "0";
    static constexpr const char* radius_sm   = "1px";
    static constexpr const char* radius_md   = "2px";
    static constexpr const char* radius_lg   = "3px";


    //tighter spacing
    static constexpr const char* spacing_xs = "1px";
    static constexpr const char* spacing_sm = "3px";
    static constexpr const char* spacing_md = "4px";
    static constexpr const char* spacing_lg = "8px";
    static constexpr const char* spacing_xl = "10px";
    static constexpr const char* spacing_2xl = "12px";

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
    "#0a0a0a", // bg_page - near black
    "#111111", // bg_card - slightly lighter
    "#1a1a1a", // bg_card_hover
    "#0a0a0a", // bg_input
    "#0a0a0a", // bg_navbar
    "#0a0a0a", // bg_sidebar
    "#22c55e", // bg_button - vibrant green
    "#16a34a", // bg_button_hover
    "#1a1a1a", // bg_button_secondary
    "#262626", // bg_button_secondary_hover
    "#22c55e", // bg_accent
    "#fafafa", // text_primary - bright white
    "#a1a1aa", // text_secondary
    "#52525b", // text_muted
    "#0a0a0a", // text_button - dark on green
    "#22c55e", // text_accent - terminal green
    "#22c55e", // text_link
    "#22c55e", // border - green accent
    "#262626", // border_subtle - dark grey
    "#22c55e", // border_focus
    "#22c55e", // border_accent
    "none",    // shadow
    "0 0 0 1px #22c55e", // shadow_lg
    "#22c55e", // success - same green
    "#eab308", // warning - yellow
    "#ef4444", // error - red
    "#3b82f6"  // info - blue
};

const ColorScheme Theme::light_colors =
{
    "#fafafa", // bg_page - off white
    "#ffffff", // bg_card
    "#f4f4f5", // bg_card_hover
    "#ffffff", // bg_input
    "#fafafa", // bg_navbar
    "#fafafa", // bg_sidebar
    "#18181b", // bg_button - near black
    "#27272a", // bg_button_hover
    "#f4f4f5", // bg_button_secondary
    "#e4e4e7", // bg_button_secondary_hover
    "#18181b", // bg_accent
    "#09090b", // text_primary - almost black
    "#52525b", // text_secondary
    "#a1a1aa", // text_muted
    "#fafafa", // text_button
    "#18181b", // text_accent
    "#18181b", // text_link
    "#18181b", // border - dark
    "#e4e4e7", // border_subtle - light grey
    "#18181b", // border_focus
    "#18181b", // border_accent
    "none",    // shadow
    "0 0 0 1px #18181b", // shadow_lg
    "#16a34a", // success
    "#ca8a04", // warning
    "#dc2626", // error
    "#2563eb"  // info
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
    border-bottom: 1px solid )" + border_subtle + R"(;
    position: sticky;
    top: 0;
    z-index: 100;
}

.ew-navbar-brand {
    font-size: )" + Theme::font_size_lg + R"(;
    font-weight: 600;
    color: )" + text_primary + R"(;
    text-decoration: none;
    letter-spacing: -0.01em;
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
    font-weight: 500;
    font-size: )" + Theme::font_size_sm + R"(;
    border-bottom: 1px solid transparent;
    transition: all 0.15s ease;
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
    border-right: 1px solid )" + border_subtle + R"(;
    padding: )" + Theme::spacing_md + R"( 0;
    overflow-y: auto;
    height: calc(100vh - 41px);
    position: sticky;
    top: 41px;
}

.ew-sidebar-section {
    margin-bottom: )" + Theme::spacing_lg + R"(;
}

.ew-sidebar-title {
    font-size: )" + Theme::font_size_xs + R"(;
    font-weight: 600;
    text-transform: uppercase;
    letter-spacing: 0.05em;
    color: )" + text_muted + R"(;
    padding: )" + Theme::spacing_sm + " " + Theme::spacing_md + R"(;
    margin-bottom: )" + Theme::spacing_xs + R"(;
    border-left: 2px solid transparent;
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
    font-weight: 400;
    font-size: )" + Theme::font_size_sm + R"(;
    border-left: 2px solid transparent;
    transition: all 0.15s ease;
}

.ew-sidebar-item:hover {
    color: )" + text_primary + R"(;
    border-left-color: )" + border_subtle + R"(;
}

.ew-sidebar-item-active {
    color: )" + text_accent + R"(;
    border-left-color: )" + border_accent + R"(;
    font-weight: 500;
}

/* ============================================
   CARDS - Clean, Minimal
   ============================================ */

.ew-card {
    background: )" + bg_card + R"(;
    border: 1px solid )" + border_subtle + R"(;
    padding: )" + Theme::spacing_lg + R"(;
    margin-bottom: )" + Theme::spacing_sm + R"(;
    transition: border-color 0.15s ease;
}

.ew-card:hover {
    border-color: )" + border + R"(;
}

.ew-card-title {
    font-size: )" + Theme::font_size_base + R"(;
    font-weight: 600;
    margin-bottom: )" + Theme::spacing_md + R"(;
    color: )" + text_primary + R"(;
    padding-bottom: )" + Theme::spacing_sm + R"(;
    border-bottom: 1px solid )" + border_subtle + R"(;
}

.ew-card-compact {
    padding: )" + Theme::spacing_md + R"(;
}

.ew-card-accent {
    border-left: 2px solid )" + border_accent + R"(;
}

/* ============================================
   BOX & CONTAINERS
   ============================================ */

.ew-box {
    padding: )" + Theme::spacing_md + R"(;
}

.ew-box-bordered {
    border: 1px solid )" + border_subtle + R"(;
}

/* ============================================
   TYPOGRAPHY - Clean
   ============================================ */

.ew-text {
    margin-bottom: )" + Theme::spacing_sm + R"(;
    color: )" + text_primary + R"(;
    line-height: 1.6;
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
    font-size: )" + Theme::font_size_2xl + R"(;
    font-weight: 600;
    margin-bottom: )" + Theme::spacing_md + R"(;
    letter-spacing: -0.02em;
    line-height: 1.2;
}

.ew-heading-2 {
    font-size: )" + Theme::font_size_xl + R"(;
    font-weight: 600;
    margin-bottom: )" + Theme::spacing_md + R"(;
    line-height: 1.3;
    letter-spacing: -0.01em;
}

.ew-heading-3 {
    font-size: )" + Theme::font_size_lg + R"(;
    font-weight: 600;
    margin-bottom: )" + Theme::spacing_sm + R"(;
    line-height: 1.4;
}

/* ============================================
   BUTTONS - Clean, Minimal
   ============================================ */

.ew-button {
    display: inline-flex;
    align-items: center;
    justify-content: center;
    gap: )" + Theme::spacing_sm + R"(;
    padding: 8px 16px;
    font-size: )" + Theme::font_size_sm + R"(;
    font-weight: 500;
    font-family: inherit;
    border: 1px solid transparent;
    cursor: pointer;
    transition: all 0.15s ease;
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
    color: )" + text_primary + R"(;
}

.ew-button-sm {
    padding: 4px 10px;
    font-size: )" + Theme::font_size_xs + R"(;
}

.ew-button-xs {
    padding: 2px 8px;
    font-size: )" + Theme::font_size_xs + R"(;
}

.ew-button-lg {
    padding: 12px 24px;
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
    padding: 8px 12px;
    font-size: )" + Theme::font_size_sm + R"(;
    font-family: inherit;
    border: 1px solid )" + border_subtle + R"(;
    background: )" + bg_input + R"(;
    color: )" + text_primary + R"(;
    transition: border-color 0.15s ease;
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
    font-weight: 500;
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
    border-top: 1px solid )" + border_subtle + R"(;
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
   BADGE - Clean
   ============================================ */

.ew-badge {
    display: inline-flex;
    align-items: center;
    padding: 2px 8px;
    font-size: )" + Theme::font_size_xs + R"(;
    font-weight: 500;
    border: 1px solid )" + border_accent + R"(;
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
   STAT CARD - Clean
   ============================================ */

.ew-stat {
    display: flex;
    flex-direction: column;
}

.ew-stat-label {
    font-size: )" + Theme::font_size_xs + R"(;
    font-weight: 500;
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
   CODE BLOCK - Terminal Style
   ============================================ */

.ew-code {
    font-family: 'IBM Plex Mono', monospace;
    background: )" + bg_card_hover + R"(;
    padding: 1px 4px;
    font-size: )" + Theme::font_size_sm + R"(;
    color: )" + text_accent + R"(;
}

.ew-code-block {
    background: )" + bg_card + R"(;
    border: 1px solid )" + border_subtle + R"(;
    padding: 0;
    overflow: hidden;
}

.ew-code-block .ew-card-title,
.ew-code-block > .ew-row:first-child {
    background: )" + bg_card_hover + R"(;
    border-bottom: 1px solid )" + border_subtle + R"(;
    padding: )" + Theme::spacing_sm + " " + Theme::spacing_md + R"(;
    margin: 0;
}

.ew-code-block .ew-code {
    display: block;
    padding: )" + Theme::spacing_md + R"(;
    margin: 0;
    background: transparent;
    white-space: pre;
    overflow-x: auto;
    line-height: 1.5;
    color: )" + text_primary + R"(;
}

/* ============================================
   RESPONSIVE DESIGN SYSTEM
   ============================================ */

/* Mobile-first responsive utilities */
.ew-hidden-mobile { display: none; }
.ew-hidden-tablet { display: initial; }
.ew-hidden-desktop { display: initial; }

@media (min-width: 576px) {
    .ew-hidden-mobile { display: initial; }
    .ew-hidden-tablet { display: none; }
}

@media (min-width: 1024px) {
    .ew-hidden-tablet { display: initial; }
    .ew-hidden-desktop { display: none; }
}

@media (min-width: 1200px) {
    .ew-hidden-desktop { display: initial; }
}

/* Responsive spacing utilities */
.ew-p-sm { padding: )" + Theme::spacing_sm + R"(; }
.ew-p-md { padding: )" + Theme::spacing_md + R"(; }
.ew-p-lg { padding: )" + Theme::spacing_lg + R"(; }
.ew-p-xl { padding: )" + Theme::spacing_xl + R"(; }

.ew-m-sm { margin: )" + Theme::spacing_sm + R"(; }
.ew-m-md { margin: )" + Theme::spacing_md + R"(; }
.ew-m-lg { margin: )" + Theme::spacing_lg + R"(; }
.ew-m-xl { margin: )" + Theme::spacing_xl + R"(; }

.ew-mb-sm { margin-bottom: )" + Theme::spacing_sm + R"(; }
.ew-mb-md { margin-bottom: )" + Theme::spacing_md + R"(; }
.ew-mb-lg { margin-bottom: )" + Theme::spacing_lg + R"(; }
.ew-mb-xl { margin-bottom: )" + Theme::spacing_xl + R"(; }

/* Responsive text sizes */
.ew-text-xs { font-size: 0.75rem; line-height: 1rem; }
.ew-text-sm { font-size: 0.875rem; line-height: 1.25rem; }
.ew-text-base { font-size: 1rem; line-height: 1.5rem; }
.ew-text-lg { font-size: 1.125rem; line-height: 1.75rem; }
.ew-text-xl { font-size: 1.25rem; line-height: 1.75rem; }
.ew-text-2xl { font-size: 1.5rem; line-height: 2rem; }
.ew-text-3xl { font-size: 1.875rem; line-height: 2.25rem; }

/* Touch-friendly button sizes */
.ew-btn-touch {
    min-height: 44px;
    min-width: 44px;
    padding: )" + Theme::spacing_md + R"(;
}

/* Mobile-specific utilities */
.ew-row-mobile-stack {
    flex-direction: row;
}

.ew-center-mobile {
    justify-content: flex-start;
    text-align: left;
}

@media (max-width: 768px) {
    .ew-row-mobile-stack {
        flex-direction: column;
        align-items: stretch;
        gap: )" + Theme::spacing_md + R"(;
    }

    .ew-center-mobile {
        justify-content: center;
        text-align: center;
    }
}

/* Responsive grid utilities */
.ew-grid-responsive {
    display: grid;
    gap: )" + Theme::spacing_md + R"(;
    grid-template-columns: 1fr;
}

@media (min-width: 576px) {
    .ew-grid-responsive {
        grid-template-columns: repeat(auto-fit, minmax(280px, 1fr));
    }
}

@media (min-width: 768px) {
    .ew-grid-responsive {
        grid-template-columns: repeat(auto-fit, minmax(320px, 1fr));
    }
}

@media (min-width: 1024px) {
    .ew-grid-responsive {
        grid-template-columns: repeat(auto-fit, minmax(360px, 1fr));
    }
}

/* ============================================
   BREAKPOINT-SPECIFIC STYLES
   ============================================ */

@media (max-width: 1024px) {
    .ew-sidebar {
        display: none;
    }

    .ew-page {
        padding: )" + Theme::spacing_md + R"(;
    }

    .ew-card {
        padding: )" + Theme::spacing_md + R"(;
        margin-bottom: )" + Theme::spacing_md + R"(;
    }

    .ew-card-title {
        font-size: )" + Theme::font_size_base + R"(;
    }
}

@media (max-width: 768px) {
    .ew-page {
        padding: )" + Theme::spacing_sm + R"(;
        max-width: 100%;
    }

    .ew-grid-2, .ew-grid-3, .ew-grid-4 {
        grid-template-columns: 1fr;
    }

    .ew-row {
        flex-direction: column;
        gap: )" + Theme::spacing_md + R"(;
    }

    .ew-navbar {
        padding: )" + Theme::spacing_sm + " " + Theme::spacing_md + R"(;
        flex-wrap: wrap;
    }

    .ew-navbar-nav {
        display: none;
    }

    .ew-navbar-brand {
        font-size: )" + Theme::font_size_base + R"(;
    }

    .ew-card {
        padding: )" + Theme::spacing_sm + R"(;
        margin-bottom: )" + Theme::spacing_md + R"(;
    }

    .ew-card-title {
        font-size: )" + Theme::font_size_base + R"(;
        margin-bottom: )" + Theme::spacing_sm + R"(;
    }

    .ew-btn {
        width: 100%;
        margin-bottom: )" + Theme::spacing_sm + R"(;
    }

    .ew-input, .ew-textarea {
        font-size: 16px; /* Prevent zoom on iOS */
    }

    .ew-chart-container {
        overflow-x: auto;
        -webkit-overflow-scrolling: touch;
    }

    .ew-table {
        font-size: )" + Theme::font_size_sm + R"(;
    }

    .ew-stat-value {
        font-size: )" + Theme::font_size_lg + R"(;
    }

    .ew-stat-label {
        font-size: )" + Theme::font_size_sm + R"(;
    }
}

@media (max-width: 576px) {
    .ew-page {
        padding: )" + Theme::spacing_xs + R"(;
    }

    .ew-card {
        padding: )" + Theme::spacing_xs + R"(;
        border-radius: 8px;
    }

    .ew-card-mobile-full {
        margin: 0 -)" + Theme::spacing_xs + R"( )" + Theme::spacing_md + R"( -)" + Theme::spacing_xs + R"(;
        border-radius: 0;
    }

    .ew-card-title {
        font-size: )" + Theme::font_size_sm + R"(;
        text-align: center;
    }

    .ew-text-h1 {
        font-size: )" + Theme::font_size_xl + R"(;
        text-align: center;
    }

    .ew-text-h2 {
        font-size: )" + Theme::font_size_lg + R"(;
        text-align: center;
    }

    .ew-text-h3 {
        font-size: )" + Theme::font_size_base + R"(;
        text-align: center;
    }

    .ew-spacer {
        height: )" + Theme::spacing_md + R"(;
    }

    .ew-spacer-sm {
        height: )" + Theme::spacing_sm + R"(;
    }

    .ew-spacer-lg {
        height: )" + Theme::spacing_lg + R"(;
    }

    .ew-spacer-xl {
        height: )" + Theme::spacing_xl + R"(;
    }

    /* Stack everything vertically on mobile */
    .ew-row, .ew-row-wrap {
        flex-direction: column;
        align-items: stretch;
    }

    .ew-center-content {
        justify-content: center;
        text-align: center;
    }

    /* Make buttons more touch-friendly */
    .ew-btn {
        min-height: 48px;
        font-size: )" + Theme::font_size_base + R"(;
        padding: )" + Theme::spacing_md + " " + Theme::spacing_lg + R"(;
    }

    /* Improve form elements for mobile */
    .ew-input, .ew-textarea, .ew-select {
        padding: )" + Theme::spacing_md + R"(;
        font-size: 16px;
        border-radius: 8px;
    }

    /* Better spacing for lists and badges */
    .ew-badge {
        font-size: )" + Theme::font_size_xs + R"(;
        padding: 4px 8px;
    }

    /* Make charts responsive */
    .ew-chart-container svg {
        max-width: 100%;
        height: auto;
    }
}

/* ============================================================================
   Chat/Streaming Components
   ============================================================================ */

.ew-chat-container {
    display: flex;
    flex-direction: column;
    height: 100%;
    min-height: 400px;
    max-height: 80vh;
    border: 1px solid )" + std::string(colors.border_subtle) + R"(;
    border-radius: 8px;
    overflow: hidden;
    background: )" + std::string(colors.bg_card) + R"(;
}

.ew-chat-messages {
    flex: 1;
    overflow-y: auto;
    padding: )" + Theme::spacing_lg + R"(;
    display: flex;
    flex-direction: column;
    gap: )" + Theme::spacing_md + R"(;
}

.ew-chat-message {
    max-width: 80%;
    padding: )" + Theme::spacing_md + R"( )" + Theme::spacing_lg + R"(;
    border-radius: 12px;
    line-height: 1.5;
}

.ew-chat-message-user {
    align-self: flex-end;
    background: )" + std::string(colors.bg_accent) + R"(;
    color: )" + std::string(colors.text_button) + R"(;
    border-bottom-right-radius: 4px;
}

.ew-chat-message-assistant {
    align-self: flex-start;
    background: )" + std::string(colors.bg_input) + R"(;
    color: )" + std::string(colors.text_primary) + R"(;
    border: 1px solid )" + std::string(colors.border_subtle) + R"(;
    border-bottom-left-radius: 4px;
}

.ew-chat-message-streaming {
    position: relative;
}

.ew-chat-message-streaming::after {
    content: '▋';
    animation: blink 1s infinite;
    color: )" + std::string(colors.text_accent) + R"(;
}

@keyframes blink {
    0%, 50% { opacity: 1; }
    51%, 100% { opacity: 0; }
}

.ew-chat-message-content {
    word-wrap: break-word;
    white-space: pre-wrap;
}

.ew-chat-input-container {
    display: flex;
    gap: )" + Theme::spacing_sm + R"(;
    padding: )" + Theme::spacing_md + R"(;
    border-top: 1px solid )" + std::string(colors.border_subtle) + R"(;
    background: )" + std::string(colors.bg_card) + R"(;
}

.ew-chat-input {
    flex: 1;
    margin: 0;
}

.ew-chat-stream {
    display: flex;
    flex-direction: column;
}

.ew-chat-stream-content {
    display: inline;
}

/* Streaming token styles */
.ew-token {
    display: inline;
}

.ew-token-streaming {
    border-right: 2px solid )" + std::string(colors.text_accent) + R"(;
    animation: cursor-blink 1s infinite;
}

@keyframes cursor-blink {
    0%, 50% { border-color: )" + std::string(colors.text_accent) + R"(; }
    51%, 100% { border-color: transparent; }
}

/* Loading indicator */
.ew-chat-loading {
    display: flex;
    gap: 4px;
    padding: )" + Theme::spacing_sm + R"(;
}

.ew-chat-loading-dot {
    width: 8px;
    height: 8px;
    border-radius: 50%;
    background: )" + std::string(colors.text_muted) + R"(;
    animation: loading-bounce 1.4s infinite ease-in-out both;
}

.ew-chat-loading-dot:nth-child(1) { animation-delay: -0.32s; }
.ew-chat-loading-dot:nth-child(2) { animation-delay: -0.16s; }
.ew-chat-loading-dot:nth-child(3) { animation-delay: 0; }

@keyframes loading-bounce {
    0%, 80%, 100% { transform: scale(0); }
    40% { transform: scale(1); }
}

/* Mobile adjustments for chat */
@media (max-width: 768px) {
    .ew-chat-message {
        max-width: 90%;
    }

    .ew-chat-input-container {
        flex-direction: column;
    }

    .ew-chat-input-container .ew-button {
        width: 100%;
    }
}
)";
}

}
