//===-- Cartesian Coordinate System 2-Dimensional: Free Vector --*- C++ -*-===//
///
/// \defgroup gC2Fv 平面直角坐标系：自由向量。
/// \ingroup gGeom
///
/// \version 2018-07-27
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2FV_HXX_
#define RRCXX_C2FV_HXX_

#include <cmath>

#include "c2pt.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

/// @addtogroup gC2Fv
/// @{

///
/// \brief 自由向量 \f$ \vec{v} \f$。
///
template <typename ScalarType = double>
struct FreeVector {
    ScalarType x;  ///< 横坐标 \f$ x \f$。
    ScalarType y;  ///< 纵坐标 \f$ y \f$。

    ///
    /// \brief 零向量 \f$ \vec{0} \f$。
    ///
    inline explicit FreeVector() = default;

    ///
    /// \brief 自由向量 \f$ \vec{v} = \left<x, y\right> \f$。
    ///
    inline explicit FreeVector(const ScalarType &x, const ScalarType &y)
    {
        this->x = x;
        this->y = y;
    }

    static const FreeVector<ScalarType> ZERO = {0, 0};   ///< 零向量 \f$ \vec{0} \f$。
    static const FreeVector<ScalarType> XUNIT = {1, 0};  ///< 横轴单位向量 \f$ \hat{x} \f$。
    static const FreeVector<ScalarType> YUNIT = {0, 1};  ///< 纵轴单位向量 \f$ \hat{y} \f$。

    ///
    /// \brief 反向量 \f$ -\vec{v} \f$。
    ///
    inline FreeVector<ScalarType> opposite() const
    {
        return FreeVector<ScalarType>(-x, -y);
    }

    ///
    /// \brief 范数 \f$ \left\|\vec{v}\right\| \f$。
    ///
    inline ScalarType norm() const
    {
        return std::sqrt(x * x + y * y);
    }

    ///
    /// \brief 单位向量 \f$ \hat{u} \f$。
    ///
    inline FreeVector<ScalarType> unit() const
    {
        const ScalarType length = norm();
        if (length == 0)
            return FreeVector<ScalarType>(0, 0);
        else
            return FreeVector<ScalarType>(x / length, y / length);
    }

    ///
    /// \brief 垂直向量 \f$ \vec{v}^\perp \f$。
    ///
    /// \param ccw 逆时针旋转。
    /// \returns 逆时针或顺时针旋转\f$ 90^\circ \f$的垂直向量 \f$ \vec{0} \f$。
    ///
    inline FreeVector<ScalarType> perpendicular(const bool ccw = true) const
    {
        if (ccw)
            return FreeVector<ScalarType>(-y, x);
        else
            return FreeVector<ScalarType>(y, -x);
    }

    ///
    /// \brief 垂直向量 \f$ \vec{v}^\perp \f$。
    ///
    /// \param ind 指示向量 \f$ \vec{ind} \f$。
    /// \returns 垂直向量 \f$ \vec{v}^\perp \f$ 或零向量 \f$ \vec{0} \f$。
    ///
    inline FreeVector<ScalarType> perpendicular(const FreeVector<ScalarType> &ind) const
    {
        const ScalarType crossProduct = x * ind.y - y * ind.x;
        if (crossProduct < 0)
            return FreeVector<ScalarType>(y, -x);
        else if (0 < crossProduct)
            return FreeVector<ScalarType>(-y, x);
        else
            return FreeVector<ScalarType>(0, 0);
    }

    ///
    /// \brief 点 \f$ (x, y) \f$ 转自由向量 \f$ \left<x, y\right> \f$。
    ///
    inline explicit FreeVector(const Point<ScalarType> &pt)
    {
        x = pt.x;
        y = pt.y;
    }

    ///
    /// \brief 自由向量 \f$ \left<x, y\right> \f$ 转点 \f$ (x, y) \f$。
    ///
    inline explicit operator Point<ScalarType>() const
    {
        return Point<ScalarType>(x, y);
    }

    ///
    /// \brief 双点
    ///        \f$ \left\{ \begin{align}
    ///          (x_1, y_1) \\
    ///          (x_2, y_2)
    ///        \end{align} \right. \f$
    ///        转自由向量 \f$ \left<x_2-x_1, y_2-y_1\right> \f$。
    ///
    inline explicit FreeVector(const Point<ScalarType> &pt1, const Point<ScalarType> &pt2)
    {
        x = pt2.x - pt1.x;
        y = pt2.y - pt1.y;
    }
};

///
/// \brief 反 \f$ -\vec{v} \f$。
///
template<typename ScalarType = double>
inline FreeVector<ScalarType> operator -(const FreeVector<ScalarType> &v)
{
    return v.opposite();
}

///
/// \brief 加 \f$ \vec{a} + \vec{b} \f$。
///
template<typename ScalarType = double>
inline FreeVector<ScalarType> operator +(const FreeVector<ScalarType> &a, const FreeVector<ScalarType> &b)
{
    return FreeVector<ScalarType>(a.x + b.x, a.y + b.y);
}

///
/// \brief 减 \f$ \vec{a} - \vec{b} \f$。
///
template<typename ScalarType = double>
inline FreeVector<ScalarType> operator -(const FreeVector<ScalarType> &a, const FreeVector<ScalarType> &b)
{
    return FreeVector<ScalarType>(a.x - b.x, a.y - b.y);
}

///
/// \brief 点乘 \f$ \vec{a} \cdot \vec{b} \f$。
///
template<typename ScalarType = double>
inline ScalarType DotProduct(const FreeVector<ScalarType> &a, const FreeVector<ScalarType> &b)
{
    return a.x * b.x + a.y * b.y;
}

///
/// \brief 叉乘 \f$ \vec{a} \times \vec{b} \f$。
///
template<typename ScalarType = double>
inline ScalarType CrossProduct(const FreeVector<ScalarType> &a, const FreeVector<ScalarType> &b)
{
    return a.x * b.y - a.y * b.x;
}

///
/// \brief 数乘 \f$ k \vec{v} \f$。
///
template<typename ScalarType = double>
inline FreeVector<ScalarType> operator *(const ScalarType &k, const FreeVector<ScalarType> &v)
{
    return FreeVector<ScalarType>(k * v.x, k * v.y);
}

///
/// \brief 数乘 \f$ \vec{v} k \f$。
///
template<typename ScalarType = double>
inline FreeVector<ScalarType> operator *(const FreeVector<ScalarType> &v, const ScalarType &k)
{
    return k * v;
}

///
/// \brief 夹角 \f$ \theta \f$。
/// \details \f[ \begin{align}
///            \vec{a} \cdot \vec{b} &= \left\|\vec{a}\right\| \left\|\vec{b}\right\| \cos(\theta)                                 \\
///                     \cos(\theta) &= \frac{ \vec{a} \cdot \vec{b} }{ \left\|\vec{a}\right\| \left\|\vec{b}\right\| }         \\
///                           \theta &= \arccos(\frac{\vec{a} \cdot \vec{b}}{\left\|\vec{a}\right\| \left\|\vec{b}\right\|})
///          \end{align} \f]
///
template<typename ScalarType = double>
inline ScalarType IncludedAngle(const FreeVector<ScalarType> &a, const FreeVector<ScalarType> &b)
{
    return std::acos(DotProduct(a, b) / (a.norm() * b.norm()));
}

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2FV_HXX_
