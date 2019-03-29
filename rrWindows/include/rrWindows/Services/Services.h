/*===-- Services -----------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 服务。
 *
 * \version 2019-03-29
 * \since 2019-03-29
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrWindows/macros.h"

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 查询服务状态，Simplify 接口，ANSI 适配。
 *
 * \param[in]  name    服务名。
 * \param[out] pStatus 状态。
 * \returns `!FALSE` 成功；\n
 *           `FALSE` 失败，可调用 `GetLastError()` 获取扩展错误信息。
 * 
 * \version 2019-03-29
 * \since 2019-03-29
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
QueryServiceStatusSA(
    _In_z_ PCSTR            name,
    _Out_  LPSERVICE_STATUS pStatus
);

/**
 * \brief 查询服务状态，Simplify 接口，Unicode 适配。
 *
 * \param[in]  name    服务名。
 * \param[out] pStatus 状态。
 * \returns `!FALSE` 成功；\n
 *           `FALSE` 失败，可调用 `GetLastError()` 获取扩展错误信息。
 * 
 * \version 2019-03-29
 * \since 2019-03-29
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
QueryServiceStatusSW(
    _In_z_ PCWSTR           name,
    _Out_  LPSERVICE_STATUS pStatus
);

#ifdef _UNICODE
# define QueryServiceStatusS QueryServiceStatusSW
#else
# define QueryServiceStatusS QueryServiceStatusSA
#endif

/**
 * \brief 服务是否启动，Simplify 接口，ANSI 适配。
 *
 * \param name 服务名。
 * \returns `!FALSE` 成功；\n
 *           `FALSE` 失败，可调用 `GetLastError()` 获取扩展错误信息。
 * 
 * \version 2019-03-29
 * \since 2019-03-29
 */
FORCEINLINE
BOOL
WINAPI_INLINE
ServiceIsRunningA(
    _In_z_ PCSTR name)
{
    SERVICE_STATUS status;
    if (QueryServiceStatusSA(name, &status))
        if (status.dwCurrentState == SERVICE_RUNNING)
            return TRUE;
    return FALSE;
}

/**
 * \brief 服务是否启动，Simplify 接口，Unicode 适配。
 *
 * \param name 服务名。
 * \returns `!FALSE` 成功；\n
 *           `FALSE` 失败，可调用 `GetLastError()` 获取扩展错误信息。
 * 
 * \version 2019-03-29
 * \since 2019-03-29
 */
FORCEINLINE
BOOL
WINAPI_INLINE
ServiceIsRunningW(
    _In_z_ PCWSTR name)
{
    SERVICE_STATUS status;
    if (QueryServiceStatusSW(name, &status))
        if (status.dwCurrentState == SERVICE_RUNNING)
            return TRUE;
    return FALSE;
}

#ifdef _UNICODE
# define ServiceIsRunning ServiceIsRunningW
#else
# define ServiceIsRunning ServiceIsRunningA
#endif

