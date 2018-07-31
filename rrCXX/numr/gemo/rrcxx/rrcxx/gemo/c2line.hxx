//===-- Cartesian Coordinate System 2-Dimensional: Line ---------*- C++ -*-===//
///
/// \defgroup gC2Line 平面直角坐标系：直线
/// \ingroup gGeom
///
/// \version 2018-07-30
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2LINE_HXX_
#define RRCXX_C2LINE_HXX_

namespace rrcxx {
namespace geom {
namespace c2 {

/// @addtogroup gC2Line
/// @{

///
/// \brief 直线 \f$ \overleftrightarrow{L} \f$。
///
template<typename ScalarType = double>
struct Line {
    ScalarType a = 0;  ///< 横坐标系数。
    ScalarType b = 0;  ///< 纵坐标系数。
    ScalarType c = 0;  ///< 常数。

    explicit Line() = default;

    ///
    /// \brief 直线 \f$ \overleftrightarrow{L} = \{ (x,y) \mid ax+by+c=0 \} \f$。
    ///
    explicit Line(const ScalarType &a, const ScalarType &b, const ScalarType &c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2LINE_HXX_