/**
 * \copyright Unlicense
 */

#define RRWINDOWS_EXPORTS
#include "rrwindows/Debug/StructuredExceptionHandling.h"

#include <ImageHlp.h>
#pragma comment(lib, "DbgHelp.Lib")
#include <PathCch.h>
#pragma comment(lib, "pathcch.Lib")
#include <strsafe.h>

#include "rrwindows/Dlls/DynamicLinkLibrary.h"
#include "rrwindows/Memory/MemoryManagement.h"
#include "rrwindows/MenuRc/VersionInformation.h"

#define countof(array) (sizeof (array) / sizeof *(array))

static BOOL TempDumpPath(WCHAR *CONST buf, CONST size_t cnt)
{
    BOOL rv = FALSE;

    PCWSTR CONST exePath = AllocExecutablePathW();
    PCWSTR CONST exeBaseName = AllocExecutableBaseNameW();

    /* %TEMP% */
    if (0 == GetTempPathW((DWORD)cnt, buf))
        goto exit;

    /* %TEMP%/dump */
    if (FAILED(PathCchAppend(buf, cnt, L"dump")))
        goto exit;

    CreateDirectoryW(buf, NULL);

    /* %TEMP%/dump/ExeBaseName */
    if (FAILED(PathCchAppend(buf, cnt, exeBaseName)))
        goto exit;

    /* %TEMP%/dump/ExeBaseName[_m.n.p.t] */
    WORD major, minor, patch, tweak;
    if (GetFileFileVersionInformation(exePath, &major, &minor, &patch, &tweak)) {
        WCHAR ver[25];
        if (FAILED(StringCchPrintfW(ver, countof(ver), L"_%hu.%hu.%hu.%hu", major, minor, patch, tweak)))
            goto exit;
        if (FAILED(StringCchCatW(buf, cnt, ver)))
            goto exit;
    }

    /* %TEMP%/dump/ExeBaseName[_m.n.p.t]_YYYYMMDD_hhmmss */
    SYSTEMTIME lclTm;
    GetLocalTime(&lclTm);
    WCHAR tm[17];
    if (FAILED(StringCchPrintfW(tm, countof(tm), L"_%04hu%02hu%02hu_%02hu%02hu%02hu", lclTm.wYear, lclTm.wMonth, lclTm.wDay, lclTm.wHour, lclTm.wMinute, lclTm.wSecond)))
        goto exit;
    if (FAILED(StringCchCatW(buf, cnt, tm)))
        goto exit;

    /* %TEMP%/dump/ExeBaseName[_m.n.p.t]_YYYYMMDD_hhmmss.dmp */
    if (FAILED(StringCchCatW(buf, cnt, L".dmp")))
        goto exit;

    rv = TRUE;

exit:
    HeapFreeS((LPVOID)exePath);
    HeapFreeS((LPVOID)exeBaseName);
    return rv;
}

RRWINDOWS_API
LONG
WINAPI
ExceptionCrashHandler(
    _In_ EXCEPTION_POINTERS *CONST ExceptionInfo)
{
    WCHAR dumpPath[MAX_PATH];
    if (!TempDumpPath(dumpPath, countof(dumpPath)))
        if (FAILED(StringCchCopyW(dumpPath, countof(dumpPath), L"crash.dmp")))
            return EXCEPTION_EXECUTE_HANDLER;

    HANDLE CONST dumpFile = CreateFileW(dumpPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (dumpFile == INVALID_HANDLE_VALUE)
        goto exit;

    MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
    dumpInfo.ThreadId = GetCurrentThreadId();
    dumpInfo.ExceptionPointers = ExceptionInfo;
    dumpInfo.ClientPointers = TRUE;

    if (FAILED(MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), dumpFile, MiniDumpNormal, &dumpInfo, NULL, NULL)))
        goto exit_close;

exit_close:
    CloseHandle(dumpFile);
exit:
    return EXCEPTION_EXECUTE_HANDLER;
}
