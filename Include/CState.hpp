#pragma once

#include "CEvent.hpp"
class EWatch;

class CState
{
public:
    CState() = default;
    virtual ~CState() = default;
    virtual void handle(const Event &p_event, EWatch& p_fsm) = 0;
};




