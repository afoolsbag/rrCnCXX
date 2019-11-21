/// \copyright Unlicense

#include "rrwindows/menurc/strings.hxx"

#include <cstring>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <strsafe.h>

#include "rrwindows/debug/error_handling.hxx"

using namespace std;

namespace rrwindows {

RRWINDOWS_API int RRWINDOWS_CALL strcmp(const char *lhs, const char *rhs)
{
    if (!lhs || !rhs)
        throw invalid_argument_exception(__FUNCTION__);
    return std::strcmp(lhs, rhs);
}

RRWINDOWS_API int RRWINDOWS_CALL strcmp(const wchar_t *lhs, const wchar_t *rhs)
{
    switch (CompareStringOrdinal(reinterpret_cast<LPCWCH>(lhs),
                                 -1,
                                 reinterpret_cast<LPCWCH>(rhs),
                                 -1,
                                 FALSE)) {
    case CSTR_LESS_THAN:
        return -1;
    case CSTR_EQUAL:
        return 0;
    case CSTR_GREATER_THAN:
        return 1;
    default:
        throw system_error_exception("CompareStringOrdinal failed", GetLastError());
    }
}

RRWINDOWS_API size_t RRWINDOWS_CALL strlen(const char *str)
{
    size_t sizLen;
    CONST HRESULT hr = StringCchLengthA(str, STRSAFE_MAX_CCH, &sizLen);
    if (FAILED(hr))
        throw system_error_exception("StringCchLengthA failed", HRESULT_CODE(hr));
    return sizLen;
}

RRWINDOWS_API size_t RRWINDOWS_CALL strlen(const wchar_t *str)
{
    size_t sizLen;
    CONST HRESULT hr = StringCchLengthW(str, STRSAFE_MAX_CCH, &sizLen);
    if (FAILED(hr))
        throw system_error_exception("StringCchLengthW failed", HRESULT_CODE(hr));
    return sizLen;
}

}
