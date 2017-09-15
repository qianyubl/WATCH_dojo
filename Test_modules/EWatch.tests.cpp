#include "EWatch.hpp"
#include <gmock/gmock.h>
#include "GuiObserver.hpp"

using namespace ::testing;

namespace {

TEST(EWatchTests, TheDefaultEWatchIsTimer)
{
    EWatch fsm;
    EXPECT_EQ(fsm.m_stateTimer, fsm.getCurrState());
}

TEST(EWatchTests, switchEWatchWhenEWatchIsTimer)
{
    EWatch fsm;
    fsm.process(Event::Switch);
    EXPECT_EQ(fsm.m_stateWatch, fsm.getCurrState());
}

TEST(EWatchTests, switchEWatchWhenEWatchIsWatch)
{
    EWatch fsm;
    fsm.process(Event::Switch);
    fsm.process(Event::Switch);
    EXPECT_EQ(fsm.m_stateTimer, fsm.getCurrState());
}

TEST(EWatchTests, TheDefaultValueIsZeroForTimer)
{
    GuiObserver watchGui;
    EXPECT_EQ("0", watchGui.onSecond());
}

TEST(EWatchTests, TheTimerValueIncrementedWhenUpinkClickedOnce)
{
    GuiObserver watchGui;
    watchGui.onUpClick();
    EXPECT_EQ("1", watchGui.onSecond());
    EXPECT_EQ("2", watchGui.onSecond());
}

TEST(EWatchTests, SecondPressUpShouldStopTimer)
{
    GuiObserver watchGui;
    watchGui.onUpClick();
    EXPECT_EQ("1", watchGui.onSecond());
    EXPECT_EQ("2", watchGui.onSecond());
    watchGui.onUpClick();
    EXPECT_EQ("2", watchGui.onSecond());
    EXPECT_EQ("2", watchGui.onSecond());
}

}
