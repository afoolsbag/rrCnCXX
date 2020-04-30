/*===-- zhengrr's Library With C -------------------------------*- C -*-===*//**
 *
 * \file
 * \brief zhengrr's library with C
 *
 * \sa [*DLL 编写教程*](http://blogjava.net/wxb_nudt/archive/2007/09/11/144371.html)
 *
 * \version 2020-04-30
 * \since 2017-01-06
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRLIBC_RRLIBC_H_
#define RRLIBC_RRLIBC_H_

#ifdef __cplusplus
#include <ctime>
#else
#include <time.h>
#endif

#include "rrlibc/api.h"

/**
 * \brief 状态码。
 */
enum rrlibc_status_t {
    rrlibc_success = 0,

    rrlibc_exception,
    rrlibc_logic_error,
    rrlibc_invalid_argument,
    rrlibc_domain_error,
    rrlibc_length_error,
    rrlibc_out_of_range,
    rrlibc_future_error,
    rrlibc_bad_optional_access,
    rrlibc_runtime_error,
    rrlibc_range_error,
    rrlibc_overflow_error,
    rrlibc_underflow_error,
    rrlibc_regex_error,
    rrlibc_nonexistent_local_time,
    rrlibc_ambiguous_local_time,
    rrlibc_tx_exception,
    rrlibc_system_error,
    rrlibc_ios_base_failure,
    rrlibc_filesystem_filesystem_error,
    rrlibc_bad_typeid,
    rrlibc_bad_cast,
    rrlibc_bad_any_cast,
    rrlibc_bad_weak_ptr,
    rrlibc_bad_function_call,
    rrlibc_bad_alloc,
    rrlibc_bad_array_new_length,
    rrlibc_bad_exception,
    rrlibc_bad_variant_access,
};

/**
 * \brief 获取版本。
 *
 * \param[out] r_major 主版本号引用
 * \param[out] r_minor 次版本号引用
 * \param[out] r_patch 补丁版本号引用
 * \param[out] r_tweak 微调版本号引用
 */
EXTERN_C RRLIBC_API enum rrlibc_status_t CDECL
rrlibc_get_version(int *r_major, int *r_minor, int *r_patch, int *r_tweak) NOEXCEPT;

/**
 * \brief 叹。
 *
 * \param[out] r_time 时间引用
 */
EXTERN_C RRLIBC_API enum rrlibc_status_t CDECL
rrlibc_sigh(time_t *r_time) NOEXCEPT;

#endif
