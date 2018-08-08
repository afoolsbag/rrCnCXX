//===-- C2: Axis-Parallel Rectangle -----------------------------*- C++ -*-===//
///
/// \defgroup gC2ApRect 平面直角坐标系：轴平行矩形
/// \ingroup gGeom
///
/// \version 2018-08-06
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2_APRECT_HXX_
#define RRCXX_C2_APRECT_HXX_

#include "rrCXX/numr/gemo/c2/BndVec.hxx"
#include "rrCXX/numr/gemo/c2/LineSeg.hxx"
#include "rrCXX/numr/gemo/c2/Vec.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

/// @addtogroup gC2ApRect
/// @{

///
/// \brief 轴平行矩形 \f$ R \f$。
///
template<typename ScalarType>
struct AxisParallelRectangle_ {
    ScalarType xMin = 0;  ///< 最小横坐标 \f$ x_{min} \f$。
    ScalarType xMax = 0;  ///< 最大横坐标 \f$ x_{max} \f$。
    ScalarType yMin = 0;  ///< 最小纵坐标 \f$ y_{min} \f$。
    ScalarType yMax = 0;  ///< 最大纵坐标 \f$ y_{max} \f$。

    inline explicit AxisParallelRectangle_() = default;

    /// \brief 有序轴平行矩形。
    inline explicit AxisParallelRectangle_(const ScalarType &x1, const ScalarType &x2, const ScalarType &y1, const ScalarType &y2)
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
};

/// \brief 相等 \f$ R_1 = R_2 \f$。
template <typename ScalarType>
inline bool operator ==(const AxisParallelRectangle_<ScalarType> &r1, const AxisParallelRectangle_<ScalarType> &r2)
{
    return r1.xMin == r2.xMin && r1.xMax == r2.xMax && r1.yMin == r2.yMin && r1.yMax == r2.yMax;
}

/// \brief 不等 \f$ R_1 \ne R_2 \f$。
template <typename ScalarType>
inline bool operator !=(const AxisParallelRectangle_<ScalarType> &r1, const AxisParallelRectangle_<ScalarType> &r2)
{
    return !(r1 == r2);
}

/// \brief 是否相交 \f$ p: P \cap R \ne \emptyset \f$。
template<typename ScalarType>
inline bool Intersected(const Point_<ScalarType> &p, const AxisParallelRectangle_<ScalarType> &r)
{
    return r.xMin <= p.x && p.x <= r.xMax && r.yMin <= p.y && p.y <= r.yMax;
}

/// \brief 是否相交 \f$ p: R \cap P \ne \emptyset \f$。
template<typename ScalarType>
inline bool Intersected(const AxisParallelRectangle_<ScalarType> &r, const Point_<ScalarType> &p)
{
    return Intersected(p, r);
}

/// \brief 是否相交 \f$ p: \overline{S} \cap R \ne \emptyset \f$。
template<typename ScalarType>
inline bool Intersected(const LineSegment_<ScalarType> &s, const AxisParallelRectangle_<ScalarType> &r)
{
    using BoundVector_ = BoundVector_<ScalarType>;
    using Point_ = Point_<ScalarType>;
    using Vector_ = Vector_<ScalarType>;

    // 进行快速判定，排除明显不相交的情形：
    if (s.xProjection().max < r.xMin || r.xMax < s.xProjection().min ||
        s.yProjection().max < r.yMin || r.yMax < s.yProjection().min)
        return false;

    // 若通过快速判定，则进行严格判定：
    const Vector_ vMN = BoundVector_(s).vec;
    const Vector_ vMA = BoundVector_(s.ept1, Point_(r.xMin, r.yMin)).vec;
    const Vector_ vMB = BoundVector_(s.ept1, Point_(r.xMin, r.yMax)).vec;
    const Vector_ vMC = BoundVector_(s.ept1, Point_(r.xMax, r.yMin)).vec;
    const Vector_ vMD = BoundVector_(s.ept1, Point_(r.xMax, r.yMax)).vec;

    // 因已通过快速判定，共线必然相交，同边必然相离：
    const ScalarType ref = CrossProduct(vMN, vMA);
    if (0 < ref) {
        if (CrossProduct(vMN, vMB) <= 0)
            return true;
        if (CrossProduct(vMN, vMC) <= 0)
            return true;
        if (CrossProduct(vMN, vMD) <= 0)
            return true;
        return false;
    } else if (ref < 0) {
        if (0 <= CrossProduct(vMN, vMB))
            return true;
        if (0 <= CrossProduct(vMN, vMC))
            return true;
        if (0 <= CrossProduct(vMN, vMD))
            return true;
        return false;
    } else /* ref == 0 */ {
        return true;
    }
}

/// \brief 是否相交 \f$ p: R \cap \overline{S} \ne \emptyset \f$。
template<typename ScalarType>
inline bool Intersected(const AxisParallelRectangle_<ScalarType> &r, const LineSegment_<ScalarType> &s)
{
    return Intersected(s, r);
}

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2_APRECT_HXX_
