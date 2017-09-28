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

TEST_F(WatchTestSuite, TheDefaultValueIsZeroForTimerAndShowOnLCD)
{
    EXPECT_EQ("._. \n|.| \n|_| ", m_watchGui.onSecond());
}

TEST_F(WatchTestSuite, TheTimerValueIncrementedWhenUpinkClickedOnceAndShowOnLCD)
{
    m_watchGui.onUpClick();
    EXPECT_EQ("... \n..| \n..| ", m_watchGui.onSecond());
    EXPECT_EQ("._. \n._| \n|_. ", m_watchGui.onSecond());
}

TEST_F(WatchTestSuite, SecondPressUpShouldStopTimerAndShowOnLCD)
{
    m_watchGui.onUpClick();
    EXPECT_EQ("... \n..| \n..| ", m_watchGui.onSecond());
    EXPECT_EQ("._. \n._| \n|_. ", m_watchGui.onSecond());
    m_watchGui.onUpClick();
    EXPECT_EQ("._. \n._| \n|_. ", m_watchGui.onSecond());
    EXPECT_EQ("._. \n._| \n|_. ", m_watchGui.onSecond());

}

TEST_F(WatchTestSuite, FirstPressDownShouldResetTimerAndShowOnLCD)
{
    m_watchGui.onUpClick();
    EXPECT_EQ("... \n..| \n..| ", m_watchGui.onSecond());
    EXPECT_EQ("._. \n._| \n|_. ", m_watchGui.onSecond());

    m_watchGui.onDownClick();
    EXPECT_EQ("._. \n|.| \n|_| ", m_watchGui.onSecond());
}

TEST_F(WatchTestSuite, TheTimerValueIncrementedWhenUpinkClickedOnceAndShowTwoNumberOnLCD)
{
    m_watchGui.onUpClick();
    for(int i = 0; i < 10; i++)
    {
       m_watchGui.onSecond();
    }
    EXPECT_EQ("... ... \n..| ..| \n..| ..| ",m_watchGui.onSecond());
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


TEST_F(WatchTestSuite, WatchStateAndShowTimeOnLCD)
{
    EXPECT_EQ(m_fsm->m_stateTimer, m_fsm->getCurrState());
    m_watchGui.onSwitchClick();
    EXPECT_EQ(m_fsm->m_stateWatch, m_fsm->getCurrState());
    EXPECT_CALL(*m_TimeMock, getCurrentTime()).WillOnce(Return("11:11"));
    EXPECT_EQ("... ... ._. ... ... \n..| ..| ... ..| ..| \n..| ..| .-. ..| ..| ",m_watchGui.onSecond());
}

TEST_F(WatchTestSuite, ShowCurrentTime)
{
    Time l_localtime;
    l_localtime.getCurrentTime();
}


