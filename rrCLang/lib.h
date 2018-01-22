/**
 * \file
 * \brief 库
 * \sa [DLL编写教程](http://blogjava.net/wxb_nudt/archive/2007/09/11/144371.html)
 * \author zhengrr
 * \date 2017-1-6 – 2018-1-22
 * \copyright The MIT License
 */

#ifndef RRCLANG_LIBRARY_H_
#define RRCLANG_LIBRARY_H_

#include <stdint.h>

#include "api.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief 库版本结构体 */
struct rrclang_version {
	int16_t major,  /**< 库主版本号 */
		minor,  /**< 库次版本号 */
		patch,  /**< 库补丁版本号 */
		tweak;  /**< 库微调版本号 */
};

/**
 * \brief 获取库版本
 * \param verptr[out] 库版本结构体的指针
 */
RRCLANG_API void rrclang_get_version(struct rrclang_version *verptr);

/**
 * \brief 叹
 */
RRCLANG_API int32_t rrclang_sigh(void);

#ifdef __cplusplus
}
#endif

#endif/* RRCLANG_LIBRARY_H_*/
