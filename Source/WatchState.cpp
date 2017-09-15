#include "WatchState.hpp"
#include "EWatch.hpp"
#include <iostream>

void WatchState::handle(const Event &p_event, EWatch& p_fsm)
{
    p_fsm.doStateOff(p_event);
}

