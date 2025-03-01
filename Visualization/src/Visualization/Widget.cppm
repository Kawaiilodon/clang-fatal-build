module;

export module Visualization:Widget;
import :WidgetGuard;

export namespace visual {

class Widget {
public:
    Widget(const std::string& name) :
        m_name(name)
    {}
    virtual ~Widget() = default;

    virtual void draw() {
        helpers::WidgetGuard guard{m_name};
        draw_content();
    }

    virtual void draw_content() = 0;
private:
    std::string m_name;
};

}