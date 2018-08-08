//===-- C2: Vector ----------------------------------------------*- C++ -*-===//
///
/// \defgroup gC2Vec 平面直角坐标系：向量
/// \ingroup gGeom
///
/// \version 2018-08-06
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2_VEC_HXX_
#define RRCXX_C2_VEC_HXX_

#include <cmath>

#include "rrCXX/numr/gemo/c2/Pt.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

/// @addtogroup gC2Vec
/// @{

///
/// \brief 向量 \f$ \vec{v} \f$。
///
template <typename ScalarType>
struct Vector_ {
    ScalarType x = 0;  ///< 横坐标 \f$ x \f$。
    ScalarType y = 0;  ///< 纵坐标 \f$ y \f$。

    /// \brief 零向量 \f$ \vec{0} = \left<0, 0\right> \f$。
    inline explicit Vector_() = default;

    /// \brief 向量 \f$ \vec{v} = \left<x, y\right> \f$。
    inline explicit Vector_(const ScalarType &x, const ScalarType &y)
    {
        this->x = x;
        this->y = y;
    }

    static const Vector_<ScalarType> ZERO;   ///< 零向量 \f$ \vec{0} \f$。
    static const Vector_<ScalarType> XUNIT;  ///< 横轴单位向量 \f$ \hat{x} \f$。
    static const Vector_<ScalarType> YUNIT;  ///< 纵轴单位向量 \f$ \hat{y} \f$。

    /// \brief 反向量 \f$ -\vec{v} \f$。
    inline Vector_<ScalarType> opposite() const
    {
        return Vector_<ScalarType>(-x, -y);
    }

    /// \brief 范数 \f$ \left\|\vec{v}\right\| \f$。
    inline ScalarType norm() const
    {
        return std::sqrt(x * x + y * y);
    }

    /// \brief 单位向量 \f$ \hat{v} \f$。
    inline Vector_<ScalarType> unit() const
    {
        const ScalarType length = norm();
        if (length == 0)
            return Vector_<ScalarType>(0, 0);
        else
            return Vector_<ScalarType>(x / length, y / length);
    }

    /// \brief 垂直向量 \f$ \vec{v}^\perp \f$。
    ///
    /// \param ccw 逆时针旋转。
    /// \returns 逆时针或顺时针旋转\f$ 90^\circ \f$的垂直向量 \f$ \vec{0} \f$。
    inline Vector_<ScalarType> perpendicular(const bool ccw = true) const
    {
        if (ccw)
            return Vector_<ScalarType>(-y, x);
        else
            return Vector_<ScalarType>(y, -x);
    }

    /// \brief 垂直向量 \f$ \vec{v}^\perp \f$。
    ///
    /// \param vInd 指示向量 \f$ \vec{V_{ind}} \f$。
    /// \returns 垂直向量 \f$ \vec{v}^\perp \f$ 或零向量 \f$ \vec{0} \f$。
    inline Vector_<ScalarType> perpendicular(const Vector_<ScalarType> &vInd) const
    {
        const ScalarType crossProduct = x * vInd.y - y * vInd.x;
        if (crossProduct < 0)
            return Vector_<ScalarType>(y, -x);
        else if (0 < crossProduct)
            return Vector_<ScalarType>(-y, x);
        else
            return Vector_<ScalarType>(0, 0);
    }

    /// \brief 点 \f$ P = (x, y) \f$ 转向量 \f$ \vec{v} = \left<x, y\right> \f$。
    inline explicit Vector_(const Point_<ScalarType> &p)
        : Vector_(p.x, p.y)
    {}

    /// \brief 向量 \f$ \vec{v} = \left<x, y\right> \f$ 转点 \f$ P = (x, y) \f$。
    inline explicit operator Point_<ScalarType>() const
    {
        return Point_<ScalarType>(x, y);
    }
};

template<typename ScalarType>
const Vector_<ScalarType> Vector_<ScalarType>::ZERO(0, 0);
template<typename ScalarType>
const Vector_<ScalarType> Vector_<ScalarType>::XUNIT(1, 0);
template<typename ScalarType>
const Vector_<ScalarType> Vector_<ScalarType>::YUNIT(0, 1);

