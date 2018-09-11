//===-- Message Digest 5 ----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 信息摘要第五版。
///
/// \version 2018-09-11
/// \since 2018-09-11
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_MD5_HXX_
#define RRCXX_MD5_HXX_

#include <cstdint>
#include <array>

namespace rrcxx {
namespace demov {

///
/// \brief 信息摘要第五版。
///
using MD5 = std::array<std::uint8_t, 16>;

}//namespace demov
}//namespace rrcxx

#endif//RRCXX_MD5_HXX_
