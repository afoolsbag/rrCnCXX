//===-- Cartesian Coordinate System 2-Dimensional: Line Segment -*- C++ -*-===//
///
/// \defgroup gC2Ls 平面直角坐标系：线段。
/// \ingroup gGeom
///
/// \version 2018-07-27
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2LS_HXX_
#define RRCXX_C2LS_HXX_

#include "c2bv.hxx"
#include "c2fv.hxx"
#include "c2pt.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

/// @addtogroup gC2Ls
/// @{

///
/// \brief 线段 \f$ \overline{L} \f$。
///
template<typename ScalarType = double>
struct LineSegment {
    Point<ScalarType> ept1;  ///< 端点 \f$ Ept1 \f$。
    Point<ScalarType> ept2;  ///< 端点 \f$ Ept2 \f$。

    inline explicit LineSegment() = default;
    ///
    /// \brief 线段 \f$ \overline{Ept1 Ept2} \f$。
    ///
    inline explicit LineSegment(const Point<ScalarType> &ept1, const Point<ScalarType> &ept2)
    {
        this->ept1 = ept1;
        this->ept2 = ept2;
    }

    ///
    /// \brief 横轴上的投影区间。
    ///
    nl1::Interval<ScalarType> xProjection() const
    {
        return nl1::Interval<ScalarType>(nl1::Interval<ScalarType>::Type::CLOSE,
                                         nl1::Point<ScalarType>(ept1.x),
                                         nl1::Point<ScalarType>(ept2.x));
    }

    ///
    /// \brief 纵轴上的投影区间。
    ///
    nl1::Interval<ScalarType> yProjection() const
    {
        return nl1::Interval<ScalarType>(nl1::Interval<ScalarType>::Type::CLOSE,
                                         nl1::Point<ScalarType>(ept1.y),
                                         nl1::Point<ScalarType>(ept2.y));
    }

    ///
    /// \brief 线段转自由向量。
    ///
    inline explicit operator FreeVector<ScalarType>() const
    {
        return FreeVector<ScalarType>(ept2.x - ept1.x, ept2.y - ept1.y);
    }

    ///
    /// \brief 固定向量转线段。
    ///
    inline explicit LineSegment(const BoundVector<ScalarType> &vec)
    {
        ept1 = vec.ipt;
        ept2 = vec.ipt + vec.vec;
    }
    ///
    /// \brief 线段转固定向量。
    ///
    inline explicit operator BoundVector<ScalarType>() const
    {
        return BoundVector<ScalarType>(ept1, FreeVector<ScalarType>(*this));
    }
};

///
/// \brief 点与线段相交否。
///
template<typename ScalarType = double>
inline bool Intersected(const Point<ScalarType> &pt, const LineSegment<ScalarType> &ls)
{
    // 进行快速判定，排除明显不相交的情形：
    if (pt.x < ls.xProjection().min() ||
        ls.xProjection().max() < pt.x ||
        pt.y < ls.yProjection().min() ||
        ls.yProjection().max() < pt.y)
        return false;

    // 若通过快速判定，则进行严格判定：
    const FreeVector<ScalarType> AB(ls);
    const FreeVector<ScalarType> AP(ls.ept1, pt);
    // 因已通过快速判定，共线必然相交，不共线必然相离：
    return CrossProduct(AB, AP) == 0;
}

///
/// \brief 线段与点相交否。
///
template<typename ScalarType = double>
inline bool Intersected(const LineSegment<ScalarType> &ls, const Point<ScalarType> &pt)
{
    return Intersected(pt, ls);
}

