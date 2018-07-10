/*===-- Byte String Manipulation -------------------------------*- C -*-===*//**
 *
 * \defgroup gBStrMan 空终止字节字符串：字符串操作
 * \ingroup gStr
 *
 * \sa <http://zh.cppreference.com/w/c/string/byte#String_manipulation>
 *
 * \version 2018-04-25
 * \since 2018-01-05
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#define __STDC_WANT_LIB_EXT1__ 1
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

#include <check/check.h>

#include "rrc/ver.h"

#include "tsuite_str.h"

/** \brief 复制一个字符串给另一个（string copies）。
 *  \sa http://en.cppreference.com/w/c/string/byte/strcpy */
START_TEST(test_strcpy)
{
    char dst[8] = "";
    const char src[] = "zhengrr";
    strcpy(dst, src);
    ck_assert_str_eq(src, dst);
}
END_TEST;

START_TEST(test_strcpy_s)
{
#if LIB_EXT1
#endif/*LIB_EXT1*/
}
END_TEST;

/** \brief 从一个字符串复制一定数量的字符到另一个（string n copies）。
 *  \sa http://en.cppreference.com/w/c/string/byte/strncpy */
START_TEST(test_strncpy)
{
    char dst[8] = "";
    const char src[] = "zhengrr";
    strncpy(dst, src, sizeof(dst) - 1);
    dst[sizeof(dst) - 1] = '\0';
    ck_assert_str_eq(src, dst);
}
END_TEST;

START_TEST(test_strncpy_s)
{
#if LIB_EXT1
#endif/*LIB_EXT1*/
}
END_TEST;

/** \brief 连接两个字符串（string catenates）。
 *  \sa http://en.cppreference.com/w/c/string/byte/strcat */
START_TEST(test_strcat)
{
    char dst[8] = "zheng";
    const char src[] = "rr";
    strcat(dst, src);
    ck_assert_str_eq(dst, "zhengrr");
}
END_TEST;

START_TEST(test_strcat_s)
{
#if LIB_EXT1
#endif/*LIB_EXT1*/
}
END_TEST;

/** \brief 连接两个字符串的一定数量字符（string n catenates）。
 *  \sa http://en.cppreference.com/w/c/string/byte/strncat */
START_TEST(test_strncat)
{
    char dst[8] = "zheng";
    const char src[] = "rr";
    strncat(dst, src, sizeof(dst) - strlen(dst) - 1);
    ck_assert_str_eq(dst, "zhengrr");
}
END_TEST;

START_TEST(test_strncat_s)
{
#if LIB_EXT1
#endif/*LIB_EXT1*/
}
END_TEST;

/** \brief 变换字符串，使得`strcmp`会产生同`strcoll`的结果。
 *  \sa http://en.cppreference.com/w/c/string/byte/strxfrm */
START_TEST(test_strxfrm)
{

}
END_TEST;

/** @} */

TCase *tcase_bstr_man(void)
{
    TCase *tcase = tcase_create("bstr_man");

    tcase_add_test(tcase, test_strcpy);
    tcase_add_test(tcase, test_strcpy_s);
    tcase_add_test(tcase, test_strncpy);
    tcase_add_test(tcase, test_strncpy_s);

    tcase_add_test(tcase, test_strcat);
    tcase_add_test(tcase, test_strcat_s);
    tcase_add_test(tcase, test_strncat);
    tcase_add_test(tcase, test_strncat_s);

    tcase_add_test(tcase, test_strxfrm);

    return tcase;
}
