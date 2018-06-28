//===-- Pre-Compiled Header -------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 预编译头文件。
///
/// \version 2018-06-28
/// \since 2018-04-04
/// \authors zhengrr
/// \copyright The MIT License
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

#if 0
#// DON'T LINK MANIFEST
#elif defined _M_IX86
# pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
# pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
# pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
# pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

#include <afxwin.h>
#include <afxcmn.h>
