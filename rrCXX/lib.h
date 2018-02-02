/*===-- Library ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 库
 *
 * \author zhengrr
 * \date 2018-1-9 – 2018-2-1
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#ifndef RRCXX_LIB_H_
#define RRCXX_LIB_H_

#include <stdint.h>
#include <time.h>

#include "api.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief 库版本结构体 */
struct rrcxx_ver {
  uint16_t major;  /**< 库主版本号 `YYYY` */
  uint8_t minor;   /**< 库次版本号 `MM` */
  uint8_t patch;   /**< 库补丁版本号 `DD` */
  uint16_t tweak;  /**< 库微调版本号 `hhmm` */
};

/**
 * \brief 获取库版本
 * \param[out] pver 指向库版本结构体的指针
 */
RRCXX_API void rrcxx_get_ver(struct rrcxx_ver *const pver);

/** \brief 叹 */
RRCXX_API time_t rrcxx_sigh();

#ifdef __cplusplus
}
#endif

#endif/* RRCXX_LIB_H_*/
