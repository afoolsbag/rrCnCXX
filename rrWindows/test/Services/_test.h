#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

/** \brief 程序入口。 */
INT WINAPI TheServiceMain(INT argc, TCHAR *argv[], TCHAR *envp[]);

/** \brief 服务工具。 */
VOID WINAPI TheServiceTool(CONST INT type);

/** \brief 服务入口。 */
VOID WINAPI TheServiceEntry(DWORD dwNumServicesArgs, LPTSTR *lpServiceArgVectors);
/** \brief 控制回调。 */
VOID WINAPI TheServiceCtrlHandler(DWORD dwControl);

/** \brief 报告服务状态。 */
VOID WINAPI ReportTheServiceStatus(CONST DWORD currentState, CONST DWORD win32ExitCode, CONST DWORD waitHint);

/** \brief 报告失败事件。 */
VOID WINAPI ReportTheServiceFailingEvent(PTSTR CONST functionName, CONST DWORD errorCode);
/** \brief 报告服务事件。 */
VOID WINAPI ReportTheServiceEvent(CONST WORD type, PTSTR CONST message);

TCase *tcServices(void);

inline Suite *tsServices(void)
{
    Suite *const ts = suite_create("Services");
    return ts;
}
