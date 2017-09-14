#pragma once

#include "CState.hpp"

class LightOnState : public CState
{
public:
    void handle(const Event &p_event, LightBulb& p_fsm);
};

