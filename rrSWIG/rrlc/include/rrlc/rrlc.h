/*===-- rrlc ---------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief rrlc
 *
 * \sa [*DLL 编写教程*](http://blogjava.net/wxb_nudt/archive/2007/09/11/144371.html)
 *
 * \version 2019-07-18
 * \since 2017-01-06
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRLC_RRLC_H_
#define RRLC_RRLC_H_

#ifdef __cplusplus
#include <ctime>
#else
#include <time.h>
#endif

#include "rrlc/api.h"

/**
 * \brief 状态码。
 */
enum rrlc_status_t {
    rrlc_success = 0,

    rrlc_exception,
    rrlc_logic_error,
    rrlc_invalid_argument,
    rrlc_domain_error,
    rrlc_length_error,
    rrlc_out_of_range,
    rrlc_future_error,
    rrlc_bad_optional_access,
    rrlc_runtime_error,
    rrlc_range_error,
    rrlc_overflow_error,
    rrlc_underflow_error,
    rrlc_regex_error,
    rrlc_nonexistent_local_time,
    rrlc_ambiguous_local_time,
    rrlc_tx_exception,
    rrlc_system_error,
    rrlc_ios_base_failure,
    rrlc_filesystem_filesystem_error,
    rrlc_bad_typeid,
    rrlc_bad_cast,
    rrlc_bad_any_cast,
    rrlc_bad_weak_ptr,
    rrlc_bad_function_call,
    rrlc_bad_alloc,
    rrlc_bad_array_new_length,
    rrlc_bad_exception,
    rrlc_bad_variant_access,
};

/**
 * \brief 获取版本。
 *
 * \param[out] r_major 主版本号引用
 * \param[out] r_minor 次版本号引用
 * \param[out] r_patch 补丁版本号引用
 * \param[out] r_tweak 微调版本号引用
 */
RRLC_APIp enum rrlc_status_t
RRLC_APIm rrlc_get_version(int *r_major, int *r_minor, int *r_patch, int *r_tweak)
RRLC_APIs;

/**
 * \brief 叹。
 *
 * \param[out] r_time 时间引用
 */
RRLC_APIp enum rrlc_status_t
RRLC_APIm rrlc_sigh(time_t *r_time)
RRLC_APIs;

#endif
