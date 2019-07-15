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
 * \version 2019-07-15
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

#include "rrlibx/api.h"

/*==============================================================================
 * 状态码：STATUS CODES
 *----------------------------------------------------------------------------*/

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

/*==============================================================================
 * 类型和常量：TYPES & CONSTANTS
 *----------------------------------------------------------------------------*/

enum {
    rrlibx_last_internal_error_message_fsb_size = 128,  /**< 最新内部错误消息定长缓存尺寸 */
    rrlibx_string_fsb_size = 777,                       /**< 字串定长缓存尺寸 */
};

/**
 * \brief 实例句柄类型。
 */
typedef struct incomplete_rrlibx_t *rrlibx_handle_t;

/**
 * \brief `rrlibx_non_blocking` 回调函数类型。
 */
typedef void(*rrlibx_non_blocking_callback_t)(void *p_user_data);

/*==============================================================================
 * 接口：INTERFACE
 *----------------------------------------------------------------------------*/

/**
 * \brief 获取版本。
 *
 * \param[out] r_major 主版本号引用，可空
 * \param[out] r_minor 次版本号引用，可空
 * \param[out] r_patch 补丁版本号引用，可空
 * \param[out] r_tweak 微调版本号引用，可空
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_version(int *r_major, int *r_minor, int *r_patch, int *r_tweak)
RRLIBX_APIs;

/**
 * \brief 构造实例。
 *
 * \param[out] r_handle 实例句柄引用
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_construct(rrlibx_handle_t *r_handle)
RRLIBX_APIs;

/**
 * \brief 析构实例。
 *
 * \param handle 实例句柄
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_destruct(rrlibx_handle_t handle)
RRLIBX_APIs;

/*==============================================================================
 * 接口，基础读取：BASIC GETTER & SETTER
 *----------------------------------------------------------------------------*/

/**
 * \brief 基础赋值。
 *
 * \param handle 实例句柄
 * \param value  值
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_set_basic(rrlibx_handle_t handle, int value)
RRLIBX_APIs;

/**
 * \brief 基础取值。
 *
 * \param[in]  handle  实例句柄
 * \param[out] r_value 值引用
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_basic(rrlibx_handle_t handle, int *r_value)
RRLIBX_APIs;

/*==============================================================================
 * 接口，数组读取：ARRAY GETTER & SETTER
 *----------------------------------------------------------------------------*/

/**
 * \brief 数组赋值。
 *
 * \param handle 实例句柄
 * \param data   只读数组
 * \param size   数组尺寸
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_set_array(rrlibx_handle_t handle, const uint8_t data[], size_t size)
RRLIBX_APIs;

/**
 * \brief 数组取值。
 *
 * \param[in]     handle 实例句柄
 * \param[out]    buffer 缓存数组，可空
 * \param[in,out] r_size 尺寸引用，输入缓存尺寸，输出数据尺寸。
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_array(rrlibx_handle_t handle, uint8_t buffer[], size_t *r_size)
RRLIBX_APIs;

/**
 * \brief 数组取值，只读易变引用（const volatile reference）变种。
 *
 * \param[in]  handle 实例句柄
 * \param[out] r_data 只读数组引用
 * \param[out] r_size 尺寸引用
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_array_cvr(rrlibx_handle_t handle, const uint8_t *(*r_data), size_t *r_size)
RRLIBX_APIs;

/*==============================================================================
 * 接口，字串读取：STRING GETTER & SETTER
 *----------------------------------------------------------------------------*/

/**
 * \brief 字串赋值。
 *
 * \param handle 实例句柄
 * \param string 只读字串
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_set_string(rrlibx_handle_t handle, const char string[])
RRLIBX_APIs;

/**
 * \brief 字串取值，定长缓存（fixed size buffer）变种。
 *
 * \param[in]  handle 实例句柄
 * \param[out] buffer 定长缓存
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_string_fsb(rrlibx_handle_t handle, char buffer[rrlibx_string_fsb_size])
RRLIBX_APIs;

/**
 * \brief 字串取值，只读易变引用（const volatile reference）变种。
 *
 * \param[in]  handle   实例句柄
 * \param[out] r_string 只读字串引用
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_string_cvr(rrlibx_handle_t handle, const char *(*r_string))
RRLIBX_APIs;

/*==============================================================================
 * 接口，回调：CALLBACK
 *----------------------------------------------------------------------------*/

/**
 * \brief 异步回调。
 *
 * \param handle      实例句柄
 * \param callback    回调函数
 * \param p_user_data 用户数据指针，在回调时将原样传递此指针，用户需注意其指向内容的生存期
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_non_blocking(rrlibx_handle_t handle, rrlibx_non_blocking_callback_t callback, void *p_user_data)
RRLIBX_APIs;

/*==============================================================================
 * 接口，错误处理：ERROR HANDLING
 *----------------------------------------------------------------------------*/

/**
 * \brief 最新内部错误消息。
 *
 * \param[in]  handle 实例句柄
 * \param[out] buffer 定长缓存
 */
RRLIBX_APIp enum rrlibx_status_t
RRLIBX_APIm rrlibx_get_last_internal_error_message(rrlibx_handle_t handle, char buffer[rrlibx_last_internal_error_message_fsb_size])
RRLIBX_APIs;

#endif
