/*===-- rrLibC -------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief rrLibC
 *
 * \sa [*DLL 编写教程*](http://blogjava.net/wxb_nudt/archive/2007/09/11/144371.html)
 *
 * \version 2019-05-13
 * \since 2017-01-06
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRLIBC_RRLIBC_H_
#define RRLIBC_RRLIBC_H_

#include <time.h>

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
 * \param[out] ref_major 主版本引用，reference to major version
 * \param[out] ref_minor 次版本引用，reference to minor version
 * \param[out] ref_patch 补丁版本引用，reference to patch version
 * \param[out] ref_tweak 微调版本引用，reference to tweak version
 */
RRLIBC_APIp enum rrlibc_status_t
RRLIBC_APIm rrlibc_get_version(int *ref_major, int *ref_minor, int *ref_patch, int *ref_tweak)
RRLIBC_APIs;

/**
 * \brief 叹。
 *
 * \param[out] ref_time 时间引用，reference to time
 */
RRLIBC_APIp enum rrlibc_status_t
RRLIBC_APIm rrlibc_sigh(time_t *ref_time)
RRLIBC_APIs;

#endif
