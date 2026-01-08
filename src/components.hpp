#pragma once

#include <string>
#include <vector>
#include <memory>
#include <sstream>

namespace zero_js
{ 

// Forward declarations
class Component;
using ComponentPtr = std::shared_ptr<Component>;

// Helper to create component pointers
template<typename T>
ComponentPtr make_component(T&& component) {
    return std::make_shared<std::decay_t<T>>(std::forward<T>(component));
}

// Base component class
class Component {
public:
    virtual ~Component() = default;
    virtual std::string render() const = 0;

    std::string id_;
    std::string classes_;
    std::string hx_get_;
    std::string hx_post_;
    std::string hx_target_;
    std::string hx_swap_;
    std::string hx_trigger_;
    std::string hx_ext_;
    std::string hx_vals_;
    std::string sse_connect_;
    std::string sse_swap_;
    std::string sse_close_;

protected:
    std::string render_attributes() const {
        std::ostringstream attrs;
        if (!id_.empty()) attrs << " id=\"" << id_ << "\"";
        if (!hx_get_.empty()) attrs << " hx-get=\"" << hx_get_ << "\"";
        if (!hx_post_.empty()) attrs << " hx-post=\"" << hx_post_ << "\"";
        if (!hx_target_.empty()) attrs << " hx-target=\"" << hx_target_ << "\"";
        if (!hx_swap_.empty()) attrs << " hx-swap=\"" << hx_swap_ << "\"";
        if (!hx_trigger_.empty()) attrs << " hx-trigger=\"" << hx_trigger_ << "\"";
        if (!hx_ext_.empty()) attrs << " hx-ext=\"" << hx_ext_ << "\"";
        if (!hx_vals_.empty()) attrs << " hx-vals='" << hx_vals_ << "'";
        if (!sse_connect_.empty()) attrs << " sse-connect=\"" << sse_connect_ << "\"";
        if (!sse_swap_.empty()) attrs << " sse-swap=\"" << sse_swap_ << "\"";
        if (!sse_close_.empty()) attrs << " sse-close=\"" << sse_close_ << "\"";
        return attrs.str();
    }

    std::string render_children(const std::vector<ComponentPtr>& children) const {
        std::ostringstream html;
        for (const auto& child : children) {
            html << child->render();
        }
        return html.str();
    }
};

// ============================================================================
// Text Components
// ============================================================================

class Text : public Component {
public:
    std::string content_;
    int heading_level_ = 0;
    bool secondary_ = false;
    bool muted_ = false;
    bool accent_ = false;

    Text() = default;
    explicit Text(const std::string& content) : content_(content) {}

    Text& content(const std::string& c) { content_ = c; return *this; }
    Text& h1() { heading_level_ = 1; return *this; }
    Text& h2() { heading_level_ = 2; return *this; }
    Text& h3() { heading_level_ = 3; return *this; }
    Text& secondary() { secondary_ = true; return *this; }
    Text& muted() { muted_ = true; return *this; }
    Text& accent() { accent_ = true; return *this; }
    Text& id(const std::string& i) { id_ = i; return *this; }
    Text& classes(const std::string& c) { classes_ = c; return *this; }

    std::string render() const override {
        std::ostringstream html;
        std::string tag = "p";
        std::string cls = "ew-text";

        if (heading_level_ == 1) { tag = "h1"; cls = "ew-heading-1"; }
        else if (heading_level_ == 2) { tag = "h2"; cls = "ew-heading-2"; }
        else if (heading_level_ == 3) { tag = "h3"; cls = "ew-heading-3"; }
        else if (secondary_) { cls += " ew-text-secondary"; }
        else if (muted_) { cls += " ew-text-muted"; }
        else if (accent_) { cls += " ew-text-accent"; }

        if (!classes_.empty()) cls += " " + classes_;

        html << "<" << tag << " class=\"" << cls << "\"" << render_attributes() << ">";
        html << content_;
        html << "</" << tag << ">";
        return html.str();
    }
};

// ============================================================================
// Utility Components
// ============================================================================

class Divider : public Component {
public:
    std::string render() const override {
        return "<hr class=\"ew-divider\">";
    }
};

class Spacer : public Component {
public:
    std::string size_ = "md";

