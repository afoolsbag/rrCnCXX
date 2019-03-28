/*===-- Time ---------------------------------------------------*- C -*-===*//**
 *
 * \defgroup gTime 时间
 * \ingroup gSysInfo
 *
 * \sa ["Registry"](https://docs.microsoft.com/windows/desktop/SysInfo/time). *Microsoft Docs*.
 *
 * \version 2019-03-28
 * \since 2019-03-28
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check.h>

#include "rrWindows/rrWindows.h"
#include "tsSysInfo.h"

START_TEST(tfGetSystemTime)
{
    SYSTEMTIME time;

    GetSystemTime(&time);

    PrintfStdout(_T("The system time: %02d:%02d\n"), time.wHour, time.wMinute);
}
END_TEST

START_TEST(tfGetLocalTime)
{
    SYSTEMTIME time;

    GetLocalTime(&time);

    PrintfStdout(_T("The local time: %02d:%02d\n"), time.wHour, time.wMinute);
}
END_TEST

/**
 * @}
 */

TCase *tcTime(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tfGetSystemTime);
    tcase_add_test(tc, tfGetLocalTime);
    return tc;
}
