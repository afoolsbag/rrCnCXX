/*===-- rrDLLx -------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief rrDLLx
 *
 * 关于 C++ 库的三种导出方式：
 *
 * *   C 方法
 *     *   `+` 操作系统范围 C ABI 已形成事实标准；几乎所有现代编程语言都支持与 C 互操作。
 *     *   `+` 独立的资源管理，不对 CRT 作限制。
 *     *   `-` 不支持异常。
 *     *   `-` 手动资源管理。
 *     *   `-` 繁琐；句柄和方法分离。
 *     *   `*` 以上缺陷可通过调用语言包装进行改进。
 * *   C++ 方法
 *     *   `+` 导出 C++ 类和本地 C++ 类一样使用。
 *     *   `+` 可以捕获 DLL 引发的异常。
 *     *   `+` 可缓解大型项目的重建压力。
 *     *   `+` 有助于项目模块化。
 *     *   `-` 必须使用相同的动态 CRT。
 *     *   `-` 必须使用相同的异常配置。
 *     *   `-` 符号导出将导出类的所有内容。
 *     *   `-` C++ ABI 尚无事实标准；不与纯 C 兼容。
 * *   COM 方法
 *     *   `+` 导出的 C++ 类可以与任何 C++ 编译器一同使用。
 *     *   `+` 独立的资源管理，不对 CRT 作限制。
 *     *   `+` 使项目模块化。
 *     *   `+` 容易转换为 COM 模块。
 *     *   `-` 手动管理实例的创建和销毁。
 *     *   `-` 接口类型受限：COM 接口类型限制。
 *     *   `-` 不与纯 C 兼容。
 *
 * 综上，推荐选用“C 方法”。
 *
 * \sa [HowTo: Export C++ classes from a DLL](https://codeproject.com/Articles/28969/HowTo-Export-C-classes-from-a-DLL)
 *
 * \version 2019-05-17
 * \since 2018-01-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRDLLX_RRDLLX_H_
#define RRDLLX_RRDLLX_H_

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif

#include "api.h"

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

    /*标准异常*/

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

    /* 接口异常 */

    rrdllx_null_pointer,
    rrdllx_null_reference,
    rrdllx_dereference_not_initialized,

    /* 内部异常 */

    rrdllx_instance_not_found,
    rrdllx_instance_zstring_not_found,
    rrdllx_instance_zstring_array_not_found,
    rrdllx_instance_binary_not_found,

    rrdllx_unexpected_exception
} rrdllx_status_t;

/**
 * \brief 版本。
 */
typedef struct {
    int major;  /**< 主版本号。 */
    int minor;  /**< 次版本号。 */
    int patch;  /**< 补丁版本号。 */
    int tweak;  /**< 微调版本号。 */
} rrdllx_version_t;

/**
 * \brief 实例句柄。
 */
typedef void
*rrdllx_handle_t;

/**
 * \brief 空终止字符串。
 */
typedef const char
rrdllx_zstring_deref_t[], *rrdllx_zstring_t;

/**
 * \brief 空终止字符串数组。
 */
typedef struct {
    const size_t                  count;
    const rrdllx_zstring_t *const vector;
} rrdllx_zstring_array_deref_t, *rrdllx_zstring_array_t;

/**
 * \brief 二进制数据。
 */
typedef struct {
    const size_t         size;
    const uint8_t *const data;
} rrdllx_binary_deref_t, *rrdllx_binary_t;

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
RRDLLX_APIm rrdllx_get_version(rrdllx_version_t *rv)
RRDLLX_APIs;

/**
 * \brief 构造实例。
 *
 * \param[out] rh 句柄引用（reference to handle）
 *
 * \pre `assert(*rh == NULL)`
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
 * \brief 分配空终止字符串，并纳入实例资源管理。
 *
 * \param[in]  h  实例句柄（handle）
 * \param[in]  v  字符串值（value of zstring）
 * \param[out] rz 空终止字符串引用（reference to zstring）
 *
 * \pre `assert(*rz == NULL)`
 */
RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_zstring(rrdllx_handle_t h, rrdllx_zstring_t v, rrdllx_zstring_t *rz)
RRDLLX_APIs;

/**
 * \brief 释放实例管理的空终止字符串。
 *
 * \param h 实例句柄（handle）
 * \param z 空终止字符串（zstring）
 */
RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_zstring(rrdllx_handle_t h, rrdllx_zstring_t z)
RRDLLX_APIs;

/**
 * \brief 分配空终止字符串数组，并纳入实例资源管理。
 *
 * \param[in]  h   实例句柄（handle）
 * \param[in]  v   字符串数组值（value of zstring array）
 * \param[in]  c   字符串数组计数（count of zstring array）
 * \param[out] rza 空终止字符串数组引用（reference to zstring array）
 *
 * \pre `assert(*rza == NULL)`
 */
RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_zstring_array(rrdllx_handle_t h, const rrdllx_zstring_t v[], size_t c, rrdllx_zstring_array_t *rza)
RRDLLX_APIs;

/**
 * \brief 释放实例管理的空终止字符串数组。
 *
 * \param h 实例句柄（handle）
 * \param za 空终止字符串数组（zstring array）
 */
RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_zstring_array(rrdllx_handle_t h, rrdllx_zstring_array_t za)
RRDLLX_APIs;

/**
 * \brief 分配二进制数据，并纳入实例资源管理。
 *
 * \param[in]  h  实例句柄（handle）
 * \param[in]  v  二进制数据值（value of binary）
 * \param[in]  s  二进制数据大小（size of binary）
 * \param[out] rb 二进制数据引用（reference to binary）
 *
 * \pre `assert(*rb == NULL)`
 */
RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_binary(rrdllx_handle_t h, const uint8_t *v, size_t s, rrdllx_binary_t *rb)
RRDLLX_APIs;

/**
 * \brief 释放实例管理的二进制数据。
 *
 * \param h 实例句柄（handle）
 * \param b 二进制数据（binary）
 */
RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_binary(rrdllx_handle_t h, rrdllx_binary_t b)
RRDLLX_APIs;

/**
 * \brief 释放实例所有资源。
 *
 * \param h 实例句柄（handle）
 */
RRDLLX_APIp rrdllx_status_t
RRDLLX_APIm rrdllx_free_all(rrdllx_handle_t h)
RRDLLX_APIs;

#endif/*RRDLLX_RRDLLX_H_*/
