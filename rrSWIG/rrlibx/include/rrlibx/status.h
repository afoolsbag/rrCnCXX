/*===-- Status -------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 状态码。
 *
 * \version 2020-04-30
 * \since 2018-01-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRLIBX_STATUS_H_
#define RRLIBX_STATUS_H_

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

    rrlibx_internal_exception,           /**< 内部异常 */
    rrlibx_unexpected_exception          /**< 不预期的异常：不遵循标准异常或任何已知异常，意料之外的状况。 */
};

#endif
