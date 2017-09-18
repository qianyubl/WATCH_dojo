#include "WatchState.hpp"
#include "EWatch.hpp"
#include <iostream>

void WatchState::handle(const Event &p_event, EWatch& p_fsm)
{
    p_fsm.doStateOff(p_event);
}

std::string WatchState::onSecond()
{
    return "";
}

void WatchState::UpClick()
{
}

void WatchState::DownClick()
{
}

void WatchState::registerTime(ITime p_time)
{
    m_time = p_time;
}


