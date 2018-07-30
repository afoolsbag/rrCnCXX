//===-- Cartesian Coordinate System 2-Dimensional: Bound Vector -*- C++ -*-===//
///
/// \defgroup gC2BndVec 平面直角坐标系：固定向量。
/// \ingroup gGeom
///
/// \version 2018-07-30
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2BNDVEC_HXX_
#define RRCXX_C2BNDVEC_HXX_

#include "c2pt.hxx"
#include "c2vec.hxx"

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

    ///
    /// \brief 固定向量 \f$ \vec{B} = \vec{OO} \f$。
    ///
    inline explicit BoundVector() = default;

    ///
    /// \brief 固定向量 \f$ \vec{B} = \vec{P_{base}P_{tip}}, P_{tip} = P_{base} + \vec{v} \f$。
    ///
    inline explicit BoundVector(const Point<ScalarType> &pBase, const FreeVector<ScalarType> &v)
    {
        bpt = pBase;
        vec = v;
    }

    ///
    /// \brief 固定向量 \f$ \vec{B} = \vec{P_{base}P_{tip}}, \left\{ \begin{align}
    ///                                                        P_{tip} &= P_{base} + \vec{v}        \\
    ///                                                       P_{base} &= (x_{base}, y_{base})      \\
    ///                                                        \vec{v} &= \left<x_{v}, y_{v}\right>
    ///                                                     \end{align} \right.                        \f$。
    ///
    inline explicit BoundVector(const ScalarType &xBase, const ScalarType &yBase, const ScalarType &xV, const ScalarType &yV)
    {
        BoundVector(Point<ScalarType>(xBase, yBase), FreeVector<ScalarType>(xV, yV));
    }

    ///
    /// \brief 固定向量 \f$ \vec{B} = \vec{P_{base}P_{tip}} \f$。
    ///
    inline explicit BoundVector(const Point<ScalarType> &pBase, const Point<ScalarType> &pTip)
    {
        BoundVector(pBase, FreeVector<ScalarType>(pTip.x - pBase.x, pTip.y - pBase.y));
    }
};

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2BNDVEC_HXX_
