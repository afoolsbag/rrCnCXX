/** \copyright The MIT License */

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "check/check.h"

#include "rrwindows/errhdl.h"

START_TEST(TestErrHdl)
{
    GetProcessId(NULL);
    ck_assert(_tcslen(GetLastErrorText()));
}
END_TEST

TCase *TCaseErrHdl(VOID)
{
    TCase *tcase = tcase_create("ErrHdl");
    tcase_add_test(tcase, TestErrHdl);
    return tcase;
}
