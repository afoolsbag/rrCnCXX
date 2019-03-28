/*===-- Event Log ----------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 服务事件日志。
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

#include "rrWindows/rrWindows.h"

/**
 * \brief 向系统报告事件。
 */
VOID WINAPI EventLog(WORD type, PCTSTR message);

/**
 * \brief 向系统报告函数失败事件。
 */
FORCEINLINE VOID WINAPI_INLINE EventLogFunctionFailed(PCTSTR functionName, DWORD errorCode)
{
    TCHAR buffer[MAX_PATH];

    CONST PCTSTR errorMessage = FormatMessageS(errorCode);
    StringCchPrintf(buffer, countof(buffer), _T("%s failed: %s\n"), functionName, errorMessage);
    LocalFree((HLOCAL)errorMessage);

    EventLog(EVENTLOG_ERROR_TYPE, buffer);
}
