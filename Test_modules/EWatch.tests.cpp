#include "EWatch.hpp"
#include <gmock/gmock.h>

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

}