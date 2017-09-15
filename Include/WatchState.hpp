#pragma once
#include "CState.hpp"

class WatchState : public CState
{
public:
    void handle(const Event &p_event, EWatch& p_fsm);
};
