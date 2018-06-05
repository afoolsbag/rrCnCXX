#pragma once
#ifndef RRC_PT1D_H_
#define RRC_PT1D_H_

#include "rrc/api.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief 空间直角坐标点。 */
struct rrc_pt3dc_t {
	double x;
	double y;
	double z;
};

#ifdef __cplusplus
}
#endif

#endif/*RRC_PT1D_H_*/
