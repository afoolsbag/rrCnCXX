#pragma once
#ifndef RRC_PT1D_H_
#define RRC_PT1D_H_

#include "rrc/api.h"
#include "unit.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief 数轴点类型。
 *         Point. */
struct rrc_pt1d_t {
	grad_t x;
};

#ifdef __cplusplus
}
#endif

#endif/*RRC_PT1D_H_*/
