#pragma once
#ifndef RRC_PT3DC_H_
#define RRC_PT3DC_H_

#include "rrc/api.h"
#include "unit.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief 空间直角坐标点类型。
 *         Point. */
struct rrc_pt3dc_t {
	grad_t x;
	grad_t y;
	grad_t z;
};

#ifdef __cplusplus
}
#endif

#endif/*RRC_PT3DC_H_*/
