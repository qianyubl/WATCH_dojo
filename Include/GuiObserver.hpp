#pragma once

#include "IWatchObserver.hpp"
#include <Fsm.hpp>

class GuiObserver : public IWatchObserver
{
public:
    GuiObserver();
    void onSwitchClick();
    void onUpClick();
    void onDownClick();
    std::string onSecond();
};



