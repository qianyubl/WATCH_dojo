#pragma once

#include "CState.hpp"
#include "TimerState.hpp"
#include "WatchState.hpp"
#include "ITime.hpp"
#include <memory>


class EWatch
{
public:
    EWatch(std::shared_ptr<ITime> p_Timer)
        :m_stateTimer(std::make_shared<TimerState>()),
        m_stateWatch(std::make_shared<WatchState>(p_Timer))
    {
         m_currState = m_stateTimer;
    }
    ~EWatch() = default;
    void process(const Event &p_event);
    std::shared_ptr<CState> getCurrState() const;
    void doStateOn(const Event &p_event);
    void doStateOff(const Event &p_event);
    std::shared_ptr<CState> m_stateTimer;
    std::shared_ptr<CState> m_stateWatch;

private:
    std::shared_ptr<CState> m_currState;


    void stateTransition(std::shared_ptr<CState> p_state);

};

