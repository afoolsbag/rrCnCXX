//===-- Service -------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 服务。
///
/// \version 2019-07-07
/// \since 2019-01-04
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

namespace rrwdt {

constexpr TCHAR service_name[] {_T("rrWdt")};
constexpr TCHAR service_display[] {_T("zhengrr's Watchdog Timer Service")};
constexpr TCHAR service_description[] {_T("zhengrr 的看门狗计时器服务。")};

/// \brief 服务入口回调。
VOID CALLBACK ServiceMain(DWORD dwNumServicesArgs, LPTSTR *lpServiceArgVectors);

/// \brief 服务控制回调。
VOID CALLBACK ServiceCtrlHandler(DWORD dwControl);

}
