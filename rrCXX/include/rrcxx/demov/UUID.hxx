//===-- Universally Unique Identifier ---------------------------*- C++ -*-===//
///
/// \file
/// \brief 全局唯一标识符。
///
/// \version 2018-09-12
/// \since 2018-09-10
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_UUID_HXX_
#define RRCXX_UUID_HXX_

#include <cstddef>
#include <array>

namespace rrcxx {
namespace demov {

///
/// \brief 全局唯一标识符。
///
using UUID = std::array<std::byte, 16>;

///
/// \brief 生成全局唯一标识符。
///
UUID GenerateUuid();

}//namespace demov
}//namespace rrcxx

#endif//RRCXX_UUID_HXX_
