/**
 * \file
 * \brief Windows® 错误处理
 * \author zhengrr
 * \date 2018-1-15
 * \copyright The MIT License
 */

#ifndef RRWINDOWS_ERROR_H_
#define RRWINDOWS_ERROR_H_

#include <tchar.h>
#include <windows.h>

/**
 * \details "<tips>: system error <code>, <message>"
 */
VOID ShowLastError(PCTSTR tips);

#endif/* RRWINDOWS_ERROR_H_*/
