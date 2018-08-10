//===-- Digon (2C) ---------------------------------------------*- C++ -*-===//
///
/// \defgroup gDigon2C 线段（平面直角坐标系）
/// \ingroup gGeom
///
/// \version 2018-08-09
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2_DIGON_HXX_
#define RRCXX_C2_DIGON_HXX_

#include "rrCXX/numr/gemo/c2/Polygon.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

/// @addtogroup gDigon2C
/// @{

///
/// \brief 线段 \f$ \overline{S} \f$。
///
struct Digon: Ngon<2> {
    Point &ept1 = epts[0];  ///< 端点（End Point）\f$ P_1 \f$。
    Point &ept2 = epts[1];  ///< 端点（End Point）\f$ P_2 \f$。

    /// \brief 线段 \f$ \overline{S} = \overline{OO} \f$。
    inline explicit Digon() = default;

    /// \brief 线段 \f$ \overline{S} = \overline{P_1P_2} \f$。
    inline explicit Digon(const Point &p1, const Point &p2)
    {
        ept1 = p1;
        ept2 = p2;
    }

    /// \brief 线段 \f$ \overline{S} = \overline{P_1P_2},
    ///        \left\{ \begin{align}
    ///          P_1 &= (x_1, y_1) \\
    ///          P_2 &= (x_2, y_2)
    ///        \end{align} \right.    \f$。
    inline explicit Digon(const double x1, const double y1, const double x2, const double y2)
        : Digon(Point(x1, y1), Point(x2, y2))
    {}
};

/// \brief 两线段是否重叠 \f$ p: \overline{S_1} = \overline{S_2} \f$。
inline bool operator ==(const Digon &s1, const Digon &s2)
{
    return (s1.ept1 == s2.ept1 && s1.ept2 == s2.ept2)
        || (s1.ept1 == s2.ept2 && s1.ept2 == s2.ept1);
}

/// \brief 两线段是否错开 \f$ p: \overline{S_1} \ne \overline{S_2} \f$。
inline bool operator !=(const Digon &s1, const Digon &s2)
{
    return !(s1 == s2);
}

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2_DIGON_HXX_
