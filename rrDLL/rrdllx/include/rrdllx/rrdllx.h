/*===-- rrDLLx -------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief rrDLLx
 *
 * 关于 C++ 库的三种导出方式：
 *
 * *   C 方法
 *     *   `+` 操作系统范围 C ABI 已形成事实标准；几乎所有现代编程语言都支持与 C 互操作。
 *     *   `+` 独立的资源管理，不对 CRT 作限制。
 *     *   `-` 不支持异常。
 *     *   `-` 手动资源管理。
 *     *   `-` 繁琐；句柄和方法分离。
 *     *   `*` 以上缺陷可通过调用语言包装进行改进。
 * *   C++ 方法
 *     *   `+` 导出 C++ 类和本地 C++ 类一样使用。
 *     *   `+` 可以捕获 DLL 引发的异常。
 *     *   `+` 可缓解大型项目的重建压力。
 *     *   `+` 有助于项目模块化。
 *     *   `-` 必须使用相同的动态 CRT。
 *     *   `-` 必须使用相同的异常配置。
 *     *   `-` 符号导出将导出类的所有内容。
 *     *   `-` C++ ABI 尚无事实标准；不与纯 C 兼容。
 * *   COM 方法
 *     *   `+` 导出的 C++ 类可以与任何 C++ 编译器一同使用。
 *     *   `+` 独立的资源管理，不对 CRT 作限制。
 *     *   `+` 使项目模块化。
 *     *   `+` 容易转换为 COM 模块。
 *     *   `-` 手动管理实例的创建和销毁。
 *     *   `-` 接口类型受限：COM 接口类型限制。
 *     *   `-` 不与纯 C 兼容。
 *
 * 综上，推荐选用“C 方法”。
 *
 * \sa [HowTo: Export C++ classes from a DLL](https://codeproject.com/Articles/28969/HowTo-Export-C-classes-from-a-DLL)
 *
 * \version 2019-05-23
 * \since 2018-01-09
 * \authors zhengrr
 * \copyright Unlicense
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRDLLX_RRDLLX_H_
#define RRDLLX_RRDLLX_H_

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif

#include "api.h"

/*==============================================================================
 *  _______   _______ _____ _____
 * |_   _\ \ / / ___ \  ___/  ___|
 *   | |  \ V /| |_/ / |__ \ `--.
 *   | |   \ / |  __/|  __| `--. \
 *   | |   | | | |   | |___/\__/ /
 *   \_/   \_/ \_|   \____/\____/
 */

/** \brief 状态码（status）。 */
enum rrdllx_status_t {
    rrdllx_success = 0,                  /**< 成功 */

    rrdllx_exception,                    /**< 标准基异常 */
    rrdllx_logic_error,                  /**< 标准逻辑错误：程序内部错误逻辑所导致的可避免错误。 */
    rrdllx_invalid_argument,             /**< 标准无效参数：因参数值未被接受而引发的错误。 */
    rrdllx_domain_error,                 /**< 标准定义域错误 */
    rrdllx_length_error,                 /**< 标准长度错误：试图超出一些对象的实现定义长度极限所导致的错误。 */
    rrdllx_out_of_range,                 /**< 标准越界错误：访问试图受定义范围外的元素所带来的错误。 */
    rrdllx_future_error,
    rrdllx_bad_optional_access,
    rrdllx_runtime_error,                /**< 标准运行时错误：源于程序作用域外，且不能轻易预测到的错误。 */
    rrdllx_range_error,                  /**< 标准值域错误 */
    rrdllx_overflow_error,               /**< 标准算术上溢错误 */
    rrdllx_underflow_error,              /**< 标准算术下溢错误 */
    rrdllx_regex_error,
    rrdllx_nonexistent_local_time,
    rrdllx_ambiguous_local_time,
    rrdllx_tx_exception,
    rrdllx_system_error,                 /**< 标准系统错误 */
    rrdllx_ios_base_failure,             /**< 标准输入输出系统错误 */
    rrdllx_filesystem_filesystem_error,  /**< 标准文件系统错误 */
    rrdllx_bad_typeid,
    rrdllx_bad_cast,
    rrdllx_bad_any_cast,
    rrdllx_bad_weak_ptr,
    rrdllx_bad_function_call,
    rrdllx_bad_alloc,                    /**< 标准存储分配失败 */
    rrdllx_bad_array_new_length,
    rrdllx_bad_exception,
    rrdllx_bad_variant_access,

