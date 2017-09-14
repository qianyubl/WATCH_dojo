#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;
const int LCD_STRING_LENGTH = 9;
const int LCD_MAX_DIGIT_NUM = 3;

extern vector<string> g_LCD_Table;

class LCD
{
public:
    static void printIntergerOnScreen(const int p_num);
    static int getIntergerFromScreenString(const string p_str);
private:
    static string getLCDSymbolfromTable(const char p_charNum);
    static void isSizeValid(const string p_str);
    static void isSymbolValid(const vector<string>::iterator p_it);
};

