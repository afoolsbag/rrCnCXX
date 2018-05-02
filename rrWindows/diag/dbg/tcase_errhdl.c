/** \copyright The MIT License */

#include <strsafe.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "check/check.h"

#include "rrwindows/errhdl.h"

START_TEST(TestErrHdl)
{
    GetProcessId(NULL);
    size_t len = 0;
    StringCchLength(GetLastErrorText(), STRSAFE_MAX_CCH, &len);
    ck_assert(len);
}
END_TEST

TCase *TCaseErrHdl(VOID)
{
    TCase *tcase = tcase_create("ErrHdl");
    tcase_add_test(tcase, TestErrHdl);
    return tcase;
}
