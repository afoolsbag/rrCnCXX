/*===-- Status -------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 状态码。
 *
 * \version 2020-06-03
 * \since 2018-01-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRX_STATUS_H_
#define RRX_STATUS_H_

/**
 * \brief 状态码。
 */
enum rrx_status_t {
    rrx_success = 0,                  /**< 成功 */

    rrx_exception,                    /**< 标准基异常 */
    rrx_logic_error,                  /**< 标准逻辑错误：程序内部错误逻辑所导致的可避免错误。 */
    rrx_invalid_argument,             /**< 标准无效参数：因参数值未被接受而引发的错误。 */
    rrx_domain_error,                 /**< 标准定义域错误 */
    rrx_length_error,                 /**< 标准长度错误：试图超出一些对象的实现定义长度极限所导致的错误。 */
    rrx_out_of_range,                 /**< 标准越界错误：访问试图受定义范围外的元素所带来的错误。 */
    rrx_future_error,
    rrx_bad_optional_access,
    rrx_runtime_error,                /**< 标准运行时错误：源于程序作用域外，且不能轻易预测到的错误。 */
    rrx_range_error,                  /**< 标准值域错误 */
    rrx_overflow_error,               /**< 标准算术上溢错误 */
    rrx_underflow_error,              /**< 标准算术下溢错误 */
    rrx_regex_error,
    rrx_nonexistent_local_time,
    rrx_ambiguous_local_time,
    rrx_tx_exception,
    rrx_system_error,                 /**< 标准系统错误 */
    rrx_ios_base_failure,             /**< 标准输入输出系统错误 */
    rrx_filesystem_filesystem_error,  /**< 标准文件系统错误 */
    rrx_bad_typeid,
    rrx_bad_cast,
    rrx_bad_any_cast,
    rrx_bad_weak_ptr,
    rrx_bad_function_call,
    rrx_bad_alloc,                    /**< 标准存储分配失败 */
    rrx_bad_array_new_length,
    rrx_bad_exception,
    rrx_bad_variant_access,

    rrx_internal_exception,           /**< 内部异常 */
    rrx_unexpected_exception          /**< 不预期的异常：不遵循标准异常或任何已知异常，意料之外的状况。 */
};

#endif
