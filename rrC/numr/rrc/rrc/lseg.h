/*===-- Point --------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 线。
 *
 * \version 2018-06-24
 * \since 2018-06-04
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once
#ifndef RRC_LINE_H_
#define RRC_LINE_H_

#include "rrc/api.h"
#include "pt.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief 线段（1D Line-Segment）。 */
struct rrc_1d_lseg_t {
	struct rrc_1d_pt_t a;
	struct rrc_1d_pt_t b;
};

/** \brief 线段（line-segment 2d-cartesian）。 */
struct rrc_lseg2dc_t {
	struct rrc_pt2dc_t a;
	struct rrc_pt2dc_t b;
};

/** \brief 线段（line-segment 3d-cartesian）。 */
struct rrc_lseg3dc_t {
	struct rrc_pt3dc_t a;
	struct rrc_pt3dc_t b;
};

/** \brief 线段端点排序（line-segment endpoint-sort 1d）。 */
inline void
rrc_lseg_ept_sort_1d(
	struct rrc_lseg1d_t *const pL)
{
	if (pL->a.x <= pL->b.x)
		return;
	const double tmp = pL->a.x;
	pL->a.x = pL->b.x;
	pL->b.x = tmp;
}

/** \brief 线段交集长度（line-segment and(intersect)-length 1d）。 */
inline double
rrc_lseg_and_len_1d(
	const struct rrc_lseg1di_t *const pL,
	const struct rrc_lseg1di_t *const pN)
{
	struct rrc_lseg1di_t l = *pL;
	rrc_lseg_eptsort_1di(&l);
	struct rrc_lseg1di_t n = *pN;
	rrc_lseg_eptsort_1di(&n);

}


#ifdef __cplusplus
}
#endif

#endif/*RRC_LINE_H_*/
