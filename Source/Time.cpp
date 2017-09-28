#include "Time.hpp"
#include <time.h>

using namespace std;

std::string Time::getCurrentTime()
{
    time_t nowtime;
    nowtime = time(NULL);
    struct tm *local;
    local = localtime(&nowtime);

    cout << local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec <<" " ;
   return to_string(local->tm_hour) + ":" + to_string(local->tm_min);
}

