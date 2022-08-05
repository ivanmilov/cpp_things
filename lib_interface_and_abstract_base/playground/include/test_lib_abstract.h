#pragma once

#include "i_test_lib.h"

class TestLibAbstract : public ITestLib
{
  public:
    TestLibAbstract(std::string name, int version);
    std::string get_name() const override;
    int get_version() const override;

  protected:
    const std::string name{};
    const int version{};
};
