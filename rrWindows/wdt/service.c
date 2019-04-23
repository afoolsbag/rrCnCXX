/**
 * \copyright Unlicense
 */

#include "service.h"

#include "rrWindows/rrWindows.h"

#include "eventlog.h"
#include "inifile.h"

static SERVICE_STATUS_HANDLE ServiceStatusHandle = NULL;

static BOOL ServiceStopFlag = FALSE;
static BOOL ServicePauseFlag = FALSE;

VOID WINAPI ServiceEntry(DWORD dwNumServicesArgs, LPTSTR *lpServiceArgVectors)
{
    UNREFERENCED_PARAMETER(dwNumServicesArgs);
    UNREFERENCED_PARAMETER(lpServiceArgVectors);

    static CONST DWORD MainLoopCycle = 10 * 1000;
    static CONST DWORD CheckPauseCycle = 1000;

    ServiceStatusHandle = RegisterServiceCtrlHandler(ServiceName, ServiceCtrlHandler);
    if (!ServiceStatusHandle) {
        EventLogFunctionFailed(_T("RegisterServiceCtrlHandler"), GetLastError());
        return;
    }

    ReportServiceStatus(SERVICE_START_PENDING, NO_ERROR, 3000);
    ReportServiceStatus(SERVICE_RUNNING, NO_ERROR, 0);

    Bones bones;
    AllocBones(&bones);

    while (!ServiceStopFlag) {
        if (ServicePauseFlag) {
            Sleep(CheckPauseCycle);
            continue;
        }

        SYSTEMTIME currentTime;
        GetLocalTime(&currentTime);

        for (int i = 0; i < bones.Count; ++i) {
            /* 遍历所有项 */

            Bone *ref = bones.Data + i;

            if (!ref->IsValid)
                continue;

            if (ref->EnableKillPerDay &&
                TimeCompare(&ref->NextKillAt, &currentTime) == TIME_LESS_THAN) {
                /* 若该项启用了定时重启，且符合重启条件 */

                /* 杀死现有进程，等待看门狗将其拉起 */
                if (ref->IsService)
                    StopServiceS(ref->Name);
                else
                    KillExecutable(ref->Name);

                /* 设置下次开启时间 */
                while (TimeCompare(&ref->NextKillAt, &currentTime) == TIME_LESS_THAN)
                    TimeAdd(&ref->NextKillAt, &TimeOneDay);

                continue;
            }

            if (ref->IsService && !ServiceIsRunning(ref->Name) ||
                !ref->IsService && !CountProcessesByExecutable(ref->Name)) {
                /* 若项未在运行 */

                /* 检查重试间隔 */
                SYSTEMTIME canTryAt = ref->LastTryAt;
                TimeAdd(&canTryAt, &ref->RetryInterval);
                if (TimeCompare(&currentTime, &canTryAt) == TIME_LESS_THAN)
                    continue;

                if (ref->IsService)
                    StartServiceS(ref->Name, 0, NULL);
                else
                    if (!RunExecutableAsActive(ref->Path, ref->Args, ref->StartIn, FALSE))
                        EventLogFunctionFailed(_T("RunExecutableAsAdmin"), GetLastError());

                /* 更新重试间隔 */
                ref->LastTryAt = currentTime;
            }
        }

        Sleep(MainLoopCycle);
    }

    FreeBones(&bones);
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
    static SERVICE_STATUS ServiceStatus = {.dwServiceType = SERVICE_WIN32_OWN_PROCESS,.dwServiceSpecificExitCode = 0};
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
