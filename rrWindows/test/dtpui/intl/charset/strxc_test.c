/** \copyright The MIT License */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>
#include "rrwindows/rrwindows.h"

#include "_test.h"

START_TEST(TestGb2312ToUtf8)
{
    CHAR gb2312[5] = {'\xC4', '\xE3', '\xBA', '\xC3', '\0'};  /* GB2312 "你好" */
    CHAR utf8[7];
    StringTranscode(CP_GB2312, gb2312, -1, CP_UTF8, utf8, countof(utf8));
    ck_assert('\xE4' == utf8[0] && '\xBD' == utf8[1] && '\xA0' == utf8[2]);  /* UTF8 '你' */
    ck_assert('\xE5' == utf8[3] && '\xA5' == utf8[4] && '\xBD' == utf8[5]);  /* UTF8 '好' */
    ck_assert('\0' == utf8[6]);
}
END_TEST

TCase *TCaseStrXc(VOID)
{
    TCase *tcase = tcase_create("StrXc");
    tcase_add_test(tcase, TestGb2312ToUtf8);
    return tcase;
}
