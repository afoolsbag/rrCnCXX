/** \copyright The MIT License */

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "check/check.h"

#include "rrwindows/dbgprt.h"

START_TEST(TestDbgPrt)
{
    DbgPrtF();
    DbgPrtD(_T("Lovely little fool.\n"));
}
END_TEST

TCase *TCaseDbgPrt(VOID)
{
    TCase *tcase = tcase_create("DbgPrt");
    tcase_add_test(tcase, TestDbgPrt);
    return tcase;
}
