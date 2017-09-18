#include "EWatch.hpp"
#include <gmock/gmock.h>
#include "GuiObserver.hpp"
#include "TimeMock.hpp"

using namespace ::testing;
class WatchTestSuite : public Test
{
public:
    WatchTestSuite():watchGui(fsm){}
    std::shared_ptr<EWatch> fsm{std::make_shared<EWatch>()};
    GuiObserver watchGui;
    TimeMock m_TimeMock;
};


TEST_F(WatchTestSuite, TheDefaultEWatchIsTimer)
{
    EXPECT_EQ(fsm->m_stateTimer, fsm->getCurrState());
}

TEST_F(WatchTestSuite, switchEWatchWhenEWatchIsTimer)
{
    fsm->process(Event::Switch);
    EXPECT_EQ(fsm->m_stateWatch, fsm->getCurrState());
}

TEST_F(WatchTestSuite, switchEWatchWhenEWatchIsWatch)
{
    fsm->process(Event::Switch);
    fsm->process(Event::Switch);
    EXPECT_EQ(fsm->m_stateTimer, fsm->getCurrState());
}

TEST_F(WatchTestSuite, TheDefaultValueIsZeroForTimer)
{
    EXPECT_EQ("0", watchGui.onSecond());
}

TEST_F(WatchTestSuite, TheTimerValueIncrementedWhenUpinkClickedOnce)
{
    watchGui.onUpClick();
    EXPECT_EQ("1", watchGui.onSecond());
    EXPECT_EQ("2", watchGui.onSecond());
}

TEST_F(WatchTestSuite, SecondPressUpShouldStopTimer)
{
    watchGui.onUpClick();
    EXPECT_EQ("1", watchGui.onSecond());
    EXPECT_EQ("2", watchGui.onSecond());
    watchGui.onUpClick();
    EXPECT_EQ("2", watchGui.onSecond());
    EXPECT_EQ("2", watchGui.onSecond());
}

TEST_F(WatchTestSuite, FirstPressDownShouldResetTimer)
{
    watchGui.onUpClick();
    EXPECT_EQ("1", watchGui.onSecond());
    EXPECT_EQ("2", watchGui.onSecond());

    watchGui.onDownClick();
    EXPECT_EQ("0", watchGui.onSecond());
}

TEST_F(WatchTestSuite, FirstClickSwitchShouldGoToWatchState)
{
    EXPECT_EQ(fsm->m_stateTimer, fsm->getCurrState());
    watchGui.onSwitchClick();
    EXPECT_EQ(fsm->m_stateWatch, fsm->getCurrState());
}


TEST_F(WatchTestSuite, SecondClickSwitchShouldGoToTimerState)
{
    EXPECT_EQ(fsm->m_stateTimer, fsm->getCurrState());
    watchGui.onSwitchClick();
    watchGui.onSwitchClick();
    EXPECT_EQ(fsm->m_stateTimer, fsm->getCurrState());
}


TEST_F(WatchTestSuite, WatchStateAndShowTime)
{
//m_TimeMock
    EXPECT_EQ(fsm->m_stateTimer, fsm->getCurrState());
    watchGui.onSwitchClick();
    EXPECT_EQ(fsm->m_stateWatch, fsm->getCurrState());
    EXPECT_CALL(m_TimeMock, getCurrentTime()).WillOnce(Return("13:45"));
    watchGui.onSecond();
}

