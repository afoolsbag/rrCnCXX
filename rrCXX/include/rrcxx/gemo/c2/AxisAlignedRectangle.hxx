//===-- Axis-Aligned Rectangle (2C) -----------------------------*- C++ -*-===//
///
/// \file
/// \brief 轴对齐矩形（平面直角坐标系）。
///
/// \version 2018-08-23
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2_AXISALIGNEDRECTANGLE_HXX_
#define RRCXX_C2_AXISALIGNEDRECTANGLE_HXX_

#include <cassert>

namespace rrcxx {
namespace geom {
namespace c2 {

///
/// \brief 轴对齐矩形 \f$ Raa \f$。
///
struct AxisAlignedRectangle {
    double xMin = 0;  ///< 最小横坐标 \f$ x_{min} \f$。
    double xMax = 0;  ///< 最大横坐标 \f$ x_{max} \f$。
    double yMin = 0;  ///< 最小纵坐标 \f$ y_{min} \f$。
    double yMax = 0;  ///< 最大纵坐标 \f$ y_{max} \f$。

    /// \brief 单元素轴对齐矩形 \f$ Raa \f$。
    inline explicit AxisAlignedRectangle() = default;

    /// \brief 轴对齐矩形 \f$ Raa \f$。
    inline explicit AxisAlignedRectangle(const double x1, const double x2, const double y1, const double y2)
    {
        if (x1 < x2) {
            xMin = x1;
            xMax = x2;
        } else {
            xMin = x2;
            xMax = x1;
        }
        if (y1 < y2) {
            yMin = y1;
            yMax = y2;
        } else {
            yMin = y2;
            yMax = y1;
        }
    }

    /// \brief 是否可视为点 \f$ p: Raa = P \f$。
    inline bool isPoint() const
    {
        return xMin == xMax && yMin == yMax;
    }

    /// \brief 是否可视为轴对齐线段 \f$ p: Raa = \overline{Saa} \f$。
    inline bool isAxisAlignedLineSegment() const
    {
        return xMin == xMax || yMin == yMax;
    }

    /// \brief 长度 \f$ l_{Raa} \f$。
    /// \pre AxisAlignedRectangle.xMin <= AxisAlignedRectangle.xMax
    inline double length() const
    {
        assert(xMin <= xMax);
        return xMax - xMin;
    }

    /// \brief 宽度 \f$ w_{Raa} \f$。
    /// \pre AxisAlignedRectangle.yMin <= AxisAlignedRectangle.yMax
    inline double width() const
    {
        assert(yMin <= yMax);
        return yMax - yMin;
    }

    /// \brief 面积 \f$ A_{Raa} \f$。
    /// \pre AxisAlignedRectangle.xMin <= AxisAlignedRectangle.xMax
    /// \pre AxisAlignedRectangle.yMin <= AxisAlignedRectangle.yMax
    inline double area() const
    {
        return length() * width();
    }

    /// \brief 周长 \f$ P_{Raa} \f$。
    /// \pre AxisAlignedRectangle.xMin <= AxisAlignedRectangle.xMax
    /// \pre AxisAlignedRectangle.yMin <= AxisAlignedRectangle.yMax
    inline double perimeter() const
    {
        return 2 * (length() + width());
    }
};

/// \brief 两轴对齐矩形是否重叠 \f$ p: Raa_1 = Raa_2 \f$。
inline bool operator ==(const AxisAlignedRectangle &raa1, const AxisAlignedRectangle &raa2)
{
    return raa1.xMin == raa2.xMin && raa1.xMax == raa2.xMax && raa1.yMin == raa2.yMin && raa1.yMax == raa2.yMax;
}

/// \brief 两轴对齐矩形是否错开 \f$ p: Raa_1 \ne Raa_2 \f$。
inline bool operator !=(const AxisAlignedRectangle &raa1, const AxisAlignedRectangle &raa2)
{
    return !(raa1 == raa2);
}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2_AXISALIGNEDRECTANGLE_HXX_
