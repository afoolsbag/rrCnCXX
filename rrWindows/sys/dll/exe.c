/*===-- Executable ---------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief “掷骰子”库。
 *
 * \sa [DLL编写教程](http://blogjava.net/wxb_nudt/archive/2007/09/11/144371.html)
 *
 * \version 2018-04-26
 * \since 2017-01-03
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "lib.h"

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
	_tprintf(_T("Dicing... %d!\n"), Dice());
    _tsystem(_T("pause"));
	return EXIT_SUCCESS;
}