    Spacer() = default;

    Spacer& sm() { size_ = "sm"; return *this; }
    Spacer& lg() { size_ = "lg"; return *this; }
    Spacer& xl() { size_ = "xl"; return *this; }

    std::string render() const override {
        std::string cls = "ew-spacer";
        if (size_ == "sm") cls += "-sm";
        else if (size_ == "lg") cls += "-lg";
        else if (size_ == "xl") cls += "-xl";
        return "<div class=\"" + cls + "\"></div>";
    }
};

class Image : public Component {
public:
    std::string src_;
    std::string alt_;

    Image() = default;
    explicit Image(const std::string& src) : src_(src) {}

    Image& src(const std::string& s) { src_ = s; return *this; }
    Image& alt(const std::string& a) { alt_ = a; return *this; }
    Image& id(const std::string& i) { id_ = i; return *this; }
    Image& classes(const std::string& c) { classes_ = c; return *this; }

    std::string render() const override {
        std::ostringstream html;
        std::string cls = "ew-image";
        if (!classes_.empty()) cls += " " + classes_;
        html << "<img src=\"" << src_ << "\" alt=\"" << alt_ << "\" class=\"" << cls << "\"" << render_attributes() << ">";
        return html.str();
    }
};

// Badge component
class Badge : public Component {
public:
    std::string text_;
    std::string variant_ = "default"; // default, success, warning, error

    Badge() = default;
    explicit Badge(const std::string& text) : text_(text) {}

    Badge& text(const std::string& t) { text_ = t; return *this; }
    Badge& success() { variant_ = "success"; return *this; }
    Badge& warning() { variant_ = "warning"; return *this; }
    Badge& error() { variant_ = "error"; return *this; }

    std::string render() const override {
        std::string cls = "ew-badge";
        if (variant_ == "success") cls += " ew-badge-success";
        else if (variant_ == "warning") cls += " ew-badge-warning";
        else if (variant_ == "error") cls += " ew-badge-error";
        return "<span class=\"" + cls + "\">" + text_ + "</span>";
    }
};

// Stat component for dashboard metrics
class Stat : public Component {
public:
    std::string label_;
    std::string value_;
    std::string change_;
    bool change_up_ = true;

    Stat() = default;

    Stat& label(const std::string& l) { label_ = l; return *this; }
    Stat& value(const std::string& v) { value_ = v; return *this; }
    Stat& change(const std::string& c, bool up = true) { change_ = c; change_up_ = up; return *this; }
    Stat& id(const std::string& i) { id_ = i; return *this; }

    std::string render() const override {
        std::ostringstream html;
        html << "<div class=\"ew-stat\"" << render_attributes() << ">";
        html << "<span class=\"ew-stat-label\">" << label_ << "</span>";
        html << "<span class=\"ew-stat-value\">" << value_ << "</span>";
        if (!change_.empty()) {
            html << "<span class=\"ew-stat-change " << (change_up_ ? "ew-stat-change-up" : "ew-stat-change-down") << "\">";
            html << (change_up_ ? "+" : "") << change_;
            html << "</span>";
        }
        html << "</div>";
        return html.str();
    }
};

// ============================================================================
// Interactive Components
// ============================================================================

class Button : public Component {
public:
    std::string label_;
    std::string variant_ = "primary"; // primary, secondary, outline, ghost

    Button() = default;
    explicit Button(const std::string& label) : label_(label) {}

    Button& label(const std::string& l) { label_ = l; return *this; }
    Button& secondary() { variant_ = "secondary"; return *this; }
    Button& outline() { variant_ = "outline"; return *this; }
    Button& ghost() { variant_ = "ghost"; return *this; }
    Button& id(const std::string& i) { id_ = i; return *this; }
    Button& classes(const std::string& c) { classes_ = c; return *this; }

