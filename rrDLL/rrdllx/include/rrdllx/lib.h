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
 * \version 2019-05-10
 * \since 2018-01-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRDLLX_LIB_H_
#define RRDLLX_LIB_H_

#include "rrdllx/api.h"

/*==============================================================================
 *  _______   _______ _____ _____
 * |_   _\ \ / / ___ \  ___/  ___|
 *   | |  \ V /| |_/ / |__ \ `--.
 *   | |   \ / |  __/|  __| `--. \
 *   | |   | | | |   | |___/\__/ /
 *   \_/   \_/ \_|   \____/\____/
 */

/**
 * \brief 状态码。
 */
typedef enum rrdllx_status_t {
    rrdllx_success = 0,

    rrdllx_exception,
    rrdllx_logic_error,
    rrdllx_invalid_argument,
    rrdllx_domain_error,
    rrdllx_length_error,
    rrdllx_out_of_range,
    rrdllx_future_error,
    rrdllx_bad_optional_access,
    rrdllx_runtime_error,
    rrdllx_range_error,
    rrdllx_overflow_error,
    rrdllx_underflow_error,
    rrdllx_regex_error,
    rrdllx_nonexistent_local_time,
    rrdllx_ambiguous_local_time,
    rrdllx_tx_exception,
    rrdllx_system_error,
    rrdllx_ios_base_failure,
    rrdllx_filesystem_filesystem_error,
    rrdllx_bad_typeid,
    rrdllx_bad_cast,
    rrdllx_bad_any_cast,
    rrdllx_bad_weak_ptr,
    rrdllx_bad_function_call,
    rrdllx_bad_alloc,
    rrdllx_bad_array_new_length,
    rrdllx_bad_exception,
    rrdllx_bad_variant_access,
} rrdllx_status_t;

/**
 * \brief 版本。
 */
typedef struct rrdllx_version_t {
    int major;  /**< 主版本号。 */
    int minor;  /**< 次版本号。 */
    int patch;  /**< 补丁版本号。 */
    int tweak;  /**< 微调版本号。 */
} rrdllx_version_t;

/**
 * \brief 实例句柄。
 */
typedef struct rrdllx_t *rrdllx_handle_t;

/**
 * \brief 字符串。
 */
typedef const char *rrdllx_string_t;

/**
 * \brief 字符串索引。
 */
typedef const rrdllx_string_t *rrdllx_string_index_t;

/**
 * \brief 字符串数组。
 */
typedef struct rrdllx_string_array_dereference_t {
    const size_t                c;  /** 数目（counter） */
    const rrdllx_string_index_t v;  /** 数组（vector） */
} *rrdllx_string_array_t;

/*==============================================================================
 * ______ _   _ _   _ _____ _____ _____ _____ _   _  _____
 * |  ___| | | | \ | /  __ \_   _|_   _|  _  | \ | |/  ___|
 * | |_  | | | |  \| | /  \/ | |   | | | | | |  \| |\ `--.
 * |  _| | | | | . ` | |     | |   | | | | | | . ` | `--. \
 * | |   | |_| | |\  | \__/\ | |  _| |_\ \_/ / |\  |/\__/ /
 * \_|    \___/\_| \_/\____/ \_/  \___/ \___/\_| \_/\____/
 */

/**
 * \brief 获取版本。
 *
 * \param[out] rv 版本引用（reference to version）
 */
RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_version(rrdllx_version_t *rv)
RRDLLX_APIs;

/**
 * \brief 构造实例。
 *
 * \param[out] rh 句柄引用（reference to handle）
 */
RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_construct(rrdllx_handle_t *rh)
RRDLLX_APIs;

/**
 * \brief 析构实例。
 *
 * \param h 实例句柄（handle）
 */
RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_destruct(rrdllx_handle_t h)
RRDLLX_APIs;

/**
 * \brief 分配字符串，并纳入实例资源管理。
 *
 * \param[in]  h  实例句柄（handle）
 * \param[in]  v  输入的字符串值（value of string）
 * \param[out] rs 输出的字符串引用（reference to string）
 */
RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_string(rrdllx_handle_t h, rrdllx_string_t v, rrdllx_string_t *rs)
RRDLLX_APIs;

/**
 * \brief 释放实例字符串。
 *
 * \param h 实例句柄（handle）
 * \param s 字符串（string）
 */
RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_string(rrdllx_handle_t h, rrdllx_string_t s)
RRDLLX_APIs;

/**
 * \brief 分配字符串数组，并纳入实例资源管理。
 *
 * \param h  实例句柄（handle）
 * \param s  字符串数目（size）。
 * \param ra 字符串数组引用（reference to string array）
 */
RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_string_array(rrdllx_handle_t h, size_t s, rrdllx_string_array_t *ra)
RRDLLX_APIs;

/**
 * \brief 释放实例字符串数组。
 *
 * \param h 实例句柄（handle）
 * \param a 字符串数组（string array）
 */
RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_string_array(rrdllx_handle_t h, rrdllx_string_array_t a)
RRDLLX_APIs;

/**
 * \brief 释放实例所有资源。
 *
 * \param h 实例句柄（handle）
 */
RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_all(rrdllx_handle_t h)
RRDLLX_APIs;

#endif/*RRDLLX_LIB_H_*/
