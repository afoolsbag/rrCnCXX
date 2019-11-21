//===-- Application Programming Interface Macros ----------------*- C++ -*-===//
///
/// \file
/// \brief 应用程序接口宏。
///
/// \version 2019-11-13
/// \since 2019-11-13
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#if (4 <= __GNUC__)
# define RRPOSIX_API   __attribute__ ((visibility ("default")))
# define RRPOSIX_LOCAL __attribute__ ((visibility ("hidden")))
#else
# define RRPOSIX_API
# define RRPOSIX_LOCAL
#endif
