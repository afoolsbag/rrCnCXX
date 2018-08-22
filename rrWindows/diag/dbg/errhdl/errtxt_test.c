/** \copyright The MIT License */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <strsafe.h>

#include <check/check.h>
#include "rrWindows/rrWindows.h"

#include "test.h"

START_TEST(TestErrTxt)
{
    GetProcessId(NULL);
    ck_assert_int_lt(0, StringCchLengthS(LastErrorText()));
}
END_TEST

TCase *TCaseErrTxt(VOID)
{
    TCase *tcase = tcase_create("ErrTxt");
    tcase_add_test(tcase, TestErrTxt);
    return tcase;
}
