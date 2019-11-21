//===-- Application Programming Interface Macros ----------------*- C++ -*-===//
///
/// \file
/// \brief 应用程序接口宏。
///
/// \version 2019-07-01
/// \since 2018-06-12
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#ifdef RRWINDOWS_SHARED
# ifdef RRWINDOWS_EXPORTS
#  define RRWINDOWS_API __declspec(dllexport)
# else
#  define RRWINDOWS_API __declspec(dllimport)
# endif
#else
#  define RRWINDOWS_API
#endif

#define RRWINDOWS_CALL  __stdcall
#define RRWINDOWS_CALLV __cdecl
