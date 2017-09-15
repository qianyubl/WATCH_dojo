#pragma once

#include "CState.hpp"

class TimerState : public CState
{
public:
    void handle(const Event &p_event, EWatch& p_fsm);
};

