#include "LCD.hpp"
#include <stdexcept>
#include <algorithm>


vector<string> g_LCD_Table = {"._.|.||_|",
                              ".....|..|",
                              "._.._||_.",
                              "._.._|._|",
                              "...|_|..|",
                              "._.|_.._|",
                              "._.|_.|_|",
                              "._...|..|",
                              "._.|_||_|",
                              "._.|_|..|"};


string LCD::getLCDSymbolfromTable(const char p_charNum)
{
    int l_char2IntIndex = p_charNum - '0';
    return g_LCD_Table[l_char2IntIndex];
}

void LCD::printIntergerOnScreen(const int p_num)
{
   if(p_num > 999 || p_num < 0)
        throw invalid_argument("input number more than 3 digit");

   string l_str = to_string(p_num);
   string line1, line2, line3;
   for(auto c : l_str)
   {
        string l_p = getLCDSymbolfromTable(c);
        line1 += l_p.substr(0,3) + " ";
        line2 += l_p.substr(3,3) + " ";
        line3 += l_p.substr(6,3) + " ";
   }
   cout<<line1<<endl<<line2<<endl<<line3<<endl;

}

int LCD::getIntergerFromScreenString(const string p_str)
{

    isSizeValid(p_str);
    int l_result = 0;
    for(int i = 0;  i < p_str.size()/LCD_STRING_LENGTH; i++)
    {
        auto l_iter = find(begin(g_LCD_Table), end(g_LCD_Table), p_str.substr(i*9, 9));
        isSymbolValid(l_iter);
        l_result = l_result*10 + (l_iter - g_LCD_Table.begin());
    }
    return l_result;
}

 void LCD::isSizeValid(const string p_str)
{
    if (LCD_MAX_DIGIT_NUM * LCD_STRING_LENGTH < p_str.size()
        or 0 != p_str.size() % LCD_STRING_LENGTH)
    {
        throw invalid_argument("input string is invalid");
    }
}

void LCD::isSymbolValid(const vector<string>::iterator p_it)
{
    if (g_LCD_Table.end() == p_it)
    {
        throw invalid_argument("input string is invalid");
    }
}

