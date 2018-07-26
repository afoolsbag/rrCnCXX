//===-- Cartesian Coordinate System 2-Dimensional ---------------*- C++ -*-===//
///
/// \file
/// \brief 平面直角坐标系。
///
/// \version 2018-07-26
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2_HXX_
#define RRCXX_C2_HXX_

#include "nl1.hxx"

namespace rrcxx {
namespace geom {
///
/// \brief 平面直角坐标系（二维）。
///
namespace c2 {

///
/// \brief 平面区域。
///
enum class PlaneArea {
    ORIGIN,           ///< 原点。
    POSITIVE_X_AXIS,  ///< 正横轴。
    QUADRANT_I,       ///< 第一象限。
    POSITIVE_Y_AXIS,  ///< 正纵轴。
    QUADRANT_II,      ///< 第二象限。
    NEGATIVE_X_AXIS,  ///< 负横轴。
    QUADRANT_III,     ///< 第三象限。
    NEGATIVE_Y_AXIS,  ///< 负纵轴。
    QUADRANT_IV,      ///< 第四象限。
};

///
/// \brief 点。
///
template <typename ScalarType>
struct Point {
    ScalarType x = 0;  ///< 横坐标。
    ScalarType y = 0;  ///< 纵坐标。

    inline explicit Point() = default;
    inline explicit Point(const ScalarType &x, const ScalarType &y)
    {
        this->x = x;
        this->y = y;
    }

    explicit operator PlaneArea() const
    {
        if (0 < x) {
            if (0 < y)
                return PlaneArea::QUADRANT_I;
            else if (y < 0)
                return PlaneArea::QUADRANT_IV;
            else /* 0 == y */
                return PlaneArea::POSITIVE_X_AXIS;
        } else if (x < 0) {
            if (0 < y)
                return PlaneArea::QUADRANT_II;
            else if (y < 0)
                return PlaneArea::QUADRANT_III;
            else /* 0 == y */
                return PlaneArea::NEGATIVE_X_AXIS;
        } else /* 0 == x */ {
            if (0 < y)
                return PlaneArea::POSITIVE_Y_AXIS;
            else if (y < 0)
                return PlaneArea::NEGATIVE_Y_AXIS;
            else /* 0 == y */
                return PlaneArea::ORIGIN;
        }
    }
};

///
/// \brief 自由矢量。
///
template <typename ScalarType>
struct FreeVector {
    ScalarType x = 0;  ///< 横坐标。
    ScalarType y = 0;  ///< 纵坐标。

    inline explicit FreeVector() = default;
    inline explicit FreeVector(const ScalarType &x, const ScalarType &y)
    {
        this->x = x;
        this->y = y;
    }
    inline explicit FreeVector(const Point<ScalarType> &pt)
    {
        x = pt.x;
        y = pt.y;
    }
    inline explicit FreeVector(const Point<ScalarType> &from, const Point<ScalarType> &to)
    {
        x = to.x - from.x;
        y = to.y - from.y;
    }

    inline explicit operator Point<ScalarType>() const
    {
        return Point<ScalarType>(x, y);
    }
};

///
/// \brief 反矢量。
///
template<typename ScalarType>
inline FreeVector<ScalarType> operator -(const FreeVector<ScalarType> &vec)
{
    return FreeVector<ScalarType>(-vec.x, -vec.y);
}

///
/// \brief 矢量加。
///
template<typename ScalarType>
inline FreeVector<ScalarType> operator +(const FreeVector<ScalarType> &vec1, const FreeVector<ScalarType> &vec2)
{
    return FreeVector<ScalarType>(vec1.x + vec2.x, vec1.y + vec2.y);
}

///
/// \brief 矢量减。
///
template<typename ScalarType>
inline FreeVector<ScalarType> operator -(const FreeVector<ScalarType> &vec1, const FreeVector<ScalarType> &vec2)
{
    return FreeVector<ScalarType>(vec1.x - vec1.x, vec2.y - vec2.y);
}

///
/// \brief 点积（标量积）。
///
template<typename ScalarType>
inline ScalarType DotProduct(const FreeVector<ScalarType> &vec1, const FreeVector<ScalarType> &vec2)
{
    return vec1.x * vec2.x + vec1.y * vec2.y;
}

///
/// \brief 叉积（矢量积）。
///
template<typename ScalarType>
inline ScalarType CrossProduct(const FreeVector<ScalarType> &vec1, const FreeVector<ScalarType> &vec2)
{
    return vec1.x * vec2.y - vec1.y * vec2.x;
}

///
/// \brief 常量乘矢量。
///
template<typename ScalarType>
inline FreeVector<ScalarType> operator *(const ScalarType &a, const FreeVector<ScalarType> &vec)
{
    return FreeVector<ScalarType>(a * vec.x, a * vec.y);
}

///
/// \brief 矢量乘常量。
///
template<typename ScalarType>
inline FreeVector<ScalarType> operator *(const FreeVector<ScalarType> &vec, const ScalarType &a)
{
    return a * vec;
}

///
/// \brief 点加矢量。
///
template<typename ScalarType>
inline Point<ScalarType> operator +(const Point<ScalarType> &pt, const FreeVector<ScalarType> &vec)
{
    return Point<ScalarType>(pt.x + vec.x, pt.y + vec.y);
}

///
/// \brief 点减矢量。
///
template<typename ScalarType>
inline Point<ScalarType> operator -(const Point<ScalarType> &pt, const FreeVector<ScalarType> &vec)
{
    return Point<ScalarType>(pt.x - vec.x, pt.y - vec.y);
}

///
/// \brief 固定矢量。
///
template<typename ScalarType>
struct BoundVector {
    Point<ScalarType> ipt;       ///< 起始点。
    FreeVector<ScalarType> vec;  ///< 自由矢量。

