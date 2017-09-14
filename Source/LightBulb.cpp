#include "LightBulb.hpp"
#include <iostream>

using namespace std;

void LightBulb::process(const Event &p_event)
{    
    m_currState->handle(p_event, *this);
}

shared_ptr<CState> LightBulb::getCurrState() const
{
    return m_currState;
}

void LightBulb::stateTransition(shared_ptr<CState> p_state)
{
    m_currState = p_state;
}

void LightBulb::doStateOn(const Event &p_event)
{   
    if(Event::TurnOff == p_event)
    {
        stateTransition(m_stateOff);
    }
}

void LightBulb::doStateOff(const Event &p_event)
{
    if(Event::TurnOn == p_event)
    {
         stateTransition(m_stateOn);
    }
}