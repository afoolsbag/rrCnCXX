#pragma once
#ifndef RRC_LSEG2DC_H_
#define RRC_LSEG2DC_H_

#include "rrc/api.h"
#include "pt2dc.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief 平面直角坐标线段类型。
 *         Line-Segment. */
struct rrc_lseg2dc_t {
	struct rrc_pt2dc_t a;
	struct rrc_pt2dc_t b;
};

#ifdef __cplusplus
}
#endif

#endif/*RRC_LSEG2DC_H_*/
