#pragma once

#include "CEvent.hpp"
#include <string>
class EWatch;

class CState
{
public:
    CState() = default;
    virtual ~CState() = default;
    virtual void handle(const Event &p_event, EWatch& p_fsm) = 0;
    virtual std::string onSecond() = 0;
    virtual void UpClick() = 0;
    virtual void DownClick() = 0;
};




