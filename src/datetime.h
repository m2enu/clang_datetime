/**
 * @file        datetime.h
 * @brief       Handle Date and Time
 * @author      m2enu
 * @license     https://github.com/m2enu/clang_datetime/blob/main/LICENSE
 */
#ifndef CLANG_DATETIME_H_INCLUDE
#define CLANG_DATETIME_H_INCLUDE

#include <stdint.h>
#include <stdbool.h>

typedef uint16_t    datetime_year_t;    /**< type definition for year */
typedef uint8_t     datetime_month_t;   /**< type definition for month */
typedef uint8_t     datetime_day_t;     /**< type definition for day */

/**
 * @brief       Enumeration for algorithm to acquire day of month
 */
typedef enum datetime_day_of_month_algorithm_t
{
    DATETIME_DAY_OF_MONTH_ALGORITHM_1,      /**< Algorithm 1 */
    DATETIME_DAY_OF_MONTH_ALGORITHM_2,      /**< Algorithm 2 */
    DATETIME_DAY_OF_MONTH_ALGORITHM_MAX,    /**< Algorithm maximum index */
} datetime_day_of_month_algorithm_t;

/**
 * @brief       Switch algorithm to acquire day of month
 * @param       algo    Algorithm enumeration
 */
void DateTimeSwitchDayOfMonthAlgorithm(datetime_day_of_month_algorithm_t algo);

/**
 * @brief       Returns true if specified year is a leap year.
 * @param       year    Year of date
 * @return      true if specified year is a leap year
 */
bool DateTimeIsLeapYear(datetime_year_t year);

/**
 * @brief       Returns number of day of specified month.
 * @param       year    Year of date
 * @param       month   Month of date
 * @return      Number of day of specified month
 */
datetime_day_t DateTimeDayOfMonth(datetime_year_t year, datetime_month_t month);

#endif
