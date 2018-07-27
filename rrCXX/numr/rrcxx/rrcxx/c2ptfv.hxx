//===-- C2: Point & Free Vector ---------------------------------*- C++ -*-===//
///
/// \defgroup gC2PtFv 平面直角坐标系：点和自由向量。
/// \ingroup gGeom
///
/// \version 2018-07-27
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2PTFV_HXX_
#define RRCXX_C2PTFV_HXX_

#include "c2pt.hxx"
#include "c2fv.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

/// @addtogroup gC2PtFv
/// @{

///
/// \brief 点加向量 \f$ P + \vec{v} \f$。
///
template<typename ScalarType = double>
inline Point<ScalarType> operator +(const Point<ScalarType> &p, const FreeVector<ScalarType> &v)
{
    return Point<ScalarType>(p.x + v.x, p.y + v.y);
}

///
/// \brief 点减向量 \f$ P - \vec{v} \f$。
///
template<typename ScalarType = double>
inline Point<ScalarType> operator -(const Point<ScalarType> &p, const FreeVector<ScalarType> &v)
{
    return Point<ScalarType>(p.x - v.x, p.y - v.y);
}

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2PTFV_HXX_
