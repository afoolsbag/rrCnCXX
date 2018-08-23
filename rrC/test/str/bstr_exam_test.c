/*===-- Byte String Examination --------------------------------*- C -*-===*//**
 *
 * \defgroup gBStrExam 空终止字节字符串：字符串检验
 * \ingroup gStr
 *
 * \sa ["String examination"](https://zh.cppreference.com/w/c/string/byte#String_examination). *cppreference.com*.
 *
 * \version 2018-07-11
 * \since 2018-01-05
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>

#include <check/check.h>
#include "rrc/adp.h"
#include "rrc/def.h"

#include "_test.h"

/**
 * \brief 字符串长度。
 *        String Length.
 *
 * \sa <https://zh.cppreference.com/w/c/string/byte/strlen>
 * \sa <http://cplusplus.com/reference/cstring/strlen/>
 */
START_TEST(test_strlen)
{
    ck_assert_int_eq(strlen("zhengrr"), 7);

#if LIB_EXT1
    ck_assert_int_eq(strnlen_s("zhengrr", countof("zhengrr")), 7);
#endif
}
END_TEST;

/**
 * \brief 字符串比较。
 *        String Compare.
 *
 * \sa <https://zh.cppreference.com/w/c/string/byte/strcmp>
 * \sa <https://zh.cppreference.com/w/c/string/byte/strncmp>
 * \sa <http://cplusplus.com/reference/cstring/strcmp/>
 * \sa <http://cplusplus.com/reference/cstring/strncmp/>
 */
START_TEST(test_strcmp)
{
    ck_assert_int_lt(strcmp("1993ZhengRr", "1993zhengrr"), 0);
    ck_assert_int_eq(strncmp("1993ZhengRr", "1993zhengrr", 4), 0);
}
END_TEST;

/**
 * \brief 字符串指针打断。
 *        String Pointer Break
 *
 * \sa <https://zh.cppreference.com/w/c/string/byte/strpbrk>
 * \sa <http://cplusplus.com/reference/cstring/strpbrk/>
 */
START_TEST(test_strpbrk)
{
    const char src[] = "My life for Aiur!";
    ck_assert(strpbrk(src, "\t\n\v\r") == src + 2);
}
END_TEST;

/** @} */

TCase *tcase_bstr_exam(void)
{
    TCase *tcase = tcase_create("bstr_exam");

    tcase_add_test(tcase, test_strlen);
    tcase_add_test(tcase, test_strcmp);
    tcase_add_test(tcase, test_strpbrk);

    return tcase;
}
