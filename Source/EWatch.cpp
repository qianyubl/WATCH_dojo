#include "EWatch.hpp"
#include <iostream>

using namespace std;

void EWatch::process(const Event &p_event)
{
    m_currState->handle(p_event, *this);
}

shared_ptr<CState> EWatch::getCurrState() const
{
    return m_currState;
}

void EWatch::stateTransition(shared_ptr<CState> p_state)
{
    m_currState = p_state;
}

void EWatch::doStateOn(const Event &p_event)
{
    if(Event::Switch == p_event)
    {
        stateTransition(m_stateWatch);
    }
}

void EWatch::doStateOff(const Event &p_event)
{
    if(Event::Switch == p_event)
    {
         stateTransition(m_stateTimer);
    }
}