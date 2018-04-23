/// \copyright The MIT License

#include "stdafx.h"
#include "main.h"

#include "Application.h"

UINT RM_RRMFC_PROCESS_DIALOG_CALLEE_CREATING = RegisterWindowMessage(
    TEXT("RM_RRMFC_PROCESS_DIALOG_CALLEE_CREATING "));
UINT RM_RRMFC_PROCESS_DIALOG_CALLEE_DESTROYING = RegisterWindowMessage(
    TEXT("RM_RRMFC_PROCESS_DIALOG_CALLEE_DESTROYING "));

Application GlobalApplication;
