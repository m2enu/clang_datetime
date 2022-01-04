/**
 * @file        test_main.c
 * @brief       Unit test template
 * @author      m2enu
 * @copyright   Copyright (c) 2021 m2enu
 */
#include "unity.h"
#include "test_datetime.h"

/** Unused indicator to suppress compiler warning
 */
#define UNUSED_PARAMETER(x)         ((void)x)

/** Unit test setup
 */
void setUp(void)
{
}

/** Unit test teardown
 */
void tearDown(void)
{
}

/** Unit test main
 */
int main(int argc, char **argv)
{
    UNUSED_PARAMETER(argc);
    UNUSED_PARAMETER(argv);

    UNITY_BEGIN();
    RUN_TEST(test_DateTimeIsLeapYear);
    RUN_TEST(test_DateTimeDayOfMonth1);
    RUN_TEST(test_DateTimeDayOfMonth2);
    return UNITY_END();
}
