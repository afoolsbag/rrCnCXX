//===-- Universally Unique Identifier ---------------------------*- C++ -*-===//
///
/// \file
/// \brief 通用唯一标识符。
///
/// \version 2018-09-21
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

namespace rrcxx::prototypes::igcf2 {

/// \brief 通用唯一标识符。
using uuid = std::array<std::byte, 16>;

/// \brief 生成通用唯一标识符。
uuid generate_uuid();

}//namespace rrcxx::prototypes::igcf2

#endif//RRCXX_UUID_HXX_
