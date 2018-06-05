#pragma once
#ifndef RRC_LSEG3DC_H_
#define RRC_LSEG3DC_H_

#include "rrc/api.h"
#include "pt3dc.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief 空间直角坐标线段类型。
 *         Line-Segment. */
struct rrc_lseg3dc_t {
	struct rrc_pt3dc_t a;
	struct rrc_pt3dc_t b;
};

#ifdef __cplusplus
}
#endif

#endif/*RRC_LSEG3DC_H_*/
