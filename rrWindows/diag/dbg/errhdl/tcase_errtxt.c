/** \copyright The MIT License */

#include <strsafe.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "check/check.h"

#include "rrwindows/errtxt.h"

START_TEST(TestErrTxt)
{
    GetProcessId(NULL);
    size_t len = 0;
    StringCchLength(GetLastErrorText(), STRSAFE_MAX_CCH, &len);
    ck_assert(len);
}
END_TEST

TCase *TCaseErrTxt(VOID)
{
    TCase *tcase = tcase_create("ErrTxt");
    tcase_add_test(tcase, TestErrTxt);
    return tcase;
}
