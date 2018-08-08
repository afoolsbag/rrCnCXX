//===-- NL1: Point ----------------------------------------------*- C++ -*-===//
///
/// \defgroup gNl1Pt 数轴：点。
/// \ingroup gGeom
///
/// \version 2018-08-06
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_NL1_PT_HXX_
#define RRCXX_NL1_PT_HXX_

namespace rrcxx {
namespace geom {
namespace nl1 {

/// @addtogroup gNl1Pt
/// @{

///
/// \brief 区域。
///
enum class Area {
    ORIGIN,         ///< 原点 \f$ O = (0) \f$。
    POSITIVE_AXIS,  ///< 正轴 \f$ (+) \f$。
    NEGATIVE_AXIS,  ///< 负轴 \f$ (-) \f$。
};

///
/// \brief 点 \f$ P \f$。
///
template <typename ScalarType>
struct Point_ {
    ScalarType x = 0;  ///< 坐标 \f$ x \f$。

    /// \brief 原点 \f$ O = (0) \f$。
    inline explicit Point_() = default;

    /// \brief 点 \f$ P = (x) \f$。
    inline explicit Point_(const ScalarType &x)
    {
        this->x = x;
    }

    /// \brief 所在区域。
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

/// \brief 相等 \f$ P_1 = P_2 \f$。
template <typename ScalarType>
inline bool operator ==(const Point_<ScalarType> &p1, const Point_<ScalarType> &p2)
{
    return p1.x == p2.x;
}

/// \brief 不等 \f$ P_1 \ne P_2 \f$。
template <typename ScalarType>
inline bool operator !=(const Point_<ScalarType> &p1, const Point_<ScalarType> &p2)
{
    return p1.x != p2.x;
}

/// \brief 小于 \f$ P_1 \lt P_2 \f$。
template <typename ScalarType>
inline bool operator <(const Point_<ScalarType> &p1, const Point_<ScalarType> &p2)
{
    return p1.x < p2.x;
}

/// \brief 不小于 \f$ P_1 \ge P_2 \f$。
template <typename ScalarType>
inline bool operator >=(const Point_<ScalarType> &p1, const Point_<ScalarType> &p2)
{
    return p1.x >= p2.x;
}

/// \brief 大于 \f$ P_1 \gt P_2 \f$。
template <typename ScalarType>
inline bool operator >(const Point_<ScalarType> &p1, const Point_<ScalarType> &p2)
{
    return p1.x > p2.x;
}

/// \brief 不大于 \f$ P_1 \le P_2 \f$。
template <typename ScalarType>
inline bool operator <=(const Point_<ScalarType> &p1, const Point_<ScalarType> &p2)
{
    return p1.x <= p2.x;
}

/// @}

}//namespace nl1
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_NL1_PT_HXX_
