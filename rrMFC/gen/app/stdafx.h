//===-- Pre-Compiled Header -------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 预编译头文件。
///
/// \version 2018-05-02
/// \since 2017-12-11
/// \authors zhengrr
/// \copyright The MIT License
///
/// \sa ["Compiler Options Macros"](https://docs.microsoft.com/cpp/atl/reference/compiler-options-macros). *Microsoft? Docs*.
///
//===----------------------------------------------------------------------===//

#pragma once

#ifndef _AFX_ALL_WARNINGS
#define _AFX_ALL_WARNINGS
#endif
#ifndef _ATL_CSTRING_EXPLICIT_CONSTRUCTORS
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS
#endif
#ifndef _ATL_ENABLE_PTM_WARNING
#define _ATL_ENABLE_PTM_WARNING
#endif
#ifndef _ATL_NO_AUTOMATIC_NAMESPACE
#define _ATL_NO_AUTOMATIC_NAMESPACE
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

#include <winsdkver.h>
#define _WIN32_WINNT _WIN32_WINNT_MAXVER

#include <afxwin.h>
