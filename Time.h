#ifndef TIME_H
#define TIME_H


#include <iostream>


using namespace std;

    /**
     * @class Time
     * @brief Set and Get the time (hour, minute)
     *
     * Consists of hour and minute
     *
     *
     * @author Victor Kavassaki Pimentel
     * @version 01
     * @date 18/04/2020 Victor Kavassaki Pimentel, Started
     *
     *
     *
     */

class Time{
public:
    /**
     * @brief Constructs the time from hour and minute
     *
     */
    Time();

    /**
     * @brief Constructs the date from day, month and year
     * @param hour - hour, minute - minute
     */
    Time(unsigned hour, unsigned minute);

    /**
     * @brief Set the hour
     * @param h - hour
     * @return void
     */
    void SetHour(unsigned h);

    /**
     * @brief Get (return) the hour
     * Nothing should be modified as it is const
     * @return unsigned
     */
    unsigned GetHour() const;

    /**
     * @brief Set the minute
     * @param m - minute
     * @return void
     */
    void SetMinute(unsigned m);

    /**
     * @brief Get (return) the minute
     * Nothing should be modified as it is const
     * @return unsigned
     */
    unsigned GetMinute() const;

private:
    unsigned hour; //hour
    unsigned minute; //minute


} ;


#endif
