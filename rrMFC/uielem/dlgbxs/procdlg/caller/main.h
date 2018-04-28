//===-- Main ----------------------------------------------------*- C++ -*-===//
///
/// \file
///
/// \verison 2018-04-28
/// \since 2018-04-23
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "Application.h"

#// Register Messages
extern UINT RM_RRMFC_GUEST_CREATE;
extern UINT RM_RRMFC_GUEST_SIZE;
extern UINT RM_RRMFC_GUEST_SHOWWINDOW;
extern UINT RM_RRMFC_GUEST_DESTROY;

extern UINT RM_RRMFC_HOST_MOVE;

/// \brief Global Application
extern Application GlobalApplication;
