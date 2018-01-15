/**
 * \file
 * \brief “掷骰子”（Windows® 动态链接库简单示例）
 * \author zhengrr
 * \date 2018-1-3 – 15
 * \copyright The MIT License
 */

#include <stdio.h>

#include <tchar.h>
#include <windows.h>

#include "DiceLibrary.h"

INT _tmain(INT argc, _TCHAR *argv[], _TCHAR *envp[])
{
	_tprintf(TEXT("Dicing... %d!"), Dice());

	return EXIT_SUCCESS;
}
