//===-- NL1: Interval -------------------------------------------*- C++ -*-===//
///
/// \defgroup gNl1Inr 数轴：区间。
/// \ingroup gGeom
///
/// \version 2018-08-06
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_NL1_INR_HXX_
#define RRCXX_NL1_INR_HXX_

namespace rrcxx {
namespace geom {
namespace nl1 {

/// @addtogroup gNl1Inr
/// @{

///
/// \brief 区间。
///
template <typename ScalarType = double>
struct Interval {
    /// \brief 区间类型。
    enum class Type {
        OPEN,        ///< 开区间 \f$ (min, max) \f$。
        OPEN_CLOSE,  ///< 左开右闭区间 \f$ (min, max] \f$。
        CLOSE_OPEN,  ///< 左闭右开区间 \f$ [min, max) \f$。
        CLOSE        ///< 闭区间 \f$ [min, max] \f$。
    };

    ScalarType min = 0;            ///< 最小限制 \f$ min \f$。
    ScalarType max = 0;            ///< 最大限制 \f$ max \f$。
    Type       type = Type::OPEN;  ///< 类型。

    /// \brief 空集 \f$ \emptyset \f$。
    inline explicit Interval() = default;

    /// \brief 有序区间。
    inline explicit Interval(const ScalarType &limit1, const ScalarType &limit2, const Type type)
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

    /// \brief 直径。
    inline ScalarType diameter() const
    {
        return max - min;
    }
};

/// \brief 相等。
template <typename ScalarType = double>
inline bool operator ==(const Interval<ScalarType> &i1, const Interval<ScalarType> &i2)
{
    return i1.min == i2.min && i1.max == i2.max && i1.type == i2.type;
}

/// \brief 不等。
template <typename ScalarType = double>
inline bool operator !=(const Interval<ScalarType> &i1, const Interval<ScalarType> &i2)
{
    return !(i1 == i2);
}

/// @}

}//namespace nl1
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_NL1_INR_HXX_
