/**
 * @file        datetime.c
 * @brief       Handle Date and Time
 * @author      m2enu
 * @license     https://github.com/m2enu/clang_datetime/blob/main/LICENSE
 */
#include "datetime.h"

/**
 * @brief       Returns true if specified month is invalid
 * @param       month   Month of date
 * @return      true if specified month is invalid
 */
static inline bool IsInvalidMonth(datetime_month_t month);

/**
 * @brief       Returns number of day of specified month algorithm 1.
 * @param       year    Year of date
 * @param       month   Month of date
 * @return      Number of day of specified month
 */
static datetime_day_t FuncDayOfMonth1(datetime_year_t year, datetime_month_t month);

/**
 * @brief       Returns number of day of specified month algorithm 2.
 * @param       year    Year of date
 * @param       month   Month of date
 * @return      Number of day of specified month
 */
static datetime_day_t FuncDayOfMonth2(datetime_year_t year, datetime_month_t month);

/**
 * @brief       Internal algorithm index
 */
static datetime_day_of_month_algorithm_t day_of_month_algorithm = DATETIME_DAY_OF_MONTH_ALGORITHM_1;

/**
 * @brief       Array of function pointer to calculate day of month
 */
static datetime_day_t (* const FuncDayOfMonth[])(datetime_year_t, datetime_month_t) = {
    &FuncDayOfMonth1,
    &FuncDayOfMonth2};

void DateTimeSwitchDayOfMonthAlgorithm(datetime_day_of_month_algorithm_t algo)
{
    if (algo < DATETIME_DAY_OF_MONTH_ALGORITHM_MAX)
    {
        day_of_month_algorithm = algo;
    }
}

bool DateTimeIsLeapYear(datetime_year_t year)
{
    bool divisibleBy400 = ((year % 400) == 0);
    bool divisibleBy100 = ((year % 100) == 0);
    bool divisibleBy004 = ((year %   4) == 0);
    return ( divisibleBy400 || (divisibleBy004 && !divisibleBy100) );
}

datetime_day_t DateTimeDayOfMonth(datetime_year_t year, datetime_month_t month)
{
    if (IsInvalidMonth(month))
    {
        return 0;
    }
    return (*FuncDayOfMonth[day_of_month_algorithm])(year, month);
}

static inline bool IsInvalidMonth(datetime_month_t month)
{
    return (1 > month) || (12 < month);
}

static datetime_day_t FuncDayOfMonth1(datetime_year_t year, datetime_month_t month)
{
    uint8_t reminder = month & 0x1u;
    if (2 == month)
    {
        bool isLeapYear = DateTimeIsLeapYear(year);
        return (false == isLeapYear) ? 28: 29;
    }
    else if (
           ( (7 >= month) && (1 == reminder) )
        || ( (8 <= month) && (0 == reminder) ) )
    {
        return 31;
    }
    else
    {
        return 30;
    }
}

static datetime_day_t FuncDayOfMonth2(datetime_year_t year, datetime_month_t month)
{
    /**
     * @par     Day of month
     *  1                : 31
     *  2                : 28 or 29
     *  3,  4,  5,  6,  7: 31, 30, 31, 30, 31
     *  8,  9, 10, 11, 12: 31, 30, 31, 30, 31
     */
    static const datetime_day_t days[] = {
        31,     /* [0]: Jan. */
        28,     /* [1]: Feb. */
        31,     /* [2]: Mar. or Aug. */
        30,     /* [3]: Apr. or Sep. */
        31,     /* [4]: May  or Oct. */
        30,     /* [5]: Jun. or Nov. */
        31};    /* [6]: Jul. or Dec. */
    uint8_t index = (7 >= month) ? (month - 1) : (month - 6);

    if (2 == month)
    {
        bool isLeapYear = DateTimeIsLeapYear(year);
        return (false == isLeapYear) ? days[index] : days[index] + 1;
    }
    else
    {
        return days[index];
    }
}