    Button& action(const std::string& url) { hx_post_ = url; return *this; }
    Button& get(const std::string& url) { hx_get_ = url; return *this; }
    Button& post(const std::string& url) { hx_post_ = url; return *this; }
    Button& target(const std::string& t) { hx_target_ = t; return *this; }
    Button& swap(const std::string& s) { hx_swap_ = s; return *this; }
    Button& trigger(const std::string& t) { hx_trigger_ = t; return *this; }

    std::string render() const override {
        std::ostringstream html;
        std::string cls = "ew-button ew-button-" + variant_;
        if (!classes_.empty()) cls += " " + classes_;
        html << "<button class=\"" << cls << "\"" << render_attributes() << ">";
        html << label_;
        html << "</button>";
        return html.str();
    }
};

class Link : public Component {
public:
    std::string label_;
    std::string href_;

    Link() = default;
    Link(const std::string& label, const std::string& href) : label_(label), href_(href) {}

    Link& label(const std::string& l) { label_ = l; return *this; }
    Link& href(const std::string& h) { href_ = h; return *this; }
    Link& id(const std::string& i) { id_ = i; return *this; }
    Link& classes(const std::string& c) { classes_ = c; return *this; }

    std::string render() const override {
        std::ostringstream html;
        std::string cls = "ew-link";
        if (!classes_.empty()) cls += " " + classes_;
        html << "<a href=\"" << href_ << "\" class=\"" << cls << "\"" << render_attributes() << ">";
        html << label_;
        html << "</a>";
        return html.str();
    }
};

// ============================================================================
// Form Components
// ============================================================================

class Input : public Component {
public:
    std::string name_;
    std::string type_ = "text";
    std::string placeholder_;
    std::string value_;
    std::string label_text_;

    Input() = default;
    explicit Input(const std::string& name) : name_(name) {}

    Input& name(const std::string& n) { name_ = n; return *this; }
    Input& type(const std::string& t) { type_ = t; return *this; }
    Input& placeholder(const std::string& p) { placeholder_ = p; return *this; }
    Input& value(const std::string& v) { value_ = v; return *this; }
    Input& label(const std::string& l) { label_text_ = l; return *this; }
    Input& id(const std::string& i) { id_ = i; return *this; }
    Input& classes(const std::string& c) { classes_ = c; return *this; }

    std::string render() const override {
        std::ostringstream html;
        std::string input_id = id_.empty() ? name_ : id_;

        if (!label_text_.empty()) {
            html << "<div class=\"ew-form-group\">";
            html << "<label class=\"ew-label\" for=\"" << input_id << "\">" << label_text_ << "</label>";
        }

        std::string cls = "ew-input";
        if (!classes_.empty()) cls += " " + classes_;

        html << "<input type=\"" << type_ << "\" name=\"" << name_ << "\"";
        html << " id=\"" << input_id << "\" class=\"" << cls << "\"";
        if (!placeholder_.empty()) html << " placeholder=\"" << placeholder_ << "\"";
        if (!value_.empty()) html << " value=\"" << value_ << "\"";
        html << render_attributes() << ">";

        if (!label_text_.empty()) {
            html << "</div>";
        }

        return html.str();
    }
};

// ============================================================================
// Layout Components (Containers)
// ============================================================================

class Box : public Component {
public:
    std::vector<ComponentPtr> children_;

    Box() = default;

    template<typename T>
    Box& add(T&& component) {
        children_.push_back(make_component(std::forward<T>(component)));
        return *this;
    }

    Box& id(const std::string& i) { id_ = i; return *this; }
    Box& classes(const std::string& c) { classes_ = c; return *this; }

    // HTMX attributes
    Box& get(const std::string& url) { hx_get_ = url; return *this; }
    Box& post(const std::string& url) { hx_post_ = url; return *this; }
    Box& target(const std::string& t) { hx_target_ = t; return *this; }
    Box& swap(const std::string& s) { hx_swap_ = s; return *this; }
    Box& trigger(const std::string& t) { hx_trigger_ = t; return *this; }
    Box& ext(const std::string& e) { hx_ext_ = e; return *this; }
    Box& vals(const std::string& v) { hx_vals_ = v; return *this; }

