#pragma once
#ifndef RRC_PT2DC_H_
#define RRC_PT2DC_H_

#include "rrc/api.h"
#include "unit.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief 平面直角坐标点类型。
 *         Point. */
struct rrc_pt2dc_t {
	grad_t x;
	grad_t y;
};

#ifdef __cplusplus
}
#endif

#endif/*RRC_PT2DC_H_*/
