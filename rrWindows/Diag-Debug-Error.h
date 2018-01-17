/**
 * \file
 * \brief 错误处理
 * \sa ["Error Handling"](https://msdn.microsoft.com/library/ms679320). *Microsoft® Developer Network*.
 * \author zhengrr
 * \date 2018-1-15 – 17
 * \copyright The MIT License
 */

#ifndef RRWINDOWS_ERROR_H_
#define RRWINDOWS_ERROR_H_

#include <tchar.h>
#include <Windows.h>

/**
 * \details "<tips>: system error <code>, <message>"
 */
VOID ShowLastError(PCTSTR tips);

#endif/* RRWINDOWS_ERROR_H_*/
