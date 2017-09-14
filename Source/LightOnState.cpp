#include "LightOnState.hpp"
#include "LightBulb.hpp"
#include <iostream>

void LightOnState::handle(const Event &p_event, LightBulb& p_fsm)
{
    p_fsm.doStateOn(p_event);
    std::cout << "### Handle light state On" << std::endl;
}
