//===-- Main ----------------------------------------------------*- C++ -*-===//
///
/// \file
///
/// \verison 2018-04-10
/// \since 2018-04-10
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "Application.h"

#// Register Messages
extern UINT RM_CUSTOM_REGISTER_MESSAGE;

#// Application Messages
#define AM_CUSTOM_APPLICATION_MESSAGE (WM_APP + 1)

/// \brief Global Application
extern Application GlobalApplication;
