/** \file
 *  \brief 解析位流（bit stream）。
 *  \author zhengrr
 *  \date 2017-1-6 – 2018-1-8
 *  \copyright The MIT License */

#ifndef RRCLANG_LIB_H_
#define RRCLANG_LIB_H_

#include <stdint.h>
#include <stdlib.h>

#include "api.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief 返回一个数
 *  \return 一个数 */
RRCLANG_API long rrclang_number();

#ifdef __cplusplus
}
#endif

#endif/*RRCLANG_LIB_H_*/
