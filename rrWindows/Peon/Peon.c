/** \file
 *  \brief 苦工（Ｗｉｎｄｏｗｓ线程简单示例）
 *  \author zhengrr
 *  \date 2016-11-8 – 2018-1-3
 *  \copyright The MIT License*/

#include <windows.h>
#include <tchar.h>

#include <stdio.h>
#include <time.h>

#include <process.h>

static VOID ThreadWork(PVOID pVoid);

/** \sa [`CreateThread`与`_beginthreadex`本质区别](http://blog.csdn.net/morewindows/article/details/7421759)
 *  \sa ["`_beginthread`"](https://msdn.microsoft.com/kdzttdcb). *MSDN*.
 *  \sa ["`WaitForSingleObject` function"](http://msdn.microsoft.com/ms687032). *MSDN*. */
INT _tmain(INT argc, _TCHAR *argv[], _TCHAR *envp[])
{
        HANDLE hPeon;

        hPeon = (HANDLE) _beginthread(ThreadWork, 0, _T("Peon"));
        if (hPeon) {
                _tprintf(_T("Main: A peon has been produced.\n"));
        } else {
                _ftprintf(stderr, _T("Thread creating failed.\n"));
                exit(EXIT_FAILURE);
        }

        WaitForSingleObject(hPeon, INFINITE);
        _tprintf(_T("Main: The Peon work done.\n"));

        exit(EXIT_SUCCESS);
}

/** \sa ["`Sleep` function"](http://msdn.microsoft.com/ms686298). *MSDN*. */
static VOID ThreadWork(PVOID pVoid)
{
        PTSTR szName = (PTSTR) pVoid;
        _tprintf(_T("%s: Ready to work!\n"), szName);

        srand((UINT) time(NULL));
        const INT maxWorkload = 5 + rand() % 10;

        for (int iWorkload = 1; iWorkload <= maxWorkload; ++iWorkload) {

                srand((UINT) time(NULL));
                switch (rand() % 4) {
                case 0:
                        _tprintf(_T("%s: Be happy to (%d/%d).\n"),
                                 szName, iWorkload, maxWorkload);
                        break;
                case 1:
                        _tprintf(_T("%s: I can do that (%d/%d).\n"),
                                 szName, iWorkload, maxWorkload);
                        break;
                case 2:
                        _tprintf(_T("%s: Okie dokie (%d/%d).\n"),
                                 szName, iWorkload, maxWorkload);
                        break;
                case 3:
                        _tprintf(_T("%s: Work, work (%d/%d).\n"),
                                 szName, iWorkload, maxWorkload);
                        break;
                default:
                        break;
                }

                srand((UINT) time(NULL));
                Sleep((DWORD) 1000 + rand() % 5000);
        }
}
