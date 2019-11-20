//===-- High Performance Computing ------------------------------*- C++ -*-===//
///
/// \file
/// \brief 高性能计算
/// \sa [Introduction to Intel® Advanced Vector Extensions](https://software.intel.com/articles/introduction-to-intel-advanced-vector-extensions/)
/// \sa [Intel® Intrinsics Guide](https://software.intel.com/sites/landingpage/IntrinsicsGuide/)
///
/// \version 2019-11-19
/// \since 2019-10-15
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRASSEMBLY_RRHPC_HXX_
#define RRASSEMBLY_RRHPC_HXX_

#include <cstddef>
#include <array>

namespace rrassembly {

namespace internal {
}

/// \brief 欧几里得距离（euclidean distance）
///
/// \param pt1     点（point）
/// \param pt2     点（point）
/// \tparam pt_dim 点维度（point dimension）
/// \returns 略
template<std::size_t pt_dim>
float euclidean_distance(const std::array<float, pt_dim> &pt1, const std::array<float, pt_dim> &pt2);

/// \brief 长度（length）
///
/// \param v        向量（vector）
/// \tparam vec_dim 向量维度（vector dimension）
/// \returns 略
template<std::size_t vec_dim>
float length(const std::array<float, vec_dim> &v);

/// \brief 点积（dot product）、数量积（scalar product）
///
/// \param v1       向量（feature vector）
/// \param v2       向量（feature vector）
/// \tparam vec_dim 向量维度（vector dimension）
/// \returns 略
template<std::size_t vec_dim>
float dot_product(const std::array<float, vec_dim> &v1, const std::array<float, vec_dim> &v2);

/// \brief 余弦相似性（cosine similarity）
/// \details 即两个向量的夹角的余弦值，取值在 [-1, 1]；同向时为 1、反向时为 -1，垂直时为 0。
///          由欧几里得点积公式
///          \f[
///              \vec{a} \cdot \vec{b} = \left\|{\vec{a}}\right\| \left\|{\vec{b}}\right\| \cos\theta
///          \f]
///          可导出两向量余弦值的一种求值方法。
///
/// \param v1       向量（feature vector）
/// \param v2       向量（feature vector）
/// \tparam vec_dim 向量维度（vector dimension）
/// \returns 略
template<std::size_t vec_dim>
float cosine_similarity(const std::array<float, vec_dim> &v1, const std::array<float, vec_dim> &v2);

}

#include "rrhpc.inl"

#endif
