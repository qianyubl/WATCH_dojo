#include <GuiObserver.hpp>

void GuiObserver::onSwitchClick()
{
}

void GuiObserver::onUpClick()
{
    m_upClickFlag = !m_upClickFlag;
}

void GuiObserver::onDownClick()
{
}

std::string GuiObserver::onSecond()
{
    if(m_upClickFlag)
    {
        m_currentTimerValue++;
    }

    return std::to_string(m_currentTimerValue);
}


