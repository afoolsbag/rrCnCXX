//===-- C2: Line Segment ----------------------------------------*- C++ -*-===//
///
/// \defgroup gC2LineSeg 平面直角坐标系：线段
/// \ingroup gGeom
///
/// \version 2018-08-06
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2_LINESEG_HXX_
#define RRCXX_C2_LINESEG_HXX_

#include "rrCXX/numr/gemo/c2/BndVec.hxx"
#include "rrCXX/numr/gemo/c2/Pt.hxx"
#include "rrCXX/numr/gemo/c2/Vec.hxx"
#include "rrCXX/numr/gemo/nl1/Inr.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

/// @addtogroup gC2LineSeg
/// @{

///
/// \brief 线段 \f$ \overline{S} \f$。
///
template<typename ScalarType>
struct LineSegment_ {
    Point_<ScalarType> ept1;  ///< 端点（End Point）\f$ P_1 \f$。
    Point_<ScalarType> ept2;  ///< 端点（End Point）\f$ P_2 \f$。

    /// \brief 线段 \f$ \overline{S} = \overline{OO} \f$。
    inline explicit LineSegment_() = default;

    /// \brief 线段 \f$ \overline{S} = \overline{P_1P_2} \f$。
    inline explicit LineSegment_(const Point_<ScalarType> &p1, const Point_<ScalarType> &p2)
    {
        ept1 = p1;
        ept2 = p2;
    }

    /// \brief 线段 \f$ \overline{S} = \overline{P_1P_2}, \left\{ \begin{align}
    ///                                                     P_1 &= (x_1, y_1) \\
    ///                                                     P_2 &= (x_2, y_2)
    ///                                                   \end{align} \right.    \f$。
    inline explicit LineSegment_(const ScalarType &x1, const ScalarType &y1, const ScalarType &x2, const ScalarType &y2)
        : LineSegment_(Point_<ScalarType>(x1, y1), Point_<ScalarType>(x2, y2))
    {}

    /// \brief 端点是否重合。
    inline bool isPoint() const
    {
        return ept1 == ept2;
    }

    /// \brief 横轴投影区间。
    inline nl1::Interval_<ScalarType> xProjection() const
    {
        using Interval_ = nl1::Interval_<ScalarType>;

        return Interval_(ept1.x, ept2.x, Interval_::Type::CLOSE);
    }

    /// \brief 纵轴投影区间。
    inline nl1::Interval_<ScalarType> yProjection() const
    {
        using Interval_ = nl1::Interval_<ScalarType>;

        return Interval_(ept1.y, ept2.y, Interval_::Type::CLOSE);
    }

    /// \brief 固定向量 \f$ \vec{B} \f$ 转线段 \f$ \overline{S} \f$。
    inline explicit LineSegment_(const BoundVector_<ScalarType> &b)
        : LineSegment_(b.bpt, b.bpt + b.vec)
    {}

    /// \brief 线段 \f$ \overline{S} \f$ 转固定向量 \f$ \vec{B} \f$。
    inline explicit operator BoundVector_<ScalarType>() const
    {
        return BoundVector_<ScalarType>(ept1, ept2);
    }
};

/// \brief 相等 \f$ \overline{S_1} = \overline{S_2} \f$。
template <typename ScalarType>
inline bool operator ==(const LineSegment_<ScalarType> &s1, const LineSegment_<ScalarType> &s2)
{
    return (s1.ept1 == s2.ept1 && s1.ept2 == s2.ept2)
        || (s1.ept1 == s2.ept2 && s1.ept2 == s2.ept1);
}

/// \brief 不等 \f$ \overline{S_1} \ne \overline{S_2} \f$。
template <typename ScalarType>
inline bool operator !=(const LineSegment_<ScalarType> &s1, const LineSegment_<ScalarType> &s2)
{
    return !(s1 == s2);
}

/// \brief 是否相交 \f$ p: P \cap \overline{S} \ne \emptyset \f$。
template<typename ScalarType>
inline bool Intersected(const Point_<ScalarType> &p, const LineSegment_<ScalarType> &s)
{
    using BoundVector_ = BoundVector_<ScalarType>;
    using Vector_ = Vector_<ScalarType>;

    // 若线段端点重合。
    if (s.isPoint())
        return p == s.ept1;

    // 进行快速判定，排除明显不相交的情形：
    if (p.x < s.xProjection().min || s.xProjection().max < p.x ||
        p.y < s.yProjection().min || s.yProjection().max < p.y)
        return false;

    // 若通过快速判定，则进行严格判定：
    const Vector_ vAB = BoundVector_(s).vec;
    const Vector_ vAP = BoundVector_(s.ept1, p).vec;
    // 因已通过快速判定，共线必然相交，不共线必然相离：
    return CrossProduct(vAB, vAP) == 0;
}

