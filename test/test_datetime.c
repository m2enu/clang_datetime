/**
 * @file        test_datetime.c
 * @brief       Unit test for datetime module
 * @author      m2enu
 * @license     https://github.com/m2enu/clang_datetime/blob/main/LICENSE
 */
#include "datetime.h"
#include "unity.h"

void test_DateTimeIsLeapYear(void)
{
    /* Not leap year */
    TEST_ASSERT_EQUAL(false, DateTimeIsLeapYear(   1));
    TEST_ASSERT_EQUAL(false, DateTimeIsLeapYear( 100));
    TEST_ASSERT_EQUAL(false, DateTimeIsLeapYear(2100));

    /* Leap year */
    TEST_ASSERT_EQUAL(true , DateTimeIsLeapYear(   0));
    TEST_ASSERT_EQUAL(true , DateTimeIsLeapYear( 400));
    TEST_ASSERT_EQUAL(true , DateTimeIsLeapYear(2000));
}

void test_DateTimeDayOfMonth1(void)
{
    /* Switch algorithm */
    DateTimeSwitchDayOfMonthAlgorithm(DATETIME_DAY_OF_MONTH_ALGORITHM_1);

    /* February */
    TEST_ASSERT_EQUAL(29, DateTimeDayOfMonth(2000,  2));
    TEST_ASSERT_EQUAL(28, DateTimeDayOfMonth(2001,  2));

    /* Except February */
    TEST_ASSERT_EQUAL(31, DateTimeDayOfMonth(2000,  1));
    TEST_ASSERT_EQUAL(31, DateTimeDayOfMonth(2000,  3));
    TEST_ASSERT_EQUAL(30, DateTimeDayOfMonth(2000,  4));
    TEST_ASSERT_EQUAL(31, DateTimeDayOfMonth(2000,  5));
    TEST_ASSERT_EQUAL(30, DateTimeDayOfMonth(2000,  6));
    TEST_ASSERT_EQUAL(31, DateTimeDayOfMonth(2000,  7));
    TEST_ASSERT_EQUAL(31, DateTimeDayOfMonth(2000,  8));
    TEST_ASSERT_EQUAL(30, DateTimeDayOfMonth(2000,  9));
    TEST_ASSERT_EQUAL(31, DateTimeDayOfMonth(2000, 10));
    TEST_ASSERT_EQUAL(30, DateTimeDayOfMonth(2000, 11));
    TEST_ASSERT_EQUAL(31, DateTimeDayOfMonth(2000, 12));
}

void test_DateTimeDayOfMonth2(void)
{
    /* Switch algorithm */
    DateTimeSwitchDayOfMonthAlgorithm(DATETIME_DAY_OF_MONTH_ALGORITHM_2);

    /* February */
    TEST_ASSERT_EQUAL(29, DateTimeDayOfMonth(2000,  2));
    TEST_ASSERT_EQUAL(28, DateTimeDayOfMonth(2001,  2));

    /* Except February */
    TEST_ASSERT_EQUAL(31, DateTimeDayOfMonth(2000,  1));
    TEST_ASSERT_EQUAL(31, DateTimeDayOfMonth(2000,  3));
    TEST_ASSERT_EQUAL(30, DateTimeDayOfMonth(2000,  4));
    TEST_ASSERT_EQUAL(31, DateTimeDayOfMonth(2000,  5));
    TEST_ASSERT_EQUAL(30, DateTimeDayOfMonth(2000,  6));
    TEST_ASSERT_EQUAL(31, DateTimeDayOfMonth(2000,  7));
    TEST_ASSERT_EQUAL(31, DateTimeDayOfMonth(2000,  8));
    TEST_ASSERT_EQUAL(30, DateTimeDayOfMonth(2000,  9));
    TEST_ASSERT_EQUAL(31, DateTimeDayOfMonth(2000, 10));
    TEST_ASSERT_EQUAL(30, DateTimeDayOfMonth(2000, 11));
    TEST_ASSERT_EQUAL(31, DateTimeDayOfMonth(2000, 12));
}