    inline explicit BoundVector() = default;
    inline explicit BoundVector(const Point<ScalarType> &ipt, const FreeVector<ScalarType> &vec)
    {
        this->ipt = ipt;
        this->vec = vec;
    }
};

///
/// \brief 线段。
///
template<typename ScalarType>
struct LineSegment {
    Point<ScalarType> ept1;  ///< 端点1。
    Point<ScalarType> ept2;  ///< 端点2。

    inline explicit LineSegment() = default;
    inline explicit LineSegment(const Point<ScalarType> &ept1, const Point<ScalarType> &ept2)
    {
        this->ept1 = ept1;
        this->ept2 = ept2;
    }
    inline explicit LineSegment(const BoundVector<ScalarType> &vec)
    {
        ept1 = vec.ipt;
        ept2 = vec.ipt + vec.vec;
    }

    inline explicit operator FreeVector<ScalarType>() const
    {
        return FreeVector<ScalarType>(ept2.x - ept1.x, ept2.y - ept1.y);
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
};

///
/// \brief 点与线段相交否。
///
template<typename ScalarType>
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
template<typename ScalarType>
inline bool Intersected(const LineSegment<ScalarType> &ls, const Point<ScalarType> &pt)
{
    return Intersected(pt, ls);
}

///
/// \brief 线段相交否。
/// \details 设两线段 \f$ AB \f$ 和 \f$ CD \f$ 交于点 \f$ X \f$，则有：\n
///          （1）
///          \f$
///            \begin{align*}
///              \vec{OX} &= \vec{OA} + \vec{AX}          \\
///                       &= \vec{OA} + r_{AB} × \vec{AB}
///            \end{align*}
///          \f$ \n
///          （2）
///          \f$
///            \begin{align*}
///              \vec{OX} &= \vec{OC} + \vec{CX}          \\
///                       &= \vec{OC} + r_{CD} × \vec{CD}
///            \end{align*}
///          \f$ \n
///          由（1）和（2）可得（3）
///          \f$
///            \begin{align*}
///                                        \vec{OA} + r_{AB} × \vec{AB} &= \vec{OC} + r_{CD} × \vec{CD}                                              \\
///              \left( \vec{OA} + r_{AB} × \vec{AB} \right) × \vec{CD} &= \left( \vec{OC} + r_{CD} × \vec{CD} \right) × \vec{CD}                    \\
///                  \vec{OA} × \vec{CD} + r_{AB} × \vec{AB} × \vec{CD} &= \vec{OC} × \vec{CD} + r_{CD} × \vec{CD} × \vec{CD}                        \\
///                                                              r_{AB} &= \frac{ \vec{OC} × \vec{CD} - \vec{OA} × \vec{CD} }{ \vec{AB} × \vec{CD} } \\
///                                                              r_{AB} &= \frac{ \vec{AC} × \vec{CD} }{ \vec{AB} × \vec{CD} }
///            \end{align*}
///          \f$ \n
///          同理可得（4）
///          \f$
///            \begin{align*}
///              r_{CD} &= \frac{ \vec{CA} × \vec{AB} }{ \vec{CD} × \vec{AB} } \\
///                     &= \frac{ \vec{AB} × \vec{CA} }{ \vec{AB} × \vec{CD} } \\
///                     &= \frac{ \vec{AC} × \vec{AB} }{ \vec{AB} × \vec{CD} }
///            \end{align*}
///          \f$ \n
///          + 若 \f$ \vec{AB} × \vec{CD} \f$ 为零（两线段平行），且 \f$ \vec{AC} × \vec{CD} \f$ 和 \f$ \vec{AC} × \vec{AB} \f$ 为零（两线段共线），则通过投影判断是否相交；
///          + 若平行而不共线，则必然不相交；
///          + 若不平行，则通过判断 \f$ r_{AB} \f$ 和 \f$ r_{CD} \f$ 是否处于 \f$ [0, 1] \f$ 判断是否相交。
///
template<typename ScalarType>
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
        const ScalarType rAB = ACxCD / ABxCD;
        const ScalarType rCD = ACxAB / ABxCD;
        return (0 <= rAB && rAB <= 1 && 0 <= rCD && rCD <= 1);
    }
}

///
/// \brief 射线。
///
template<typename ScalarType>
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
template<typename ScalarType>
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
template<typename ScalarType>
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
template<typename ScalarType>
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
template<typename ScalarType>
inline bool Intersected(const AxisParallelRectangle<ScalarType> &r, const LineSegment<ScalarType> &ls)
{
    return Intersected(ls, r);
}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2_HXX_
