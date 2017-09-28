#pragma once
#include <iostream>

class ITime
{
public:
    virtual std::string getCurrentTime() = 0;
};


