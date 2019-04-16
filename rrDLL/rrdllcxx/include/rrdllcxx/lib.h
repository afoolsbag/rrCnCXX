/*===-- Library ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 库。
 *
 * 关于 C++ 库的三种导出方式：
 *
 * *   C 方法
 *     *   `+` 操作系统范围内 C ABI 已形成事实标准。
 *     *   `+` 独立的资源管理，不对选用的 CRT 作限制。
 *     *   `-` 不支持异常。
 *     *   `-` 句柄和方法分离。
 *     *   `-` 手动资源管理。
 *     *   `+` 以上三项可通过纯头文件类包装进行改进。
 * *   C++ 方法
 *     *   `+` DLL 类和本地类一样使用。
 *     *   `-` 必须使用相同的 CRT。
 *     *   `-` 必须使用相同的异常配置。
 *     *   `-` 符号导出将导出类的所有内容。
 *     *   `-` C++ ABI 尚无事实标准。
 * *   COM 方法
 *     *   `+` 与 C 方法相比，解决了“句柄和方法分离”的问题。
 *     *   `-` 仅解决了“句柄和方法分离”问题。
 *
 * 综上，推荐选用“C 方法”。
 *
 * \sa [HowTo: Export C++ classes from a DLL](https://codeproject.com/Articles/28969/HowTo-Export-C-classes-from-a-DLL)
 *
 * \version 2019-04-16
 * \since 2018-01-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRDLLCXX_LIB_H_
#define RRDLLCXX_LIB_H_

#include "rrdllcxx/api.h"

/*------------------------------------------------------------------------------
 * TYPES
 */

/**
 * \brief 状态码。
 */
enum rrdllcxx_status_t {
    rrdllcxx_success = 0,

    rrdllcxx_exception,
    rrdllcxx_logic_error,
    rrdllcxx_invalid_argument,
    rrdllcxx_domain_error,
    rrdllcxx_length_error,
    rrdllcxx_out_of_range,
    rrdllcxx_future_error,
    rrdllcxx_bad_optional_access,
    rrdllcxx_runtime_error,
    rrdllcxx_range_error,
    rrdllcxx_overflow_error,
    rrdllcxx_underflow_error,
    rrdllcxx_regex_error,
    rrdllcxx_nonexistent_local_time,
    rrdllcxx_ambiguous_local_time,
    rrdllcxx_tx_exception,
    rrdllcxx_system_error,
    rrdllcxx_ios_base_failure,
    rrdllcxx_filesystem_filesystem_error,
    rrdllcxx_bad_typeid,
    rrdllcxx_bad_cast,
    rrdllcxx_bad_any_cast,
    rrdllcxx_bad_weak_ptr,
    rrdllcxx_bad_function_call,
    rrdllcxx_bad_alloc,
    rrdllcxx_bad_array_new_length,
    rrdllcxx_bad_exception,
    rrdllcxx_bad_variant_access,
};

/**
 * \brief 版本。
 */
struct rrdllcxx_version_t {
    int major;  /**< 主版本号。 */
    int minor;  /**< 次版本号。 */
    int patch;  /**< 补丁版本号。 */
    int tweak;  /**< 微调版本号。 */
};

/**
 * \brief 实例句柄。
 */
typedef struct rrdllcxx_t *rrdllcxx_handle_t;

/*------------------------------------------------------------------------------
 * FUNCTIONS
 */

/**
 * \brief 获取版本。
 *
 * \param[out] pv 版本指针（pointer to version）
 */
RRDLLCXX_APIp enum rrdllcxx_status_t
RRDLLCXX_APIm rrdllcxx_version(struct rrdllcxx_version_t *pv)
RRDLLCXX_APIs;

/**
 * \brief 构造实例。
 *
 * \param[out] ph 句柄指针（pointer to handle）
 */
RRDLLCXX_APIp enum rrdllcxx_status_t
RRDLLCXX_APIm rrdllcxx_construct(rrdllcxx_handle_t *ph)
RRDLLCXX_APIs;

/**
 * \brief 加。
 *
 * \param h 实例句柄（handle）
 * \param n 加数
 */
RRDLLCXX_APIp enum rrdllcxx_status_t
RRDLLCXX_APIm rrdllcxx_plus(rrdllcxx_handle_t h, int n)
RRDLLCXX_APIs;

/**
 * \brief 减。
 *
 * \param h 实例句柄（handle）
 * \param n 减数
 */
RRDLLCXX_APIp enum rrdllcxx_status_t
RRDLLCXX_APIm rrdllcxx_minus(rrdllcxx_handle_t h, int n)
RRDLLCXX_APIs;

/**
 * \brief 等于。
 *
 * \param[in]  h  实例句柄（handle）
 * \param[out] pn 值指针（pointer to n）
 */
RRDLLCXX_APIp enum rrdllcxx_status_t
RRDLLCXX_APIm rrdllcxx_equals(rrdllcxx_handle_t h, int *pn)
RRDLLCXX_APIs;

/**
 * \brief 析构实例。
 *
 * \param h 实例句柄（handle）
 */
RRDLLCXX_APIp enum rrdllcxx_status_t
RRDLLCXX_APIm rrdllcxx_destruct(rrdllcxx_handle_t h)
RRDLLCXX_APIs;

#endif/*RRDLLCXX_LIB_H_*/
