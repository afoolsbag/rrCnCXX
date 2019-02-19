#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check.h>

#include "rrwindows/rrwindows.h"
#include "tsServices.h"

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

/**
 * \addtogroup gServices
 * @{
 */

enum TheServiceToolType {
    Install,  /**< 安装 */
    Remove,   /**< 卸载 */
    Start,    /**< 启动 */
    Stop,     /**< 停止 */
    Pause,    /**< 暂停 */
    Continue, /**< 恢复 */
};

static PCTSTR CONST TheServiceName = _T("rrWindowsService");
static PCTSTR CONST TheServiceDisplay = _T("zhengrr's Windows Service");
static PCTSTR CONST TheServiceDescription = _T("zhengrr（测试用）的 Windows 服务。");

INT WINAPI TheServiceMain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    UNREFERENCED_PARAMETER(envp);

    if (argc == 2) {

        if (CompareString_Simplify(argv[1], _T("install")) == CSTR_EQUAL) {
            TheServiceTool(Install);
            return EXIT_SUCCESS;
        }

        if (CompareString_Simplify(argv[1], _T("remove")) == CSTR_EQUAL) {
            TheServiceTool(Remove);
            return EXIT_SUCCESS;
        }

        if (CompareString_Simplify(argv[1], _T("start")) == CSTR_EQUAL) {
            TheServiceTool(Start);
            return EXIT_SUCCESS;
        }

        if (CompareString_Simplify(argv[1], _T("stop")) == CSTR_EQUAL) {
            TheServiceTool(Stop);
            return EXIT_SUCCESS;
        }

        if (CompareString_Simplify(argv[1], _T("pause")) == CSTR_EQUAL) {
            TheServiceTool(Pause);
            return EXIT_SUCCESS;
        }

        if (CompareString_Simplify(argv[1], _T("continue")) == CSTR_EQUAL) {
            TheServiceTool(Continue);
            return EXIT_SUCCESS;
        }

        if (CompareString_Simplify(argv[1], _T("restart")) == CSTR_EQUAL) {
            TheServiceTool(Stop);
            TheServiceTool(Start);
            return EXIT_SUCCESS;
        }

        _putts(_T("Unexpected parameter.\n"));
        return EXIT_FAILURE;
    }

#pragma warning(push)
#pragma warning(disable: 4204)
    SERVICE_TABLE_ENTRY table[] =
    {
        {(PTSTR)TheServiceName, TheServiceEntry},
        {       NULL,           NULL}
    };
#pragma warning(pop)

    if (!StartServiceCtrlDispatcher(table)) {
        ReportTheServiceFailingEvent(_T("StartServiceCtrlDispatcher"), GetLastError());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

VOID WINAPI TheServiceTool(CONST INT type)
{
    SC_HANDLE serviceCM = NULL;
    SC_HANDLE service = NULL;

    switch (type) {
    case Install:  _tprintf(_T("Installing %s service...\n"), TheServiceDisplay); break;
    case Start:    _tprintf(_T("Starting %s service...\n"),   TheServiceDisplay); break;
    case Stop:     _tprintf(_T("Stopping %s service...\n"),   TheServiceDisplay); break;
    case Pause:    _tprintf(_T("Pausing %s service...\n"),    TheServiceDisplay); break;
    case Continue: _tprintf(_T("Continuing %s service...\n"), TheServiceDisplay); break;
    case Remove:   _tprintf(_T("Removing %s service...\n"),   TheServiceDisplay); break;
    default:       _putts(_T("Unexpected switch-case routing.\n"));               break;
    }

    serviceCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!serviceCM) {
        _tprintf(_T("OpenSCManager failed, errorCode=%lu.\n"), GetLastError());
        goto exit;
    }

    if (type == Install) {
        TCHAR path[MAX_PATH];
        if (!GetModuleFileName(NULL, path, MAX_PATH)) {
            _tprintf(_T("GetModuleFileName failed, errorCode=%lu.\n"), GetLastError());
            goto exit;
        }

        service = CreateService(
            serviceCM, TheServiceName, TheServiceDisplay,
            SERVICE_ALL_ACCESS, SERVICE_WIN32_OWN_PROCESS, SERVICE_DEMAND_START, SERVICE_ERROR_NORMAL,
            path, NULL, NULL, NULL, NULL, NULL);
        if (!service) {
            _tprintf(_T("CreateService failed, errorCode=%lu.\n"), GetLastError());
            goto exit;
        }

#pragma warning(push)
#pragma warning(disable: 4204)
        SERVICE_DESCRIPTION sd = {(PTSTR)TheServiceDescription};
#pragma warning(pop)
        ChangeServiceConfig2(service, SERVICE_CONFIG_DESCRIPTION, &sd);

    } else if (type == Remove) {
        service = OpenService(serviceCM, TheServiceName, DELETE);
        if (!service) {
            _tprintf(_T("OpenService failed, errorCode=%lu.\n"), GetLastError());
            goto exit;
        }

        if (!DeleteService(service)) {
            _tprintf(_T("DeleteService failed, errorCode=%lu.\n"), GetLastError());
            goto exit;
        }

    } else /* Start, Stop, Pause or Continue */ {
        service = OpenService(serviceCM, TheServiceName, GENERIC_EXECUTE);
        if (!service) {
            _tprintf(_T("OpenService failed, errorCode=%lu.\n"), GetLastError());
            goto exit;
        }

        SERVICE_STATUS status;

        switch (type) {
        case Start:
            if (!StartService(service, 0, NULL)) {
                _tprintf(_T("StartService failed, errorCode=%lu.\n"), GetLastError());
                goto exit;
            }
            break;

        case Stop:
            if (!ControlService(service, SERVICE_CONTROL_STOP, &status)) {
                _tprintf(_T("ControlService failed, errorCode=%lu.\n"), GetLastError());
                goto exit;
            }
            break;

        case Pause:
            if (!ControlService(service, SERVICE_CONTROL_PAUSE, &status)) {
                _tprintf(_T("ControlService failed, errorCode=%lu.\n"), GetLastError());
                goto exit;
            }
            break;

        case Continue:
            if (!ControlService(service, SERVICE_CONTROL_CONTINUE, &status)) {
                _tprintf(_T("ControlService failed, errorCode=%lu.\n"), GetLastError());
                goto exit;
            }
            break;

        default:
            _putts(_T("Unexpected switch-case routing.\n"));
            break;
        }
    }

    switch (type) {
    case Install:  _putts(_T("Service installed successfully.\n")); break;
    case Start:    _putts(_T("Service started successfully.\n"));   break;
    case Stop:     _putts(_T("Service stopped successfully.\n"));   break;
    case Pause:    _putts(_T("Service paused successfully.\n"));    break;
    case Continue: _putts(_T("Service continued successfully.\n")); break;
    case Remove:   _putts(_T("Service removed successfully.\n"));   break;
    default:       _putts(_T("Unexpected switch-case routing.\n")); break;
    }

exit:
    if (service)
        CloseServiceHandle(service);
    if (serviceCM)
        CloseServiceHandle(serviceCM);
}

