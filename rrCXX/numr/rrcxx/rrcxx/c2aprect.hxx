//===-- C2: Axis-Parallel Rectangle -----------------------------*- C++ -*-===//
///
/// \defgroup gC2ApRect 平面直角坐标系：轴平行矩形。
/// \ingroup gGeom
///
/// \version 2018-07-30
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2APRECT_HXX_
#define RRCXX_C2APRECT_HXX_

#include "c2bndvec.hxx"
#include "c2lineseg.hxx"
#include "c2vec.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

/// @addtogroup gC2ApRect
/// @{

///
/// \brief 轴平行矩形 \f$ R \f$。
///
template<typename ScalarType = double>
struct AxisParallelRectangle {
    ScalarType xMin = 0;  ///< 最小横坐标 \f$ x_{min} \f$。
    ScalarType xMax = 0;  ///< 最大横坐标 \f$ x_{max} \f$。
    ScalarType yMin = 0;  ///< 最小纵坐标 \f$ y_{min} \f$。
    ScalarType yMax = 0;  ///< 最大纵坐标 \f$ y_{max} \f$。

    inline explicit AxisParallelRectangle() = default;

    ///
    /// \brief 有序平行轴矩形。
    ///
    inline explicit AxisParallelRectangle(const ScalarType &x1, const ScalarType &x2, const ScalarType &y1, const ScalarType &y2)
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

///
/// \brief 是否相交 \f$ p: \overline{S} \cap R \ne \emptyset \f$。
///
template<typename ScalarType = double>
inline bool Intersected(const LineSegment<ScalarType> &s, const AxisParallelRectangle<ScalarType> &r)
{
    // 进行快速判定，排除明显不相交的情形：
    if (s.xProjection().max < r.xMin || r.xMax < s.xProjection().min ||
        s.yProjection().max < r.yMin || r.yMax < s.yProjection().min)
        return false;

    // 若通过快速判定，则进行严格判定：
    const Vector<ScalarType> vMN = BoundVector<ScalarType>(s).vec;
    const Vector<ScalarType> vMA = BoundVector<ScalarType>(s.ept1, Point<ScalarType>(r.x1, r.y1)).vec;
    const Vector<ScalarType> vMB = BoundVector<ScalarType>(s.ept1, Point<ScalarType>(r.x1, r.y2)).vec;
    const Vector<ScalarType> vMC = BoundVector<ScalarType>(s.ept1, Point<ScalarType>(r.x2, r.y1)).vec;
    const Vector<ScalarType> vMD = BoundVector<ScalarType>(s.ept1, Point<ScalarType>(r.x2, r.y2)).vec;

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

///
/// \brief 是否相交 \f$ p: R \cap \overline{S} \ne \emptyset \f$。
///
template<typename ScalarType = double>
inline bool Intersected(const AxisParallelRectangle<ScalarType> &r, const LineSegment<ScalarType> &s)
{
    return Intersected(s, r);
}

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2APRECT_HXX_