    rrdllx_null_reference,                     /**< 要求参数为引用时，实际传入空指针。 */
    rrdllx_null_handle,                        /**< 要求参数为实例句柄时，实际传入空指针。 */
    rrdllx_null_zstring,                       /**< 要求参数为空终止字符串时，实际传入空指针。 */
    rrdllx_null_zstring_rarray,                /**< 要求参数为空终止字符串原始数组时，实际传入空指针。 */
    rrdllx_null_byte8_rarray,                  /**< 要求参数为八位字节原始数组时，实际传入空指针。 */

    rrdllx_instance_not_found,                 /**< 实例未找到，通常由于传入了错误的句柄，或错误地提前释放资源造成。 */
    rrdllx_instance_byte8_array_not_found,     /**< 资源未找到，通常由于传入了错误的参数，或错误地提前释放资源造成。 */
    rrdllx_instance_char_array_not_found,      /**< 资源未找到，通常由于传入了错误的指针，或错误地提前释放资源造成。 */
    rrdllx_instance_zstring_array_not_found,   /**< 资源未找到，通常由于传入了错误的参数，或错误地提前释放资源造成。 */

    rrdllx_internal_error,       /**< 内部错误：可紧接调用 `rrdllx_alloc_last_internal_error_zstring` 获取错误信息。 */
    rrdllx_unexpected_exception  /**< 不预期的异常：不遵循标准异常或任何已知异常，意料之外的状况。 */
};

/** \brief 版本（version）。 */
struct rrdllx_version_t {
    int major;  /**< 主版本号 */
    int minor;  /**< 次版本号 */
    int patch;  /**< 补丁版本号 */
    int tweak;  /**< 微调版本号 */
};

/** \brief 实例句柄（instance handle）。 */
typedef void *rrdllx_handle_t;

/** \brief 八位字节原始数组（8-bit byte raw array）。 */
typedef const uint8_t *rrdllx_byte8_rarray_t;

/** \brief 八位字节结构数组（8-bit byte structured array）。 */
struct rrdllx_byte8_sarray_t {
    size_t                size;
    rrdllx_byte8_rarray_t data;
};

/** \brief 字符原始数组（character raw array）。 */
typedef const char *rrdllx_char_rarray_t;

/** \brief 字符结构数组（character structured array）。 */
struct rrdllx_char_sarray_t {
    size_t               size;
    rrdllx_char_rarray_t data;
};

/** \brief 空终止字符串（zero-terminated string）。 */
typedef rrdllx_char_rarray_t rrdllx_zstring_t;

/** \brief 空终止字符串原始数组（zero-terminated string raw array）。 */
typedef const rrdllx_zstring_t *rrdllx_zstring_rarray_t;

/** \brief 空终止字符串结构数组（zero-terminated string structured array）。 */
struct rrdllx_zstring_sarray_t {
    size_t                  size;
    rrdllx_zstring_rarray_t data;
};

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
RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_get_version(struct rrdllx_version_t *rv)
RRDLLX_APIs;

/**
 * \brief 构造实例。
 *
 * \param[out] rh 句柄引用（reference to handle）
 */
RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_construct(rrdllx_handle_t *rh)
RRDLLX_APIs;

/**
 * \brief 析构实例。
 *
 * \param h 实例句柄（handle）
 */
RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_destruct(rrdllx_handle_t h)
RRDLLX_APIs;