    // SSE attributes
    Box& sse_connect(const std::string& url) { hx_ext_ = "sse"; sse_connect_ = url; return *this; }
    Box& sse_swap(const std::string& event) { sse_swap_ = event; return *this; }
    Box& sse_close(const std::string& event) { sse_close_ = event; return *this; }

    std::string render() const override {
        std::ostringstream html;
        std::string cls = "ew-box";
        if (!classes_.empty()) cls += " " + classes_;
        html << "<div class=\"" << cls << "\"" << render_attributes() << ">";
        html << render_children(children_);
        html << "</div>";
        return html.str();
    }
};

class Card : public Component {
public:
    std::string title_;
    std::vector<ComponentPtr> children_;
    bool compact_ = false;
    bool accent_ = false;
    std::string border_color_;

    Card() = default;

    template<typename T>
    Card& add(T&& component) {
        children_.push_back(make_component(std::forward<T>(component)));
        return *this;
    }

    Card& title(const std::string& t) { title_ = t; return *this; }
    Card& compact() { compact_ = true; return *this; }
    Card& accent() { accent_ = true; return *this; }
    Card& border(const std::string& color) { border_color_ = color; return *this; }
    Card& mobile_full() { classes_ += " ew-card-mobile-full"; return *this; }
    Card& id(const std::string& i) { id_ = i; return *this; }
    Card& classes(const std::string& c) { classes_ = c; return *this; }

    std::string render() const override {
        std::ostringstream html;
        std::string cls = "ew-card";
        if (compact_) cls += " ew-card-compact";
        if (accent_) cls += " ew-card-accent";
        if (!classes_.empty()) cls += " " + classes_;
        html << "<div class=\"" << cls << "\"";
        if (!border_color_.empty()) {
            html << " style=\"border-color: " << border_color_ << ";\"";
        }
        html << render_attributes() << ">";
        if (!title_.empty()) {
            html << "<div class=\"ew-card-title\">" << title_ << "</div>";
        }
        html << render_children(children_);
        html << "</div>";
        return html.str();
    }
};

class Row : public Component {
public:
    std::vector<ComponentPtr> children_;
    bool wrap_ = false;
    std::string gap_;

    Row() = default;

    template<typename T>
    Row& add(T&& component) {
        children_.push_back(make_component(std::forward<T>(component)));
        return *this;
    }

    Row& wrap() { wrap_ = true; return *this; }
    Row& gap(const std::string& g) { gap_ = g; return *this; }
    Row& stack_mobile() { classes_ += " ew-row-mobile-stack"; return *this; }
    Row& center_mobile() { classes_ += " ew-center-mobile"; return *this; }
    Row& id(const std::string& i) { id_ = i; return *this; }
    Row& classes(const std::string& c) { classes_ = c; return *this; }

    std::string render() const override {
        std::ostringstream html;
        std::string cls = "ew-row";
        if (wrap_) cls += " ew-row-wrap";
        if (gap_ == "sm") cls += " ew-gap-sm";
        else if (gap_ == "lg") cls += " ew-gap-lg";
        else if (gap_ == "xl") cls += " ew-gap-xl";
        if (!classes_.empty()) cls += " " + classes_;
        html << "<div class=\"" << cls << "\"" << render_attributes() << ">";
        html << render_children(children_);
        html << "</div>";
        return html.str();
    }
};

class Column : public Component {
public:
    std::vector<ComponentPtr> children_;
    std::string gap_;

    Column() = default;

    template<typename T>
    Column& add(T&& component) {
        children_.push_back(make_component(std::forward<T>(component)));
        return *this;
    }

    Column& gap(const std::string& g) { gap_ = g; return *this; }
    Column& id(const std::string& i) { id_ = i; return *this; }
    Column& classes(const std::string& c) { classes_ = c; return *this; }

    std::string render() const override {
        std::ostringstream html;
        std::string cls = "ew-column";
        if (gap_ == "sm") cls += " ew-gap-sm";
        else if (gap_ == "lg") cls += " ew-gap-lg";
        else if (gap_ == "xl") cls += " ew-gap-xl";
        if (!classes_.empty()) cls += " " + classes_;
        html << "<div class=\"" << cls << "\"" << render_attributes() << ">";
        html << render_children(children_);
        html << "</div>";
        return html.str();
    }
};

class Grid : public Component {
public:
    std::vector<ComponentPtr> children_;
    int columns_ = 2;
    bool responsive_ = false;

