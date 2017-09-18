#include <GuiObserver.hpp>
#include "CEvent.hpp"

void GuiObserver::onSwitchClick()
{
    if(m_watchFsm != nullptr)
    {
        m_watchFsm->process(Event::Switch);
    }
}

void GuiObserver::onUpClick()
{
    if(m_watchFsm != nullptr)
    {
        m_watchFsm->getCurrState()->UpClick();
    }
}

void GuiObserver::onDownClick()
{
    if(m_watchFsm != nullptr)
    {
        m_watchFsm->getCurrState()->DownClick();
    }
}

std::string GuiObserver::onSecond()
{
    if(m_watchFsm != nullptr)
    {
        return m_watchFsm->getCurrState()->onSecond();
    }
}


