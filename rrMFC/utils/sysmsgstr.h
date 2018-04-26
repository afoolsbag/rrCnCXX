/*===-- System Message String ----------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 系统消息字串。
 *
 * \version 2018-04-26
 * \since 2018-04-13
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "api.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief 系统消息号转（文本）字串。 */
RRMFC_UTILITIES_API LPCTSTR WINAPI
SystemMessageString(
    _In_ CONST UINT messageNumber);
/** \brief 系统消息号转（文本）字串（缩写）。 */
#define SysMsgStr SystemMessageString

#ifdef __cplusplus
}
#endif
