#pragma once
#include "CState.hpp"
#include "ITime.hpp"
#include <memory>

class WatchState : public CState
{
public:
    WatchState(std::shared_ptr<ITime> p_time):m_time(p_time){}
    void handle(const Event &p_event, EWatch& p_fsm);
    std::string onSecond();
    void UpClick();
    void DownClick();
private:
    std::shared_ptr<ITime> m_time;
};
