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

#include "rrwindows/def.h"
#include "rrwindows/exepath.h"

RRWINDOWS_API
LONG
WINAPI
ExceptionCrashHandler(
    _In_ EXCEPTION_POINTERS *CONST ExceptionInfo)
{
    OutputDebugStringW(L"--------------------------------------------------------------------------------");
    OutputDebugStringW(ExecutableNameW());
    OutputDebugStringW(L"The program has crashed by unhandled exception.");
    OutputDebugStringW(L" ");
    OutputDebugStringW(L"Try generating a dump file...");

    WCHAR dumpPath[MAX_PATH];

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
        WCHAR ext[21];
        if (FAILED(StringCchPrintfW(ext, countof(ext), L"_%04hu%02hu%02hu_%02hu%02hu%02hu.dmp", lclTm.wYear, lclTm.wMonth, lclTm.wDay, lclTm.wHour, lclTm.wMinute, lclTm.wSecond)))
            break;
        if (FAILED(StringCchCatW(dumpPath, countof(dumpPath), ext)))
            break;

        tempDump = TRUE;
    } while (FALSE);
    if (tempDump) {
        OutputDebugStringW(L"   o find the first dump place");
    } else {
        OutputDebugStringW(L"   x find the first dump place");
        if (FAILED(StringCchCopyW(dumpPath, countof(dumpPath), L"crash.dmp"))) {
            OutputDebugStringW(L"   x find the second dump place failed");
            OutputDebugStringW(L"Generate the dump file failed.");
            OutputDebugStringW(L"--------------------------------------------------------------------------------");
            return EXCEPTION_EXECUTE_HANDLER;
        }
        OutputDebugStringW(L"   o find the second dump place");
    }

    HANDLE CONST dumpFile = CreateFileW(dumpPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == dumpPath) {
        OutputDebugStringW(L"   x create the dump file");
        OutputDebugStringW(L"Generate the dump file failed.");
        OutputDebugStringW(L"--------------------------------------------------------------------------------");
        return EXCEPTION_EXECUTE_HANDLER;
    }
    OutputDebugStringW(L"   o create the dump file");

    MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
    dumpInfo.ThreadId = GetCurrentThreadId();
    dumpInfo.ExceptionPointers = ExceptionInfo;
    dumpInfo.ClientPointers = TRUE;

    if (FAILED(MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), dumpFile, MiniDumpNormal, &dumpInfo, NULL, NULL))) {
        CloseHandle(dumpFile);
        OutputDebugStringW(L"   x write MiniDump to the dump file");
        OutputDebugStringW(L"Generate the dump file failed.");
        OutputDebugStringW(L"--------------------------------------------------------------------------------");
    }
    CloseHandle(dumpFile);
    OutputDebugStringW(L"   o write MiniDump to the dump file");
    OutputDebugStringW(L"Generate the dump file succeeded.");
    OutputDebugStringW(L"--------------------------------------------------------------------------------");

    WCHAR txt[512];
    if (SUCCEEDED(StringCchPrintfW(txt, countof(txt), L"%s has crashed.\nThe dump file is generated at %s.", ExecutableNameW(), dumpPath)))
        MessageBoxW(NULL, txt, L"Whoops...", MB_ICONERROR | MB_OK);

    return EXCEPTION_EXECUTE_HANDLER;
}
