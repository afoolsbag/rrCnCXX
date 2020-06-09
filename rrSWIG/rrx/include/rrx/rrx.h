/*===-- C Interface --------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief C 接口。
 * \note 基础 C 接口应尽可能基础，“若非必须勿添什物”。
 *
 * \sa [HowTo: Export C++ classes from a DLL](https://codeproject.com/Articles/28969/HowTo-Export-C-classes-from-a-DLL)
 *
 * \version 2020-06-03
 * \since 2018-01-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRX_RRX_H_
#define RRX_RRX_H_

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif

#include "api.h"
#include "status.h"

/**
 * \brief 获取版本。
 *
 * \param[out] r_major 主版本号引用，可空
 * \param[out] r_minor 次版本号引用，可空
 * \param[out] r_patch 补丁版本号引用，可空
 * \param[out] r_tweak 微调版本号引用，可空
 */
EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_get_version(int *r_major, int *r_minor, int *r_patch, int *r_tweak) NOEXCEPT;

/**
 * \brief 实例句柄类型。
 */
typedef struct incomplete_rrx_t *rrx_handle_t;

/**
 * \brief 构造实例。
 *
 * \param[out] r_handle 实例句柄引用
 */
EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_construct(rrx_handle_t *r_handle) NOEXCEPT;

/**
 * \brief 析构实例。
 *
 * \param handle 实例句柄
 */
EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_destruct(rrx_handle_t handle) NOEXCEPT;

/**
 * \brief 基础赋值。
 *
 * \param handle 实例句柄
 * \param value  值
 */
EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_set_basic(rrx_handle_t handle, int value) NOEXCEPT;

/**
 * \brief 基础取值。
 *
 * \param[in]  handle  实例句柄
 * \param[out] r_value 值引用
 */
EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_get_basic(rrx_handle_t handle, int *r_value) NOEXCEPT;

/**
 * \brief 数组赋值。
 *
 * \param handle 实例句柄
 * \param data   只读数组首指针
 * \param size   数组尺寸
 */
EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_set_array(rrx_handle_t handle, const uint8_t *data, size_t size) NOEXCEPT;

/**
 * \brief 数组取值。
 *
 * \param[in]     handle 实例句柄
 * \param[out]    buffer 缓存数组首指针，可空
 * \param[in,out] r_size 尺寸引用，输入缓存尺寸，输出数据尺寸。
 */
EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_get_array(rrx_handle_t handle, uint8_t *buffer, size_t *r_size) NOEXCEPT;

/**
 * \brief 数组取值，只读易变引用（const volatile reference）变种。
 *
 * \param[in]  handle 实例句柄
 * \param[out] r_data 只读数组引用
 * \param[out] r_size 尺寸引用
 */
EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_get_array_cvr(rrx_handle_t handle, const uint8_t *(*r_data), size_t *r_size) NOEXCEPT;

/**
 * \brief 字串赋值。
 *
 * \param handle 实例句柄
 * \param string 只读字串
 */
EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_set_string(rrx_handle_t handle, const char *string) NOEXCEPT;

enum {
    rrx_string_fsb_size = 777  /**< 字串定长缓存尺寸 */
};

/**
 * \brief 字串取值，定长缓存（fixed size buffer）变种。
 *
 * \param[in]  handle 实例句柄
 * \param[out] buffer 定长缓存
 */
EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_get_string_fsb(rrx_handle_t handle, char buffer[rrx_string_fsb_size]) NOEXCEPT;

/**
 * \brief 字串取值，只读易变引用（const volatile reference）变种。
 *
 * \param[in]  handle   实例句柄
 * \param[out] r_string 只读字串引用
 */
EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_get_string_cvr(rrx_handle_t handle, const char *(*r_string)) NOEXCEPT;

/**
 * \brief 回调函数类型。
 */
EXTERN_C_FP typedef void(CDECL *rrx_callback_t)(void *p_user_data);

/**
 * \brief 回调设置。
 *
 * \param handle      实例句柄
 * \param callback    回调函数
 * \param p_user_data 用户数据指针，在回调时将原样传递此指针，用户需维护其指向内容的生存期。
 */
EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_set_callback(rrx_handle_t handle, rrx_callback_t callback, void *p_user_data) NOEXCEPT;

/**
 * \brief 回调调用。
 *
 * \param handle      实例句柄
 */
EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_invoke_callback(rrx_handle_t handle) NOEXCEPT;

enum {
    rrx_last_error_message_fsb_size = 128  /**< 最后错误消息定长缓存尺寸 */
};

/**
 * \brief 最新错误消息。
 *
 * \param[in]  handle 实例句柄
 * \param[out] buffer 定长缓存
 */
EXTERN_C RRX_API enum rrx_status_t CDECL
rrx_get_last_error_message(rrx_handle_t handle, char buffer[rrx_last_error_message_fsb_size]) NOEXCEPT;

#endif
