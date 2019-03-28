/*===-- Ini File -----------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 服务事件日志。
 *
 * \version 2019-03-28
 * \since 2019-03-28
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

/**
 * [Index]
 * Count=1
 * 
 * [Item1]
 * ExeName=PrintArgs.exe
 * ExePath=Path\To\PrintArgs.exe
 * ExeArgs=arg1 arg2 arg3 arg4
 * ExeStartIn=Path\To
 * ExeShow=0
 * 
 * RetryInterval=0
 * 
 * EnableKillAtTime=1
 * KillAtHour=23
 * KillAtMinute=59
 * KillAtSecond=59
 *
 * [Item2]
 * ...
 */
typedef struct Bone {
    /* Config Value (Const) */
    PTSTR ExeName;
    PTSTR ExePath;
    PTSTR ExeArgs;
    PTSTR ExeStartIn;
    BOOL  ExeShow;

    ULARGE_INTEGER RetryInterval;

    BOOL EnableKillAtTime;
    INT  KillAtHour;
    INT  KillAtMinute;
    INT  KillAtSecond;

    /* Runtime Value */
    SYSTEMTIME LastTryAt;
    SYSTEMTIME NextKillAt;
} Bone;

typedef struct Bones {
    INT  Count;
    Bone *Data;
} Bones, *PBones;

PBones WINAPI AllocBones(VOID);

VOID WINAPI FreeBones(Bones *pBones);
