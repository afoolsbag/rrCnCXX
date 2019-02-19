/*===-- Windows Sockets 2 --------------------------------------*- C -*-===*//**
 *
 * \defgroup gWinSock Windows 套接字 2 版
 * \ingroup gDevelop
 *
 * \sa ["Windows Sockets 2"](https://docs.microsoft.com/windows/desktop/WinSock/windows-sockets-start-page-2). *Microsoft Docs*.
 *
 * \version 2019-02-19
 * \since 2018-02-05
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#include <check.h>

TCase *tcWindowsSockets2(void);

inline Suite *tsWinSock(void)
{
    Suite *const ts = suite_create(__func__);
    suite_add_tcase(ts, tcWindowsSockets2());
    return ts;
}
