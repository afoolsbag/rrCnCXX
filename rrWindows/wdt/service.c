/**
 * \copyright Unlicense
 */

#include "service.h"

#include "eventlog.h"

#define MAX_COMMAND 32768

static SERVICE_STATUS_HANDLE ServiceStatusHandle = NULL;

static BOOL ServiceStopFlag = FALSE;
static BOOL ServicePauseFlag = FALSE;

VOID WINAPI ServiceEntry(DWORD dwNumServicesArgs, LPTSTR *lpServiceArgVectors)
{
    UNREFERENCED_PARAMETER(dwNumServicesArgs);
    UNREFERENCED_PARAMETER(lpServiceArgVectors);

    static CONST DWORD SleepCycle = 10 * 1000;

    ServiceStatusHandle = RegisterServiceCtrlHandler(ServiceName, ServiceCtrlHandler);
    if (!ServiceStatusHandle) {
        EventLogFunctionFailed(_T("RegisterServiceCtrlHandler"), GetLastError());
        return;
    }

    ReportServiceStatus(SERVICE_START_PENDING, NO_ERROR, 3000);
    ReportServiceStatus(SERVICE_RUNNING, NO_ERROR, 0);

    /* 读取配置 */

    while (!ServiceStopFlag) {
        if (ServicePauseFlag) {
            Sleep(1000);
            continue;
        }

        static INT cnt = 0;
        TCHAR buffer[MAX_PATH];
        StringCchPrintf(buffer, ARRAYSIZE(buffer), _T("Count %d.\n"), ++cnt);
        OutputDebugString(buffer);

        Sleep(SleepCycle);
    }
}

VOID WINAPI ServiceCtrlHandler(DWORD dwControl)
{
    switch (dwControl) {
    case SERVICE_CONTROL_STOP:
    case SERVICE_CONTROL_SHUTDOWN:
        ReportServiceStatus(SERVICE_STOP_PENDING, NO_ERROR, 0);
        ServiceStopFlag = TRUE;
        ReportServiceStatus(SERVICE_STOPPED, NO_ERROR, 0);
        break;

    case SERVICE_CONTROL_PAUSE:
        ReportServiceStatus(SERVICE_PAUSE_PENDING, NO_ERROR, 0);
        ServicePauseFlag = TRUE;
        ReportServiceStatus(SERVICE_PAUSED, NO_ERROR, 0);
        break;

    case SERVICE_CONTROL_CONTINUE:
        ReportServiceStatus(SERVICE_CONTINUE_PENDING, NO_ERROR, 0);
        ServicePauseFlag = FALSE;
        ReportServiceStatus(SERVICE_RUNNING, NO_ERROR, 0);
        break;

    case SERVICE_CONTROL_INTERROGATE:
        break;

    default:
        break;
    }
}

VOID WINAPI ReportServiceStatus(DWORD currentState, DWORD win32ExitCode, DWORD waitHint)
{
    static SERVICE_STATUS ServiceStatus = {.dwServiceType = SERVICE_WIN32_OWN_PROCESS, .dwServiceSpecificExitCode = 0};
    static DWORD CheckPoint = 1;

    ServiceStatus.dwCurrentState = currentState;

    if (currentState == SERVICE_RUNNING || currentState == SERVICE_PAUSED)
        ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_PAUSE_CONTINUE | SERVICE_ACCEPT_SHUTDOWN;
    else
        ServiceStatus.dwControlsAccepted = 0;

    ServiceStatus.dwWin32ExitCode = win32ExitCode;

    if (currentState == SERVICE_STOPPED || currentState == SERVICE_RUNNING || currentState == SERVICE_PAUSED)
        ServiceStatus.dwCheckPoint = 0;
    else
        ServiceStatus.dwCheckPoint = CheckPoint++;

    ServiceStatus.dwWaitHint = waitHint;

    SetServiceStatus(ServiceStatusHandle, &ServiceStatus);
}
