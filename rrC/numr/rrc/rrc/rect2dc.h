#pragma once
#ifndef RRC_RECT2DC_H_
#define RRC_RECT2DC_H_

#include "rrc/api.h"
#include "pt2dc.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief 平面直角坐标直矩形（轴对齐矩形）类型。
 *         Upright Rectangle. */
struct rrc_urtrect2dc_t {
	struct rrc_pt2dc_t a;
	struct rrc_pt2dc_t b;
};

#ifdef __cplusplus
}
#endif

#endif/*RRC_RECT2DC_H_*/
