/*===-- Windows Sockets 2 --------------------------------------*- C -*-===*//**
 *
 * \defgroup gWinSock Windows 套接字 2 版
 * \ingroup gDevelop
 *
 * \sa ["Windows Sockets 2"](https://docs.microsoft.com/windows/desktop/WinSock/windows-sockets-start-page-2). *Microsoft Docs*.
 *
 * \version 2019-01-04
 * \since 2018-02-05
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

#include "_test.h"
#include "rrwindows/rrwindows.h"

START_TEST(tfGetFirstAdapterUnicastIPv4InternetAddress)
{
    CONST IN_ADDR ia = GetFirstAdapterUnicastIPv4InternetAddress();
    printf("%hhu.%hhu.%hhu.%hhu\n", ia.s_net, ia.s_host, ia.s_lh, ia.s_impno);
}
END_TEST

/** @} */

TCase *tcWindowsSockets2(void)
{
    TCase *const tc = tcase_create("WindowsSockets2");
    tcase_add_test(tc, tfGetFirstAdapterUnicastIPv4InternetAddress);
    return tc;
}
