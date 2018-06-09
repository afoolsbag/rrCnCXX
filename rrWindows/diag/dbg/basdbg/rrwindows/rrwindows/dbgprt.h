/*===-- Debug Print --------------------------------------------*- C -*-===*//**
 *
 * \defgroup gDbgPrt 调试打印
 * \ingroup gBasDbg
 *
 * \version 2018-06-09
 * \since 2018-05-26
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#pragma once

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/rrwindowsapi.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief 调试打印字串（ANSI适配）。
 * \warning 预设的缓存尺寸可能不足。
 */
RRWINDOWS_API VOID WINAPIV
DebugPrintA(
    _In_z_ _Printf_format_string_ LPCSTR CONST format,
    ...);

/**
 * \brief 调试打印字串（UNICODE适配）。
 * \warning 预设的缓存尺寸可能不足。
 */
RRWINDOWS_API VOID WINAPIV
DebugPrintW(
    _In_z_ _Printf_format_string_ LPCWSTR CONST format,
    ...);

#ifdef _UNICODE
# define DebugPrint DebugPrintW
#else
# define DebugPrint DebugPrintA
#endif

#ifdef __cplusplus
}
#endif

#ifdef _DEBUG
 /**
  * \brief 调试打印字串（调试适配）。
  * \details 形如`path/to/file.c(1337): @Function: ...`
  */
# define DbgPrtD(format, ...) DebugPrint(_T("%s(%d): @%s: ") format, _T(__FILE__), __LINE__, _T(__FUNCTION__), __VA_ARGS__)
 /**
  * \brief 函数名、函数修饰名和函数签名（调试适配）。
  * \details 形如`...: Function "F", decorated "_F", signature "void __cdecl F(void)".\\n`
  */
# define DbgPrtF() DbgPrtD(_T("Function \"%s\", decorated \"%s\", signature \"%s\".\n"), _T(__FUNCTION__), _T(__FUNCDNAME__), _T(__FUNCSIG__))
#else
 /**
  * \brief 调试打印字串（发布适配）。
  * \details 形如`@Function: ...`
  */
# define DbgPrtD(format, ...) DebugPrint(_T("@%s: ") format, _T(__FUNCTION__), __VA_ARGS__)
# define DbgPrtF() ((void)0)
#endif

/** @} */
