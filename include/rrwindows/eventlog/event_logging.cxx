/// \copyright Unlicense


#include "rrwindows/eventlog/event_logging.hxx"

#include <gsl/gsl>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/debug/error_handling.hxx"

using namespace std;
using namespace gsl;

namespace rrwindows {

RRWINDOWS_API void RRWINDOWS_CALL log_event(const char *src, uint16_t type, const char *msg)
{
    CONST HANDLE hEventSrc {RegisterEventSourceA(nullptr, reinterpret_cast<LPCSTR>(src))};
    if (!hEventSrc)
        throw system_error_exception("RegisterEventSourceA failed", GetLastError());
    const auto finally_clost_src = finally([&] { DeregisterEventSource(hEventSrc); });

    LPCSTR aszStrings[2] {src, msg};
    if (!ReportEventA(hEventSrc,
                      static_cast<WORD>(type),
                      0,
                      0,
                      nullptr,
                      2,
                      0,
                      aszStrings,
                      nullptr))
        throw system_error_exception("ReportEventA failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL log_event(const wchar_t *src, uint16_t type, const wchar_t *msg)
{
    CONST HANDLE hEventSrc {RegisterEventSourceW(nullptr, reinterpret_cast<LPCWSTR>(src))};
    if (!hEventSrc)
        throw system_error_exception("RegisterEventSourceW failed", GetLastError());
    const auto finally_clost_src = finally([&] { DeregisterEventSource(hEventSrc); });

    LPCWSTR aszStrings[2] {src, msg};
    if (!ReportEventW(hEventSrc,
                      static_cast<WORD>(type),
                      0,
                      0,
                      nullptr,
                      2,
                      0,
                      aszStrings,
                      nullptr))
        throw system_error_exception("ReportEventW failed", GetLastError());
}

}
