/// \copyright Unlicense

#include "rrwindows/intl/unicode_and_character_sets.hxx"

#include <memory>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/debug/error_handling.hxx"

using namespace std;

namespace rrwindows {

RRWINDOWS_API wstring RRWINDOWS_CALL multi_byte_to_wide_char(const char *src, unsigned srccp)
{
    CONST INT iCnt = MultiByteToWideChar(static_cast<UINT>(srccp),
                                         0,
                                         reinterpret_cast<LPCCH>(src),
                                         -1,
                                         nullptr,
                                         0);
    if (iCnt == 0)
        throw system_error_exception("MultiByteToWideChar failed", GetLastError());
    const auto buf = make_unique<wchar_t[]>(iCnt);
    if (!buf)
        throw bad_alloc();
    if (!MultiByteToWideChar(static_cast<UINT>(srccp),
                             0,
                             reinterpret_cast<LPCCH>(src),
                             -1,
                             reinterpret_cast<LPWSTR>(buf.get()),
                             iCnt))
        throw system_error_exception("MultiByteToWideChar failed", GetLastError());
    return buf.get();
}

RRWINDOWS_API string RRWINDOWS_CALL wide_char_to_multi_byte(const wchar_t *src, unsigned dstcp)
{
    CONST INT iCnt = WideCharToMultiByte(static_cast<UINT>(dstcp),
                                         0,
                                         reinterpret_cast<LPCWCH>(src),
                                         -1,
                                         nullptr,
                                         0,
                                         nullptr,
                                         nullptr);
    if (iCnt == 0)
        throw system_error_exception("WideCharToMultiByte failed", GetLastError());
    const auto buf = make_unique<char[]>(iCnt);
    if (!buf)
        throw bad_alloc();
    if (!WideCharToMultiByte(static_cast<UINT>(dstcp),
                             0,
                             reinterpret_cast<LPCWCH>(src),
                             -1,
                             reinterpret_cast<LPSTR>(buf.get()),
                             iCnt,
                             nullptr,
                             nullptr))
        throw system_error_exception("WideCharToMultiByte failed", GetLastError());
    return buf.get();
}

RRWINDOWS_API string RRWINDOWS_CALL multi_byte_to_multi_byte(const char *src, unsigned srccp, unsigned dstcp)
{
    return wide_char_to_multi_byte(multi_byte_to_wide_char(src, srccp), dstcp);
}

}
