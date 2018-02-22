/**
 * \file
 * \brief 单实例应用
 * \author zhengrr
 * \date 2018-1-20
 * \copyright The MIT License
 */

#include <stdio.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <Windows.h>

/**
 * \sa ["OpenMutex function"](https://msdn.microsoft.com/library/ms684315). *Microsoft® Developer Network*.
 * \sa ["CreateMutex function"](https://msdn.microsoft.com/library/ms682411). *Microsoft® Developer Network*.
 * \sa ["ReleaseMutex function"](https://msdn.microsoft.com/library/ms685066). *Microsoft® Developer Network*.
 */
INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
	HANDLE mutexSIA = OpenMutex(MUTEX_ALL_ACCESS, 0, TEXT("rrWindowsSIA"));
	if (!mutexSIA)
		mutexSIA = CreateMutex(0, 0, TEXT("rrWindowsSIA"));
	else
		return EXIT_SUCCESS;

	_putts(TEXT("Single Instance Application."));
	_tsystem(TEXT("pause"));

	ReleaseMutex(mutexSIA);
	return EXIT_SUCCESS;
}