/**
 * \brief 启动服务，Simplify 接口，ANSI 适配。
 *
 * \param name 服务名；
 * \param argc 参数计数
 * \param argv 参数列表，可为 `NULL`
 * \returns `!FALSE` 成功；\n
 *           `FALSE` 失败，可调用 `GetLastError()` 获取扩展错误信息。
 * 
 * \version 2019-03-29
 * \since 2019-03-29
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
StartServiceSA(
    _In_z_     PCSTR name,
    _In_       DWORD argc,
    _In_opt_z_ PCSTR argv[]
);

/**
 * \brief 启动服务，Simplify 接口，Unicode 适配。
 *
 * \param name 服务名；
 * \param argc 参数计数
 * \param argv 参数列表，可为 `NULL`
 * \returns `!FALSE` 成功；\n
 *           `FALSE` 失败，可调用 `GetLastError()` 获取扩展错误信息。
 * 
 * \version 2019-03-29
 * \since 2019-03-29
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
StartServiceSW(
    _In_z_     PCWSTR name,
    _In_       DWORD  argc,
    _In_opt_z_ PCWSTR argv[]
);

#ifdef _UNICODE
# define StartServiceS StartServiceSW
#else
# define StartServiceS StartServiceSA
#endif

/**
 * \brief 停止服务，Simplify 接口，ANSI 适配。
 *
 * \param name 服务名。
 * \returns `!FALSE` 成功；\n
 *           `FALSE` 失败，可调用 `GetLastError()` 获取扩展错误信息。
 * 
 * \version 2019-03-29
 * \since 2019-03-29
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
StopServiceSA(
    _In_z_ PCSTR name
);

/**
 * \brief 停止服务，Simplify 接口，Unicode 适配。
 *
 * \param name 服务名。
 * \returns `!FALSE` 成功；\n
 *           `FALSE` 失败，可调用 `GetLastError()` 获取扩展错误信息。
 * 
 * \version 2019-03-29
 * \since 2019-03-29
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
StopServiceSW(
    _In_z_ PCWSTR name
);

#ifdef _UNICODE
# define StopServiceS StopServiceSW
#else
# define StopServiceS StopServiceSA
#endif

/**
 * \brief 暂停服务，Simplify 接口，ANSI 适配。
 *
 * \param name 服务名。
 * \returns `!FALSE` 成功；\n
 *           `FALSE` 失败，可调用 `GetLastError()` 获取扩展错误信息。
 * 
 * \version 2019-03-29
 * \since 2019-03-29
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
PauseServiceSA(
    _In_z_ PCSTR name
);

/**
 * \brief 暂停服务，Simplify 接口，Unicode 适配。
 *
 * \param name 服务名。
 * \returns `!FALSE` 成功；\n
 *           `FALSE` 失败，可调用 `GetLastError()` 获取扩展错误信息。
 * 
 * \version 2019-03-29
 * \since 2019-03-29
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
PauseServiceSW(
    _In_z_ PCWSTR name
);

#ifdef _UNICODE
# define PauseServiceS PauseServiceSW
#else
# define PauseServiceS PauseServiceSA
#endif

/**
 * \brief 继续服务，Simplify 接口，ANSI 适配。
 *
 * \param name 服务名。
 * \returns `!FALSE` 成功；\n
 *           `FALSE` 失败，可调用 `GetLastError()` 获取扩展错误信息。
 * 
 * \version 2019-03-29
 * \since 2019-03-29
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
ContinueServiceSA(
    _In_z_ PCSTR name
);

/**
 * \brief 继续服务，Simplify 接口，Unicode 适配。
 *
 * \param name 服务名。
 * \returns `!FALSE` 成功；\n
 *           `FALSE` 失败，可调用 `GetLastError()` 获取扩展错误信息。
 * 
 * \version 2019-03-29
 * \since 2019-03-29
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
ContinueServiceSW(
    _In_z_ PCWSTR name
);

#ifdef _UNICODE
# define ContinueServiceS ContinueServiceSW
#else
# define ContinueServiceS ContinueServiceSA
#endif

/**
 * \brief 卸载服务，Simplify 接口，ANSI 适配。
 *
 * \param name 服务名。
 * \returns `!FALSE` 成功；\n
 *           `FALSE` 失败，可调用 `GetLastError()` 获取扩展错误信息。
 * 
 * \version 2019-03-29
 * \since 2019-03-29
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RemoveServiceSA(
    _In_z_ PCSTR name
);

/**
 * \brief 卸载服务，Simplify 接口，Unicode 适配。
 *
 * \param name 服务名。
 * \returns `!FALSE` 成功；\n
 *           `FALSE` 失败，可调用 `GetLastError()` 获取扩展错误信息。
 * 
 * \version 2019-03-29
 * \since 2019-03-29
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
RemoveServiceSW(
    _In_z_ PCWSTR name
);

#ifdef _UNICODE
# define RemoveServiceS RemoveServiceSW
#else
# define RemoveServiceS RemoveServiceSA
#endif

#ifdef __cplusplus
}
#endif
