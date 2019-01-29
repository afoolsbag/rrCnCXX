/*===-- Byte String Manipulation -------------------------------*- C -*-===*//**
 *
 * \defgroup gBStrMan 空终止字节字符串：字符串操作
 * \ingroup gStr
 *
 * \sa <http://zh.cppreference.com/w/c/string/byte#String_manipulation>
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

#include "_test.h"
#include "c_versions.h"

#define countof(array) (sizeof(array) / sizeof((array)[0]))

/** \brief String copy.
 *  \details 复制一个字符串给另一个。
 *  \sa <http://en.cppreference.com/w/c/string/byte/strcpy> */
START_TEST(tf_strcpy)
{
    char dst[8] = "";
    const char src[] = "zhengrr";

#if LIB_EXT1
    strcpy_s(dst, countof(dst), src);
#else
    strcpy(dst, src);
#endif

    ck_assert_str_eq(src, dst);
}
END_TEST;

/** \brief String n copy.
 *  \details 从一个字符串复制一定数量的字符到另一个。
 *  \sa <http://en.cppreference.com/w/c/string/byte/strncpy> */
START_TEST(tf_strncpy)
{
    char dst[8] = "";
    const char src[] = "zhengrr";

#if LIB_EXT1
    strncpy_s(dst, countof(dst), src, countof(dst) - 1);
#else
    strncpy(dst, src, countof(dst) - 1);
    dst[countof(dst) - 1] = '\0';
#endif

    ck_assert_str_eq(src, dst);
}
END_TEST;

/** \brief String catenates.
 *  \details 连接两个字符串。
 *  \sa <http://en.cppreference.com/w/c/string/byte/strcat> */
START_TEST(tf_strcat)
{
    char dst[8] = "zheng";
    const char src[] = "rr";

#if LIB_EXT1
    strcat_s(dst, countof(dst), src);
#else
    strcat(dst, src);
#endif

    ck_assert_str_eq(dst, "zhengrr");
}
END_TEST;

/** \brief String n catenates.
 *  \details 连接两个字符串的一定数量字符。
 *  \sa <http://en.cppreference.com/w/c/string/byte/strncat> */
START_TEST(tf_strncat)
{
    char dst[8] = "zheng";
    const char src[] = "rr";

#if LIB_EXT1
    strncat_s(dst, countof(dst), src, countof(dst) - strlen(dst) - 1);
#else
    strncat(dst, src, sizeof(dst) - strlen(dst) - 1);
#endif

    ck_assert_str_eq(dst, "zhengrr");
}
END_TEST;

/** \brief 变换字符串，使得 `strcmp` 会产生同 `strcoll` 的结果。
 *  \sa <http://en.cppreference.com/w/c/string/byte/strxfrm> */
START_TEST(tf_strxfrm)
{

}
END_TEST;

/** @} */

TCase *tc_byte_strings_manipulation(void)
{
    TCase *const tc = tcase_create("byte_strings_manipulation");

    tcase_add_test(tc, tf_strcpy);
    tcase_add_test(tc, tf_strncpy);

    tcase_add_test(tc, tf_strcat);
    tcase_add_test(tc, tf_strncat);

    tcase_add_test(tc, tf_strxfrm);

    return tc;
}
