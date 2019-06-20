/*===-- rrLibX -------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief rrLibX
 *
 * \details
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
 * \note 基础 C 接口应尽可能基础，“若非必须勿添什物”。
 *
 * \sa [HowTo: Export C++ classes from a DLL](https://codeproject.com/Articles/28969/HowTo-Export-C-classes-from-a-DLL)
 *
 * \version 2019-06-20
 * \since 2018-01-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRLIBX_RRLIBX_H_
#define RRLIBX_RRLIBX_H_

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif

#include "api.h"

/**
 * \brief 状态码。
 */
enum rrlibx_status_t {
    rrlibx_success = 0,                  /**< 成功 */

    rrlibx_exception,                    /**< 标准基异常 */
    rrlibx_logic_error,                  /**< 标准逻辑错误：程序内部错误逻辑所导致的可避免错误。 */
    rrlibx_invalid_argument,             /**< 标准无效参数：因参数值未被接受而引发的错误。 */
    rrlibx_domain_error,                 /**< 标准定义域错误 */
    rrlibx_length_error,                 /**< 标准长度错误：试图超出一些对象的实现定义长度极限所导致的错误。 */
    rrlibx_out_of_range,                 /**< 标准越界错误：访问试图受定义范围外的元素所带来的错误。 */
    rrlibx_future_error,
    rrlibx_bad_optional_access,
    rrlibx_runtime_error,                /**< 标准运行时错误：源于程序作用域外，且不能轻易预测到的错误。 */
    rrlibx_range_error,                  /**< 标准值域错误 */
    rrlibx_overflow_error,               /**< 标准算术上溢错误 */
    rrlibx_underflow_error,              /**< 标准算术下溢错误 */
    rrlibx_regex_error,
    rrlibx_nonexistent_local_time,
    rrlibx_ambiguous_local_time,
    rrlibx_tx_exception,
    rrlibx_system_error,                 /**< 标准系统错误 */
    rrlibx_ios_base_failure,             /**< 标准输入输出系统错误 */
    rrlibx_filesystem_filesystem_error,  /**< 标准文件系统错误 */
    rrlibx_bad_typeid,
    rrlibx_bad_cast,
    rrlibx_bad_any_cast,
    rrlibx_bad_weak_ptr,
    rrlibx_bad_function_call,
    rrlibx_bad_alloc,                    /**< 标准存储分配失败 */
    rrlibx_bad_array_new_length,
    rrlibx_bad_exception,
    rrlibx_bad_variant_access,

    rrlibx_internal_error,               /**< 内部错误：可紧接调用 `rrlibx_alloc_last_internal_error_zstring` 获取错误信息。 */
    rrlibx_unexpected_exception          /**< 不预期的异常：不遵循标准异常或任何已知异常，意料之外的状况。 */
};

typedef struct internal_rrlibx_handle_t *rrlibx_handle_t;  /**< 实例句柄。 */

/**
 * \brief 获取版本。
 *
 * \param[out] ref_major 主版本引用，reference to major version
 * \param[out] ref_minor 次版本引用，reference to minor version
 * \param[out] ref_patch 补丁版本引用，reference to patch version
 * \param[out] ref_tweak 微调版本引用，reference to tweak version
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_version(int *ref_major, int *ref_minor, int *ref_patch, int *ref_tweak)
RRLIBX_APIs;

/**
 * \brief 构造实例。
 *
 * \param[out] ref_handle 实例句柄引用，reference to handle
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_construct(rrlibx_handle_t *ref_handle)
RRLIBX_APIs;

/**
 * \brief 析构实例。
 *
 * \param h 实例句柄，handle
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_destruct(rrlibx_handle_t h)
RRLIBX_APIs;

//------------------------------------------------------------------------------
// basic type

/**
 * \brief 基本类型赋值。
 *
 * \param h     实例句柄，handle
 * \param value 值
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_set_basic(rrlibx_handle_t h, int value)
RRLIBX_APIs;

/**
 * \brief 基本类型取值。
 *
 * \param[in]  h         实例句柄，handle
 * \param[out] ref_value 值引用，reference to value
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_basic(rrlibx_handle_t h, int *ref_value)
RRLIBX_APIs;

/*----------------------------------------------------------------------------*/
/* array type */

/**
 * \brief 数组类型赋值。
 *
 * \param h    实例句柄，handle
 * \param data 数据指针
 * \param size 数据尺寸
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_set_array(rrlibx_handle_t h, const uint8_t *data, size_t size)
RRLIBX_APIs;

/**
 * \brief 数组类型取值。
 *
 * \param[in]     h        实例句柄，handle
 * \param[out]    buffer   缓存指针
 * \param[in,out] ref_size 尺寸引用：输入缓存尺寸，输出数据尺寸。
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_array(rrlibx_handle_t h, uint8_t *buffer, size_t *ref_size)
RRLIBX_APIs;

/**
 * \brief 数组类型取值，易变只读引用变种。
 *
 * \param[in]  h        实例句柄，handle
 * \param[out] ref_data 数据指针引用，reference to data
 * \param[out] ref_size 数据尺寸引用，reference to size
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_array_volatile_readonly_reference(rrlibx_handle_t h, const uint8_t **ref_data, size_t *ref_size)
RRLIBX_APIs;

/*----------------------------------------------------------------------------*/
/* string type */

enum { rrlibx_string_fixed_size = 777 };

/**
 * \brief 字串类型赋值。
 *
 * \param h      实例句柄，handle
 * \param string 字串指针
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_set_string(rrlibx_handle_t h, const char *string)
RRLIBX_APIs;

/**
 * \brief 字串类型取值，定长缓存变种。
 *
 * \param[in]  h      实例句柄，handle
 * \param[out] buffer 定长缓存
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_string_fixed_size(rrlibx_handle_t h, char buffer[rrlibx_string_fixed_size])
RRLIBX_APIs;

/**
 * \brief 字串类型取值，易变只读引用变种。
 *
 * \param[in]  h          实例句柄，handle
 * \param[out] ref_string 字串指针引用，reference to string
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_string_volatile_readonly_reference(rrlibx_handle_t h, const char **ref_string)
RRLIBX_APIs;

/*----------------------------------------------------------------------------*/
/* error handling */

enum { rrlibx_error_message_size = 128 };

/**
 * \brief 最新内部错误消息。
 *
 * \param[in]  h      实例句柄，handle
 * \param[out] buffer 定长缓存
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_last_internal_error_message(rrlibx_handle_t h, char buffer[rrlibx_error_message_size])
RRLIBX_APIs;

#endif