/**
 * \brief 分配八位字节数组，并纳入实例资源管理。
 *
 * \param[in]  h   实例句柄（handle）
 * \param[in]  v   八位字节原始数组值（value of byte8 rarray）
 * \param[in]  s   八位字节原始数组尺寸（size of byte8 rarray）
 * \param[out] rbs 八位字节结构数组引用（reference to byte8 sarray）
 */
RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_byte8_array(rrdllx_handle_t h, rrdllx_byte8_rarray_t v, size_t s, struct rrdllx_byte8_sarray_t *rbs)
RRDLLX_APIs;

/**
 * \brief 释放实例管理的八位字节数组。
 *
 * \param h  实例句柄（handle）
 * \param br 八位字节原始数组（byte8 rarray）
 */
RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_free_byte8_array(rrdllx_handle_t h, rrdllx_byte8_rarray_t br)
RRDLLX_APIs;

/**
 * \brief 分配字符数组，并纳入实例资源管理。
 *
 * \param[in]  h   实例句柄（handle）
 * \param[in]  v   字符原始数组值（value of char rarray）
 * \param[in]  s   字符原始数组尺寸（size of char rarray）
 * \param[out] rcs 字符结构数组引用（reference to char sarray）
 */
RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_char_array(rrdllx_handle_t h, rrdllx_char_rarray_t v, size_t s, struct rrdllx_char_sarray_t *rcs)
RRDLLX_APIs;

/**
 * \brief 释放实例管理的字符数组。
 *
 * \param h  实例句柄（handle）
 * \param cr 字符原始数组（char rarray）
 */
RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_free_char_array(rrdllx_handle_t h, rrdllx_char_rarray_t cr)
RRDLLX_APIs;

/**
 * \brief 分配空终止字符串，并纳入实例资源管理。
 *
 * \param[in]  h  实例句柄（handle）
 * \param[in]  v  空终止字符串值（value of zstring）
 * \param[out] rz 空终止字符串引用（reference to zstring）
 */
RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_zstring(rrdllx_handle_t h, rrdllx_zstring_t v, rrdllx_zstring_t *rz)
RRDLLX_APIs;

/**
 * \brief 分配空终止字符串，存入内部错误信息，并纳入实例资源管理。
 * \details 支持多线程。
 *
 * \param[in]  h  实例句柄（handle）
 * \param[out] rz 空终止字符串引用（reference to zstring）
 */
RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_last_internal_error_zstring(rrdllx_handle_t h, rrdllx_zstring_t *rz)
RRDLLX_APIs;

/**
 * \brief 释放实例管理的空终止字符串。
 *
 * \param h 实例句柄（handle）
 * \param z 空终止字符串（zstring）
 */
RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_free_zstring(rrdllx_handle_t h, rrdllx_zstring_t z)
RRDLLX_APIs;

/**
 * \brief 分配空终止字符串数组，并纳入实例资源管理。
 *
 * \param[in]  h   实例句柄（handle）
 * \param[in]  v   空终止字符串原始数组值（value of zstring rarray）
 * \param[in]  s   空终止字符串原始数组尺寸（size of zstring rarray）
 * \param[out] rzs 空终止字符串结构数组引用（reference to zstring sarray）
 */
RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_alloc_zstring_array(rrdllx_handle_t h, rrdllx_zstring_rarray_t v, size_t s, struct rrdllx_zstring_sarray_t *rzs)
RRDLLX_APIs;

/**
 * \brief 释放实例管理的空终止字符串数组。
 *
 * \param h  实例句柄（handle）
 * \param zr 空终止字符串原始数组（zstring rarray）
 */
RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_free_zstring_array(rrdllx_handle_t h, rrdllx_zstring_rarray_t zr)
RRDLLX_APIs;

/**
 * \brief 释放实例所有资源。
 *
 * \param h 实例句柄（handle）
 */
RRDLLX_APIp enum rrdllx_status_t
RRDLLX_APIm rrdllx_free_all(rrdllx_handle_t h)
RRDLLX_APIs;

#endif/*RRDLLX_RRDLLX_H_*/
