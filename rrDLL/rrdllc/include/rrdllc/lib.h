/*===-- Library ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 库。
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
#ifndef RRDLLC_LIB_H_
#define RRDLLC_LIB_H_

#include <time.h>

#include "rrdllc/api.h"

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
typedef enum rrdllc_status_t {
    rrdllc_success = 0,

    rrdllc_exception,
    rrdllc_logic_error,
    rrdllc_invalid_argument,
    rrdllc_domain_error,
    rrdllc_length_error,
    rrdllc_out_of_range,
    rrdllc_future_error,
    rrdllc_bad_optional_access,
    rrdllc_runtime_error,
    rrdllc_range_error,
    rrdllc_overflow_error,
    rrdllc_underflow_error,
    rrdllc_regex_error,
    rrdllc_nonexistent_local_time,
    rrdllc_ambiguous_local_time,
    rrdllc_tx_exception,
    rrdllc_system_error,
    rrdllc_ios_base_failure,
    rrdllc_filesystem_filesystem_error,
    rrdllc_bad_typeid,
    rrdllc_bad_cast,
    rrdllc_bad_any_cast,
    rrdllc_bad_weak_ptr,
    rrdllc_bad_function_call,
    rrdllc_bad_alloc,
    rrdllc_bad_array_new_length,
    rrdllc_bad_exception,
    rrdllc_bad_variant_access,
} rrdllc_status_t;

/**
 * \brief 版本。
 */
typedef struct rrdllc_version_t {
    int major;  /**< 主版本号。 */
    int minor;  /**< 次版本号。 */
    int patch;  /**< 补丁版本号。 */
    int tweak;  /**< 微调版本号。 */
} rrdllc_version_t;

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
RRDLLC_APIp rrdllc_status_t
RRDLLC_APIm rrdllc_get_version(rrdllc_version_t *rv)
RRDLLC_APIs;

/**
 * \brief 叹。
 *
 * \param[out] rt 时间引用（reference to time）
 */
RRDLLC_APIp rrdllc_status_t
RRDLLC_APIm rrdllc_sigh(time_t *rt)
RRDLLC_APIs;

#endif/*RRDLLC_LIB_H_*/
