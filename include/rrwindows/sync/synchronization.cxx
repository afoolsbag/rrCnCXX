/// \copyright Unlicense

#include "rrwindows/sync/synchronization.hxx"

#include <gsl/gsl>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/debug/error_handling.hxx"

using namespace std;
using namespace gsl;

namespace rrwindows {

RRWINDOWS_API bool RRWINDOWS_CALL is_singleton_process(const char *identifier)
{
    CONST HANDLE hMutex {OpenMutexA(MUTEX_ALL_ACCESS, FALSE, reinterpret_cast<LPCSTR>(identifier))};
    if (hMutex) {
        CloseHandle(hMutex);
        return false;
    }
    CONST DWORD dwError {GetLastError()};
    if (dwError != ERROR_FILE_NOT_FOUND)
        throw system_error_exception("OpenMutexA failed", dwError);

    if (!CreateMutexA(nullptr, FALSE, reinterpret_cast<LPCSTR>(identifier)))
        throw system_error_exception("CreateMutexA failed", GetLastError());
    return true;
}

RRWINDOWS_API bool RRWINDOWS_CALL is_singleton_process(const wchar_t *identifier)
{
    CONST HANDLE hMutex {OpenMutexW(MUTEX_ALL_ACCESS, FALSE, reinterpret_cast<LPCWSTR>(identifier))};
    if (hMutex) {
        CloseHandle(hMutex);
        return false;
    }
    CONST DWORD dwError {GetLastError()};
    if (dwError != ERROR_FILE_NOT_FOUND)
        throw system_error_exception("OpenMutexW failed", dwError);

    if (!CreateMutexW(nullptr, FALSE, reinterpret_cast<LPCWSTR>(identifier)))
        throw system_error_exception("CreateMutexW failed", GetLastError());
    return true;
}

}
