//===-- C2: Bound Vector ----------------------------------------*- C++ -*-===//
///
/// \defgroup gC2BndVec 平面直角坐标系：固定向量
/// \ingroup gGeom
///
/// \version 2018-08-06
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2_BNDVEC_HXX_
#define RRCXX_C2_BNDVEC_HXX_

#include "rrCXX/numr/gemo/c2/Pt.hxx"
#include "rrCXX/numr/gemo/c2/Vec.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

/// @addtogroup gC2BndVec
/// @{

///
/// \brief 固定向量 \f$ \vec{B} \f$。
///
template<typename ScalarType = double>
struct BoundVector {
    Point<ScalarType>  bpt;  ///< 基点（Base Point）\f$ P_{base} \f$。
    Vector<ScalarType> vec;  ///< 向量（Vector）\f$ \vec{v} \f$。

    /// \brief 固定向量 \f$ \vec{B} = \vec{OO} \f$。
    inline explicit BoundVector() = default;

    /// \brief 固定向量 \f$ \vec{B} = \vec{P_{base}P_{tip}}, P_{tip} = P_{base} + \vec{v} \f$。
    inline explicit BoundVector(const Point<ScalarType> &pBase, const Vector<ScalarType> &v)
    {
        bpt = pBase;
        vec = v;
    }

    /// \brief 固定向量 \f$ \vec{B} = \vec{P_{base}P_{tip}}, \left\{ \begin{align}
    ///                                                        P_{tip} &= P_{base} + \vec{v}        \\
    ///                                                       P_{base} &= (x_{base}, y_{base})      \\
    ///                                                        \vec{v} &= \left<x_{v}, y_{v}\right>
    ///                                                     \end{align} \right.                        \f$。
    inline explicit BoundVector(const ScalarType &xBase, const ScalarType &yBase, const ScalarType &xV, const ScalarType &yV)
        : BoundVector(Point<ScalarType>(xBase, yBase), Vector<ScalarType>(xV, yV))
    {}

    /// \brief 固定向量 \f$ \vec{B} = \vec{P_{base}P_{tip}} \f$。
    inline explicit BoundVector(const Point<ScalarType> &pBase, const Point<ScalarType> &pTip)
        : BoundVector(pBase, Vector<ScalarType>(pTip.x - pBase.x, pTip.y - pBase.y))
    {}
};

/// \brief 相等 \f$ \vec{B_1} = \vec{B_2} \f$。
template <typename ScalarType = double>
inline bool operator ==(const BoundVector<ScalarType> &b1, const BoundVector<ScalarType> &b2)
{
    return b1.bpt == b2.bpt && b1.vec == b2.vec;
}

/// \brief 不等 \f$ \vec{B_1} \ne \vec{B_2} \f$。
template <typename ScalarType = double>
inline bool operator !=(const BoundVector<ScalarType> &b1, const BoundVector<ScalarType> &b2)
{
    return !(b1 == b2);
}

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2_BNDVEC_HXX_
