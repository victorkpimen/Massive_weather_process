#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string.h>

using namespace std;

    /**
     * @class Date
     * @brief Set and Get the date (Day, Month and Year)
     *
     * Consists of Day, Month and Year
     *
     *
     * @author Victor Kavassaki Pimentel
     * @version 01
     * @date 18/04/2020 Victor Kavassaki Pimentel, Started
     *
     *
     *
     */

class Date{
public:
    /**
     * @brief Default contructor which constructs the date from day, month, and year
     *
     */
    Date();

    /**
     * @brief Constructor which includes values for day, month, and year
     * @param d - day, mon - month, y - year
     *
     */
    Date(unsigned d, unsigned mon, unsigned y);

    /**
     * @brief Set the day
     * @param d - day
     * @return void
     */
    void SetDay(unsigned d);

    /**
     * @brief Get (return) the day
     * Nothing should be modified when this function is called as it is const
     * @return unsigned
     */
    unsigned GetDay() const;

    /**
     * @brief Set the month
     * @param mon - month
     * @return void
     */
    void SetMonth(unsigned mon);

     /**
     * @brief Get (return) the month
     * Nothing should be modified when this function is called as it is const
     * @return string
     */
    unsigned GetMonth() const;

    /**
     * @brief Set the year
     * @param y - year
     * @return void
     */
    void SetYear(unsigned y);

     /**
     * @brief Get (return) the year
     * Nothing should be modified when this function is called as it is const
     * @return unsigned
     */
    unsigned GetYear() const;

private:
    unsigned day; //Day
    unsigned month; //Month
    unsigned year; //Year
};

#endif
