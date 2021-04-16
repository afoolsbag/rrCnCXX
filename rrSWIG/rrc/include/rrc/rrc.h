/*===-- Zhengrr's Library in C ---------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 由 C 编写的 zhengrr 库。
 *
 * \sa [DLL 编写教程](http://blogjava.net/wxb_nudt/archive/2007/09/11/144371.html)
 *
 * \version 2021-04-16
 * \since 2017-01-06
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_RRC_H_
#define RRC_RRC_H_

#ifdef __cplusplus
#include <ctime>
#else
#include <time.h>
#endif

#include "rrc/api.h"

/**
 * \brief 库函数的返回状态码。
 */
enum rrc_status_t {
    rrc_success = 0,

    rrc_exception,
    rrc_logic_error,
    rrc_invalid_argument,
    rrc_domain_error,
    rrc_length_error,
    rrc_out_of_range,
    rrc_future_error,
    rrc_bad_optional_access,
    rrc_runtime_error,
    rrc_range_error,
    rrc_overflow_error,
    rrc_underflow_error,
    rrc_regex_error,
    rrc_nonexistent_local_time,
    rrc_ambiguous_local_time,
    rrc_tx_exception,
    rrc_system_error,
    rrc_ios_base_failure,
    rrc_filesystem_filesystem_error,
    rrc_bad_typeid,
    rrc_bad_cast,
    rrc_bad_any_cast,
    rrc_bad_weak_ptr,
    rrc_bad_function_call,
    rrc_bad_alloc,
    rrc_bad_array_new_length,
    rrc_bad_exception,
    rrc_bad_variant_access,
};

/**
 * \brief 获取库的版本信息。
 *
 * \param[out] r_major 主版本号引用，可为空
 * \param[out] r_minor 次版本号引用，可为空
 * \param[out] r_patch 补丁版本号引用，可为空
 * \param[out] r_tweak 微调版本号引用，可为空
 */
EXTERN_C RRC_API enum rrc_status_t CDECL
rrc_get_version(int *r_major, int *r_minor, int *r_patch, int *r_tweak) NOEXCEPT;

/**
 * \brief 太息。
 *
 * \param[out] r_time 时间引用
 */
EXTERN_C RRC_API enum rrc_status_t CDECL
rrc_sigh(time_t *r_time) NOEXCEPT;

#endif
