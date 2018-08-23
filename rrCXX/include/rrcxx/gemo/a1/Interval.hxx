//===-- Interval ------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 区间。
///
/// \sa <http://mathworld.wolfram.com/Interval.html>
///
/// \version 2018-08-23
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_A1_INTERVAL_HXX_
#define RRCXX_A1_INTERVAL_HXX_

#include <cassert>
#include <stdexcept>
#include <string>

namespace rrcxx {
namespace geom {
namespace a1 {

///
/// \brief 区间 \f$ Inr \f$。
///
struct Interval {
    /// \brief 区间类型。
    enum Type {
        OPEN,        ///< 开区间 \f$ (min, max) \f$。
        OPEN_CLOSE,  ///< 左开右闭区间 \f$ (min, max] \f$。
        CLOSE_OPEN,  ///< 左闭右开区间 \f$ [min, max) \f$。
        CLOSE        ///< 闭区间 \f$ [min, max] \f$。
    };

    double min = 0;      ///< 最小限制 \f$ min \f$。
    double max = 0;      ///< 最大限制 \f$ max \f$。
    Type   type = OPEN;  ///< 类型。

    /// \brief 空区间 \f$ Inr = \emptyset \f$。
    inline explicit Interval() = default;

    /// \brief 区间 \f$ Inr \f$。
    inline explicit Interval(const double limit1, const double limit2, const Type type)
    {
        if (limit1 < limit2) {
            min = limit1;
            max = limit2;
        } else {
            min = limit2;
            max = limit1;
        }
        this->type = type;
    }

    /// \brief 是否是空区间 \f$ p: Inr = \emptyset \f$。
    /// \pre Interval.min <= Interval.max
    inline bool isEmpty() const
    {
        assert(min <= max);
        return min == max && type != CLOSE;
    }

    /// \brief 是否是单元素区间。
    /// \pre Interval.min <= Interval.max
    inline bool isSingleton() const
    {
        assert(min <= max);
        return min == max && type == CLOSE;
    }

    /// \brief 直径。
    /// \pre Interval.min <= Interval.max
    inline double diameter() const
    {
        assert(min <= max);
        return max - min;
    }

    /// \brief 是否拥有某元素 \f$ p: obj \in Inr \f$。
    /// \pre Interval.min <= Interval.max
    /// \pre Interval::OPEN <= Interval.type && Interval.type <= Interval::CLOSE
    inline bool haveElement(const double obj) const
    {
        assert(min <= max);
        assert(OPEN <= type && type <= CLOSE);
        switch (type) {
        case OPEN:       return min < obj  && obj < max;
        case OPEN_CLOSE: return min < obj  && obj <= max;
        case CLOSE_OPEN: return min <= obj && obj < max;
        case CLOSE:      return min <= obj && obj <= max;
        default:         throw std::invalid_argument("the Interval type is invalid: " + std::to_string(type) + ".");
        }
    }
};

/// \brief 两区间是否相等 \f$ p: Inr_1 = Inr_2 \f$。
/// \pre Interval.min <= Interval.max
inline bool operator ==(const Interval &inr1, const Interval &inr2)
{
    if (inr1.isEmpty() && inr2.isEmpty())
        return true;
    return inr1.min == inr2.min && inr1.max == inr2.max && inr1.type == inr2.type;
}

/// \brief 两区间是否不等 \f$ p: Inr_1 \ne Inr_2 \f$。
/// \pre Interval.min <= Interval.max
inline bool operator !=(const Interval &inr1, const Interval &inr2)
{
    return !(inr1 == inr2);
}

}//namespace a1
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_A1_INTERVAL_HXX_
