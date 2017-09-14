#ifndef HIKER_INCLUDED
#define HIKER_INCLUDED
#include "CState.hpp"
#include "LightOnState.hpp"
#include "LightOffState.hpp"
#include <memory>


class LightBulb
{
public:
    LightBulb() {m_currState = m_stateOff;}
    ~LightBulb() = default;
    void process(const Event &p_event);
    std::shared_ptr<CState> getCurrState() const;
    std::shared_ptr<CState> m_stateOn{std::make_shared<LightOnState>()};
    std::shared_ptr<CState> m_stateOff{std::make_shared<LightOffState>()};
    void doStateOn(const Event &p_event);
    void doStateOff(const Event &p_event);
private:
    std::shared_ptr<CState> m_currState;

    void stateTransition(std::shared_ptr<CState> p_state);

};

#endif
