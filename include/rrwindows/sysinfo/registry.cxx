/// \copyright Unlicense

#include "rrwindows/sysinfo/registry.hxx"

#include <gsl/gsl>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/debug/error_handling.hxx"

using namespace std;
using namespace gsl;

namespace rrwindows {

RRWINDOWS_API void RRWINDOWS_CALL write_ini(const char *path, const char *section, const char *key, const char *value)
{
    if (!WritePrivateProfileStringA(reinterpret_cast<LPCSTR>(section),
                                    reinterpret_cast<LPCSTR>(key),
                                    reinterpret_cast<LPCSTR>(value),
                                    reinterpret_cast<LPCSTR>(path)))
        throw system_error_exception("WritePrivateProfileStringA failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL write_ini(const wchar_t *path, const wchar_t *section, const wchar_t *key, const wchar_t *value)
{
    if (!WritePrivateProfileStringW(reinterpret_cast<LPCWSTR>(section),
                                    reinterpret_cast<LPCWSTR>(key),
                                    reinterpret_cast<LPCWSTR>(value),
                                    reinterpret_cast<LPCWSTR>(path)))
        throw system_error_exception("WritePrivateProfileStringW failed", GetLastError());
}

RRWINDOWS_API string RRWINDOWS_CALL read_ini(const char *path, const char *section, const char *key, const char *default_value)
{
    unique_ptr<CHAR[]> buf {};
    for (size_t cchCnt = 128; ; cchCnt *= 2) {
        buf = make_unique<CHAR[]>(cchCnt);
        CONST DWORD dwCopy {GetPrivateProfileStringA(reinterpret_cast<LPCSTR>(section),
                                                     reinterpret_cast<LPCSTR>(key),
                                                     reinterpret_cast<LPCSTR>(default_value),
                                                     reinterpret_cast<LPSTR>(buf.get()),
                                                     static_cast<DWORD>(cchCnt),
                                                     reinterpret_cast<LPCSTR>(path))};
        if (dwCopy + 2 < cchCnt)
            return buf.get();
    }
}

RRWINDOWS_API wstring RRWINDOWS_CALL read_ini(const wchar_t *path, const wchar_t *section, const wchar_t *key, const wchar_t *default_value)
{
    unique_ptr<WCHAR[]> buf {};
    for (size_t cchCnt = 128; ; cchCnt *= 2) {
        buf = make_unique<WCHAR[]>(cchCnt);
        CONST DWORD dwCopy {GetPrivateProfileStringW(reinterpret_cast<LPCWSTR>(section),
                                                     reinterpret_cast<LPCWSTR>(key),
                                                     reinterpret_cast<LPCWSTR>(default_value),
                                                     reinterpret_cast<LPWSTR>(buf.get()),
                                                     static_cast<DWORD>(cchCnt),
                                                     reinterpret_cast<LPCWSTR>(path))};
        if (dwCopy + 2 < cchCnt)
            return buf.get();
    }
}

RRWINDOWS_API int RRWINDOWS_CALL read_ini(const char *path, const char *section, const char *key, int default_value)
{
    return GetPrivateProfileIntA(reinterpret_cast<LPCSTR>(section),
                                 reinterpret_cast<LPCSTR>(key),
                                 static_cast<INT>(default_value),
                                 reinterpret_cast<LPCSTR>(path));
}

RRWINDOWS_API int RRWINDOWS_CALL read_ini(const wchar_t *path, const wchar_t *section, const wchar_t *key, int default_value)
{
    return GetPrivateProfileIntW(reinterpret_cast<LPCWSTR>(section),
                                 reinterpret_cast<LPCWSTR>(key),
                                 static_cast<INT>(default_value),
                                 reinterpret_cast<LPCWSTR>(path));
}

}