///
/// \brief 线段相交否。
/// \details 设两线段 \f$ AB \f$ 和 \f$ CD \f$ 交于点 \f$ X \f$，则有：
///          \f[
///            \left\{ \begin{align}
///              \vec{OX} &= \vec{OA} + \vec{AX}              && \text{令} \vec{AX} = \lambda_{AB} \vec{AB} \\
///                       &= \vec{OA} + \lambda_{AB} \vec{AB}
///            \end{align} \right.
///          \f]
///          \f[
///            \left\{ \begin{align}
///              \vec{OX} &= \vec{OC} + \vec{CX}              && \text{令} \vec{CX} = \lambda_{CD} \vec{CD} \\
///                       &= \vec{OC} + \lambda_{CD} \vec{CD}
///            \end{align} \right.
///          \f]
///          \f[
///            \left\{ \begin{align}
///                                              \vec{OA} + \lambda_{AB} \vec{AB} &= \vec{OC} + \lambda_{CD} \vec{CD}
///                                                                               && \text{两边同乘}\vec{CD}                                                                   \\
///              \vec{OA} \times \vec{CD} + \lambda_{AB} \vec{AB} \times \vec{CD} &= \vec{OC} \times \vec{CD} + \lambda_{CD} \vec{CD} \times \vec{CD}
///                                                                               && \text{消去} \vec{CD} \times \vec{CD} = 0                                                 \\
///                                                                  \lambda_{AB} &= \frac{ \vec{OC} \times \vec{CD} - \vec{OA} \times \vec{CD} }{ \vec{AB} \times \vec{CD} } \\
///                                                                  \lambda_{AB} &= \frac{ \vec{AC} \times \vec{CD} }{ \vec{AB} \times \vec{CD} }
///            \end{align} \right.
///          \f]
///          \f[
///            \left\{ \begin{align}
///              \lambda_{CD} &= \frac{ \vec{CA} \times \vec{AB} }{ \vec{CD} \times \vec{AB} } && \text{减少变量} \\
///                           &= \frac{ \vec{AB} \times \vec{CA} }{ \vec{AB} \times \vec{CD} } && \text{减少变量} \\
///                           &= \frac{ \vec{AC} \times \vec{AB} }{ \vec{AB} \times \vec{CD} }
///            \end{align} \right.
///          \f]
///          + 若 \f$ \vec{AB} × \vec{CD} \f$ 为零（两线段平行），且 \f$ \vec{AC} × \vec{CD} \f$ 和 \f$ \vec{AC} × \vec{AB} \f$ 为零（两线段共线），则通过投影判断是否相交；
///          + 若平行而不共线，则必然不相交；
///          + 若不平行，则通过判断 \f$ \lambda_{AB} \f$ 和 \f$ \lambda_{CD} \f$ 是否处于 \f$ [0, 1] \f$ 判断是否相交。
///
/// \sa <https://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect>
///
template<typename ScalarType = double>
inline bool Intersected(const LineSegment<ScalarType> &ls1, const LineSegment<ScalarType> &ls2)
{
    // 进行快速判定，排除明显不相交的情形：
    if (ls1.xProjection().max() < ls2.xProjection().min() ||
        ls2.xProjection().max() < ls1.xProjection().min() ||
        ls1.yProjection().max() < ls2.yProjection().min() ||
        ls2.yProjection().max() < ls1.yProjection().min())
        return false;

    // 若通过快速判定，则进行严格判定：
    const FreeVector<ScalarType> AB(ls1);
    const FreeVector<ScalarType> AC(ls1.ept1, ls2.ept1);
    const FreeVector<ScalarType> CD(ls2);

    const ScalarType ABxCD = CrossProduct(AB, CD);
    const ScalarType ACxCD = CrossProduct(AC, CD);
    const ScalarType ACxAB = CrossProduct(AC, AB);

    if (ABxCD == 0) {
        // 因已通过快速判定，平行且共线必然相交，平行不共线必然相离：
        return ACxCD == 0 && ACxAB == 0;
    } else {
        const ScalarType lambdaAB = ACxCD / ABxCD;
        const ScalarType lambdaCD = ACxAB / ABxCD;
        return (0 <= lambdaAB && lambdaAB <= 1 && 0 <= lambdaCD && lambdaCD <= 1);
    }
}

