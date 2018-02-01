/*===-- Library ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 库
 *
 * \sa [DLL编写教程](http://blogjava.net/wxb_nudt/archive/2007/09/11/144371.html)
 *
 * \author zhengrr
 * \date 2017-1-6 – 2018-2-1
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#ifndef RRC_LIB_H_
#define RRC_LIB_H_

#include <stdint.h>
#include <time.h>

#include "api.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief 库版本结构体 */
struct rrc_ver {
	int16_t major;  /**< 库主版本号 */
	int16_t minor;  /**< 库次版本号 */
	int16_t patch;  /**< 库补丁版本号 */
	int16_t tweak;  /**< 库微调版本号 */
};

/**
 * \brief 获取库版本
 * \param[out] pver 指向库版本结构体的指针
 */
RRC_API void rrc_get_ver(struct rrc_ver *const pver);

/** \brief 叹 */
RRC_API time_t rrc_sigh(void);

#ifdef __cplusplus
}
#endif

#endif/* RRC_LIB_H_*/
