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
/// \version 2019-01-15
/// \since 2018-01-09
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRDLL_LWICXX_LIBRARY_HXX_
#define RRDLL_LWICXX_LIBRARY_HXX_

#include "lwicxx/api_macros.hxx"

typedef enum rrdll_lwicxx_error_code_t_ {
    rrdll_lwicxx_success = 0,
    rrdll_lwicxx_invalid_handle = 0x6,
    rrdll_lwicxx_invalid_parameter = 0x57,
}rrdll_lwicxx_error_code_t;

typedef void *rrdll_lwicxx_handle_t;

EXTERN_C
RRDLL_LWICXX_API
rrdll_lwicxx_error_code_t
APIENTRY
rrdll_lwicxx_construct(rrdll_lwicxx_handle_t *pout);

EXTERN_C
RRDLL_LWICXX_API
rrdll_lwicxx_error_code_t
APIENTRY
rrdll_lwicxx_plus(rrdll_lwicxx_handle_t handle, int n);

EXTERN_C
RRDLL_LWICXX_API
rrdll_lwicxx_error_code_t
APIENTRY
rrdll_lwicxx_minus(rrdll_lwicxx_handle_t handle, int n);

EXTERN_C
RRDLL_LWICXX_API
rrdll_lwicxx_error_code_t
APIENTRY
rrdll_lwicxx_equals(rrdll_lwicxx_handle_t handle, int *pout);

EXTERN_C
RRDLL_LWICXX_API
rrdll_lwicxx_error_code_t
APIENTRY
rrdll_lwicxx_destruct(rrdll_lwicxx_handle_t handle);

#endif//RRDLL_LWICXX_LIBRARY_HXX_
