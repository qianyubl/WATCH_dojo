#pragma once
#include "CState.hpp"
#include

class WatchState : public CState
{
public:
    void handle(const Event &p_event, EWatch& p_fsm);
    std::string onSecond();
    void UpClick();
    void DownClick();
    void registerTime(ITime p_time);
private:
    ITime *m_time;
};
