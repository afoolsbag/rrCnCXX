/// \copyright The MIT License

#include "stdafx.h"
#include "main.h"

#include "Application.h"

UINT RM_RRMFC_GUEST_CREATING = RegisterWindowMessage(
    TEXT("RM_RRMFC_GUEST_CREATING"));
UINT RM_RRMFC_GUEST_SIZING = RegisterWindowMessage(
    TEXT("RM_RRMFC_GUEST_SIZING"));
UINT RM_RRMFC_GUEST_DESTROYING = RegisterWindowMessage(
    TEXT("RM_RRMFC_GUEST_DESTROYING"));

UINT RM_RRMFC_HOST_MOVING = RegisterWindowMessage(
    TEXT("RM_RRMFC_HOST_MOVING"));

Application GlobalApplication;