///
/// \brief 射线。
///
template<typename ScalarType = double>
struct Ray {
    Point<ScalarType> ipt;  ///< 起始点。
    ScalarType phi = 0;     ///< 角。

    explicit Ray() = default;
    explicit Ray(const Point<ScalarType> &ipt, const ScalarType &phi)
    {
        this->ipt = ipt;
        this->phi = phi;
    }
};

///
/// \brief 直线。
/// \details 形如 \f$ L = \{ (x,y) \mid ax+by+c=0 \} \f$
///
template<typename ScalarType = double>
struct Line {
    ScalarType a = 0;  ///< 横坐标系数。
    ScalarType b = 0;  ///< 纵坐标系数。
    ScalarType c = 0;  ///< 常数。

    explicit Line() = default;
    explicit Line(const ScalarType &a, const ScalarType &b, const ScalarType &c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

///
/// \brief 轴平行矩形。
///
template<typename ScalarType = double>
struct AxisParallelRectangle {
    ScalarType x1 = 0;  ///< 横坐标1。
    ScalarType x2 = 0;  ///< 横坐标2。
    ScalarType y1 = 0;  ///< 纵坐标1。
    ScalarType y2 = 0;  ///< 纵坐标2。

    ///
    /// \brief 左横坐标。
    ///
    inline ScalarType &xMin()
    {
        return x1 < x2 ? x1 : x2;
    }

    ///
    /// \brief 右横坐标。
    ///
    inline ScalarType &xMax()
    {
        return x1 < x2 ? x2 : x1;
    }
    ///
    /// \brief 下纵坐标。
    ///
    inline ScalarType &yMin()
    {
        return y1 < y2 ? y1 : y2;
    }
    ///
    /// \brief 上纵坐标。
    ///
    inline ScalarType &yMax()
    {
        return y1 < y2 ? y2 : y1;
    }
};

///
/// \brief 线段与轴平行矩形相交否。
///
template<typename ScalarType = double>
inline bool Intersected(const LineSegment<ScalarType> &ls, const AxisParallelRectangle<ScalarType> &r)
{
    // 进行快速判定，排除明显不相交的情形：
    if (ls.xProjection().max() < r.xMin() ||
        r.xMax() < ls.xProjection().min() ||
        ls.yProjection().max() < r.yMin() ||
        r.yMax() < ls.yProjection().min())
        return false;

    // 若通过快速判定，则进行严格判定：
    const FreeVector<ScalarType> MN(ls);
    const FreeVector<ScalarType> MA(ls.ept1, Point<ScalarType>(r.x1, r.y1));
    const FreeVector<ScalarType> MB(ls.ept1, Point<ScalarType>(r.x1, r.y2));
    const FreeVector<ScalarType> MC(ls.ept1, Point<ScalarType>(r.x2, r.y1));
    const FreeVector<ScalarType> MD(ls.ept1, Point<ScalarType>(r.x2, r.y2));

    // 因已通过快速判定，共线必然相交，同边必然相离：
    const ScalarType ref = CrossProduct(MN, MA);
    if (0 < ref) {
        if (CrossProduct(MN, MB) <= 0)
            return true;
        if (CrossProduct(MN, MC) <= 0)
            return true;
        if (CrossProduct(MN, MD) <= 0)
            return true;
        return false;
    } else if (ref < 0) {
        if (0 <= CrossProduct(MN, MB))
            return true;
        if (0 <= CrossProduct(MN, MC))
            return true;
        if (0 <= CrossProduct(MN, MD))
            return true;
        return false;
    } else /* ref == 0 */ {
        return true;
    }
}

///
/// \brief 轴平行矩形与线段相交否。
///
template<typename ScalarType = double>
inline bool Intersected(const AxisParallelRectangle<ScalarType> &r, const LineSegment<ScalarType> &ls)
{
    return Intersected(ls, r);
}

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2LS_HXX_
