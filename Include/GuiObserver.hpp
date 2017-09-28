#pragma once

#include "IWatchObserver.hpp"
#include <EWatch.hpp>

class GuiObserver : public IWatchObserver
{
public:
    explicit GuiObserver(std::shared_ptr<EWatch> p_fsm):m_watchFsm(p_fsm){}
    void onSwitchClick();
    void onUpClick();
    void onDownClick();
    std::string onSecond();

private:
    std::shared_ptr<EWatch> m_watchFsm;
};



