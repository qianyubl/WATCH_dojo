#include "LightBulb.hpp"
#include <gmock/gmock.h>

using namespace ::testing;

namespace {

TEST(LightBulbTests, TheDefaultLightBulbIsOff)
{
    LightBulb fsm;
    EXPECT_EQ(fsm.m_stateOff, fsm.getCurrState());
}

TEST(LightBulbTests, TurnOnTheLightBulbWhenTheLightBulbIsOff)
{
    LightBulb fsm;
    fsm.process(Event::TurnOn);
    EXPECT_EQ(fsm.m_stateOn, fsm.getCurrState());
}

TEST(LightBulbTests, TurnOffTheLightBulbWhenTheLightBulbIsOn)
{
    LightBulb fsm;
    fsm.process(Event::TurnOn);
     fsm.process(Event::TurnOff);
    EXPECT_EQ(fsm.m_stateOff, fsm.getCurrState());
}
    
TEST(LightBulbTests, TurnOffTheLightBulbWhenTheLightBulbIsOff)
{
    LightBulb fsm;
    fsm.process(Event::TurnOff);
    EXPECT_EQ(fsm.m_stateOff, fsm.getCurrState());
}
    
TEST(LightBulbTests, TurnOnTheLightBulbWhenTheLightBulbIsOn)
{
    LightBulb fsm;
    fsm.process(Event::TurnOn);
    fsm.process(Event::TurnOn);
    EXPECT_EQ(fsm.m_stateOn, fsm.getCurrState());
}

}