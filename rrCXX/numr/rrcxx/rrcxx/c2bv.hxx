//===-- Cartesian Coordinate System 2-Dimensional: Bound Vector -*- C++ -*-===//
///
/// \defgroup gC2Bv 平面直角坐标系：固定向量。
/// \ingroup gGeom
///
/// \version 2018-07-27
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2BV_HXX_
#define RRCXX_C2BV_HXX_

#include "c2fv.hxx"
#include "c2pt.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

/// @addtogroup gC2Bv
/// @{

///
/// \brief 固定向量 \f$ \vec{B} \f$。
///
template<typename ScalarType = double>
struct BoundVector {
    Point<ScalarType> bpt;       ///< 基点 \f$ Bpt \f$。
    FreeVector<ScalarType> vec;  ///< 自由矢量 \f$ \vec{vec} \f$。

    ///
    /// \brief 固定向量 \f$ \vec{OO} \f$。
    ///
    inline explicit BoundVector() = default;

    ///
    /// \brief 固定向量。
    ///
    inline explicit BoundVector(const Point<ScalarType> &bpt, const FreeVector<ScalarType> &vec)
    {
        this->bpt = bpt;
        this->vec = vec;
    }

    ///
    /// \brief 固定向量（展开为标量）。
    ///
    inline explicit BoundVector(const ScalarType &xBpt, const ScalarType &yBpt, const ScalarType &xVec, const ScalarType &yVec)
    {
        BoundVector(Point<ScalarType>(xBpt, yBpt), FreeVector<ScalarType>(xVec, yVec));
    }
};

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2BV_HXX_
