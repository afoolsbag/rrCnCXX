/// \copyright The MIT License

#include "stdafx.h"
#include "main.h"

#include "Application.h"

UINT RM_RRMFC_GUEST_CREATE = RegisterWindowMessage(TEXT("RM_RRMFC_GUEST_CREATE"));
UINT RM_RRMFC_GUEST_SIZE = RegisterWindowMessage(TEXT("RM_RRMFC_GUEST_SIZE"));
UINT RM_RRMFC_GUEST_DESTROY = RegisterWindowMessage(TEXT("RM_RRMFC_GUEST_DESTROY"));

UINT RM_RRMFC_HOST_MOVE = RegisterWindowMessage(TEXT("RM_RRMFC_HOST_MOVE"));

Application GlobalApplication;
