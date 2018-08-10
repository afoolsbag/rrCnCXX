//===-- Polygon (2C) --------------------------------------------*- C++ -*-===//
///
/// \defgroup gPolygon2C 多边形（平面直角坐标系）
/// \ingroup gGeom
///
/// \sa <http://mathworld.wolfram.com/Polygon.html>
///
/// \version 2018-08-09
/// \since 2018-08-08
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2_POLYGON_HXX_
#define RRCXX_C2_POLYGON_HXX_

#include <cassert>
#include <array>
#include <vector>

#include "rrCXX/numr/gemo/c2/AxisAlignedRectangle.hxx"
#include "rrCXX/numr/gemo/c2/Point.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

/// @addtogroup gPolygon2C
/// @{

///
/// \brief 多边形 \f$ G \f$。
///
struct Polygon {
    std::vector<Point> epts;  ///< 端点集。

    /// \brief 轴对齐最小边界框 \f$ Raa_{mbb} \f$。\n
    ///        Axis-Aligned Minimum Bounding Box.
    /// \pre !Polygon.epts.empty()
    AxisAlignedRectangle aabb() const
    {
        assert(!epts.empty());
        AxisAlignedRectangle tmp;
        if (epts.empty())
            return tmp;
        tmp.xMin = tmp.xMax = epts.front().x;
        tmp.yMin = tmp.yMax = epts.front().y;
        for (const auto &ept : epts) {
            if (ept.x < tmp.xMin)
                tmp.xMin = ept.x;
            else if (tmp.xMax < ept.x)
                tmp.xMax = ept.x;
            if (ept.y < tmp.yMin)
                tmp.yMin = ept.y;
            else if (tmp.yMax < ept.y)
                tmp.yMax = ept.y;
        }
        return tmp;
    }
};

///
/// \brief N 边形 \f$ Gn \f$。
///
template<std::size_t N>
struct Ngon {
    static_assert(2 <= N);
    std::array<Point, N> epts;  ///< 端点集。

    /// \brief 轴对齐最小边界框 \f$ Raa_{mbb} \f$。\n
    ///        Axis-Aligned Minimum Bounding Box.
    /// \pre !Ngon.epts.empty()
    AxisAlignedRectangle aabb() const
    {
        AxisAlignedRectangle tmp;
        tmp.xMin = tmp.xMax = epts.front().x;
        tmp.yMin = tmp.yMax = epts.front().y;
        for (const auto &ept : epts) {
            if (ept.x < tmp.xMin)
                tmp.xMin = ept.x;
            else if (tmp.xMax < ept.x)
                tmp.xMax = ept.x;
            if (ept.y < tmp.yMin)
                tmp.yMin = ept.y;
            else if (tmp.yMax < ept.y)
                tmp.yMax = ept.y;
        }
        return tmp;
    }
};

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2_POLYGON_HXX_