    Grid() = default;

    template<typename T>
    Grid& add(T&& component) {
        children_.push_back(make_component(std::forward<T>(component)));
        return *this;
    }

    Grid& columns(int c) { columns_ = c; return *this; }
    Grid& responsive(bool r = true) { responsive_ = r; return *this; }
    Grid& id(const std::string& i) { id_ = i; return *this; }
    Grid& classes(const std::string& c) { classes_ = c; return *this; }

    std::string render() const override {
        std::ostringstream html;
        std::string cls = responsive_ ? "ew-grid-responsive" : "ew-grid";
        if (!responsive_) {
            if (columns_ == 2) cls += " ew-grid-2";
            else if (columns_ == 3) cls += " ew-grid-3";
            else if (columns_ == 4) cls += " ew-grid-4";
        }
        if (!classes_.empty()) cls += " " + classes_;
        html << "<div class=\"" << cls << "\"" << render_attributes() << ">";
        html << render_children(children_);
        html << "</div>";
        return html.str();
    }
};

class Form : public Component {
public:
    std::vector<ComponentPtr> children_;
    std::string action_;
    std::string method_ = "post";

    Form() = default;

    template<typename T>
    Form& add(T&& component) {
        children_.push_back(make_component(std::forward<T>(component)));
        return *this;
    }

    Form& action(const std::string& a) { action_ = a; return *this; }
    Form& method(const std::string& m) { method_ = m; return *this; }
    Form& id(const std::string& i) { id_ = i; return *this; }
    Form& classes(const std::string& c) { classes_ = c; return *this; }
    Form& post(const std::string& url) { hx_post_ = url; return *this; }
    Form& get(const std::string& url) { hx_get_ = url; return *this; }
    Form& target(const std::string& t) { hx_target_ = t; return *this; }
    Form& swap(const std::string& s) { hx_swap_ = s; return *this; }

    std::string render() const override {
        std::ostringstream html;
        html << "<form";
        if (!action_.empty()) html << " action=\"" << action_ << "\"";
        html << " method=\"" << method_ << "\"";
        html << render_attributes() << ">";
        html << render_children(children_);
        html << "</form>";
        return html.str();
    }
};

// ============================================================================
// Navigation Components
// ============================================================================

// NavItem for navbar links
class NavItem : public Component {
public:
    std::string label_;
    std::string href_ = "#";
    bool active_ = false;

    NavItem() = default;
    explicit NavItem(const std::string& label) : label_(label) {}

    NavItem& label(const std::string& l) { label_ = l; return *this; }
    NavItem& href(const std::string& h) { href_ = h; return *this; }
    NavItem& active() { active_ = true; return *this; }

    std::string render() const override {
        std::string cls = "ew-navbar-item";
        if (active_) cls += " ew-navbar-item-active";
        return "<a href=\"" + href_ + "\" class=\"" + cls + "\">" + label_ + "</a>";
    }
};

// Navbar component
class Navbar : public Component {
public:
    std::string brand_;
    std::vector<ComponentPtr> nav_items_;
    std::vector<ComponentPtr> actions_;

    Navbar() = default;

    Navbar& brand(const std::string& b) { brand_ = b; return *this; }

    template<typename T>
    Navbar& add(T&& item) {
        nav_items_.push_back(make_component(std::forward<T>(item)));
        return *this;
    }

    template<typename T>
    Navbar& addAction(T&& action) {
        actions_.push_back(make_component(std::forward<T>(action)));
        return *this;
    }

    std::string render() const override {
        std::ostringstream html;
        html << "<nav class=\"ew-navbar\">";
        html << "<a href=\"#\" class=\"ew-navbar-brand\">" << brand_ << "</a>";
        html << "<div class=\"ew-navbar-nav\">";
        html << render_children(nav_items_);
        html << "</div>";
        if (!actions_.empty()) {
            html << "<div class=\"ew-navbar-actions\">";
            html << render_children(actions_);
            html << "</div>";
        }
        html << "</nav>";
        return html.str();
    }
};

// SidebarItem for sidebar links
class SidebarItem : public Component {
public:
    std::string label_;
    std::string href_ = "#";
    bool active_ = false;

