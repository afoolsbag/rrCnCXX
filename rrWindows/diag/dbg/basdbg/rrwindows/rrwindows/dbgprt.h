/*===-- Debug Print --------------------------------------------*- C -*-===*//**
 *
 * \defgroup gDbgPrt 调试打印
 * \ingroup gBasDbg
 *
 * \version 2018-05-26
 * \since 2018-05-26
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#pragma once

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

#ifdef UNICODE
# define DebugPrint DebugPrintW
#else
# define DebugPrint DebugPrintA
#endif
/** \brief 调试打印字串（缩写）。 */
#define DbgPrt DebugPrint

#ifdef __cplusplus
}
#endif

#ifdef _DEBUG
 /**
  * \brief 调试打印字串（调试适配）。
  * \details 形如`path/to/file.c(1337): @Func: ...`
  */
# define DbgPrtD(format, ...) DbgPrt(TEXT("%s(%d): @%s: ") format, TEXT(__FILE__), __LINE__, TEXT(__func__), __VA_ARGS__)
 /**
  * \brief 函数名、函数修饰名和函数签名（调试适配）。
  * \details 形如`...: Function "F", decorated "_F", signature "void __cdecl F(void)".\\n`
  */
# define DbgPrtF() DbgPrtD(TEXT("Function \"%s\", decorated \"%s\", signature \"%s\".\n"), TEXT(__FUNCTION__), TEXT(__FUNCDNAME__), TEXT(__FUNCSIG__))
#else
# define DbgPrtD DbgPrt
# define DbgPrtF() ((void)0)
#endif

/** @} */
