/**
 * \file
 * \brief “掷骰子”（Windows®动态链接库简单示例）。
 * \author zhengrr
 * \date 2018-1-3 – 22
 * \copyright The MIT License
 */

#include <stdio.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <Windows.h>

#include "lib.h"

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
	_tprintf(_T("Dicing... %d!\n"), Dice());
    _tsystem(_T("pause"));
	return EXIT_SUCCESS;
}
