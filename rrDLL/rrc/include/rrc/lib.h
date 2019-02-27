/*===-- Library ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 库。
 *
 * \sa [*DLL 编写教程*](http://blogjava.net/wxb_nudt/archive/2007/09/11/144371.html)
 *
 * \version 2019-02-27
 * \since 2017-01-06
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_LIB_H_
#define RRC_LIB_H_

#include <time.h>

#include "rrc/api.h"

/*----- Types ----------------------------------------------------------------*/

/**
 * \brief 状态码。
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
 * \brief 版本。
 */
struct rrc_version_t {
    int major;  /**< 主版本号。 */
    int minor;  /**< 次版本号。 */
    int patch;  /**< 补丁版本号。 */
    int tweak;  /**< 微调版本号。 */
};

/*----- Functions ------------------------------------------------------------*/

/**
 * \brief 获取版本。
 *
 * \param[out] pv 版本指针（pointer to version）
 */
RRC_DECORATING RRC_PORTING enum rrc_status_t RRC_CALLING
rrc_version(struct rrc_version_t *pv);

/**
 * \brief 叹。
 *
 * \param[out] pt 时间指针（pointer to time）
 */
RRC_DECORATING RRC_PORTING enum rrc_status_t RRC_CALLING
rrc_sigh(time_t *pt);

#endif/*RRC_LIB_H_*/
