/*===-- Console Control Handler --------------------------------*- C -*-===*//**
 *
 * \defgroup gConCtrlHdl
 * \ingroup gCons
 *
 * \author zhengrr
 * \version 2018-08-22
 * \since 2018-08-22
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check/check.h>

#include "_test.h"

static
BOOL
WINAPI
HandlerRoutine(_In_ DWORD dwCtrlType)
{
    switch (dwCtrlType) {
    case CTRL_C_EVENT:  // fallthrough
    case CTRL_BREAK_EVENT:  // fallthrough
    case CTRL_CLOSE_EVENT:  // fallthrough
    case CTRL_LOGOFF_EVENT:  // fallthrough
    case CTRL_SHUTDOWN_EVENT:  // fallthrougn
    default: break;
    }
    return TRUE;
}

START_TEST(TestConCtrlHdl)
{
    SetConsoleCtrlHandler(&HandlerRoutine, TRUE);
}
END_TEST

/** @} */

TCase *TCaseConCtrlHdl(void)
{
    TCase *tcase = tcase_create("ConCtrlHdl");
    tcase_add_test(tcase, TestConCtrlHdl);
    return tcase;
}
