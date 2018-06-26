/** \copyright The MIT License */

#include <strsafe.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

#include "rrwindows/errtxt.h"
#include "rrwindows/winstr.h"

START_TEST(TestErrTxt)
{
    GetProcessId(NULL);
    ck_assert_int_lt(0, StringCchLengthS(GetLastErrorText()));
}
END_TEST

TCase *TCaseErrTxt(VOID)
{
    TCase *tcase = tcase_create("ErrTxt");
    tcase_add_test(tcase, TestErrTxt);
    return tcase;
}
