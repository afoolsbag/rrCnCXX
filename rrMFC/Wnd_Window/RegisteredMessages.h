//===-- Registered Messages -------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 注册消息。
///
/// \verison 2018-10-24
/// \since 2018-10-24
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include "stdafx.h"

namespace rrMFC {
namespace RegisteredMessages {
/// \brief 定制注册消息。
const unsigned Custom = RegisterWindowMessage(_T("rrMFC::RegisteredMessages::Custom"));
}//namespace ResigteredMessages
}//namespace rrMFC
