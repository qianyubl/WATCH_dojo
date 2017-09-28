#include "EWatch.hpp"
#include <gmock/gmock.h>
#include "GuiObserver.hpp"
#include "TimeMock.hpp"
#include "Time.hpp"

using namespace ::testing;
class WatchTestSuite : public Test
{
public:
    WatchTestSuite():m_TimeMock(std::make_shared<TimeMock>()),
                         m_fsm(std::make_shared<EWatch>(m_TimeMock)),
                         m_watchGui(GuiObserver(m_fsm))
    {

    }
    std::shared_ptr<TimeMock> m_TimeMock;
    std::shared_ptr<EWatch> m_fsm;
    GuiObserver m_watchGui;
};


TEST_F(WatchTestSuite, TheDefaultEWatchIsTimer)
{
    EXPECT_EQ(m_fsm->m_stateTimer, m_fsm->getCurrState());
}

TEST_F(WatchTestSuite, switchEWatchWhenEWatchIsTimer)
{
    m_fsm->process(Event::Switch);
    EXPECT_EQ(m_fsm->m_stateWatch, m_fsm->getCurrState());
}

TEST_F(WatchTestSuite, switchEWatchWhenEWatchIsWatch)
{
    m_fsm->process(Event::Switch);
    m_fsm->process(Event::Switch);
    EXPECT_EQ(m_fsm->m_stateTimer, m_fsm->getCurrState());
}

TEST_F(WatchTestSuite, TheDefaultValueIsZeroForTimer)
{
    EXPECT_EQ("0", m_watchGui.onSecond());
}

TEST_F(WatchTestSuite, TheTimerValueIncrementedWhenUpinkClickedOnce)
{
    m_watchGui.onUpClick();
    EXPECT_EQ("1", m_watchGui.onSecond());
    EXPECT_EQ("2", m_watchGui.onSecond());
}

TEST_F(WatchTestSuite, SecondPressUpShouldStopTimer)
{
    m_watchGui.onUpClick();
    EXPECT_EQ("1", m_watchGui.onSecond());
    EXPECT_EQ("2", m_watchGui.onSecond());
    m_watchGui.onUpClick();
    EXPECT_EQ("2", m_watchGui.onSecond());
    EXPECT_EQ("2", m_watchGui.onSecond());
}

TEST_F(WatchTestSuite, FirstPressDownShouldResetTimer)
{
    m_watchGui.onUpClick();
    EXPECT_EQ("1", m_watchGui.onSecond());
    EXPECT_EQ("2", m_watchGui.onSecond());

    m_watchGui.onDownClick();
    EXPECT_EQ("0", m_watchGui.onSecond());
}

TEST_F(WatchTestSuite, FirstClickSwitchShouldGoToWatchState)
{
    EXPECT_EQ(m_fsm->m_stateTimer, m_fsm->getCurrState());
    m_watchGui.onSwitchClick();
    EXPECT_EQ(m_fsm->m_stateWatch, m_fsm->getCurrState());
}


TEST_F(WatchTestSuite, SecondClickSwitchShouldGoToTimerState)
{
    EXPECT_EQ(m_fsm->m_stateTimer, m_fsm->getCurrState());
    m_watchGui.onSwitchClick();
    m_watchGui.onSwitchClick();
    EXPECT_EQ(m_fsm->m_stateTimer, m_fsm->getCurrState());
}


TEST_F(WatchTestSuite, WatchStateAndShowTime)
{
    EXPECT_EQ(m_fsm->m_stateTimer, m_fsm->getCurrState());
    m_watchGui.onSwitchClick();
    EXPECT_EQ(m_fsm->m_stateWatch, m_fsm->getCurrState());
    EXPECT_CALL(*m_TimeMock, getCurrentTime()).WillOnce(Return("13:45"));
    m_watchGui.onSecond();
}

TEST_F(WatchTestSuite, ShowCurrentTime)
{
    Time l_localtime;
    l_localtime.getCurrentTime();
}


