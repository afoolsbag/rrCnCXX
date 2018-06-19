/*===-- Cartesian Coordinate System Point ----------------------*- C -*-===*//**
 *
 * \file
 * \brief 点。
 *
 * \version 2018-06-05
 * \since 2018-06-04
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_PT_H_
#define RRC_PT_H_

#include <stddef.h>

#include "rrc/rrcapi.h"
#include "unit.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief 直角坐标系点类型（指针）。
 *        Point.
 */
typedef struct point_t {
	size_t dimension;      /**< 维度。 */
	graduation_t *vector;  /**< 坐标向量。 */
} *point_t;

/**
 * \brief 新建直角坐标系点。
 * \param dimension 维度。
 * \param ...
 * \return 直角坐标系点（指针）。
 */
RRC_API point_t
new_point(size_t dimension, ...);

/**
 * \brief 删除直角坐标系点。
 * \param point 直角坐标系点（指针）的指针。
 */
RRC_API void
delete_point(point_t *pointp);

/**
 * \brief 求俩直角坐标系点在axis轴上的距离。
 *        Axis Distance.
 * \param A    点A。
 * \param B    点B。
 * \param axis 轴。
 * \return 距离。
 */
RRC_API length_t
point_axis_distance(point_t A, point_t B, size_t axis);

#ifdef __cplusplus
}
#endif

#endif/*RRC_PT_H_*/