/// \brief 是否相交 \f$ p: \overline{S} \cap P \ne \emptyset \f$。
template<typename ScalarType>
inline bool Intersected(const LineSegment_<ScalarType> &s, const Point_<ScalarType> &p)
{
    return Intersected(p, s);
}

/// \brief 是否相交 \f$ p: \overline{S_1} \cap \overline{S_2} \ne \emptyset \f$。
/// \details 设两线段 \f$ \overline{AB} \f$ 和 \f$ \overline{CD} \f$ 交于点 \f$ X \f$，则有：
///          \f[ \left\{ \begin{align}
///            \vec{OX} &= \vec{OA} + \vec{AX}              && \vec{AX} = \lambda_{AB} \vec{AB} \\
///                     &= \vec{OA} + \lambda_{AB} \vec{AB}
///          \end{align} \right. \f]
///          \f[ \left\{ \begin{align}
///            \vec{OX} &= \vec{OC} + \vec{CX}              && \vec{CX} = \lambda_{CD} \vec{CD} \\
///                     &= \vec{OC} + \lambda_{CD} \vec{CD}
///          \end{align} \right. \f]
///          \f[ \left\{ \begin{align}
///                                            \vec{OA} + \lambda_{AB} \vec{AB} &= \vec{OC} + \lambda_{CD} \vec{CD}                                 && \times \vec{CD}              \\
///            \vec{OA} \times \vec{CD} + \lambda_{AB} \vec{AB} \times \vec{CD} &= \vec{OC} \times \vec{CD} + \lambda_{CD} \vec{CD} \times \vec{CD} && \vec{CD} \times \vec{CD} = 0 \\
///                                                                \lambda_{AB} &= \frac{ \vec{OC} \times \vec{CD} - \vec{OA} \times \vec{CD} }{ \vec{AB} \times \vec{CD} }         \\
///                                                                \lambda_{AB} &= \frac{ \vec{AC} \times \vec{CD} }{ \vec{AB} \times \vec{CD} }
///          \end{align} \right. \f]
///          \f[ \left\{ \begin{align}
///            \lambda_{CD} &= \frac{ \vec{CA} \times \vec{AB} }{ \vec{CD} \times \vec{AB} } \\
///                         &= \frac{ \vec{AB} \times \vec{CA} }{ \vec{AB} \times \vec{CD} } \\
///                         &= \frac{ \vec{AC} \times \vec{AB} }{ \vec{AB} \times \vec{CD} }
///          \end{align} \right. \f]
///          + 若 \f$ \vec{AB} × \vec{CD} \f$ 为零（两线段平行），且 \f$ \vec{AC} × \vec{CD} \f$ 和 \f$ \vec{AC} × \vec{AB} \f$ 为零（两线段共线），则通过投影判断是否相交；
///          + 若平行而不共线，则必然不相交；
///          + 若不平行，则通过判断 \f$ \lambda_{AB} \f$ 和 \f$ \lambda_{CD} \f$ 是否处于 \f$ [0, 1] \f$ 判断是否相交。
///
/// \sa <https://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect>
template<typename ScalarType>
inline bool Intersected(const LineSegment_<ScalarType> &s1, const LineSegment_<ScalarType> &s2)
{
    using BoundVector_ = BoundVector_<ScalarType>;
    using Vector_ = Vector_<ScalarType>;

    // 进行快速判定，排除明显不相交的情形：
    if (s1.xProjection().max < s2.xProjection().min || s2.xProjection().max < s1.xProjection().min ||
        s1.yProjection().max < s2.yProjection().min || s2.yProjection().max < s1.yProjection().min)
        return false;

    // 若通过快速判定，则进行严格判定：
    const Vector_ vAB = BoundVector_(s1).vec;
    const Vector_ vAC = BoundVector_(s1.ept1, s2.ept1).vec;
    const Vector_ vCD = BoundVector_(s2).vec;

    const ScalarType ABxCD = CrossProduct(vAB, vCD);
    const ScalarType ACxCD = CrossProduct(vAC, vCD);
    const ScalarType ACxAB = CrossProduct(vAC, vAB);

    if (ABxCD == 0) {
        // 因已通过快速判定，平行且共线必然相交，平行不共线必然相离：
        return ACxCD == 0 && ACxAB == 0;
    } else {
        const ScalarType lambdaAB = ACxCD / ABxCD;
        const ScalarType lambdaCD = ACxAB / ABxCD;
        return (0 <= lambdaAB && lambdaAB <= 1 && 0 <= lambdaCD && lambdaCD <= 1);
    }
}

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2_LINESEG_HXX_
