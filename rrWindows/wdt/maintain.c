/**
 * \copyright Unlicense
 */

#include "maintain.h"

#include <tchar.h>

#include "rrWindows/rrWindows.h"

#include "eventlog.h"
#include "service.h"

VOID Maintain(MaintainType type)
{
    SC_HANDLE serviceCM = NULL;
    SC_HANDLE service = NULL;
    PCTSTR errorMessage = NULL;

    switch (type) {
    case Install:  _tprintf(_T("Installing %s...\n"), ServiceDisplayName); break;
    case Start:    _tprintf(_T("Starting %s...\n"),   ServiceDisplayName); break;
    case Stop:     _tprintf(_T("Stopping %s...\n"),   ServiceDisplayName); break;
    case Pause:    _tprintf(_T("Pausing %s...\n"),    ServiceDisplayName); break;
    case Continue: _tprintf(_T("Continuing %s...\n"), ServiceDisplayName); break;
    case Remove:   _tprintf(_T("Removing %s...\n"),   ServiceDisplayName); break;
    default:       _putts(_T("Unexpected switch-case routing.\n"));        break;
    }

    serviceCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
    if (!serviceCM) {
        errorMessage = FormatMessageS(GetLastError());
        _ftprintf(stderr, _T("OpenSCManager failed: %s\n"), errorMessage);
        goto exit;
    }

    if (type == Install) {
        TCHAR path[MAX_PATH];
        if (!GetModuleFileName(NULL, path, MAX_PATH)) {
            errorMessage = FormatMessageS(GetLastError());
            _ftprintf(stderr, _T("GetModuleFileName failed: %s\n"), errorMessage);
            goto exit;
        }

        service = CreateService(
            serviceCM, ServiceName, ServiceDisplayName,
            SERVICE_ALL_ACCESS, SERVICE_WIN32_OWN_PROCESS, SERVICE_DEMAND_START, SERVICE_ERROR_NORMAL,
            path, NULL, NULL, NULL, NULL, NULL);
        if (!service) {
            errorMessage = FormatMessageS(GetLastError());
            _ftprintf(stderr, _T("CreateService failed: %s\n"), errorMessage);
            goto exit;
        }

#pragma warning(push)
#pragma warning(disable: 4204)
        SERVICE_DESCRIPTION sd = {(PTSTR)ServiceDescription};
#pragma warning(pop)
        ChangeServiceConfig2(service, SERVICE_CONFIG_DESCRIPTION, &sd);

    } else if (type == Remove) {
        service = OpenService(serviceCM, ServiceName, DELETE);
        if (!service) {
            errorMessage = FormatMessageS(GetLastError());
            _ftprintf(stderr, _T("OpenService failed: %s\n"), errorMessage);
            goto exit;
        }

        if (!DeleteService(service)) {
            errorMessage = FormatMessageS(GetLastError());
            _ftprintf(stderr, _T("DeleteService failed: %s\n"), errorMessage);
            goto exit;
        }

    } else /* Start, Stop, Pause or Continue */ {
        service = OpenService(serviceCM, ServiceName, GENERIC_EXECUTE);
        if (!service) {
            errorMessage = FormatMessageS(GetLastError());
            _ftprintf(stderr, _T("OpenService failed: %s\n"), errorMessage);
            goto exit;
        }

        SERVICE_STATUS status;

        switch (type) {
        case Start:
            if (!StartService(service, 0, NULL)) {
                errorMessage = FormatMessageS(GetLastError());
                _ftprintf(stderr, _T("StartService failed: %s\n"), errorMessage);
                goto exit;
            }
            break;

        case Stop:
            if (!ControlService(service, SERVICE_CONTROL_STOP, &status)) {
                errorMessage = FormatMessageS(GetLastError());
                _ftprintf(stderr, _T("ControlService failed: %s\n"), errorMessage);
                goto exit;
            }
            break;

        case Pause:
            if (!ControlService(service, SERVICE_CONTROL_PAUSE, &status)) {
                errorMessage = FormatMessageS(GetLastError());
                _ftprintf(stderr, _T("ControlService failed: %s\n"), errorMessage);
                goto exit;
            }
            break;

        case Continue:
            if (!ControlService(service, SERVICE_CONTROL_CONTINUE, &status)) {
                errorMessage = FormatMessageS(GetLastError());
                _ftprintf(stderr, _T("ControlService failed: %s\n"), errorMessage);
                goto exit;
            }
            break;

        default:
            _fputts(_T("Unexpected switch-case routing.\n"), stderr);
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
    if (errorMessage)
        LocalFree((HLOCAL)errorMessage);
    if (service)
        CloseServiceHandle(service);
    if (serviceCM)
        CloseServiceHandle(serviceCM);
}
