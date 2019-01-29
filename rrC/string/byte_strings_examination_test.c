/*===-- Byte String Examination --------------------------------*- C -*-===*//**
 *
 * \defgroup gBStrExam 空终止字节字符串：字符串检验
 * \ingroup gStr
 *
 * \sa ["String examination"](https://zh.cppreference.com/w/c/string/byte#String_examination). *cppreference.com*.
 *
 * \version 2019-01-28
 * \since 2018-01-05
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <string.h>

#include <check/check.h>

#include "ts_string.h"
#include "c_versions.h"

#define countof(array) (sizeof(array) / sizeof((array)[0]))

/**
 * \brief 字符串长度。
 *        String Length.
 *
 * \sa <https://zh.cppreference.com/w/c/string/byte/strlen>
 * \sa <http://cplusplus.com/reference/cstring/strlen/>
 */
START_TEST(tf_strlen)
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
START_TEST(tf_strcmp)
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
START_TEST(tf_strpbrk)
{
    const char src[] = "My life for Aiur!";
    ck_assert(strpbrk(src, "\t\n\v\r ") == src + 2);
}
END_TEST;

/** @} */

TCase *tc_byte_strings_examination(void)
{
    TCase *const tc = tcase_create("byte_strings_examination");

    tcase_add_test(tc, tf_strlen);
    tcase_add_test(tc, tf_strcmp);
    tcase_add_test(tc, tf_strpbrk);

    return tc;
}
