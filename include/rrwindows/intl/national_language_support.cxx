/// \copyright Unlicense

#include "rrwindows/intl/national_language_support.hxx"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/debug/error_handling.hxx"

namespace rrwindows {

RRWINDOWS_API int RRWINDOWS_CALL compare_string_invariant(const char *lhs, const char *rhs)
{
    switch (CompareStringA(LOCALE_INVARIANT,
                           0,
                           reinterpret_cast<PCNZCH>(lhs),
                           -1,
                           reinterpret_cast<PCNZCH>(rhs),
                           -1)) {
    case CSTR_LESS_THAN:
        return -1;
    case CSTR_EQUAL:
        return 0;
    case CSTR_GREATER_THAN:
        return 1;
    default:
        throw system_error_exception("CompareStringA failed", GetLastError());
    }
}

RRWINDOWS_API int RRWINDOWS_CALL compare_string_invariant(const wchar_t *lhs, const wchar_t *rhs)
{
    switch (CompareStringEx(LOCALE_NAME_INVARIANT,
                            0,
                            reinterpret_cast<LPCWCH>(lhs),
                            -1,
                            reinterpret_cast<LPCWCH>(rhs),
                            -1,
                            nullptr,
                            nullptr,
                            0)) {
    case CSTR_LESS_THAN:
        return -1;
    case CSTR_EQUAL:
        return 0;
    case CSTR_GREATER_THAN:
        return 1;
    default:
        throw system_error_exception("CompareStringEx failed", GetLastError());
    }
}

RRWINDOWS_API int RRWINDOWS_CALL compare_string_system_default(const char *lhs, const char *rhs)
{
    switch (CompareStringA(LOCALE_SYSTEM_DEFAULT,
                           0,
                           reinterpret_cast<PCNZCH>(lhs),
                           -1,
                           reinterpret_cast<PCNZCH>(rhs),
                           -1)) {
    case CSTR_LESS_THAN:
        return -1;
    case CSTR_EQUAL:
        return 0;
    case CSTR_GREATER_THAN:
        return 1;
    default:
        throw system_error_exception("CompareStringA failed", GetLastError());
    }
}

RRWINDOWS_API int RRWINDOWS_CALL compare_string_system_default(const wchar_t *lhs, const wchar_t *rhs)
{
    switch (CompareStringEx(LOCALE_NAME_SYSTEM_DEFAULT,
                            0,
                            reinterpret_cast<LPCWCH>(lhs),
                            -1,
                            reinterpret_cast<LPCWCH>(rhs),
                            -1,
                            nullptr,
                            nullptr,
                            0)) {
    case CSTR_LESS_THAN:
        return -1;
    case CSTR_EQUAL:
        return 0;
    case CSTR_GREATER_THAN:
        return 1;
    default:
        throw system_error_exception("CompareStringEx failed", GetLastError());
    }
}

RRWINDOWS_API int RRWINDOWS_CALL compare_string_user_default(const char *lhs, const char *rhs)
{
    switch (CompareStringA(LOCALE_USER_DEFAULT,
                           0,
                           reinterpret_cast<PCNZCH>(lhs),
                           -1,
                           reinterpret_cast<PCNZCH>(rhs),
                           -1)) {
    case CSTR_LESS_THAN:
        return -1;
    case CSTR_EQUAL:
        return 0;
    case CSTR_GREATER_THAN:
        return 1;
    default:
        throw system_error_exception("CompareStringA failed", GetLastError());
    }
}

RRWINDOWS_API int RRWINDOWS_CALL compare_string_user_default(const wchar_t *lhs, const wchar_t *rhs)
{
    switch (CompareStringEx(LOCALE_NAME_USER_DEFAULT,
                            0,
                            reinterpret_cast<LPCWCH>(lhs),
                            -1,
                            reinterpret_cast<LPCWCH>(rhs),
                            -1,
                            nullptr,
                            nullptr,
                            0)) {
    case CSTR_LESS_THAN:
        return -1;
    case CSTR_EQUAL:
        return 0;
    case CSTR_GREATER_THAN:
        return 1;
    default:
        throw system_error_exception("CompareStringEx failed", GetLastError());
    }
}

}
