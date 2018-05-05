//===-- Library -------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 库。
///
/// \version 2018-05-05
/// \since 2018-01-09
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_LIB_HXX_
#define RRCXX_LIB_HXX_

#include <cstdint>
#include <ctime>

#include "api.hxx"

namespace rrcxx {
namespace lib {

///
/// \brief 库版本结构体。
///
struct Version {
  std::uint16_t major;  ///< 库主版本号。
  std::uint16_t minor;  ///< 库次版本号。
  std::uint16_t patch;  ///< 库补丁版本号。
  std::uint16_t tweak;  ///< 库微调版本号。
};

///
/// \brief 获取库版本。
///
RRCXX_API Version
GetVersion();

///
/// \brief 叹。
///
RRCXX_API std::time_t
Sigh();

}//namespace lib
}//namespace rrcxx

#endif//RRCXX_LIB_HXX_