static SERVICE_STATUS_HANDLE TheServiceStatusHandle = NULL;

static BOOL TheServiceStopFlag = FALSE;
static BOOL TheServicePauseFlag = FALSE;

VOID WINAPI TheServiceEntry(DWORD dwNumServicesArgs, LPTSTR *lpServiceArgVectors)
{
    UNREFERENCED_PARAMETER(dwNumServicesArgs);
    UNREFERENCED_PARAMETER(lpServiceArgVectors);

    static CONST DWORD SleepCycle = 1 * 1000;

    TheServiceStatusHandle = RegisterServiceCtrlHandler(TheServiceName, TheServiceCtrlHandler);
    if (!TheServiceStatusHandle) {
        ReportTheServiceFailingEvent(_T("RegisterServiceCtrlHandler"), GetLastError());
        return;
    }

    ReportTheServiceStatus(SERVICE_START_PENDING, NO_ERROR, 3000);
    ReportTheServiceStatus(SERVICE_RUNNING, NO_ERROR, 0);

    while (!TheServiceStopFlag) {
        if (TheServicePauseFlag) {
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

VOID WINAPI TheServiceCtrlHandler(DWORD dwControl)
{
    switch (dwControl) {
    case SERVICE_CONTROL_STOP:
    case SERVICE_CONTROL_SHUTDOWN:
        ReportTheServiceStatus(SERVICE_STOP_PENDING, NO_ERROR, 0);
        TheServiceStopFlag = TRUE;
        ReportTheServiceStatus(SERVICE_STOPPED, NO_ERROR, 0);
        break;

    case SERVICE_CONTROL_PAUSE:
        ReportTheServiceStatus(SERVICE_PAUSE_PENDING, NO_ERROR, 0);
        TheServicePauseFlag = TRUE;
        ReportTheServiceStatus(SERVICE_PAUSED, NO_ERROR, 0);
        break;

    case SERVICE_CONTROL_CONTINUE:
        ReportTheServiceStatus(SERVICE_CONTINUE_PENDING, NO_ERROR, 0);
        TheServicePauseFlag = FALSE;
        ReportTheServiceStatus(SERVICE_RUNNING, NO_ERROR, 0);
        break;

    case SERVICE_CONTROL_INTERROGATE:
        break;

    default:
        break;
    }
}

VOID WINAPI ReportTheServiceStatus(CONST DWORD currentState, CONST DWORD win32ExitCode, CONST DWORD waitHint)
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

    SetServiceStatus(TheServiceStatusHandle, &ServiceStatus);
}

VOID WINAPI ReportTheServiceFailingEvent(PTSTR CONST functionName, CONST DWORD errorCode)
{
    TCHAR buffer[MAX_PATH];

    PCTSTR CONST errorMessage = AllocErrorMessage(errorCode);
    StringCchPrintf(buffer, ARRAYSIZE(buffer), _T("%s failed: %s\n"), functionName, errorMessage);
    LocalFree((HLOCAL)errorMessage);

    ReportTheServiceEvent(EVENTLOG_ERROR_TYPE, buffer);
}

VOID WINAPI ReportTheServiceEvent(CONST WORD type, PTSTR CONST message)
{
    HANDLE CONST eventSource = RegisterEventSource(NULL, TheServiceName);
    if (eventSource) {
        PCTSTR strings[2];
        strings[0] = TheServiceName;
        strings[1] = message;

        ReportEvent(eventSource,
                    type, 0, 0, NULL,
                    2, 0,
                    strings, NULL);

        DeregisterEventSource(eventSource);
    }
}

/**
 * @}
 */

TCase *tcServices(void)
{
    TCase *const tc = tcase_create(__func__);
    return tc;
}
