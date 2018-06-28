/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "unhdlexcfltr.h"

#include <ImageHlp.h>
#pragma comment(lib, "DbgHelp.Lib")
#include <KnownFolders.h>
#include <PathCch.h>
#pragma comment(lib, "pathcch.Lib")
#include <strsafe.h>
#include <ShlObj.h>
#pragma comment(lib, "shell32.lib")

#include "rrwindows/exepath.h"
#include "rrwindows/dbgprt.h"

RRWINDOWS_API
LONG
WINAPI
ExceptionCrashHandler(
    _In_ EXCEPTION_POINTERS *CONST ExceptionInfo)
{
    DpWarn(_T("--------------------------------------------------------------------------------"));
    DpWarn(_T("Crash by unhandled exception."));
    DpInfo(_T(""));
    DpInfo(_T("Try to generate a dump file..."));

    WCHAR dumpPath[MAX_PATH];

    DpInfo(_T("   Try to find the first dump place..."));
    BOOL tempDump = FALSE;
    do {
        if (0 == GetTempPathW(countof(dumpPath), dumpPath))
            break;

        if (FAILED(PathCchAppend(dumpPath, countof(dumpPath), L"dump")))
            break;
        CreateDirectoryW(dumpPath, NULL);

        if (FAILED(PathCchAppend(dumpPath, countof(dumpPath), ExecutableBaseNameW())))
            break;

        SYSTEMTIME lclTm;
        GetLocalTime(&lclTm);
        WCHAR ext[29];
        if (FAILED(StringCchPrintfW(ext, countof(ext), L".%04hu%02hu%02hu%02hu%02hu%02hu.unhdlexc.dmp", lclTm.wYear, lclTm.wMonth, lclTm.wDay, lclTm.wHour, lclTm.wMinute, lclTm.wSecond)))
            break;
        if (FAILED(StringCchCatW(dumpPath, countof(dumpPath), ext)))
            break;

        tempDump = TRUE;
    } while (FALSE);
    if (tempDump) {
        DpInfo(_T("   Succeeded."));
    } else {
        DpWarn(_T("   Failed, try to find the second dump place..."));
        if (FAILED(StringCchCopyW(dumpPath, countof(dumpPath), L"unhdlexc.dmp"))) {
            DpWarn(_T("   Failed."));
            DpWarn(_T("Generate the dump file failed."));
            DpWarn(_T("--------------------------------------------------------------------------------"));
            return EXCEPTION_EXECUTE_HANDLER;
        }
        DpInfo(_T("   Succeeded."));
    }

    DpInfo(_T("   Try to create the dump file..."));
    HANDLE CONST dumpFile = CreateFileW(dumpPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == dumpPath) {
        DpWarn(_T("   Failed."));
        DpWarn(_T("Generate the dump file failed."));
        DpWarn(_T("--------------------------------------------------------------------------------"));
        return EXCEPTION_EXECUTE_HANDLER;
    }
    DpInfo(_T("   Succeeded."));

    MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
    dumpInfo.ThreadId = GetCurrentThreadId();
    dumpInfo.ExceptionPointers = ExceptionInfo;
    dumpInfo.ClientPointers = TRUE;

    DpInfo(_T("   Try to write the dump file..."));
    if (FAILED(MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), dumpFile, MiniDumpNormal, &dumpInfo, NULL, NULL))) {
        CloseHandle(dumpFile);
        DpWarn(_T("   Failed."));
        DpWarn(_T("Generate the dump file failed."));
        DpWarn(_T("--------------------------------------------------------------------------------"));
    }
    CloseHandle(dumpFile);
    DpInfo(_T("   Succeeded."));
    DpInfo(_T("Generate the dump file succeeded."));
    DpInfo(_T("--------------------------------------------------------------------------------"));
    return EXCEPTION_EXECUTE_HANDLER;
}
