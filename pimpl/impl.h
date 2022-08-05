#include "widget.h"

class widget::impl
{
  public:
    // impl() = default;
    impl(std::string name) : name{name} {}

    std::string get_name() const { return name; }

  private:
    const std::string name{};
};

// widget::widget(std::string name) : pimpl{std::make_unique<impl>(name)}
widget::widget(std::string name) : pimpl{std::make_shared<impl>(name)}
{
}

std::string widget::get_name() const
{
    return pimpl->get_name();
}
