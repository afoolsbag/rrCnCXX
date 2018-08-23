//===-- Vector (2C) ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 向量（平面直角坐标系）。
///
/// \sa <http://mathworld.wolfram.com/Vector.html>
///
/// \version 2018-08-09
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2_VECTOR_HXX_
#define RRCXX_C2_VECTOR_HXX_

#include <cmath>

#include "Point.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

///
/// \brief 向量 \f$ \vec{v} \f$。
///
struct Vector {
    double x = 0;  ///< 横坐标 \f$ x \f$。
    double y = 0;  ///< 纵坐标 \f$ y \f$。

    /// \brief 零向量 \f$ \vec{0} = \left<0, 0\right> \f$。
    inline explicit Vector() = default;

    /// \brief 向量 \f$ \vec{v} = \left<x, y\right> \f$。
    inline explicit Vector(const double x, const double y)
    {
        this->x = x;
        this->y = y;
    }

    /// \brief 向量 \f$ \vec{v} = \vec{P_tP_h} \f$。
    inline explicit Vector(const Point &pt, const Point &ph)
        : Vector(ph.x - pt.x, ph.y - pt.y)
    {}

    static const Vector ZERO;   ///< 零向量 \f$ \vec{0} \f$。
    static const Vector XUNIT;  ///< 横轴单位向量 \f$ \hat{x} \f$。
    static const Vector YUNIT;  ///< 纵轴单位向量 \f$ \hat{y} \f$。

    /// \brief 反向量 \f$ -\vec{v} \f$。
    inline Vector opposite() const
    {
        return Vector(-x, -y);
    }

    /// \brief 范数 \f$ \left\|\vec{v}\right\| \f$。
    inline double norm() const
    {
        return std::sqrt(x * x + y * y);
    }

    /// \brief 单位向量 \f$ \hat{v} \f$。
    inline Vector unit() const
    {
        const double length = norm();
        if (length == 0)
            return Vector(0, 0);
        else
            return Vector(x / length, y / length);
    }

    /// \brief 垂直向量 \f$ \vec{v}^\perp \f$。
    ///
    /// \param ccw 逆时针旋转。
    /// \returns 逆时针或顺时针旋转\f$ 90^\circ \f$的垂直向量 \f$ \vec{0} \f$。
    inline Vector perpendicular(const bool ccw = true) const
    {
        if (ccw)
            return Vector(-y, x);
        else
            return Vector(y, -x);
    }

    /// \brief 垂直向量 \f$ \vec{v}^\perp \f$。
    ///
    /// \param vInd 指示向量 \f$ \vec{V_{ind}} \f$。
    /// \returns 垂直向量 \f$ \vec{v}^\perp \f$ 或零向量 \f$ \vec{0} \f$。
    inline Vector perpendicular(const Vector &vInd) const
    {
        const double crossProduct = x * vInd.y - y * vInd.x;
        if (crossProduct < 0)
            return Vector(y, -x);
        else if (0 < crossProduct)
            return Vector(-y, x);
        else
            return Vector(0, 0);
    }
};

const Vector Vector::ZERO(0, 0);
const Vector Vector::XUNIT(1, 0);
const Vector Vector::YUNIT(0, 1);

/// \brief 两向量是否相等 \f$ p: \vec{v_1} = \vec{v_2} \f$。
inline bool operator ==(const Vector &v1, const Vector &v2)
{
    return v1.x == v2.x && v1.y == v2.y;
}

/// \brief 两向量是否不等 \f$ p: \vec{v_1} \ne \vec{v_2} \f$。
inline bool operator !=(const Vector &v1, const Vector &v2)
{
    return !(v1 == v2);
}

/// \brief 向量取反 \f$ -\vec{v} \f$。
inline Vector operator -(const Vector &v)
{
    return v.opposite();
}

/// \brief 向量相加 \f$ \vec{a} + \vec{b} \f$。
inline Vector operator +(const Vector &a, const Vector &b)
{
    return Vector(a.x + b.x, a.y + b.y);
}

/// \brief 向量相减 \f$ \vec{a} - \vec{b} \f$。
inline Vector operator -(const Vector &a, const Vector &b)
{
    return Vector(a.x - b.x, a.y - b.y);
}

/// \brief 向量数乘 \f$ k \vec{v} \f$。
inline Vector operator *(const double k, const Vector &v)
{
    return Vector(k * v.x, k * v.y);
}

/// \brief 向量数乘 \f$ \vec{v} k \f$。
inline Vector operator *(const Vector &v, const double k)
{
    return k * v;
}

/// \brief 向量点乘 \f$ \vec{a} \cdot \vec{b} \f$。
inline double DotProduct(const Vector &a, const Vector &b)
{
    return a.x * b.x + a.y * b.y;
}

/// \brief 向量叉乘 \f$ \vec{a} \times \vec{b} \f$。
inline double CrossProduct(const Vector &a, const Vector &b)
{
    return a.x * b.y - a.y * b.x;
}

/// \brief 向量夹角 \f$ \theta \f$。
/// \details \f[ \begin{align}
///            \vec{a} \cdot \vec{b} &= \left\|\vec{a}\right\| \left\|\vec{b}\right\| \cos(\theta)                           \\
///                     \cos(\theta) &= \frac{ \vec{a} \cdot \vec{b} }{ \left\|\vec{a}\right\| \left\|\vec{b}\right\| }      \\
///                           \theta &= \arccos(\frac{\vec{a} \cdot \vec{b}}{\left\|\vec{a}\right\| \left\|\vec{b}\right\|})
///          \end{align} \f]
inline double IncludedAngle(const Vector &a, const Vector &b)
{
    return std::acos(DotProduct(a, b) / (a.norm() * b.norm()));
}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2_VECTOR_HXX_
