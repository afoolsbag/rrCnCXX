/*===-- String Examination -------------------------------------*- C -*-===*//**
 *
 * \defgroup gStringExamination 字符串检验
 * \ingroup gString
 *
 * \version 2019-02-13
 * \since 2018-01-05
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <string.h>

#include <check.h>

#include "ts_string.h"

/**
 * \brief 字符串长度（String Length）
 *
 * \sa <https://zh.cppreference.com/w/c/string/byte/strlen>
 */
START_TEST(tf_strlen)
{
    const char sentence[] = "Nuclear launch detected.";
    ck_assert_int_eq(strlen(sentence), 24);
}
END_TEST;

/**
 * \brief 字符串比较（String Compare）
 *
 * \sa <https://zh.cppreference.com/w/c/string/byte/strcmp>
 * \sa <https://zh.cppreference.com/w/c/string/byte/strncmp>
 */
START_TEST(tf_strcmp)
{
    const char sentence1[] = "En Taro Adun!";
    const char sentence2[] = "En Taro Tassadar!";

    ck_assert(strcmp(sentence1, sentence2) < 0);
    ck_assert(!strncmp(sentence1, sentence2, 8));
}
END_TEST;

/**
 * \brief 字符串指针打断（String Pointer Break）
 *
 * \sa <https://zh.cppreference.com/w/c/string/byte/strpbrk>
 * \sa <http://cplusplus.com/reference/cstring/strpbrk/>
 */
START_TEST(tf_strpbrk)
{
    const char sentence[] = "My life for Aiur!";
    const char token[] = "\t\n\v\r ";

    ck_assert_ptr_eq(strpbrk(sentence, token), sentence + 2);
}
END_TEST;

/** @} */

TCase *tc_string_examination(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tf_strlen);
    tcase_add_test(tc, tf_strcmp);
    tcase_add_test(tc, tf_strpbrk);
    return tc;
}
