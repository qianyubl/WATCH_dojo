#include "GuiObserver.hpp"
#include "CEvent.hpp"
#include <cassert>

void GuiObserver::onSwitchClick()
{
    assert(m_watchFsm != nullptr);

    m_watchFsm->process(Event::Switch);
}

void GuiObserver::onUpClick()
{
    assert(m_watchFsm != nullptr);

    m_watchFsm->getCurrState()->UpClick();
}

void GuiObserver::onDownClick()
{
    assert(m_watchFsm != nullptr);

    m_watchFsm->getCurrState()->DownClick();
}

std::string GuiObserver::onSecond()
{
    assert(m_watchFsm != nullptr);

    return m_watchFsm->getCurrState()->onSecond();
}


