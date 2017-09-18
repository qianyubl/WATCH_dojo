#pragma once

#include "CState.hpp"

class TimerState : public CState
{
public:
    TimerState():m_upClickFlag(false), m_currentTimerValue(0){}
    void handle(const Event &p_event, EWatch& p_fsm);
    std::string onSecond();
    void UpClick();
    void DownClick();
private:
    bool m_upClickFlag;
    int m_currentTimerValue;
};

