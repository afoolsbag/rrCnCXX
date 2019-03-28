/**
 * \copyright Unlicense
 */

#include <locale.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include "rrWindows/rrWindows.h"

#include "eventlog.h"
#include "maintain.h"
#include "service.h"

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    UNREFERENCED_PARAMETER(envp);

#ifdef _UNICODE
    setlocale(LC_ALL, "");
#endif

    if (argc == 2) {

        if (CompareStringS(argv[1], _T("install")) == CSTR_EQUAL) {
            Maintain(Install);
            return EXIT_SUCCESS;
        }

        if (CompareStringS(argv[1], _T("remove")) == CSTR_EQUAL) {
            Maintain(Stop);
            Maintain(Remove);
            return EXIT_SUCCESS;
        }

        if (CompareStringS(argv[1], _T("start")) == CSTR_EQUAL) {
            Maintain(Start);
            return EXIT_SUCCESS;
        }

        if (CompareStringS(argv[1], _T("stop")) == CSTR_EQUAL) {
            Maintain(Stop);
            return EXIT_SUCCESS;
        }

        if (CompareStringS(argv[1], _T("pause")) == CSTR_EQUAL) {
            Maintain(Pause);
            return EXIT_SUCCESS;
        }

        if (CompareStringS(argv[1], _T("continue")) == CSTR_EQUAL) {
            Maintain(Continue);
            return EXIT_SUCCESS;
        }

        if (CompareStringS(argv[1], _T("restart")) == CSTR_EQUAL) {
            Maintain(Stop);
            Maintain(Start);
            return EXIT_SUCCESS;
        }

        _fputts(_T("Unexpected parameter.\n"), stderr);
        return EXIT_FAILURE;
    }

    _putts(_T("使用方法："));
    _tprintf(_T("%s install \t安装服务。\n"), argv[0]);
    _tprintf(_T("%s remove  \t停止并卸载服务。\n"), argv[0]);
    _tprintf(_T("%s start   \t启动服务。\n"), argv[0]);
    _tprintf(_T("%s stop    \t停止服务。\n"), argv[0]);
    _tprintf(_T("%s pause   \t暂停服务。\n"), argv[0]);
    _tprintf(_T("%s continue\t继续服务。\n"), argv[0]);
    _tprintf(_T("%s restart \t重启服务。\n"), argv[0]);

#pragma warning(push)
#pragma warning(disable: 4204)
    SERVICE_TABLE_ENTRY table[] =
    {
        {(PTSTR)ServiceName, ServiceEntry},
        {       NULL,        NULL}
    };
#pragma warning(pop)

    if (!StartServiceCtrlDispatcher(table)) {
        EventLogFunctionFailed(_T("StartServiceCtrlDispatcher"), GetLastError());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
