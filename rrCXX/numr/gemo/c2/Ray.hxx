//===-- C2: Ray -------------------------------------------------*- C++ -*-===//
///
/// \defgroup gC2Ray 平面直角坐标系：射线
/// \ingroup gGeom
///
/// \version 2018-08-06
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2_RAY_HXX_
#define RRCXX_C2_RAY_HXX_

#include "rrCXX/numr/gemo/c2/Pt.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

/// @addtogroup gC2Ray
/// @{

///
/// \brief 射线 \f$ \overrightarrow{R} \f$。
///
template<typename ScalarType = double>
struct Ray {
    Point<ScalarType> ipt;        ///< 起始点（Initial Point）\f$ P_{initial} \f$。
    ScalarType        theta = 0;  ///< 角 \f$ \theta \f$。

    /// \brief 射线。
    explicit Ray() = default;

    /// \brief 射线。
    explicit Ray(const Point<ScalarType> &ipt, const ScalarType &theta)
    {
        this->ipt = ipt;
        this->theta = theta;
    }
};

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2_RAY_HXX_
