/*===-- Status -------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 状态码。
 *
 * \version 2019-07-19
 * \since 2018-01-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRLX_STATUS_H_
#define RRLX_STATUS_H_

/**
 * \brief 状态码。
 */
enum rrlx_status_t {
    rrlx_success = 0,                  /**< 成功 */

    rrlx_exception,                    /**< 标准基异常 */
    rrlx_logic_error,                  /**< 标准逻辑错误：程序内部错误逻辑所导致的可避免错误。 */
    rrlx_invalid_argument,             /**< 标准无效参数：因参数值未被接受而引发的错误。 */
    rrlx_domain_error,                 /**< 标准定义域错误 */
    rrlx_length_error,                 /**< 标准长度错误：试图超出一些对象的实现定义长度极限所导致的错误。 */
    rrlx_out_of_range,                 /**< 标准越界错误：访问试图受定义范围外的元素所带来的错误。 */
    rrlx_future_error,
    rrlx_bad_optional_access,
    rrlx_runtime_error,                /**< 标准运行时错误：源于程序作用域外，且不能轻易预测到的错误。 */
    rrlx_range_error,                  /**< 标准值域错误 */
    rrlx_overflow_error,               /**< 标准算术上溢错误 */
    rrlx_underflow_error,              /**< 标准算术下溢错误 */
    rrlx_regex_error,
    rrlx_nonexistent_local_time,
    rrlx_ambiguous_local_time,
    rrlx_tx_exception,
    rrlx_system_error,                 /**< 标准系统错误 */
    rrlx_ios_base_failure,             /**< 标准输入输出系统错误 */
    rrlx_filesystem_filesystem_error,  /**< 标准文件系统错误 */
    rrlx_bad_typeid,
    rrlx_bad_cast,
    rrlx_bad_any_cast,
    rrlx_bad_weak_ptr,
    rrlx_bad_function_call,
    rrlx_bad_alloc,                    /**< 标准存储分配失败 */
    rrlx_bad_array_new_length,
    rrlx_bad_exception,
    rrlx_bad_variant_access,

    rrlx_internal_exception,           /**< 内部异常 */
    rrlx_unexpected_exception          /**< 不预期的异常：不遵循标准异常或任何已知异常，意料之外的状况。 */
};

#endif
