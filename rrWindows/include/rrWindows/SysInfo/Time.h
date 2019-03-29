/*===-- Time ---------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 时间。
 *
 * \version 2019-03-28
 * \since 2019-03-28
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrWindows/macros.h"

#define TIME_LESS_THAN    1
#define TIME_EQUAL        2
#define TIME_GREATER_THAN 3

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 时间比较。
 *
 * \param lhSysTime 左侧值。
 * \param rhSysTime 右侧值。
 * \returns `0`                 错误，调用 `GetLastError()` 获取扩展信息；\n
 *          `TIME_LESS_THAN`    左侧小于右侧；\n
 *          `TIME_EQUAL`        两侧相等；\n
 *          `TIME_GREATER_THAN` 左侧大于右侧。
 *
 * \since 2019-03-28
 */
RRWINDOWS_API
_Success_(return != 0)
INT
WINAPI
TimeCompare(
    _In_ CONST SYSTEMTIME *lhSysTime,
    _In_ CONST SYSTEMTIME *rhSysTime
);

RRWINDOWS_API extern CONST ULARGE_INTEGER TimeOneMicrosecond;
RRWINDOWS_API extern CONST ULARGE_INTEGER TimeOneMillisecond;
RRWINDOWS_API extern CONST ULARGE_INTEGER TimeOneSecond;
RRWINDOWS_API extern CONST ULARGE_INTEGER TimeOneMinute;
RRWINDOWS_API extern CONST ULARGE_INTEGER TimeOneHour;
RRWINDOWS_API extern CONST ULARGE_INTEGER TimeOneDay;
RRWINDOWS_API extern CONST ULARGE_INTEGER TimeOneWeek;

/**
 * \brief 时间左拨（减）。
 *
 * \param[in,out] sysTime 时间值。
 * \param[in]     delta   拨动值。
 *
 * \since 2019-03-28
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
TimeSub(
    _Inout_       SYSTEMTIME     *sysTime,
    _In_    CONST ULARGE_INTEGER *delta
);

/**
 * \brief 时间右拨（加）。
 *
 * \param[in,out] sysTime 时间值。
 * \param[in]     delta   拨动值。
 *
 * \since 2019-03-28
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
TimeAdd(
    _Inout_       SYSTEMTIME     *sysTime,
    _In_    CONST ULARGE_INTEGER *delta
);

#ifdef __cplusplus
}
#endif
