/**
 * \copyright Unlicense
 */

#define RRWINDOWS_EXPORTS
#include "rrWindows/Services/Services.h"

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
QueryServiceStatusSA(
    _In_z_ PCSTR            name,
    _Out_  LPSERVICE_STATUS pStatus)
{
    BOOL rv = FALSE;
    SC_HANDLE svcCM = NULL;
    SC_HANDLE svc = NULL;

    svcCM = OpenSCManagerA(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!svcCM)
        goto exit;

    svc = OpenServiceA(svcCM, name, GENERIC_READ);
    if (!svc)
        goto exit;

    if (!QueryServiceStatus(svc, pStatus))
        goto exit;

    rv = TRUE;

exit:
    if (svc)
        CloseServiceHandle(svc);
    if (svcCM)
        CloseServiceHandle(svcCM);
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
QueryServiceStatusSW(
    _In_z_ PCWSTR           name,
    _Out_  LPSERVICE_STATUS pStatus)
{
    BOOL rv = FALSE;
    SC_HANDLE svcCM = NULL;
    SC_HANDLE svc = NULL;

    svcCM = OpenSCManagerW(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!svcCM)
        goto exit;

    svc = OpenServiceW(svcCM, name, GENERIC_READ);
    if (!svc)
        goto exit;

    if (!QueryServiceStatus(svc, pStatus))
        goto exit;

    rv = TRUE;

exit:
    if (svc)
        CloseServiceHandle(svc);
    if (svcCM)
        CloseServiceHandle(svcCM);
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
StartServiceSA(
    _In_z_     PCSTR name,
    _In_       DWORD argc,
    _In_opt_z_ PCSTR argv[])
{
    BOOL rv = FALSE;
    SC_HANDLE svcCM = NULL;
    SC_HANDLE svc = NULL;

    svcCM = OpenSCManagerA(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!svcCM)
        goto exit;

    svc = OpenServiceA(svcCM, name, GENERIC_EXECUTE);
    if (!svc)
        goto exit;

    if (!StartServiceA(svc, argc, argv))
        goto exit;

    rv = TRUE;

exit:
    if (svc)
        CloseServiceHandle(svc);
    if (svcCM)
        CloseServiceHandle(svcCM);
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
StartServiceSW(
    _In_z_     PCWSTR name,
    _In_       DWORD  argc,
    _In_opt_z_ PCWSTR argv[])
{
    BOOL rv = FALSE;
    SC_HANDLE svcCM = NULL;
    SC_HANDLE svc = NULL;

    svcCM = OpenSCManagerW(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!svcCM)
        goto exit;

    svc = OpenServiceW(svcCM, name, GENERIC_EXECUTE);
    if (!svc)
        goto exit;

    if (!StartServiceW(svc, argc, argv))
        goto exit;

    rv = TRUE;

exit:
    if (svc)
        CloseServiceHandle(svc);
    if (svcCM)
        CloseServiceHandle(svcCM);
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
StopServiceSA(
    _In_z_ PCSTR name)
{
    BOOL rv = FALSE;
    SC_HANDLE svcCM = NULL;
    SC_HANDLE svc = NULL;

    svcCM = OpenSCManagerA(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!svcCM)
        goto exit;

    svc = OpenServiceA(svcCM, name, GENERIC_EXECUTE);
    if (!svc)
        goto exit;

    SERVICE_STATUS status;
    if (!ControlService(svc, SERVICE_CONTROL_STOP, &status))
        goto exit;

    rv = TRUE;

exit:
    if (svc)
        CloseServiceHandle(svc);
    if (svcCM)
        CloseServiceHandle(svcCM);
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
StopServiceSW(
    _In_z_ PCWSTR name)
{
    BOOL rv = FALSE;
    SC_HANDLE svcCM = NULL;
    SC_HANDLE svc = NULL;

    svcCM = OpenSCManagerW(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!svcCM)
        goto exit;

    svc = OpenServiceW(svcCM, name, GENERIC_EXECUTE);
    if (!svc)
        goto exit;

    SERVICE_STATUS status;
    if (!ControlService(svc, SERVICE_CONTROL_STOP, &status))
        goto exit;

    rv = TRUE;

exit:
    if (svc)
        CloseServiceHandle(svc);
    if (svcCM)
        CloseServiceHandle(svcCM);
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
PauseServiceSA(
    _In_z_ PCSTR name)
{
    BOOL rv = FALSE;
    SC_HANDLE svcCM = NULL;
    SC_HANDLE svc = NULL;

    svcCM = OpenSCManagerA(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!svcCM)
        goto exit;

    svc = OpenServiceA(svcCM, name, GENERIC_EXECUTE);
    if (!svc)
        goto exit;

    SERVICE_STATUS status;
    if (!ControlService(svc, SERVICE_CONTROL_PAUSE, &status))
        goto exit;

    rv = TRUE;

exit:
    if (svc)
        CloseServiceHandle(svc);
    if (svcCM)
        CloseServiceHandle(svcCM);
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
PauseServiceSW(
    _In_z_ PCWSTR name)
{
    BOOL rv = FALSE;
    SC_HANDLE svcCM = NULL;
    SC_HANDLE svc = NULL;

    svcCM = OpenSCManagerW(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!svcCM)
        goto exit;

    svc = OpenServiceW(svcCM, name, GENERIC_EXECUTE);
    if (!svc)
        goto exit;

    SERVICE_STATUS status;
    if (!ControlService(svc, SERVICE_CONTROL_PAUSE, &status))
        goto exit;

    rv = TRUE;

exit:
    if (svc)
        CloseServiceHandle(svc);
    if (svcCM)
        CloseServiceHandle(svcCM);
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
ContinueServiceSA(
    _In_z_ PCSTR name)
{
    BOOL rv = FALSE;
    SC_HANDLE svcCM = NULL;
    SC_HANDLE svc = NULL;

    svcCM = OpenSCManagerA(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!svcCM)
        goto exit;

    svc = OpenServiceA(svcCM, name, GENERIC_EXECUTE);
    if (!svc)
        goto exit;

    SERVICE_STATUS status;
    if (!ControlService(svc, SERVICE_CONTROL_CONTINUE, &status))
        goto exit;

    rv = TRUE;

exit:
    if (svc)
        CloseServiceHandle(svc);
    if (svcCM)
        CloseServiceHandle(svcCM);
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
ContinueServiceSW(
    _In_z_ PCWSTR name)
{
    BOOL rv = FALSE;
    SC_HANDLE svcCM = NULL;
    SC_HANDLE svc = NULL;

    svcCM = OpenSCManagerW(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!svcCM)
        goto exit;

    svc = OpenServiceW(svcCM, name, GENERIC_EXECUTE);
    if (!svc)
        goto exit;

    SERVICE_STATUS status;
    if (!ControlService(svc, SERVICE_CONTROL_CONTINUE, &status))
        goto exit;

    rv = TRUE;

exit:
    if (svc)
        CloseServiceHandle(svc);
    if (svcCM)
        CloseServiceHandle(svcCM);
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RemoveServiceSA(
    _In_z_ PCSTR name)
{
    BOOL rv = FALSE;
    SC_HANDLE svcCM = NULL;
    SC_HANDLE svc = NULL;

    svcCM = OpenSCManagerA(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!svcCM)
        goto exit;

    svc = OpenServiceA(svcCM, name, DELETE);
    if (!svc)
        goto exit;

    if (!DeleteService(svc))
        goto exit;

    rv = TRUE;

exit:
    if (svc)
        CloseServiceHandle(svc);
    if (svcCM)
        CloseServiceHandle(svcCM);
    return rv;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RemoveServiceSW(
    _In_z_ PCWSTR name)
{
    BOOL rv = FALSE;
    SC_HANDLE svcCM = NULL;
    SC_HANDLE svc = NULL;

    svcCM = OpenSCManagerW(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!svcCM)
        goto exit;

    svc = OpenServiceW(svcCM, name, DELETE);
    if (!svc)
        goto exit;

    if (!DeleteService(svc))
        goto exit;

    rv = TRUE;

exit:
    if (svc)
        CloseServiceHandle(svc);
    if (svcCM)
        CloseServiceHandle(svcCM);
    return rv;
}
