/*===-- Positioning --------------------------------------------*- C -*-===*//**
 *
 * \defgroup gPositioning 文件定位
 * \ingroup gFileIO
 *
 * \version 2019-02-13
 * \since 2019-02-13
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <check.h>

#include "ts_io.h"

/**
 * \brief XXX
 */
START_TEST(tf_xxx)
{
}
END_TEST;

/** @} */

TCase *tc_positioning(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_xxx);
    return tc;
}
