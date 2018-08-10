//===-- Point (2C) ----------------------------------------------*- C++ -*-===//
///
/// \defgroup gPt2C 点（平面直角坐标系）
/// \ingroup gGeom
///
/// \sa <http://mathworld.wolfram.com/Point.html>
///
/// \version 2018-08-09
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2_POINT_HXX_
#define RRCXX_C2_POINT_HXX_

namespace rrcxx {
namespace geom {
namespace c2 {

/// @addtogroup gPt2C
/// @{

///
/// \brief 点 \f$ P \f$。
///
struct Point {
    double x = 0;  ///< 横坐标 \f$ x \f$。
    double y = 0;  ///< 纵坐标 \f$ y \f$。

    /// \brief 原点 \f$ O = (0, 0) \f$。
    inline explicit Point() = default;

    /// \brief 点 \f$ P = (x, y) \f$。
    inline explicit Point(const double x, const double y)
    {
        this->x = x;
        this->y = y;
    }

    static const Point ORIGIN;  ///< 原点 \f$ O = (0, 0) \f$。
};

const Point Point::ORIGIN(0, 0);

///
/// \brief 两点是否重叠 \f$ p: P_1 = P_2 \f$。
///
inline bool operator ==(const Point &p1, const Point &p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

///
/// \brief 两点是否错开 \f$ p: P_1 \ne P_2 \f$。
///
inline bool operator !=(const Point &p1, const Point &p2)
{
    return !(p1 == p2);
}

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2_POINT_HXX_
