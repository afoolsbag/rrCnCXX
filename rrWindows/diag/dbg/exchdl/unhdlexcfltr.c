/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "unhdlexcfltr.h"

#include <ImageHlp.h>
#pragma comment(lib, "DbgHelp.Lib")
#include <PathCch.h>
#pragma comment(lib, "pathcch.Lib")
#include <strsafe.h>

#include "rrWindows/def.h"
#include "rrWindows/svc/dll/exepath.h"
#include "rrWindows/dtpui/menurc/ver/verinfo.h"

RRWINDOWS_API
LONG
WINAPI
ExceptionCrashHandler(
    _In_ EXCEPTION_POINTERS *CONST ExceptionInfo)
{
    OutputDebugStringW(L"--------------------------------------------------------------------------------");
    OutputDebugStringW(L" ");
    OutputDebugStringW(ExecutableNameW());
    OutputDebugStringW(L"The program has crashed by unhandled exception.");
    OutputDebugStringW(L" ");
    OutputDebugStringW(L"Try generating a dump file...");

    WCHAR dumpPath[MAX_PATH] = L"\0";

    BOOL tempDump = FALSE;
    do {
        /* %TEMP% */
        if (0 == GetTempPathW(countof(dumpPath), dumpPath))
            break;

        /* %TEMP%/dump */
        if (FAILED(PathCchAppend(dumpPath, countof(dumpPath), L"dump")))
            break;
        CreateDirectoryW(dumpPath, NULL);

        /* %TEMP%/dump/ExeBaseName */
        if (FAILED(PathCchAppend(dumpPath, countof(dumpPath), ExecutableBaseNameW())))
            break;

        /* %TEMP%/dump/ExeBaseName[_m.n.p.t] */
        WORD major, minor, patch, tweak;
        if (GetFileFileVersionInformation(ExecutablePath(), &major, &minor, &patch, &tweak)) {
            WCHAR ver[25];
            if (FAILED(StringCchPrintfW(ver, countof(ver), L"_%hu.%hu.%hu.%hu", major, minor, patch, tweak)))
                break;
            if (FAILED(StringCchCatW(dumpPath, countof(dumpPath), ver)))
                break;
        }

        /* %TEMP%/dump/ExeBaseName[_m.n.p.t]_YYYYMMDD_hhmmss */
        SYSTEMTIME lclTm;
        GetLocalTime(&lclTm);
        WCHAR tm[17];
        if (FAILED(StringCchPrintfW(tm, countof(tm), L"_%04hu%02hu%02hu_%02hu%02hu%02hu", lclTm.wYear, lclTm.wMonth, lclTm.wDay, lclTm.wHour, lclTm.wMinute, lclTm.wSecond)))
            break;
        if (FAILED(StringCchCatW(dumpPath, countof(dumpPath), tm)))
            break;

        /* %TEMP%/dump/ExeBaseName[_m.n.p.t]_YYYYMMDD_hhmmss.dmp */
        if (FAILED(StringCchCatW(dumpPath, countof(dumpPath), L".dmp")))
            break;

        tempDump = TRUE;
    } while (FALSE);
    if (tempDump) {
        OutputDebugStringW(L"   [o] find the first dump place");
    } else {
        OutputDebugStringW(L"   [x] find the first dump place");
        if (FAILED(StringCchCopyW(dumpPath, countof(dumpPath), L"crash.dmp"))) {
            OutputDebugStringW(L"   [x] find the second dump place failed");
            OutputDebugStringW(L"Generate the dump file failed.");
            return EXCEPTION_EXECUTE_HANDLER;
        }
        OutputDebugStringW(L"   [o] find the second dump place");
    }

    HANDLE CONST dumpFile = CreateFileW(dumpPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == dumpFile) {
        OutputDebugStringW(L"   [x] create the dump file");
        OutputDebugStringW(L"Generate the dump file failed.");
        OutputDebugStringW(L" ");
        OutputDebugStringW(L"--------------------------------------------------------------------------------");
        return EXCEPTION_EXECUTE_HANDLER;
    }
    OutputDebugStringW(L"   [o] create the dump file");

    MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
    dumpInfo.ThreadId = GetCurrentThreadId();
    dumpInfo.ExceptionPointers = ExceptionInfo;
    dumpInfo.ClientPointers = TRUE;

    if (FAILED(MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), dumpFile, MiniDumpNormal, &dumpInfo, NULL, NULL))) {
        CloseHandle(dumpFile);
        OutputDebugStringW(L"   [x] write MiniDump to the dump file");
        OutputDebugStringW(L"Generate the dump file failed.");
        OutputDebugStringW(L" ");
        OutputDebugStringW(L"--------------------------------------------------------------------------------");
        return EXCEPTION_EXECUTE_HANDLER;
    }
    CloseHandle(dumpFile);
    OutputDebugStringW(L"   [o] write MiniDump to the dump file");
    OutputDebugStringW(L"Generate the dump file succeeded at:");
    OutputDebugStringW(dumpPath);
    OutputDebugStringW(L" ");
    OutputDebugStringW(L"--------------------------------------------------------------------------------");

    return EXCEPTION_EXECUTE_HANDLER;
}