/// \brief 相等 \f$ \vec{v_1} = \vec{v_2} \f$。
template <typename ScalarType>
inline bool operator ==(const Vector_<ScalarType> &v1, const Vector_<ScalarType> &v2)
{
    return v1.x == v2.x && v1.y == v2.y;
}

/// \brief 不等 \f$ \vec{v_1} \ne \vec{v_2} \f$。
template <typename ScalarType>
inline bool operator !=(const Vector_<ScalarType> &v1, const Vector_<ScalarType> &v2)
{
    return !(v1 == v2);
}

/// \brief 反 \f$ -\vec{v} \f$。
template<typename ScalarType>
inline Vector_<ScalarType> operator -(const Vector_<ScalarType> &v)
{
    return v.opposite();
}

/// \brief 加 \f$ \vec{a} + \vec{b} \f$。
template<typename ScalarType>
inline Vector_<ScalarType> operator +(const Vector_<ScalarType> &a, const Vector_<ScalarType> &b)
{
    return Vector_<ScalarType>(a.x + b.x, a.y + b.y);
}

/// \brief 减 \f$ \vec{a} - \vec{b} \f$。
template<typename ScalarType>
inline Vector_<ScalarType> operator -(const Vector_<ScalarType> &a, const Vector_<ScalarType> &b)
{
    return Vector_<ScalarType>(a.x - b.x, a.y - b.y);
}

/// \brief 点乘 \f$ \vec{a} \cdot \vec{b} \f$。
template<typename ScalarType>
inline ScalarType DotProduct(const Vector_<ScalarType> &a, const Vector_<ScalarType> &b)
{
    return a.x * b.x + a.y * b.y;
}

/// \brief 叉乘 \f$ \vec{a} \times \vec{b} \f$。
template<typename ScalarType>
inline ScalarType CrossProduct(const Vector_<ScalarType> &a, const Vector_<ScalarType> &b)
{
    return a.x * b.y - a.y * b.x;
}

/// \brief 数乘 \f$ k \vec{v} \f$。
template<typename ScalarType>
inline Vector_<ScalarType> operator *(const ScalarType &k, const Vector_<ScalarType> &v)
{
    return Vector_<ScalarType>(k * v.x, k * v.y);
}

/// \brief 数乘 \f$ \vec{v} k \f$。
template<typename ScalarType>
inline Vector_<ScalarType> operator *(const Vector_<ScalarType> &v, const ScalarType &k)
{
    return k * v;
}

/// \brief 夹角 \f$ \theta \f$。
/// \details \f[ \begin{align}
///            \vec{a} \cdot \vec{b} &= \left\|\vec{a}\right\| \left\|\vec{b}\right\| \cos(\theta)                           \\
///                     \cos(\theta) &= \frac{ \vec{a} \cdot \vec{b} }{ \left\|\vec{a}\right\| \left\|\vec{b}\right\| }      \\
///                           \theta &= \arccos(\frac{\vec{a} \cdot \vec{b}}{\left\|\vec{a}\right\| \left\|\vec{b}\right\|})
///          \end{align} \f]
template<typename ScalarType>
inline ScalarType IncludedAngle(const Vector_<ScalarType> &a, const Vector_<ScalarType> &b)
{
    return std::acos(DotProduct(a, b) / (a.norm() * b.norm()));
}

/// \brief 加 \f$ P + \vec{v} \f$。
template<typename ScalarType>
inline Point_<ScalarType> operator +(const Point_<ScalarType> &p, const Vector_<ScalarType> &v)
{
    return Point_<ScalarType>(p.x + v.x, p.y + v.y);
}

/// \brief 减 \f$ P - \vec{v} \f$。
template<typename ScalarType = double>
inline Point_<ScalarType> operator -(const Point_<ScalarType> &p, const Vector_<ScalarType> &v)
{
    return Point_<ScalarType>(p.x - v.x, p.y - v.y);
}

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2_VEC_HXX_
