/*===-- String Manipulation ------------------------------------*- C -*-===*//**
 *
 * \defgroup groupStringManipulation 字符串操作
 * \ingroup groupString
 *
 * \version 2020-01-09
 * \since 2018-01-05
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

#include <check.h>

#include "ts_string.h"

#define countof(array) (sizeof(array) / sizeof((array)[0]))

/**
 * \brief 字符串复制（String Copy）。
 *
 * \sa <http://zh.cppreference.com/w/c/string/byte/strcpy>
 * \sa <http://zh.cppreference.com/w/c/string/byte/strncpy>
 */
START_TEST(tf_strcpy)
{
    const char src[] = "The quick brown fox jumps a lazy dog.";

    /* 使用 strcpy 有必要检查缓冲区，防止溢出 */
    char dst1[256];
    if (sizeof dst1 < strlen(src) + 1)
        ck_abort_msg("strcpy failed: buffer overflow");
    strcpy(dst1, src);
    ck_assert_str_eq(dst1, src);

    /* 除非特意使用其截断特性，否则不推荐使用 strncpy */
    char dst2[16];
    strncpy(dst2, src, sizeof dst2);
    dst2[sizeof dst2 - 1] = '\0';  /* strncpy 需要手动确保尾部空字符 */
    ck_assert_mem_eq(dst2, src, sizeof dst2 - 1);
    ck_assert_str_ne(dst2, src);
}
END_TEST;

/**
 * \brief 字符串系接（String catenates）。
 *
 * \sa <http://zh.cppreference.com/w/c/string/byte/strcat>
 * \sa <http://zh.cppreference.com/w/c/string/byte/strncat>
 */
START_TEST(tf_strcat)
{
    const char rua[] = "rua rua rua!";
    const char yyf[] = "yyf: rua rua rua!";
    const char xjs[] = "xjs: rua rua rua!";

    /* 同上，使用 strcat 有必要检查缓冲区，防止溢出 */
    char dst1[256] = "yyf: ";
    if (sizeof dst1 < strlen(dst1) + strlen(rua) + 1)
        ck_abort_msg("strcat failed: buffer overflow");
    strcat(dst1, rua);
    ck_assert_str_eq(dst1, yyf);

    /* 同上，除非特意使用其截断特性，否则不推荐使用 strncat */
    char dst2[16] = "xjs: ";
    strncat(dst2, rua, sizeof dst2 - strlen(dst2) - 1);  /* 不同于 strncpy，strncat 会确保尾部空字符 */
    ck_assert_mem_eq(dst2, xjs, sizeof dst2 - 1);
    ck_assert_str_ne(dst2, xjs);
}
END_TEST;

/**
 * @}
 */

TCase *tc_string_manipulation(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_strcpy);
    tcase_add_test(tc, tf_strcat);
    return tc;
}
