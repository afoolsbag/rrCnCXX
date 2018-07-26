//===-- Number Line 1-Dimensional -------------------------------*- C++ -*-===//
///
/// \file
/// \brief 数轴。
///
/// \version 2018-07-26
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_NL1_HXX_
#define RRCXX_NL1_HXX_

namespace rrcxx {
namespace geom {
///
/// \brief 数轴（一维）。
///        Number Line (1-dimensional).
///
namespace nl1 {

///
/// \brief 点。
///
template <typename ScalarType = double>
struct Point {
    ScalarType x = 0;  ///< 坐标。

    inline explicit Point() = default;
    inline explicit Point(const ScalarType &x)
    {
        this->x = x;
    }
    inline explicit operator ScalarType() const
    {
        return x;
    }
};

///
/// \brief 区间。
///
template <typename ScalarType = double>
struct Interval {
    ///
    /// \brief 区间类型。
    ///
    enum class Type {
        OPEN,        ///< 开区间。
        OPEN_CLOSE,  ///< 左开右闭区间。
        CLOSE_OPEN,  ///< 左闭右开区间。
        CLOSE        ///< 闭区间。
    };

    Type type = Type::OPEN;  ///< 类型。
    Point<ScalarType> ept1;  ///< 端点1。
    Point<ScalarType> ept2;  ///< 端点2。

    inline explicit Interval() = default;
    inline explicit Interval(const Type type, const Point<ScalarType> &ept1, const Point<ScalarType> &ept2)
    {
        this->type = type;
        this->ept1 = ept1;
        this->ept2 = ept2;
    }

    ///
    /// \brief 左端点。
    ///
    inline Point<ScalarType> &minEpt()
    {
        return ept1.x < ept2.x ? ept1 : ept2;
    }

    ///
    /// \brief 左坐标。
    ///
    inline ScalarType &min()
    {
        return minEpt().x;
    }

    ///
    /// \brief 右端点。
    ///
    inline Point<ScalarType> &maxEpt()
    {
        return ept1.x < ept2.x ? ept2 : ept1;
    }

    ///
    /// \brief 右坐标。
    ///
    inline ScalarType &max()
    {
        return maxEpt().x;
    }

    ///
    /// \brief 长度。
    ///
    inline ScalarType length() const
    {
        return max() - min();
    }
};

}//namespace numline
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_NL1_HXX_
