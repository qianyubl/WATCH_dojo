#ifndef LIGHTOFF_HPP
#define LIGHTOFF_HPP
#include "CState.hpp"

class LightOffState : public CState
{
public:
    void handle(const Event &p_event, LightBulb& p_fsm);
};

#endif