/// \copyright Unlicense

#include "rrwindows/debug/error_handling.hxx"

#include <string>
#include <gsl/gsl>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

using namespace std;
using namespace gsl;

namespace rrwindows {

RRWINDOWS_API string RRWINDOWS_CALL system_error_message(uint32_t error_code) noexcept
{
    LPSTR lpBuf = nullptr;
    CONST DWORD dwLen = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                       nullptr, static_cast<DWORD>(error_code), LANG_USER_DEFAULT, reinterpret_cast<LPSTR>(&lpBuf), 0, nullptr);
    if (dwLen == 0)
        return string(__FUNCTION__).append(" failed with code ").append(to_string(GetLastError()));
    const auto finally_local_free = finally([&] { LocalFree(lpBuf); });
    if (2 <= dwLen)
        lpBuf[dwLen - 2] = '\0';
    return lpBuf;
}

RRWINDOWS_API wstring RRWINDOWS_CALL system_error_wmessage(uint32_t error_code) noexcept
{
    LPWSTR lpBuf {nullptr};
    CONST DWORD dwLen = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                       nullptr, static_cast<DWORD>(error_code), LANG_USER_DEFAULT, reinterpret_cast<LPWSTR>(&lpBuf), 0, nullptr);
    if (dwLen == 0)
        return wstring(__FUNCTIONW__).append(L" failed with code ").append(to_wstring(GetLastError()));
    const auto finally_local_free = finally([&] { LocalFree(lpBuf); });
    if (2 <= dwLen)
        lpBuf[dwLen - 2] = L'\0';
    return lpBuf;
}

}
