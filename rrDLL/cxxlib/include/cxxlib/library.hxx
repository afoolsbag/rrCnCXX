//===-- Library -------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 库。
///
/// 关于 C++ 库的三种导出方式：
///
/// *   C 方法
///     *   `+` 操作系统范围内 C ABI 已形成事实标准。
///     *   `+` 独立的资源管理，不对选用的 CRT 作限制。
///     *   `-` 不支持异常。
///     *   `-` 句柄和方法分离。
///     *   `-` 手动资源管理。
///     *   `+` 以上三项可通过纯头文件类包装进行改进。
/// *   C++ 方法
///     *   `+` DLL 类和本地类一样使用。
///     *   `-` 必须使用相同的 CRT。
///     *   `-` 必须使用相同的异常配置。
///     *   `-` 符号导出将导出类的所有内容。
///     *   `-` C++ ABI 尚无事实标准。
/// *   COM 方法
///     *   `+` 与 C 方法相比，解决了“句柄和方法分离”的问题。
///     *   `-` 仅解决了“句柄和方法分离”问题。
///
/// 综上，推荐选用“C 方法并提供包装类”的方式进行导出。
///
/// \sa [HowTo: Export C++ classes from a DLL](https://codeproject.com/Articles/28969/HowTo-Export-C-classes-from-a-DLL)
///
/// \version 2019-01-18
/// \since 2018-01-09
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef CXXLIB_LIBRARY_HXX_
#define CXXLIB_LIBRARY_HXX_

#include "cxxlib/api_macros.hxx"

typedef enum cxxlib_error_code_t_ {
    cxxlib_success = 0,
    cxxlib_invalid_handle = 0x6,
    cxxlib_invalid_parameter = 0x57,
} cxxlib_error_code_t;

typedef void *cxxlib_handle_t;

CXXLIB_DECORATING CXXLIB_IMEXPORT cxxlib_error_code_t CXXLIB_CALLING cxxlib_construct(cxxlib_handle_t *out);
CXXLIB_DECORATING CXXLIB_IMEXPORT cxxlib_error_code_t CXXLIB_CALLING cxxlib_plus(cxxlib_handle_t handle, int n);
CXXLIB_DECORATING CXXLIB_IMEXPORT cxxlib_error_code_t CXXLIB_CALLING cxxlib_minus(cxxlib_handle_t handle, int n);
CXXLIB_DECORATING CXXLIB_IMEXPORT cxxlib_error_code_t CXXLIB_CALLING cxxlib_equals(cxxlib_handle_t handle, int *out);
CXXLIB_DECORATING CXXLIB_IMEXPORT cxxlib_error_code_t CXXLIB_CALLING cxxlib_destruct(cxxlib_handle_t handle);

#endif//CXXLIB_LIBRARY_HXX_
