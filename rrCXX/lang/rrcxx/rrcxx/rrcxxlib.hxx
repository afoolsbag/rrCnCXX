//===-- Library -------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 库。
///
/// \version 2018-06-20
/// \since 2018-01-09
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_RRCXXLIB_HXX_
#define RRCXX_RRCXXLIB_HXX_

#include <cstdint>
#include <chrono>

#include "rrcxxapi.hxx"

namespace rrcxx {
namespace lib {

///
/// \brief 库版本类型（结构体）。
///
struct Version {
  std::uint16_t major;  ///< 主版本号。
  std::uint16_t minor;  ///< 次版本号。
  std::uint16_t patch;  ///< 补丁版本号。
  std::uint16_t tweak;  ///< 微调版本号。
};

///
/// \brief 获取库版本。
///
RRCXX_API Version
GetVersion();

///
/// \brief 叹。
///
RRCXX_API std::chrono::system_clock::time_point
Sigh();

}//namespace lib
}//namespace rrcxx

#endif//RRCXX_RRCXXLIB_HXX_
