//===-- Remote Procedure Call -----------------------------------*- C++ -*-===//
///
/// \file
/// \brief 远程过程调用。
///
/// \sa <https://docs.microsoft.com/windows/win32/rpc/rpc-start-page>
///
/// \version 2019-07-08
/// \since 2018-02-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <cstddef>
#include <string>

#include "rrwindows/api.hxx"

namespace rrwindows {

constexpr std::size_t max_uuid_len {36 + 1};

/// \brief 生成通用唯一标识符字符串。
RRWINDOWS_API std::string RRWINDOWS_CALL generate_uuid_string();
RRWINDOWS_API std::wstring RRWINDOWS_CALL generate_uuid_wstring();

}