    SidebarItem() = default;
    explicit SidebarItem(const std::string& label) : label_(label) {}

    SidebarItem& label(const std::string& l) { label_ = l; return *this; }
    SidebarItem& href(const std::string& h) { href_ = h; return *this; }
    SidebarItem& active() { active_ = true; return *this; }

    std::string render() const override {
        std::string cls = "ew-sidebar-item";
        if (active_) cls += " ew-sidebar-item-active";
        return "<a href=\"" + href_ + "\" class=\"" + cls + "\">" + label_ + "</a>";
    }
};

// SidebarSection for grouping sidebar items
class SidebarSection : public Component {
public:
    std::string title_;
    std::vector<ComponentPtr> items_;

    SidebarSection() = default;
    explicit SidebarSection(const std::string& title) : title_(title) {}

    SidebarSection& title(const std::string& t) { title_ = t; return *this; }

    template<typename T>
    SidebarSection& add(T&& item) {
        items_.push_back(make_component(std::forward<T>(item)));
        return *this;
    }

    std::string render() const override {
        std::ostringstream html;
        html << "<div class=\"ew-sidebar-section\">";
        if (!title_.empty()) {
            html << "<div class=\"ew-sidebar-title\">" << title_ << "</div>";
        }
        html << "<nav class=\"ew-sidebar-nav\">";
        html << render_children(items_);
        html << "</nav>";
        html << "</div>";
        return html.str();
    }
};

// Sidebar component
class Sidebar : public Component {
public:
    std::vector<ComponentPtr> sections_;

    Sidebar() = default;

    template<typename T>
    Sidebar& add(T&& section) {
        sections_.push_back(make_component(std::forward<T>(section)));
        return *this;
    }

    std::string render() const override {
        std::ostringstream html;
        html << "<aside class=\"ew-sidebar\">";
        html << render_children(sections_);
        html << "</aside>";
        return html.str();
    }
};

// Main content area
class Main : public Component {
public:
    std::vector<ComponentPtr> children_;

    Main() = default;

    template<typename T>
    Main& add(T&& component) {
        children_.push_back(make_component(std::forward<T>(component)));
        return *this;
    }

    Main& id(const std::string& i) { id_ = i; return *this; }
    Main& classes(const std::string& c) { classes_ = c; return *this; }

    std::string render() const override {
        std::ostringstream html;
        std::string cls = "ew-main";
        if (!classes_.empty()) cls += " " + classes_;
        html << "<main class=\"" << cls << "\"" << render_attributes() << ">";
        html << render_children(children_);
        html << "</main>";
        return html.str();
    }
};

// App layout wrapper
class App : public Component {
public:
    ComponentPtr navbar_;
    ComponentPtr sidebar_;
    std::vector<ComponentPtr> children_;

    App() = default;

    template<typename T>
    App& navbar(T&& nav) {
        navbar_ = make_component(std::forward<T>(nav));
        return *this;
    }

    template<typename T>
    App& sidebar(T&& side) {
        sidebar_ = make_component(std::forward<T>(side));
        return *this;
    }

    template<typename T>
    App& add(T&& component) {
        children_.push_back(make_component(std::forward<T>(component)));
        return *this;
    }

    std::string render() const override {
        std::ostringstream html;
        html << "<div class=\"ew-app\">";
        if (navbar_) html << navbar_->render();
        html << "<div class=\"ew-app-body\">";
        if (sidebar_) html << sidebar_->render();
        html << "<main class=\"ew-main\">";
        html << render_children(children_);
        html << "</main>";
        html << "</div>";
        html << "</div>";
        return html.str();
    }
};

// ============================================================================
// Page Component (Root)
// ============================================================================

// Theme mode enum (forward declare, defined in styles.hpp)
enum class ThemeMode;

class Page : public Component {
public:
    std::vector<ComponentPtr> children_;
    std::string title_;
    bool include_htmx_ = true;
    int theme_mode_ = 0; // 0=Dark, 1=Light, 2=Cream

