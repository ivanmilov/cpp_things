#pragma once

#include <memory>
#include <string>

class widget
{
    //   protected:
    class impl;
    // std::unique_ptr<impl> pimpl;
    std::shared_ptr<impl> pimpl;

  public:
    std::string get_name() const;

    widget(std::string);
};
