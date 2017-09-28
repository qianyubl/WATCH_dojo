#include "WatchState.hpp"
#include "EWatch.hpp"
#include <iostream>

void WatchState::handle(const Event &p_event, EWatch& p_fsm)
{
    p_fsm.doStateOff(p_event);
}

std::string WatchState::onSecond()
{
    return m_time->getCurrentTime();
}

void WatchState::UpClick()
{
}

void WatchState::DownClick()
{
}


