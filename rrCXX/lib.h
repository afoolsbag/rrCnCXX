/*===-- Library ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 库
 *
 * \version 2018-02-31
 * \since 2018-01-09
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRCXX_LIB_H_
#define RRCXX_LIB_H_

#include <stdint.h>
#include <time.h>

#include "api.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief 库版本结构体。
 */
struct rrcxx_version_t {
	uint16_t major;  /**< 库主版本号。 */
	uint16_t minor;  /**< 库次版本号。 */
	uint16_t patch;  /**< 库补丁版本号。 */
	uint16_t tweak;  /**< 库微调版本号。 */
};

/**
 * \brief 获取库版本。
 * \param[out] version_ptr 指向库版本结构体的指针。
 */
RRCXX_API void rrcxx_get_version(struct rrcxx_version_t *const version_ptr);

/**
 * \brief 叹。
 */
RRCXX_API time_t rrcxx_sigh();

#ifdef __cplusplus
}
#endif

#endif/*RRCXX_LIB_H_*/