    Page() = default;
    explicit Page(const std::string& title) : title_(title) {}

    template<typename T>
    Page& add(T&& component) {
        children_.push_back(make_component(std::forward<T>(component)));
        return *this;
    }

    Page& title(const std::string& t) { title_ = t; return *this; }
    Page& no_htmx() { include_htmx_ = false; return *this; }
    Page& dark_mode() { theme_mode_ = 0; return *this; }
    Page& light_mode() { theme_mode_ = 1; return *this; }
    Page& cream_mode() { theme_mode_ = 2; return *this; }
    Page& with_sse() { include_sse_ = true; return *this; }

    std::string render() const override;
    std::string render_fragment() const { return render_children(children_); }
    void render_to_file(const std::string& path) const;

    bool include_sse_ = false;
};

// ============================================================================
// Chat/Streaming Components
// ============================================================================

class ChatMessage : public Component {
public:
    std::string content_;
    bool is_user_ = false;
    bool is_streaming_ = false;

    ChatMessage() = default;
    explicit ChatMessage(const std::string& content) : content_(content) {}

    ChatMessage& content(const std::string& c) { content_ = c; return *this; }
    ChatMessage& user() { is_user_ = true; return *this; }
    ChatMessage& assistant() { is_user_ = false; return *this; }
    ChatMessage& streaming() { is_streaming_ = true; return *this; }
    ChatMessage& id(const std::string& i) { id_ = i; return *this; }
    ChatMessage& classes(const std::string& c) { classes_ = c; return *this; }

    std::string render() const override {
        std::ostringstream html;
        std::string cls = "ew-chat-message";
        if (is_user_) cls += " ew-chat-message-user";
        else cls += " ew-chat-message-assistant";
        if (is_streaming_) cls += " ew-chat-message-streaming";
        if (!classes_.empty()) cls += " " + classes_;
        html << "<div class=\"" << cls << "\"" << render_attributes() << ">";
        html << "<div class=\"ew-chat-message-content\">" << content_ << "</div>";
        html << "</div>";
        return html.str();
    }
};

class ChatInput : public Component {
public:
    std::string placeholder_ = "Type a message...";
    std::string endpoint_ = "/chat";
    std::string session_id_;
    std::string target_ = "#chat-response";

    ChatInput() = default;

    ChatInput& placeholder(const std::string& p) { placeholder_ = p; return *this; }
    ChatInput& endpoint(const std::string& e) { endpoint_ = e; return *this; }
    ChatInput& session(const std::string& s) { session_id_ = s; return *this; }
    ChatInput& target(const std::string& t) { target_ = t; return *this; }
    ChatInput& id(const std::string& i) { id_ = i; return *this; }
    ChatInput& classes(const std::string& c) { classes_ = c; return *this; }

    std::string render() const override {
        std::ostringstream html;
        std::string cls = "ew-chat-input-container";
        if (!classes_.empty()) cls += " " + classes_;

        html << "<form class=\"" << cls << "\"";
        html << " hx-post=\"" << endpoint_ << "\"";
        html << " hx-target=\"" << target_ << "\"";
        html << " hx-swap=\"beforeend\"";
        if (!session_id_.empty()) {
            html << " hx-vals='{\"session_id\":\"" << session_id_ << "\"}'";
        }
        html << render_attributes() << ">";
        html << "<input type=\"text\" name=\"message\" class=\"ew-input ew-chat-input\" placeholder=\"" << placeholder_ << "\" autocomplete=\"off\">";
        html << "<button type=\"submit\" class=\"ew-button ew-button-primary\">Send</button>";
        html << "</form>";
        return html.str();
    }
};

class ChatStream : public Component {
public:
    std::string session_id_;
    std::string endpoint_ = "/chat/stream";
    std::string event_name_ = "message";
    std::string close_event_ = "done";
    std::vector<ComponentPtr> children_;

    ChatStream() = default;

