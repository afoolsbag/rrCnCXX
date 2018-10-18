/*===-- Library ------------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 苦工（Windows®线程示例）。
 *
 * \sa [`CreateThread`与`_beginthreadex`](http://cnblogs.com/lgxqf/archive/2009/02/10/1387480.html)
 * \sa [`CloseHandle`与`_endthread`](http://blog.csdn.net/guyue35/article/details/45666143)
 *
 * \version 2018-04-19
 * \since 2016-11-08
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <process.h>
#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

DWORD WINAPI ThreadProc(_In_ LPVOID lpParameter)
{
    TCHAR *name = lpParameter;
    INT maxWorkload = 0;
    INT iWorkload = 0;

    _tprintf(TEXT("%s: Ready to work!\n"), name);

    srand((UINT)time(NULL));
    maxWorkload = 5 + rand() % 10;

    for (iWorkload = 1; iWorkload <= maxWorkload; ++iWorkload) {

        srand((UINT)time(NULL));
        switch (rand() % 4) {
        case 0:
            _tprintf_s(TEXT("%s: Be happy to. (%d/%d)\n"), name, iWorkload, maxWorkload);
            break;
        case 1:
            _tprintf_s(TEXT("%s: I can do that. (%d/%d)\n"), name, iWorkload, maxWorkload);
            break;
        case 2:
            _tprintf_s(TEXT("%s: Okie dokie. (%d/%d)\n"), name, iWorkload, maxWorkload);
            break;
        case 3:
            _tprintf_s(TEXT("%s: Work, work. (%d/%d)\n"), name, iWorkload, maxWorkload);
            break;
        default:
            break;
        }

        srand((UINT)time(NULL));
        Sleep((DWORD)1000 + rand() % 5000);
    }
}

/**
 * \sa ["_beginthread, _beginthreadex"](https://docs.microsoft.com/cpp/c-runtime-library/reference/beginthread-beginthreadex). *Microsoft Docs*.
 * \sa ["_endthread, _endthreadex"](https://docs.microsoft.com/cpp/c-runtime-library/reference/endthread-endthreadex). *Microsoft Docs*.
 * \sa ["`WaitForSingleObject` function"](https://msdn.microsoft.com/library/ms687032). *Microsoft® Developer Network*.
 */
INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    const HANDLE hPeon = (HANDLE)_beginthread(ThreadProc, 0, TEXT("Peon"));
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
