//===-- Cartesian Coordinate System 2-Dimensional: Point --------*- C++ -*-===//
///
/// \defgroup gC2Pt 平面直角坐标系：点
/// \ingroup gGeom
///
/// \version 2018-07-27
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2PT_HXX_
#define RRCXX_C2PT_HXX_

namespace rrcxx {
namespace geom {
namespace c2 {

/// @addtogroup gC2Pt
/// @{

///
/// \brief 区域。
///
enum class Area {
    ORIGIN,           ///< 原点 \f$ O = (0, 0) \f$。
    POSITIVE_X_AXIS,  ///< 正横轴 \f$ (+, 0) \f$。
    QUADRANT_I,       ///< 第一象限 \f$ I = (+, +) \f$。
    POSITIVE_Y_AXIS,  ///< 正纵轴 \f$ (0, +) \f$。
    QUADRANT_II,      ///< 第二象限 \f$ II = (-, +) \f$。
    NEGATIVE_X_AXIS,  ///< 负横轴 \f$ (-, 0) \f$。
    QUADRANT_III,     ///< 第三象限 \f$ III = (-, -) \f$。
    NEGATIVE_Y_AXIS,  ///< 负纵轴 \f$ (0, -) \f$。
    QUADRANT_IV,      ///< 第四象限 \f$ IV = (+, -) \f$。
};

///
/// \brief 点 \f$ P \f$。
///
template <typename ScalarType = double>
struct Point {
    ScalarType x = 0;  ///< 横坐标 \f$ x \f$。
    ScalarType y = 0;  ///< 纵坐标 \f$ y \f$。

    ///
    /// \brief 原点 \f$ O = (0, 0) \f$。
    ///
    inline explicit Point() = default;

    ///
    /// \brief 点 \f$ P = (x, y) \f$。
    ///
    inline explicit Point(const ScalarType &x, const ScalarType &y)
    {
        this->x = x;
        this->y = y;
    }

    ///
    /// \brief 所在区域。
    ///
    inline Area area() const
    {
        if (0 < x) {
            if (0 < y)
                return Area::QUADRANT_I;
            else if (y < 0)
                return Area::QUADRANT_IV;
            else /* 0 == y */
                return Area::POSITIVE_X_AXIS;
        } else if (x < 0) {
            if (0 < y)
                return Area::QUADRANT_II;
            else if (y < 0)
                return Area::QUADRANT_III;
            else /* 0 == y */
                return Area::NEGATIVE_X_AXIS;
        } else /* 0 == x */ {
            if (0 < y)
                return Area::POSITIVE_Y_AXIS;
            else if (y < 0)
                return Area::NEGATIVE_Y_AXIS;
            else /* 0 == y */
                return Area::ORIGIN;
        }
    }
};

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2PT_HXX_
