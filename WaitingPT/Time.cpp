//
// Created by 82109 on 2021-03-17.
//

#include "Time.h"
#include <iostream>


void Time::readTime(bool &errorFlag) {
    enum AM_PM {AM, PM} AM_or_PM;
    int hour, minute;
    const char delimiter = ':';

    errorFlag = true;
    // formatted input -- fail if not an int
    if (!(std::cin >> hour)) // hour 가 int 타입이 아니면 return
        return;
    if (hour < 0 || hour > 12)
        return;

    char c;

    std::cin >> c;
    if (c != delimiter)
        return;
    if (!(std::cin >> minute)) // formatted input
        return;
    if (minute < 0 || minute > 59)
        return;

    std::cin >> c;
    if (c == 'A' || c == 'a')
        AM_or_PM = AM;
    else if (c == 'P' || c == 'p')
        AM_or_PM = PM;
    else
        return;

    std::cin >> c;
    if (c != 'M' && c != 'm')
        return;
    errorFlag = false;
    if (hour == 12)
        minutes = minute;
    else
        minutes = hour*60 + minute;
    if (AM_or_PM == PM)
        minutes += 60*12;
}


int Time::subtractTimes(Time t)
{
    return minutes - t.minutes;
}
