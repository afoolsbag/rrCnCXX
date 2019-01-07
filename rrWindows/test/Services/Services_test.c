/*===-- Services -----------------------------------------------*- C -*-===*//**
 *
 * \defgroup gServices 服务
 * \ingroup gDevelop
 *
 * \sa ["Services"](https://docs.microsoft.com/windows/desktop/Services/services). *Microsoft Docs*.
 *     *   [The Complete Service Sample](https://docs.microsoft.com/windows/desktop/Services/the-complete-service-sample)
 *
 * \version 2019-01-04
 * \since 2019-01-04
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check/check.h>

#include "_test.h"
#include "rrwindows/rrwindows.h"

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

static PCTSTR CONST ServiceName = _T("rrWindowsService");
static PCTSTR CONST ServiceDisplay = _T("zhengrr's Windows Service");
static PCTSTR CONST ServiceDescription = _T("zhengrr（测试用）的 Windows 服务。");

INT
WINAPI
ServiceProgramMain(
    INT argc,
    TCHAR *argv[],
    TCHAR *envp[])
{
    UNREFERENCED_PARAMETER(envp);

    if (argc == 2) {

        if (CompareString_Simplify(argv[1], _T("install")) == CSTR_EQUAL) {
            ServiceInstall();
            return EXIT_SUCCESS;
        }

        if (CompareString_Simplify(argv[1], _T("remove")) == CSTR_EQUAL) {
            ServiceRemove();
            return EXIT_SUCCESS;
        }

        if (CompareString_Simplify(argv[1], _T("start")) == CSTR_EQUAL) {
            ServiceStart();
            return EXIT_SUCCESS;
        }

        if (CompareString_Simplify(argv[1], _T("stop")) == CSTR_EQUAL) {
            ServiceStop();
            return EXIT_SUCCESS;
        }

        if (CompareString_Simplify(argv[1], _T("pause")) == CSTR_EQUAL) {
            ServicePause();
            return EXIT_SUCCESS;
        }

        if (CompareString_Simplify(argv[1], _T("continue")) == CSTR_EQUAL) {
            ServiceContinue();
            return EXIT_SUCCESS;
        }

        if (CompareString_Simplify(argv[1], _T("restart")) == CSTR_EQUAL) {
            ServiceRestart();
            return EXIT_SUCCESS;
        }

        _putts(_T("Unexpected parameter.\n"));
        return EXIT_FAILURE;
    }

    SERVICE_TABLE_ENTRY table[] =
    {
        {(PWSTR)ServiceName, ServiceMain},
        {       NULL,        NULL}
    };

    if (!StartServiceCtrlDispatcher(table)) {
        ServiceReportFailingEvent(_T("StartServiceCtrlDispatcher"), GetLastError());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

VOID
WINAPI
ServiceInstall(VOID)
{
    _tprintf(_T("Installing %s service...\n"), ServiceDisplay);

    TCHAR path[MAX_PATH];
    if (!GetModuleFileName(NULL, path, MAX_PATH)) {
        ServicePrintFailing(_T("GetModuleFileName"), GetLastError());
        return;
    }

    SC_HANDLE CONST serviceCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!serviceCM) {
        ServicePrintFailing(_T("OpenSCManager"), GetLastError());
        return;
    }

    SC_HANDLE CONST service = CreateService(
        serviceCM, ServiceName, ServiceDisplay,
        SERVICE_ALL_ACCESS, SERVICE_WIN32_OWN_PROCESS, SERVICE_DEMAND_START, SERVICE_ERROR_NORMAL,
        path, NULL, NULL, NULL, NULL, NULL);
    if (!service) {
        ServicePrintFailing(_T("CreateService"), GetLastError());
        CloseServiceHandle(serviceCM);
        return;
    }

    SERVICE_DESCRIPTION sd = {(PWSTR)ServiceDescription};
    ChangeServiceConfig2(service, SERVICE_CONFIG_DESCRIPTION, &sd);

    _putts(_T("Service installed successfully.\n"));
    CloseServiceHandle(service);
    CloseServiceHandle(serviceCM);
}

VOID
WINAPI
ServiceRemove(VOID)
{
    _tprintf(_T("Removing %s service...\n"), ServiceDisplay);

    SC_HANDLE CONST serviceCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!serviceCM) {
        ServicePrintFailing(_T("OpenSCManager"), GetLastError());
        return;
    }

    SC_HANDLE CONST service = OpenService(serviceCM, ServiceName, DELETE);
    if (!service) {
        ServicePrintFailing(_T("OpenService"), GetLastError());
        CloseServiceHandle(serviceCM);
        return;
    }

    if (!DeleteService(service)) {
        ServicePrintFailing(_T("DeleteService"), GetLastError());
        CloseServiceHandle(service);
        CloseServiceHandle(serviceCM);
        return;
    }

    _putts(_T("Service removed successfully.\n"));
    CloseServiceHandle(service);
    CloseServiceHandle(serviceCM);
}

VOID
WINAPI
ServiceStart(VOID)
{
    _tprintf(_T("Starting %s service...\n"), ServiceDisplay);

    SC_HANDLE CONST serviceCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!serviceCM) {
        ServicePrintFailing(_T("OpenSCManager"), GetLastError());
        return;
    }

    SC_HANDLE CONST service = OpenService(serviceCM, ServiceName, DELETE);
    if (!service) {
        ServicePrintFailing(_T("OpenService"), GetLastError());
        CloseServiceHandle(serviceCM);
        return;
    }

    SERVICE_STATUS status;
    if (!QueryServiceStatus(service, &status)) {
        ServicePrintFailing(_T("QueryServiceStatus"), GetLastError());
        CloseServiceHandle(service);
        CloseServiceHandle(serviceCM);
        return;
    }

    if (status.dwCurrentState != SERVICE_STOPPED)
        return;

    if (!StartService(service, 0, NULL)) {
        ServicePrintFailing(_T("StartService"), GetLastError());
        CloseServiceHandle(service);
        CloseServiceHandle(serviceCM);
        return;
    }

    _putts(_T("Service started successfully.\n"));
    CloseServiceHandle(service);
    CloseServiceHandle(serviceCM);
}

VOID
WINAPI
ServiceStop(VOID)
{
    _tprintf(_T("Stopping %s service...\n"), ServiceDisplay);

    SC_HANDLE CONST serviceCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!serviceCM) {
        ServicePrintFailing(_T("OpenSCManager"), GetLastError());
        return;
    }

    SC_HANDLE CONST service = OpenService(serviceCM, ServiceName, DELETE);
    if (!service) {
        ServicePrintFailing(_T("OpenService"), GetLastError());
        CloseServiceHandle(serviceCM);
        return;
    }

    SERVICE_STATUS status;
    if (!QueryServiceStatus(service, &status)) {
        ServicePrintFailing(_T("QueryServiceStatus"), GetLastError());
        CloseServiceHandle(service);
        CloseServiceHandle(serviceCM);
        return;
    }

    if (status.dwCurrentState == SERVICE_STOPPED || status.dwCurrentState == SERVICE_STOP_PENDING)
        return;

    if (!ControlService(service, SERVICE_CONTROL_STOP, NULL)) {
        ServicePrintFailing(_T("ControlService"), GetLastError());
        CloseServiceHandle(service);
        CloseServiceHandle(serviceCM);
        return;
    }

    _putts(_T("Service stopped successfully.\n"));
    CloseServiceHandle(service);
    CloseServiceHandle(serviceCM);
}

VOID
WINAPI
ServicePause(VOID)
{
    _tprintf(_T("Pausing %s service...\n"), ServiceDisplay);

    SC_HANDLE CONST serviceCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!serviceCM) {
        ServicePrintFailing(_T("OpenSCManager"), GetLastError());
        return;
    }

    SC_HANDLE CONST service = OpenService(serviceCM, ServiceName, DELETE);
    if (!service) {
        ServicePrintFailing(_T("OpenService"), GetLastError());
        CloseServiceHandle(serviceCM);
        return;
    }

    SERVICE_STATUS status;
    if (!QueryServiceStatus(service, &status)) {
        ServicePrintFailing(_T("QueryServiceStatus"), GetLastError());
        CloseServiceHandle(service);
        CloseServiceHandle(serviceCM);
        return;
    }

    if (status.dwCurrentState != SERVICE_RUNNING)
        return;

    if (!ControlService(service, SERVICE_CONTROL_PAUSE, NULL)) {
        ServicePrintFailing(_T("ControlService"), GetLastError());
        CloseServiceHandle(service);
        CloseServiceHandle(serviceCM);
        return;
    }

    _putts(_T("Service paused successfully.\n"));
    CloseServiceHandle(service);
    CloseServiceHandle(serviceCM);
}

VOID
WINAPI
ServiceContinue(VOID)
{
    _tprintf(_T("Continuing %s service...\n"), ServiceDisplay);

    SC_HANDLE CONST serviceCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!serviceCM) {
        ServicePrintFailing(_T("OpenSCManager"), GetLastError());
        return;
    }

    SC_HANDLE CONST service = OpenService(serviceCM, ServiceName, DELETE);
    if (!service) {
        ServicePrintFailing(_T("OpenService"), GetLastError());
        CloseServiceHandle(serviceCM);
        return;
    }

    SERVICE_STATUS status;
    if (!QueryServiceStatus(service, &status)) {
        ServicePrintFailing(_T("QueryServiceStatus"), GetLastError());
        CloseServiceHandle(service);
        CloseServiceHandle(serviceCM);
        return;
    }

    if (status.dwCurrentState != SERVICE_PAUSED)
        return;

    if (!ControlService(service, SERVICE_CONTROL_CONTINUE, NULL)) {
        ServicePrintFailing(_T("ControlService"), GetLastError());
        CloseServiceHandle(service);
        CloseServiceHandle(serviceCM);
        return;
    }

    _putts(_T("Service continued successfully.\n"));
    CloseServiceHandle(service);
    CloseServiceHandle(serviceCM);
}

VOID
WINAPI
ServiceRestart(VOID)
{
    _tprintf(_T("Restarting %s service...\n"), ServiceDisplay);

    ServiceStop();
    ServiceStart();

    _putts(_T("Service restarted successfully.\n"));
}

static SERVICE_STATUS_HANDLE ServiceStatusHandle = NULL;

static BOOL ServiceStopFlag = FALSE;
static BOOL ServicePauseFlag = FALSE;

VOID
WINAPI
ServiceMain(
    DWORD dwNumServicesArgs,
    LPTSTR *lpServiceArgVectors)
{
    UNREFERENCED_PARAMETER(dwNumServicesArgs);
    UNREFERENCED_PARAMETER(lpServiceArgVectors);

    static CONST DWORD SleepCycle = 1 * 1000;

    ServiceStatusHandle = RegisterServiceCtrlHandler(ServiceName, ServiceCtrlHandler);
    if (!ServiceStatusHandle) {
        ServiceReportFailingEvent(_T("RegisterServiceCtrlHandler"), GetLastError());
        return;
    }

    ServiceReportStatus(SERVICE_START_PENDING, NO_ERROR, 3000);
    ServiceReportStatus(SERVICE_RUNNING, NO_ERROR, 0);

    while (!ServiceStopFlag) {
        if (ServicePauseFlag) {
            Sleep(SleepCycle);
            continue;
        }

        static INT cnt = 0;
        TCHAR buffer[MAX_PATH];
        StringCchPrintf(buffer, ARRAYSIZE(buffer), _T("Count %d.\n"), ++cnt);
        OutputDebugString(buffer);

        Sleep(SleepCycle);
    }
}

VOID
WINAPI
ServiceReportStatus(
    CONST DWORD currentState,
    CONST DWORD win32ExitCode,
    CONST DWORD waitHint)
{
    static SERVICE_STATUS ServiceStatus = {.dwServiceType = SERVICE_WIN32_OWN_PROCESS, .dwServiceSpecificExitCode = 0};
    static DWORD CheckPoint = 1;

    if (currentState)
        ServiceStatus.dwCurrentState = currentState;

    if (ServiceStatus.dwCurrentState == SERVICE_RUNNING || ServiceStatus.dwCurrentState == SERVICE_PAUSED)
        ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_PAUSE_CONTINUE | SERVICE_ACCEPT_SHUTDOWN;
    else
        ServiceStatus.dwControlsAccepted = 0;

    ServiceStatus.dwWin32ExitCode = win32ExitCode;

    if (ServiceStatus.dwCurrentState == SERVICE_STOPPED ||
        ServiceStatus.dwCurrentState == SERVICE_RUNNING ||
        ServiceStatus.dwCurrentState == SERVICE_PAUSED)
        ServiceStatus.dwCheckPoint = 0;
    else
        ServiceStatus.dwCheckPoint = CheckPoint++;

    ServiceStatus.dwWaitHint = waitHint;

    SetServiceStatus(ServiceStatusHandle, &ServiceStatus);
}

VOID
WINAPI
ServiceCtrlHandler(
    DWORD dwControl)
{
    switch (dwControl) {
    case SERVICE_CONTROL_STOP:
    case SERVICE_CONTROL_SHUTDOWN:
        ServiceReportStatus(SERVICE_STOP_PENDING, NO_ERROR, 0);
        ServiceStopFlag = TRUE;
        ServiceReportStatus(SERVICE_STOPPED, NO_ERROR, 0);
        break;

    case SERVICE_CONTROL_PAUSE:
        ServiceReportStatus(SERVICE_PAUSE_PENDING, NO_ERROR, 0);
        ServicePauseFlag = TRUE;
        ServiceReportStatus(SERVICE_PAUSED, NO_ERROR, 0);
        break;

    case SERVICE_CONTROL_CONTINUE:
        ServiceReportStatus(SERVICE_CONTINUE_PENDING, NO_ERROR, 0);
        ServicePauseFlag = FALSE;
        ServiceReportStatus(SERVICE_RUNNING, NO_ERROR, 0);
        break;

    case SERVICE_CONTROL_INTERROGATE:
        break;

    default:
        break;
    }
}

VOID
WINAPI
ServicePrintFailing(
    PTSTR CONST functionName,
    CONST DWORD errorCode)
{
    PCTSTR CONST errorMessage = AllocErrorMessage(errorCode);
    _tprintf(_T("Function %s failed: %s\n"), functionName, errorMessage);
    LocalFree((HLOCAL)errorMessage);
}

VOID
WINAPI
ServiceReportFailingEvent(
    PTSTR CONST functionName,
    CONST DWORD errorCode)
{
    TCHAR buffer[MAX_PATH];

    PCTSTR CONST errorMessage = AllocErrorMessage(errorCode);
    StringCchPrintf(buffer, ARRAYSIZE(buffer), _T("Function %s failed: %s\n"), functionName, errorMessage);
    LocalFree((HLOCAL)errorMessage);

    ServiceReportEvent(EVENTLOG_ERROR_TYPE, buffer);
}

VOID
WINAPI
ServiceReportEvent(
    CONST WORD  type,
    PTSTR CONST message)
{
    HANDLE CONST eventSource = RegisterEventSource(NULL, ServiceName);
    if (eventSource) {
        PCTSTR strings[2];
        strings[0] = ServiceName;
        strings[1] = message;

        ReportEvent(eventSource,
                    type, 0, 0, NULL,
                    2, 0,
                    strings, NULL);

        DeregisterEventSource(eventSource);
    }
}

/** @} */

TCase *tcServices(void)
{
    TCase *const tc = tcase_create("Services");
    return tc;
}
