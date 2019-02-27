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
 * \version 2019-02-27
 * \since 2018-01-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRX_LIB_H_
#define RRX_LIB_H_

#include "rrx/api.h"

/*----- Types ----------------------------------------------------------------*/

/**
 * \brief 状态码。
 */
enum rrx_status_t {
    rrx_success = 0,

    rrx_exception,
    rrx_logic_error,
    rrx_invalid_argument,
    rrx_domain_error,
    rrx_length_error,
    rrx_out_of_range,
    rrx_future_error,
    rrx_bad_optional_access,
    rrx_runtime_error,
    rrx_range_error,
    rrx_overflow_error,
    rrx_underflow_error,
    rrx_regex_error,
    rrx_nonexistent_local_time,
    rrx_ambiguous_local_time,
    rrx_tx_exception,
    rrx_system_error,
    rrx_ios_base_failure,
    rrx_filesystem_filesystem_error,
    rrx_bad_typeid,
    rrx_bad_cast,
    rrx_bad_any_cast,
    rrx_bad_weak_ptr,
    rrx_bad_function_call,
    rrx_bad_alloc,
    rrx_bad_array_new_length,
    rrx_bad_exception,
    rrx_bad_variant_access,
};

/**
 * \brief 版本。
 */
struct rrx_version_t {
    int major;  /**< 主版本号。 */
    int minor;  /**< 次版本号。 */
    int patch;  /**< 补丁版本号。 */
    int tweak;  /**< 微调版本号。 */
};

/**
 * \brief 实例句柄。
 */
typedef struct rrx_t *rrx_handle_t;

/*----- Functions ------------------------------------------------------------*/

/**
 * \brief 获取版本。
 *
 * \param[out] pv 版本指针（pointer to version）
 */
RRX_DECORATING RRX_PORTING enum rrx_status_t RRX_CALLING
rrx_version(struct rrx_version_t *pv);

/**
 * \brief 构造实例。
 *
 * \param[out] ph 句柄指针（pointer to handle）
 */
RRX_DECORATING RRX_PORTING enum rrx_status_t RRX_CALLING
rrx_construct(rrx_handle_t *ph);

/**
 * \brief 加。
 *
 * \param h 实例句柄（handle）
 * \param n 加数
 */
RRX_DECORATING RRX_PORTING enum rrx_status_t RRX_CALLING
rrx_plus(rrx_handle_t h, int n);

/**
 * \brief 减。
 *
 * \param h 实例句柄（handle）
 * \param n 减数
 */
RRX_DECORATING RRX_PORTING enum rrx_status_t RRX_CALLING
rrx_minus(rrx_handle_t h, int n);

/**
 * \brief 等于。
 *
 * \param[in]  h  实例句柄（handle）
 * \param[out] pn 值指针（pointer to n）
 */
RRX_DECORATING RRX_PORTING enum rrx_status_t RRX_CALLING
rrx_equals(rrx_handle_t h, int *pn);

/**
 * \brief 析构实例。
 *
 * \param h 实例句柄（handle）
 */
RRX_DECORATING RRX_PORTING enum rrx_status_t RRX_CALLING
rrx_destruct(rrx_handle_t h);

#endif/*RRX_LIB_H_*/
