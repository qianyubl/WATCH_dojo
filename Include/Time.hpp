#pragma once
#include "ITime.hpp"

class Time : public ITime
{
public:
    std::string getCurrentTime();
};