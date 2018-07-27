//===-- Number Line 1-Dimensional: Point ------------------------*- C++ -*-===//
///
/// \defgroup gNl1Pt 数轴：点。
/// \ingroup gGeom
///
/// \version 2018-07-27
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_NL1PT_HXX_
#define RRCXX_NL1PT_HXX_

namespace rrcxx {
namespace geom {
namespace nl1 {

/// @addtogroup gNl1Pt
/// @{

///
/// \brief 区域。
///
enum class Area {
    ORIGIN,         ///< 原点 \f$ O \f$。
    POSITIVE_AXIS,  ///< 正轴。
    NEGATIVE_AXIS,  ///< 负轴。
};

///
/// \brief 点 \f$ P \f$。
///
template <typename ScalarType = double>
struct Point {
    ScalarType x = 0;  ///< 坐标 \f$ x \f$。

    ///
    /// \brief 原点 \f$ O = (0) \f$。
    ///
    inline explicit Point() = default;

    ///
    /// \brief 点 \f$ P = (x) \f$。
    ///
    inline explicit Point(const ScalarType &x)
    {
        this->x = x;
    }

    ///
    /// \brief 所在区域。
    ///
    inline Area area() const
    {
        if (0 < x) {
            return Area::POSITIVE_AXIS;
        } else if (x < 0) {
            return Area::NEGATIVE_AXIS;
        } else /* 0 == x */ {
            return Area::ORIGIN;
        }
    }
};

///
/// \brief 比较相等。
///
template <typename ScalarType = double>
inline bool operator ==(const Point<ScalarType> &p1, const Point<ScalarType> &p2)
{
    return p1.x == p2.x;
}

///
/// \brief 比较不等。
///
template <typename ScalarType = double>
inline bool operator !=(const Point<ScalarType> &p1, const Point<ScalarType> &p2)
{
    return p1.x != p2.x;
}

///
/// \brief 比较小于。
///
template <typename ScalarType = double>
inline bool operator <(const Point<ScalarType> &p1, const Point<ScalarType> &p2)
{
    return p1.x < p2.x;
}

///
/// \brief 比较不小于。
///
template <typename ScalarType = double>
inline bool operator >=(const Point<ScalarType> &p1, const Point<ScalarType> &p2)
{
    return p1.x >= p2.x;
}

///
/// \brief 比较大于。
///
template <typename ScalarType = double>
inline bool operator >(const Point<ScalarType> &p1, const Point<ScalarType> &p2)
{
    return p1.x > p2.x;
}

///
/// \brief 比较不大于。
///
template <typename ScalarType = double>
inline bool operator <=(const Point<ScalarType> &p1, const Point<ScalarType> &p2)
{
    return p1.x <= p2.x;
}

/// @}

}//namespace nl1
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_NL1PT_HXX_
