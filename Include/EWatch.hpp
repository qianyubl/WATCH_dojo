#pragma once

#include "CState.hpp"
#include "TimerState.hpp"
#include "WatchState.hpp"
#include <memory>


class EWatch
{
public:
    EWatch(std::shared_ptr<CState> p_stateWatch) {m_currState = m_stateTimer; m_stateWatch = p_stateWatch;}
    ~EWatch() = default;
    void process(const Event &p_event);
    std::shared_ptr<CState> getCurrState() const;
    std::shared_ptr<CState> m_stateTimer{std::make_shared<TimerState>()};
    std::shared_ptr<CState> m_stateWatch{std::make_shared<WatchState>()};
    void doStateOn(const Event &p_event);
    void doStateOff(const Event &p_event);
private:
    std::shared_ptr<CState> m_currState;

    void stateTransition(std::shared_ptr<CState> p_state);

};

