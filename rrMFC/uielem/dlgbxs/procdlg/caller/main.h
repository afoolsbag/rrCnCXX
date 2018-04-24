//===-- Main ----------------------------------------------------*- C++ -*-===//
///
/// \file
///
/// \verison 2018-04-24
/// \since 2018-04-23
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "Application.h"

#// Register Messages
extern UINT RM_RRMFC_GUEST_CREATING;
extern UINT RM_RRMFC_GUEST_SIZING;
extern UINT RM_RRMFC_GUEST_DESTROYING;

extern UINT RM_RRMFC_HOST_MOVING;

/// \brief Global Application
extern Application GlobalApplication;
