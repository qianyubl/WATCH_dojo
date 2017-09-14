#ifndef STATE_HPP
#define STATE_HPP

#include "CEvent.hpp"
class LightBulb;

class CState
{
public:
    CState() = default;
    virtual ~CState() = default;
    virtual void handle(const Event &p_event, LightBulb& p_fsm) = 0;
};

#endif


