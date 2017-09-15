#include "TimerState.hpp"
#include "EWatch.hpp"
#include <iostream>

void TimerState::handle(const Event &p_event, EWatch& p_fsm)
{
    p_fsm.doStateOn(p_event);
}
