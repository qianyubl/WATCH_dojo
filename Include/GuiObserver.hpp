#pragma once

#include "IWatchObserver.hpp"
//#include <Fsm.hpp>

class GuiObserver : public IWatchObserver
{
public:
    GuiObserver():m_currentTimerValue(0),m_upClickFlag(false){}
    void onSwitchClick();
    void onUpClick();
    void onDownClick();
    std::string onSecond();

private:
    int m_currentTimerValue;
    bool m_upClickFlag;
};



