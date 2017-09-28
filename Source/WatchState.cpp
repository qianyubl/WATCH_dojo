#include "WatchState.hpp"
#include "EWatch.hpp"
#include <iostream>
#include "LCD.hpp"

void WatchState::handle(const Event &p_event, EWatch& p_fsm)
{
    p_fsm.doStateOff(p_event);
}

std::string WatchState::onSecond()
{
    std::string l_time =  m_time->getCurrentTime();

    return LCD::printIntergerOnScreen(l_time);

}

void WatchState::UpClick()
{
}

void WatchState::DownClick()
{
}


