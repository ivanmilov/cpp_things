#pragma once

#include <string>

class ITestLib
{
  public:
    virtual ~ITestLib() = default;
    virtual std::string get_name() const = 0;
    virtual int get_version() const = 0;
};
