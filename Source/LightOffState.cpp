#include "LightOffState.hpp"
#include "LightBulb.hpp"
#include <iostream>

void LightOffState::handle(const Event &p_event, LightBulb& p_fsm)
{
    p_fsm.doStateOff(p_event);
    std::cout << "### Handle light state Off" << std::endl;
}

