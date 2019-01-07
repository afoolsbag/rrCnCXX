#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

/**
 * \brief 程序入口。
 */
INT
WINAPI
ServiceProgramMain(
    INT argc,
    TCHAR *argv[],
    TCHAR *envp[]
);

/**
 * \brief 服务安装。
 */
VOID
WINAPI
ServiceInstall(VOID);

/**
 * \brief 服务卸载。
 */
VOID
WINAPI
ServiceRemove(VOID);

/**
 * \brief 服务启动。
 */
VOID
WINAPI
ServiceStart(VOID);

/**
 * \brief 服务停止。
 */
VOID
WINAPI
ServiceStop(VOID);

/**
 * \brief 服务暂停。
 */
VOID
WINAPI
ServicePause(VOID);

/**
 * \brief 服务继续。
 */
VOID
WINAPI
ServiceContinue(VOID);

/**
 * \brief 服务重启。
 */
VOID
WINAPI
ServiceRestart(VOID);

/**
 * \brief 服务入口。
 */
VOID
WINAPI
ServiceMain(
    DWORD dwNumServicesArgs,
    LPTSTR *lpServiceArgVectors
);

/**
 * \brief 报告状态。
 */
VOID
WINAPI
ServiceReportStatus(
    CONST DWORD dwCurrentState,
    CONST DWORD dwWin32ExitCode,
    CONST DWORD dwWaitHint
);

/**
 * \brief 控制回调。
 */
VOID
WINAPI
ServiceCtrlHandler(
    DWORD dwControl
);

/**
 * \brief 打印失败。
 */
VOID
WINAPI
ServicePrintFailing(
    PTSTR CONST functionName,
    CONST DWORD errorCode);

/**
 * \brief 报告失败事件。
 */
VOID
WINAPI
ServiceReportFailingEvent(
    PTSTR CONST functionName,
    CONST DWORD errorCode);

/**
 * \brief 报告事件。
 */
VOID
WINAPI
ServiceReportEvent(
    CONST WORD  type,
    PTSTR CONST message);

TCase *tcServices(void);

inline Suite *tsServices(void)
{
    Suite *const ts = suite_create("Services");
    return ts;
}
