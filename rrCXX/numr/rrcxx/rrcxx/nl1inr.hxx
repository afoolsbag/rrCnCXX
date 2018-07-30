//===-- Number Line 1-Dimensional: Interval ---------------------*- C++ -*-===//
///
/// \defgroup gNl1Inr 数轴：区间。
/// \ingroup gGeom
///
/// \version 2018-07-27
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_NL1INR_HXX_
#define RRCXX_NL1INR_HXX_

#include "nl1pt.hxx"

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
    ScalarType min;       ///< 最小限制 \f$ min \f$。
    ScalarType max;       ///< 最大限制 \f$ max \f$。
    enum class Type {
        OPEN,        ///< 开区间 \f$ (min, max) \f$。
        OPEN_CLOSE,  ///< 左开右闭区间 \f$ (min, max] \f$。
        CLOSE_OPEN,  ///< 左闭右开区间 \f$ [min, max) \f$。
        CLOSE        ///< 闭区间 \f$ [min, max] \f$。
    } type = Type::OPEN;  ///< 类型。

    ///
    /// \brief 空集 \f$ \emptyset \f$。
    ///
    inline explicit Interval() = default;

    ///
    /// \brief 有序区间。
    ///
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

    ///
    /// \brief 直径。
    ///
    inline ScalarType diameter() const
    {
        return max - min;
    }
};

/// @}

}//namespace nl1
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_NL1INR_HXX_
