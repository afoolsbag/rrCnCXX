/// \copyright Unlicense

#include "rrwindows/services/services.hxx"

#include <gsl/gsl>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/debug/error_handling.hxx"

using namespace std;
using namespace gsl;

namespace rrwindows {

RRWINDOWS_API service_status RRWINDOWS_CALL query_service_status(const char *name)
{
    CONST SC_HANDLE hScm {OpenSCManagerA(nullptr, nullptr, SC_MANAGER_ALL_ACCESS)};
    if (!hScm)
        throw system_error_exception("OpenSCManagerA failed", GetLastError());
    const auto finally_close_scm = finally([&] { CloseServiceHandle(hScm); });

    CONST SC_HANDLE hSer {OpenServiceA(hScm, reinterpret_cast<LPCSTR>(name), GENERIC_READ)};
    if (!hSer) {
        CONST DWORD dwError {GetLastError()};
        if (dwError == ERROR_SERVICE_DOES_NOT_EXIST)
            return service_status::not_exist;
        else
            throw system_error_exception("OpenServiceA failed", dwError);
    }
    const auto finally_close_ser = finally([&] { CloseServiceHandle(hSer); });

    SERVICE_STATUS stStat;
    if (!QueryServiceStatus(hSer, &stStat))
        throw system_error_exception("QueryServiceStatus failed", GetLastError());

    switch (stStat.dwCurrentState) {
    case SERVICE_STOPPED:
        return service_status::stopped;
    case SERVICE_START_PENDING:
        return service_status::start_pending;
    case SERVICE_STOP_PENDING:
        return service_status::stop_pending;
    case SERVICE_RUNNING:
        return service_status::running;
    case SERVICE_CONTINUE_PENDING:
        return service_status::continue_pending;
    case SERVICE_PAUSE_PENDING:
        return service_status::pause_pending;
    case SERVICE_PAUSED:
        return service_status::paused;
    default:
        throw range_error("unexpected switch-case routing: stStat.dwCurrentState=" + to_string(stStat.dwCurrentState));
    }
}

RRWINDOWS_API service_status RRWINDOWS_CALL query_service_status(const wchar_t *name)
{
    CONST SC_HANDLE hScm {OpenSCManagerW(nullptr, nullptr, SC_MANAGER_ALL_ACCESS)};
    if (!hScm)
        throw system_error_exception("OpenSCManagerA failed", GetLastError());
    const auto finally_close_scm = finally([&] { CloseServiceHandle(hScm); });

    CONST SC_HANDLE hSer {OpenServiceW(hScm, reinterpret_cast<LPCWSTR>(name), GENERIC_READ)};
    if (!hSer) {
        CONST DWORD dwError {GetLastError()};
        if (dwError == ERROR_SERVICE_DOES_NOT_EXIST)
            return service_status::not_exist;
        else
            throw system_error_exception("OpenServiceA failed", dwError);
    }
    const auto finally_close_ser = finally([&] { CloseServiceHandle(hSer); });

    SERVICE_STATUS stStat;
    if (!QueryServiceStatus(hSer, &stStat))
        throw system_error_exception("QueryServiceStatus failed", GetLastError());

    switch (stStat.dwCurrentState) {
    case SERVICE_STOPPED:
        return service_status::stopped;
    case SERVICE_START_PENDING:
        return service_status::start_pending;
    case SERVICE_STOP_PENDING:
        return service_status::stop_pending;
    case SERVICE_RUNNING:
        return service_status::running;
    case SERVICE_CONTINUE_PENDING:
        return service_status::continue_pending;
    case SERVICE_PAUSE_PENDING:
        return service_status::pause_pending;
    case SERVICE_PAUSED:
        return service_status::paused;
    default:
        throw range_error("unexpected switch-case routing: stStat.dwCurrentState=" + to_string(stStat.dwCurrentState));
    }
}

RRWINDOWS_API void RRWINDOWS_CALL install_service(const char *name, const char *display, const char *description, const char *path)
{
    CONST SC_HANDLE hScm = OpenSCManagerA(nullptr, nullptr, SC_MANAGER_ALL_ACCESS);
    if (!hScm)
        throw system_error_exception("OpenSCManagerA failed", GetLastError());
    const auto finally_close_scm = finally([&] { CloseServiceHandle(hScm); });

    CONST SC_HANDLE hSer {CreateServiceA(hScm,
                                         reinterpret_cast<LPCSTR>(name),
                                         reinterpret_cast<LPCSTR>(display),
                                         SERVICE_ALL_ACCESS,
                                         SERVICE_WIN32_OWN_PROCESS | SERVICE_INTERACTIVE_PROCESS,
                                         SERVICE_DEMAND_START,
                                         SERVICE_ERROR_NORMAL,
                                         reinterpret_cast<LPCSTR>(path),
                                         nullptr,
                                         nullptr,
                                         nullptr,
                                         nullptr,
                                         nullptr)};
    if (!hSer)
        throw system_error_exception("CreateServiceA failed", GetLastError());
    const auto finally_close_ser = finally([&] { CloseServiceHandle(hSer); });

    SERVICE_DESCRIPTIONA stSerDesc {const_cast<LPSTR>(description)};
    if (!ChangeServiceConfig2A(hSer, SERVICE_CONFIG_DESCRIPTION, &stSerDesc))
        throw system_error_exception("ChangeServiceConfig2A failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL install_service(const wchar_t *name, const wchar_t *display, const wchar_t *description, const wchar_t *path)
{
    CONST SC_HANDLE hScm = OpenSCManagerW(nullptr, nullptr, SC_MANAGER_ALL_ACCESS);
    if (!hScm)
        throw system_error_exception("OpenSCManagerW failed", GetLastError());
    const auto finally_close_scm = finally([&] { CloseServiceHandle(hScm); });

    CONST SC_HANDLE hSer {CreateServiceW(hScm,
                                         reinterpret_cast<LPCWSTR>(name),
                                         reinterpret_cast<LPCWSTR>(display),
                                         SERVICE_ALL_ACCESS,
                                         SERVICE_WIN32_OWN_PROCESS | SERVICE_INTERACTIVE_PROCESS,
                                         SERVICE_DEMAND_START,
                                         SERVICE_ERROR_NORMAL,
                                         reinterpret_cast<LPCWSTR>(path),
                                         nullptr,
                                         nullptr,
                                         nullptr,
                                         nullptr,
                                         nullptr)};
    if (!hSer)
        throw system_error_exception("CreateServiceW failed", GetLastError());
    const auto finally_close_ser = finally([&] { CloseServiceHandle(hSer); });

    SERVICE_DESCRIPTIONW stSerDesc {const_cast<LPWSTR>(description)};
    if (!ChangeServiceConfig2W(hSer, SERVICE_CONFIG_DESCRIPTION, &stSerDesc))
        throw system_error_exception("ChangeServiceConfig2W failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL start_service(const char *name, size_t argc, const char *argv[])
{
    CONST SC_HANDLE hScm {OpenSCManagerA(nullptr, nullptr, SC_MANAGER_ALL_ACCESS)};
    if (!hScm)
        throw system_error_exception("OpenSCManagerA failed", GetLastError());
    const auto finally_close_scm = finally([&] { CloseServiceHandle(hScm); });

    CONST SC_HANDLE hSer {OpenServiceA(hScm, reinterpret_cast<LPCSTR>(name), GENERIC_EXECUTE)};
    if (!hSer)
        throw system_error_exception("OpenServiceA failed", GetLastError());
    const auto finally_close_ser = finally([&] { CloseServiceHandle(hSer); });

    if (!StartServiceA(hSer,
                       static_cast<DWORD>(argc),
                       reinterpret_cast<LPCSTR *>(argv)))
        throw system_error_exception("StartServiceA failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL start_service(const wchar_t *name, size_t argc, const wchar_t *argv[])
{
    CONST SC_HANDLE hScm {OpenSCManagerW(nullptr, nullptr, SC_MANAGER_ALL_ACCESS)};
    if (!hScm)
        throw system_error_exception("OpenSCManagerW failed", GetLastError());
    const auto finally_close_scm = finally([&] { CloseServiceHandle(hScm); });

    CONST SC_HANDLE hSer {OpenServiceW(hScm, reinterpret_cast<LPCWSTR>(name), GENERIC_EXECUTE)};
    if (!hSer)
        throw system_error_exception("OpenServiceW failed", GetLastError());
    const auto finally_close_ser = finally([&] { CloseServiceHandle(hSer); });

    if (!StartServiceW(hSer,
                       static_cast<DWORD>(argc),
                       reinterpret_cast<LPCWSTR *>(argv)))
        throw system_error_exception("StartServiceW failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL stop_service(const char *name)
{
    CONST SC_HANDLE hScm {OpenSCManagerA(nullptr, nullptr, SC_MANAGER_ALL_ACCESS)};
    if (!hScm)
        throw system_error_exception("OpenSCManagerA failed", GetLastError());
    const auto finally_close_scm = finally([&] { CloseServiceHandle(hScm); });

    CONST SC_HANDLE hSer {OpenServiceA(hScm, reinterpret_cast<LPCSTR>(name), GENERIC_EXECUTE)};
    if (!hSer)
        throw system_error_exception("OpenServiceA failed", GetLastError());
    const auto finally_close_ser = finally([&] { CloseServiceHandle(hSer); });

    SERVICE_STATUS status;
    if (!ControlService(hSer, SERVICE_CONTROL_STOP, &status))
        throw system_error_exception("ControlService failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL stop_service(const wchar_t *name)
{
    CONST SC_HANDLE hScm {OpenSCManagerW(nullptr, nullptr, SC_MANAGER_ALL_ACCESS)};
    if (!hScm)
        throw system_error_exception("OpenSCManagerW failed", GetLastError());
    const auto finally_close_scm = finally([&] { CloseServiceHandle(hScm); });

    CONST SC_HANDLE hSer {OpenServiceW(hScm, reinterpret_cast<LPCWSTR>(name), GENERIC_EXECUTE)};
    if (!hSer)
        throw system_error_exception("OpenServiceW failed", GetLastError());
    const auto finally_close_ser = finally([&] { CloseServiceHandle(hSer); });

    SERVICE_STATUS status;
    if (!ControlService(hSer, SERVICE_CONTROL_STOP, &status))
        throw system_error_exception("ControlService failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL pause_service(const char *name)
{
    CONST SC_HANDLE hScm {OpenSCManagerA(nullptr, nullptr, SC_MANAGER_ALL_ACCESS)};
    if (!hScm)
        throw system_error_exception("OpenSCManagerA failed", GetLastError());
    const auto finally_close_scm = finally([&] { CloseServiceHandle(hScm); });

    CONST SC_HANDLE hSer {OpenServiceA(hScm, reinterpret_cast<LPCSTR>(name), GENERIC_EXECUTE)};
    if (!hSer)
        throw system_error_exception("OpenServiceA failed", GetLastError());
    const auto finally_close_ser = finally([&] { CloseServiceHandle(hSer); });

    SERVICE_STATUS status;
    if (!ControlService(hSer, SERVICE_CONTROL_PAUSE, &status))
        throw system_error_exception("ControlService failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL pause_service(const wchar_t *name)
{
    CONST SC_HANDLE hScm {OpenSCManagerW(nullptr, nullptr, SC_MANAGER_ALL_ACCESS)};
    if (!hScm)
        throw system_error_exception("OpenSCManagerW failed", GetLastError());
    const auto finally_close_scm = finally([&] { CloseServiceHandle(hScm); });

    CONST SC_HANDLE hSer {OpenServiceW(hScm, reinterpret_cast<LPCWSTR>(name), GENERIC_EXECUTE)};
    if (!hSer)
        throw system_error_exception("OpenServiceW failed", GetLastError());
    const auto finally_close_ser = finally([&] { CloseServiceHandle(hSer); });

    SERVICE_STATUS status;
    if (!ControlService(hSer, SERVICE_CONTROL_PAUSE, &status))
        throw system_error_exception("ControlService failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL continue_service(const char *name)
{
    CONST SC_HANDLE hScm {OpenSCManagerA(nullptr, nullptr, SC_MANAGER_ALL_ACCESS)};
    if (!hScm)
        throw system_error_exception("OpenSCManagerA failed", GetLastError());
    const auto finally_close_scm = finally([&] { CloseServiceHandle(hScm); });

    CONST SC_HANDLE hSer {OpenServiceA(hScm, reinterpret_cast<LPCSTR>(name), GENERIC_EXECUTE)};
    if (!hSer)
        throw system_error_exception("OpenServiceA failed", GetLastError());
    const auto finally_close_ser = finally([&] { CloseServiceHandle(hSer); });

    SERVICE_STATUS status;
    if (!ControlService(hSer, SERVICE_CONTROL_CONTINUE, &status))
        throw system_error_exception("ControlService failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL continue_service(const wchar_t *name)
{
    CONST SC_HANDLE hScm {OpenSCManagerW(nullptr, nullptr, SC_MANAGER_ALL_ACCESS)};
    if (!hScm)
        throw system_error_exception("OpenSCManagerW failed", GetLastError());
    const auto finally_close_scm = finally([&] { CloseServiceHandle(hScm); });

    CONST SC_HANDLE hSer {OpenServiceW(hScm, reinterpret_cast<LPCWSTR>(name), GENERIC_EXECUTE)};
    if (!hSer)
        throw system_error_exception("OpenServiceW failed", GetLastError());
    const auto finally_close_ser = finally([&] { CloseServiceHandle(hSer); });

    SERVICE_STATUS status;
    if (!ControlService(hSer, SERVICE_CONTROL_CONTINUE, &status))
        throw system_error_exception("ControlService failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL remove_service(const char *name)
{
    CONST SC_HANDLE hScm {OpenSCManagerA(nullptr, nullptr, SC_MANAGER_ALL_ACCESS)};
    if (!hScm)
        throw system_error_exception("OpenSCManagerA failed", GetLastError());
    const auto finally_close_scm = finally([&] { CloseServiceHandle(hScm); });

    CONST SC_HANDLE hSer {OpenServiceA(hScm, reinterpret_cast<LPCSTR>(name), DELETE)};
    if (!hSer)
        throw system_error_exception("OpenServiceA failed", GetLastError());
    const auto finally_close_ser = finally([&] { CloseServiceHandle(hSer); });

    if (!DeleteService(hSer))
        throw system_error_exception("DeleteService failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL remove_service(const wchar_t *name)
{
    CONST SC_HANDLE hScm {OpenSCManagerW(nullptr, nullptr, SC_MANAGER_ALL_ACCESS)};
    if (!hScm)
        throw system_error_exception("OpenSCManagerW failed", GetLastError());
    const auto finally_close_scm = finally([&] { CloseServiceHandle(hScm); });

    CONST SC_HANDLE hSer {OpenServiceW(hScm, reinterpret_cast<LPCWSTR>(name), DELETE)};
    if (!hSer)
        throw system_error_exception("OpenServiceW failed", GetLastError());
    const auto finally_close_ser = finally([&] { CloseServiceHandle(hSer); });

    if (!DeleteService(hSer))
        throw system_error_exception("DeleteService failed", GetLastError());
}

}
