#include "Time.h"

Time::Time()
{
    hour = 0;
    minute = 0;
}

Time::Time(unsigned h, unsigned m)
{
    if(h<0||h>24){
        cout<<"Invalid hour..."<<'\n';
    }
    hour = h;
    if(m>59){
        hour++;
        minute = m - 60;
    }
    else{
        minute = m;
    }
}

void Time::SetHour(unsigned h)
{
    if(h<0||h>24){
        cout<<"Invalid hour..."<<'\n';
    }
    hour = h;
}

unsigned Time::GetHour() const
{
    return hour;
}

void Time::SetMinute(unsigned m)
{
    if(m>59){
        hour++;
        minute = m - 60;
    }
    else{
        minute = m;
    }
}

unsigned Time::GetMinute() const
{
    return minute;
}
