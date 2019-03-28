/*===-- Maintain -----------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 服务维护。
 *
 * \version 2019-03-27
 * \since 2019-01-04
 * \authors zhengrr
 * \copyright Unlicense
 *
*//*===--------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

/**
 * 维护类型。
 */
typedef enum MaintainType {
    Install,  /**< 安装 */
    Remove,   /**< 卸载 */
    Start,    /**< 启动 */
    Stop,     /**< 停止 */
    Pause,    /**< 暂停 */
    Continue, /**< 恢复 */
} MaintainType;

/**
 * \brief 维护。
 */
VOID WINAPI Maintain(MaintainType type);
