/**
 * \copyright Unlicense
 */

#define RRWINDOWS_EXPORTS
#include "rrWindows/SysInfo/Time.h"

RRWINDOWS_API
_Success_(return != 0)
INT
WINAPI
TimeCompare(
    _In_ CONST SYSTEMTIME *lhSysTime,
    _In_ CONST SYSTEMTIME *rhSysTime)
{
    FILETIME lhFileTime;
    if (!SystemTimeToFileTime(lhSysTime, &lhFileTime))
        return 0;
    ULARGE_INTEGER lhLargeTime;
    lhLargeTime.LowPart = lhFileTime.dwLowDateTime;
    lhLargeTime.HighPart = lhFileTime.dwHighDateTime;

    FILETIME rhFileTime;
    if (!SystemTimeToFileTime(rhSysTime, &rhFileTime))
        return 0;
    ULARGE_INTEGER rhLargeTime;
    rhLargeTime.LowPart = rhFileTime.dwLowDateTime;
    rhLargeTime.HighPart = rhFileTime.dwHighDateTime;

    if (lhLargeTime.QuadPart < rhLargeTime.QuadPart)
        return TIME_LESS_THAN;
    else if (lhLargeTime.QuadPart == rhLargeTime.QuadPart)
        return TIME_EQUAL;
    else
        return TIME_GREATER_THAN;
}

RRWINDOWS_API CONST ULARGE_INTEGER TimeOneMicrosecond = {.QuadPart = 10uLL};
RRWINDOWS_API CONST ULARGE_INTEGER TimeOneMilliseconds = {.QuadPart = 1000uLL * 10uLL};
RRWINDOWS_API CONST ULARGE_INTEGER TimeOneSecond = {.QuadPart = 1000uLL * 1000uLL * 10uLL};
RRWINDOWS_API CONST ULARGE_INTEGER TimeOneMinute = {.QuadPart = 60uLL * 1000uLL * 1000uLL * 10uLL};
RRWINDOWS_API CONST ULARGE_INTEGER TimeOneHour = {.QuadPart = 60uLL * 60uLL * 1000uLL * 1000uLL * 10uLL};
RRWINDOWS_API CONST ULARGE_INTEGER TimeOneDay = {.QuadPart = 24uLL * 60uLL * 60uLL * 1000uLL * 1000uLL * 10uLL};
RRWINDOWS_API CONST ULARGE_INTEGER TimeOneWeek = {.QuadPart = 7uLL * 24uLL * 60uLL * 60uLL * 1000uLL * 1000uLL * 10uLL};

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
TimeSub(
    _Inout_       SYSTEMTIME     *sysTime,
    _In_    CONST ULARGE_INTEGER *delta)
{
    FILETIME fileTime;
    if (!SystemTimeToFileTime(sysTime, &fileTime))
        return FALSE;
    ULARGE_INTEGER largeTime;
    largeTime.LowPart = fileTime.dwLowDateTime;
    largeTime.HighPart = fileTime.dwHighDateTime;

    largeTime.QuadPart -= delta->QuadPart;

    fileTime.dwLowDateTime = largeTime.LowPart;
    fileTime.dwHighDateTime = largeTime.HighPart;
    if (!FileTimeToSystemTime(&fileTime, sysTime))
        return FALSE;

    return TRUE;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
TimeAdd(
    _Inout_       SYSTEMTIME     *sysTime,
    _In_    CONST ULARGE_INTEGER *delta)
{
    FILETIME fileTime;
    if (!SystemTimeToFileTime(sysTime, &fileTime))
        return FALSE;
    ULARGE_INTEGER largeTime;
    largeTime.LowPart = fileTime.dwLowDateTime;
    largeTime.HighPart = fileTime.dwHighDateTime;

    largeTime.QuadPart += delta->QuadPart;

    fileTime.dwLowDateTime = largeTime.LowPart;
    fileTime.dwHighDateTime = largeTime.HighPart;
    if (!FileTimeToSystemTime(&fileTime, sysTime))
        return FALSE;

    return TRUE;
}
