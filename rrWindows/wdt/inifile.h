/*===-- Ini File -----------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 服务事件日志。
 *
 * \version 2019-03-29
 * \since 2019-03-28
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

/**
 * \brief “骨头”结构体
 * \code{.ini}
 * [Index]
 * Count=2
 * 
 * [Item1]
 * IsService=0
 * Name=PrintArgs.exe
 * Path=Path\To\PrintArgs.exe
 * Args=arg1 arg2 arg3 arg4
 * StartIn=Path\To
 * 
 * RetryInterval=0
 * 
 * EnableKillPerDay=1
 * KillPerDayHour=23
 * KillPerDayMinute=59
 * KillPerDaySecond=59
 * 
 * [Item2]
 * IsService=1
 * Name=aSvc
 * Path=
 * Args=
 * StartIn=
 * 
 * RetryInterval=0
 * 
 * EnableKillPerDay=0
 * KillPerDayHour=
 * KillPerDayMinute=
 * KillPerDaySecond=
 * 
 * [Item3]
 * ...
 * \endcode
 */
typedef struct Bone {
    /* Config Value (Const) */
    BOOL IsService;

    PTSTR Name;
    PTSTR Path;
    PTSTR Args;
    PTSTR StartIn;

    ULARGE_INTEGER RetryInterval;

    BOOL EnableKillPerDay;
    INT  KillPerDayHour;
    INT  KillPerDayMinute;
    INT  KillPerDaySecond;

    /* Runtime Value */
    BOOL IsValid;
    SYSTEMTIME LastTryAt;
    SYSTEMTIME NextKillAt;
} Bone;

typedef struct Bones {
    INT  Count;
    Bone *Data;
} Bones, *PBones;

VOID WINAPI AllocBones(Bones *pBones);

VOID WINAPI FreeBones(Bones *pBones);
