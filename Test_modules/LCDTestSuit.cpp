#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "LCD.hpp"
#include <stdexcept>

TEST(LCDTestSuit, printOnScreenForSingalNumber)
{
    string l_num = "7";
    LCD::printIntergerOnScreen(l_num);
}

TEST(LCDTestSuit, printOnScreenForNumbers)
{
    string l_num = "697";
    LCD::printIntergerOnScreen(l_num);
}

TEST(LCDTestSuit, inputNegtiveNum)
{
    string l_num = "-42";
    EXPECT_THROW(LCD::printIntergerOnScreen(l_num),invalid_argument);
}

TEST(LCDTestSuit, getIntergerFromScreenString)
{
    string l_str = "._...|..|";
    int l_expectNum = 7;
    EXPECT_EQ(LCD::getIntergerFromScreenString(l_str),l_expectNum);
}


TEST(LCDTestSuit, verifyUnexpectedInputString)
{
    string l_str = "._...|..|.|";
    EXPECT_THROW(LCD::getIntergerFromScreenString(l_str),invalid_argument);
}


TEST(LCDTestSuit, verifyUnexpectedInputWrongString)
{
    string l_str = "._./.|..|";
    EXPECT_THROW(LCD::getIntergerFromScreenString(l_str),invalid_argument);
}

TEST(LCDTestSuit, verifyUnexpectedMoreThen3Symbol)
{
    string l_str = "._.|.|..._.|.|..._.|.|..||";
    EXPECT_THROW(LCD::getIntergerFromScreenString(l_str),invalid_argument);
}

TEST(LCDTestSuit, convertTwoDigitalStringToIntNum)
{
    string l_str = ".....|..|._.._||_.";
    int l_expect = 12;

    EXPECT_EQ(LCD::getIntergerFromScreenString(l_str),l_expect);
}

TEST(LCDTestSuit, convertThreeDigitalStringToIntNum)
{
    string l_str = ".....|..|._.._||_.._.|_|..|";
    int l_expect = 129;

    EXPECT_EQ(LCD::getIntergerFromScreenString(l_str),l_expect);
}



