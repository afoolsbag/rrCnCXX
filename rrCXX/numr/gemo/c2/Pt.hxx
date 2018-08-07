//===-- C2: Point -----------------------------------------------*- C++ -*-===//
///
/// \defgroup gC2Pt 平面直角坐标系：点
/// \ingroup gGeom
///
/// \version 2018-08-06
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2_PT_HXX_
#define RRCXX_C2_PT_HXX_

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

    /// \brief 原点 \f$ O = (0, 0) \f$。
    inline explicit Point() = default;

    /// \brief 点 \f$ P = (x, y) \f$。
    inline explicit Point(const ScalarType &x, const ScalarType &y)
    {
        this->x = x;
        this->y = y;
    }

    static const Point<ScalarType> ORIGIN;  ///< 零向量 \f$ \vec{0} \f$。

    /// \brief 所在区域。
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

template<typename ScalarType = double>
const Point<ScalarType> Point<ScalarType>::ORIGIN(0, 0);

///
/// \brief 相等 \f$ P_1 = P_2 \f$。
///
template <typename ScalarType = double>
inline bool operator ==(const Point<ScalarType> &p1, const Point<ScalarType> &p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

///
/// \brief 不等 \f$ P_1 \ne P_2 \f$。
///
template <typename ScalarType = double>
inline bool operator !=(const Point<ScalarType> &p1, const Point<ScalarType> &p2)
{
    return !(p1 == p2);
}

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2_PT_HXX_
