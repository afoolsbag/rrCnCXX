/**
 * \file
 * \brief 苦工（Windows®线程简单示例）
 * \author zhengrr
 * \date 2016-11-8 – 2018-1-17
 * \copyright The MIT License
 */

#include <stdio.h>
#include <time.h>

#include <process.h>

#include <tchar.h>
#include <Windows.h>

static VOID ThreadWork(PVOID pVoid);

/**
 * \sa [`CreateThread`与`_beginthreadex`](http://cnblogs.com/lgxqf/archive/2009/02/10/1387480.html)
 * \sa [`CloseHandle`与`_endthread`](http://blog.csdn.net/guyue35/article/details/45666143)
 * \sa ["`_beginthread`"](https://msdn.microsoft.com/kdzttdcb). *Microsoft® Developer Network*.
 * \sa ["`WaitForSingleObject` function"](http://msdn.microsoft.com/ms687032). *Microsoft® Developer Network*.
 */
INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
	HANDLE hPeon;

	hPeon = (HANDLE) _beginthread(ThreadWork, 0, _T("Peon"));
	if (hPeon) {
		_tprintf_s(TEXT("Main: A peon has been produced.\n"));
	} else {
		_ftprintf_s(stderr, TEXT("Thread creating failed.\n"));
		exit(EXIT_FAILURE);
	}

	WaitForSingleObject(hPeon, INFINITE);
	_tprintf_s(TEXT("Main: The Peon work done.\n"));

	exit(EXIT_SUCCESS);
}

/** \sa ["`Sleep` function"](http://msdn.microsoft.com/ms686298). *Microsoft® Developer Network*. */
static VOID ThreadWork(PVOID pVoid)
{
	PTSTR name = (PTSTR) pVoid;
	INT maxWorkload = 0;
	INT iWorkload = 0;

	_tprintf(TEXT("%s: Ready to work!\n"), name);

	srand((UINT) time(NULL));
	maxWorkload = 5 + rand() % 10;

	for (iWorkload = 1; iWorkload <= maxWorkload; ++iWorkload) {

		srand((UINT) time(NULL));
		switch (rand() % 4) {
		case 0:
			_tprintf_s(TEXT("%s: Be happy to. (%d/%d)\n"),
				   name, iWorkload, maxWorkload);
			break;
		case 1:
			_tprintf_s(TEXT("%s: I can do that. (%d/%d)\n"),
				   name, iWorkload, maxWorkload);
			break;
		case 2:
			_tprintf_s(TEXT("%s: Okie dokie. (%d/%d)\n"),
				   name, iWorkload, maxWorkload);
			break;
		case 3:
			_tprintf_s(TEXT("%s: Work, work. (%d/%d)\n"),
				   name, iWorkload, maxWorkload);
			break;
		default:
			break;
		}

		srand((UINT) time(NULL));
		Sleep((DWORD) 1000 + rand() % 5000);
	}
}
