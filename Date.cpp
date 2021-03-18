#include "date.h"


Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(unsigned d, unsigned mon, unsigned y)
{
    if(d<1||d>31){
        cout<<"Invalid day...."<<'\n';
    }
    day = d;

    if(mon<1||mon>12){
        cout<<"Invalid month..."<<'\n';
    }
    month = mon;

    year = y;
}

void Date::SetDay(unsigned d)
{
    if(d<1||d>31){
        cout<<"Invalid day..."<<'\n';
    }
    day = d;
}

unsigned Date::GetDay() const
{
    return day;
}

void Date::SetMonth(unsigned mon)
{
    if(mon<1||mon>12){
        cout<<"Invalid month..."<<'\n';
    }
    month = mon;
}

unsigned Date::GetMonth() const
{
    return month;
}

void Date::SetYear(unsigned y)
{
    year = y;
}

unsigned Date::GetYear() const
{
    return year;
}



