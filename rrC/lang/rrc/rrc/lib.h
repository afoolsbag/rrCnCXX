/*===-- Library ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 库。
 *
 * \sa [DLL编写教程](http://blogjava.net/wxb_nudt/archive/2007/09/11/144371.html)
 *
 * \version 2018-06-05
 * \since 2017-01-06
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_LIB_H_
#define RRC_LIB_H_

#include <stdint.h>
#include <time.h>

#include "api.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief rrc版本类型。
 */
struct rrc_version_t {
	uint16_t major;  /**< 主版本号。 */
	uint16_t minor;  /**< 次版本号。 */
	uint16_t patch;  /**< 补丁版本号。 */
	uint16_t tweak;  /**< 微调版本号。 */
};

/**
 * \brief 获取rrc版本。
 * \return 库版本结构体。
 */
RRC_API struct rrc_version_t
rrc_version(void);

/**
 * \brief 叹。
 */
RRC_API time_t
sigh(void);

#ifdef __cplusplus
}
#endif

#endif/*RRC_LIB_H_*/