    template<typename T>
    ChatStream& add(T&& component) {
        children_.push_back(make_component(std::forward<T>(component)));
        return *this;
    }

    ChatStream& session(const std::string& s) { session_id_ = s; return *this; }
    ChatStream& endpoint(const std::string& e) { endpoint_ = e; return *this; }
    ChatStream& event(const std::string& e) { event_name_ = e; return *this; }
    ChatStream& close_on(const std::string& e) { close_event_ = e; return *this; }
    ChatStream& id(const std::string& i) { id_ = i; return *this; }
    ChatStream& classes(const std::string& c) { classes_ = c; return *this; }

    std::string render() const override {
        std::ostringstream html;
        std::string cls = "ew-chat-stream";
        if (!classes_.empty()) cls += " " + classes_;

        // Build the SSE URL
        std::string sse_url = endpoint_;
        if (!session_id_.empty()) {
            sse_url += "?session_id=" + session_id_;
        }

        html << "<div class=\"" << cls << "\"";
        html << " hx-ext=\"sse\"";
        html << " sse-connect=\"" << sse_url << "\"";
        if (!close_event_.empty()) {
            html << " sse-close=\"" << close_event_ << "\"";
        }
        html << render_attributes() << ">";

        // Inner div that receives the streamed content
        html << "<div class=\"ew-chat-stream-content\"";
        html << " sse-swap=\"" << event_name_ << "\"";
        html << " hx-swap=\"beforeend\">";
        html << render_children(children_);
        html << "</div>";

        html << "</div>";
        return html.str();
    }
};

class ChatContainer : public Component {
public:
    std::string session_id_;
    std::string chat_endpoint_ = "/chat";
    std::string stream_endpoint_ = "/chat/stream";
    std::string placeholder_ = "Type a message...";
    std::vector<ComponentPtr> initial_messages_;

    ChatContainer() = default;

    template<typename T>
    ChatContainer& add_message(T&& component) {
        initial_messages_.push_back(make_component(std::forward<T>(component)));
        return *this;
    }

    ChatContainer& session(const std::string& s) { session_id_ = s; return *this; }
    ChatContainer& chat_endpoint(const std::string& e) { chat_endpoint_ = e; return *this; }
    ChatContainer& stream_endpoint(const std::string& e) { stream_endpoint_ = e; return *this; }
    ChatContainer& placeholder(const std::string& p) { placeholder_ = p; return *this; }
    ChatContainer& id(const std::string& i) { id_ = i; return *this; }
    ChatContainer& classes(const std::string& c) { classes_ = c; return *this; }

    std::string render() const override {
        std::ostringstream html;
        std::string cls = "ew-chat-container";
        if (!classes_.empty()) cls += " " + classes_;

        html << "<div class=\"" << cls << "\"" << render_attributes() << ">";

        // Messages area with SSE streaming
        html << "<div class=\"ew-chat-messages\" id=\"chat-messages\"";
        html << " hx-ext=\"sse\"";
        std::string sse_url = stream_endpoint_;
        if (!session_id_.empty()) {
            sse_url += "?session_id=" + session_id_;
        }
        html << " sse-connect=\"" << sse_url << "\"";
        html << " sse-close=\"done\">";

        // Initial messages
        html << render_children(initial_messages_);

        // Response area for streamed content
        html << "<div id=\"chat-response\" sse-swap=\"message\" hx-swap=\"beforeend\"></div>";

        html << "</div>";

        // Input form
        html << "<form class=\"ew-chat-input-container\"";
        html << " hx-post=\"" << chat_endpoint_ << "\"";
        html << " hx-target=\"#chat-response\"";
        html << " hx-swap=\"beforeend\"";
        if (!session_id_.empty()) {
            html << " hx-vals='{\"session_id\":\"" << session_id_ << "\"}'";
        }
        html << ">";
        html << "<input type=\"text\" name=\"message\" class=\"ew-input ew-chat-input\" placeholder=\"" << placeholder_ << "\" autocomplete=\"off\">";
        html << "<button type=\"submit\" class=\"ew-button ew-button-primary\">Send</button>";
        html << "</form>";

        html << "</div>";
        return html.str();
    }
};

}
