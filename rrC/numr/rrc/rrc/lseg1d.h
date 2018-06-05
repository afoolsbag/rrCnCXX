#pragma once
#ifndef RRC_LSEG1D_H_
#define RRC_LSEG1D_H_

#include <stdlib.h>

#include "rrc/api.h"
#include "pt1d.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief 数轴线段类型。
 *         Line-Segment. */
struct rrc_lseg1d_t {
	struct rrc_pt1d_t a;
	struct rrc_pt1d_t b;
};

/** \brief 求数轴线段长。
 *         Line-Segment Length. */
inline len_t
rrc_lseg1d_len(
	const struct rrc_lseg1d_t l)
{
	return l.a.x < l.b.x ? l.b.x - l.a.x : l.a.x - l.b.x;
}

/** \brief 两数轴线段交集。
 *         Line-Segment And(Intersection). */
RRC_API struct rrc_lseg1d_t
rrc_lseg1d_and(
	const struct rrc_lseg1d_t l, const struct rrc_lseg1d_t n);

#ifdef __cplusplus
}
#endif

#endif/*RRC_LSEG1D_H_*/
