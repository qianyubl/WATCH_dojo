#include "TimerState.hpp"
#include "EWatch.hpp"
#include <iostream>
#include "LCD.hpp"

void TimerState::handle(const Event &p_event, EWatch& p_fsm)
{
    p_fsm.doStateOn(p_event);
}

std::string TimerState::onSecond()
{
    if(m_upClickFlag)
    {
        m_currentTimerValue++;
    }

    return LCD::printIntergerOnScreen(std::to_string(m_currentTimerValue));

}

void TimerState::UpClick()
{
    m_upClickFlag = !m_upClickFlag;
}

void TimerState::DownClick()
{
    m_upClickFlag = false;
    m_currentTimerValue = 0;
}


