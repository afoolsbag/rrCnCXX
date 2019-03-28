/*===-- Service ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 服务。
 *
 * \version 2019-03-27
 * \since 2019-01-04
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

static CONST TCHAR ServiceName[] = _T("rrWdt");
static CONST TCHAR ServiceDisplayName[] = _T("zhengrr's Watchdog Timer Service");
static CONST TCHAR ServiceDescription[] = _T("zhengrr 的看门狗计时器服务。");

/**
 * \brief 服务入口。
 */
VOID WINAPI ServiceEntry(DWORD dwNumServicesArgs, LPTSTR *lpServiceArgVectors);

/**
 * \brief 服务控制回调。
 */
VOID WINAPI ServiceCtrlHandler(DWORD dwControl);

/**
 * \brief 报告服务状态。
 */
VOID WINAPI ReportServiceStatus(DWORD currentState, DWORD win32ExitCode, DWORD waitHint);
