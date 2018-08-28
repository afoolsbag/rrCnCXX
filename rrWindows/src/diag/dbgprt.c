/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "rrwindows/diag/dbgprt.h"

#include <strsafe.h>

#include "rrwindows/svc/memsim.h"
#include "rrwindows/def.h"

static DebugPrintLevel DpLevel = DEBUG_ONLY(DEBUG_PRINT_DEBUG) RELEASE_ONLY(DEBUG_PRINT_INFO);

RRWINDOWS_API
VOID
WINAPI
SetDebugPrintLevel(
    _In_ CONST DebugPrintLevel level)
{
    DpLevel = level;
}

RRWINDOWS_API
DebugPrintLevel
WINAPI
GetDebugPrintLevel(VOID)
{
    return DpLevel;
}

#ifdef _DEBUG
# define TEMPLATEA "%s(%u): %s: %s t%lup%lu.\n", file, line, lvlWord, msgBuf, GetCurrentThreadId(), GetCurrentProcessId()
# define TEMPLATEW L"%s(%u): %s: %s t%lup%lu.\n", file, line, lvlWord, msgBuf, GetCurrentThreadId(), GetCurrentProcessId()
#else
# define TEMPLATEA "[%lu] [%s]: %s\n", GetCurrentThreadId(), lvlWord, msgBuf
# define TEMPLATEW L"[%lu] [%s]: %s\n", GetCurrentThreadId(), lvlWord, msgBuf
#endif

RRWINDOWS_API
VOID
WINAPI
VDebugPrintA(
    _In_z_                        LPCSTR CONST           file,
    _In_                           CONST UINT            line,
    _In_                           CONST DebugPrintLevel level,
    _In_z_ _Printf_format_string_ LPCSTR CONST           format,
    _In_                         va_list CONST           va)
{
    if (DpLevel < level)
        return;

    CHAR lvlWord[12];
    switch (level) {
    case DEBUG_PRINT_FATAL:
        if (FAILED(StringCchCopyA(lvlWord, countof(lvlWord), "fatal error"))) {
            OutputDebugStringA(FLCSA "rrwindows foundational error: StringCchVPrintfA failed.\n");
            return;
        }
        break;
    case DEBUG_PRINT_ERROR:
        if (FAILED(StringCchCopyA(lvlWord, countof(lvlWord), "error"))) {
            OutputDebugStringA(FLCSA "rrwindows foundational error: StringCchVPrintfA failed.\n");
            return;
        }
        break;
    case DEBUG_PRINT_WARN:
        if (FAILED(StringCchCopyA(lvlWord, countof(lvlWord), "warning"))) {
            OutputDebugStringA(FLCSA "rrwindows foundational error: StringCchVPrintfA failed.\n");
            return;
        }
        break;
    case DEBUG_PRINT_INFO:
        if (FAILED(StringCchCopyA(lvlWord, countof(lvlWord), "information"))) {
            OutputDebugStringA(FLCSA "rrwindows foundational error: StringCchVPrintfA failed.\n");
            return;
        }
        break;
    case DEBUG_PRINT_DEBUG:
        if (FAILED(StringCchCopyA(lvlWord, countof(lvlWord), "debug"))) {
            OutputDebugStringA(FLCSA "rrwindows foundational error: StringCchVPrintfA failed.\n");
            return;
        }
        break;
    case DEBUG_PRINT_TRACE:
        if (FAILED(StringCchCopyA(lvlWord, countof(lvlWord), "trace"))) {
            OutputDebugStringA(FLCSA "rrwindows foundational error: StringCchVPrintfA failed.\n");
            return;
        }
        break;
    default:
        OutputDebugStringA(FLCSA "rrwindows foundational error: unexpected switch route.\n");
        return;
    }

    CONST INT msgCnt = _vscprintf(format, va) + 1/*'\0'*/;
    if (msgCnt < 0) {
        OutputDebugStringA(FLCSA "rrwindows foundational error: _vscprintf failed.\n");
        return;
    }
    CHAR *CONST msgBuf = HeapAllocS(msgCnt * sizeof(CHAR));
    if (NULL == msgBuf) {
        OutputDebugStringA(FLCSA "rrwindows foundational error: HeapAlloc failed.\n");
        return;
    }
    if (FAILED(StringCchVPrintfA(msgBuf, msgCnt, format, va))) {
        OutputDebugStringA(FLCSA "rrwindows foundational error: StringCchVPrintfA failed.\n");
        goto return_freeheap_msgbuf;
    }

    CONST INT outCnt = _scprintf(TEMPLATEA) + 1/*'\0'*/;
    if (outCnt < 0) {
        OutputDebugStringA(FLCSA "rrwindows foundational error: _vscprintf failed.\n");
        goto return_freeheap_msgbuf;
    }
    CHAR *CONST outBuf = HeapAllocS(outCnt * sizeof(CHAR));
    if (NULL == outBuf) {
        OutputDebugStringA(FLCSA "rrwindows foundational error: HeapAlloc failed.\n");
        goto return_freeheap_msgbuf;
    }
    if (FAILED(StringCchPrintfA(outBuf, outCnt, TEMPLATEA))) {
        OutputDebugStringA(FLCSA "rrwindows foundational error: StringCchVPrintfA failed.\n");
        goto return_freeheap_outbuf;
    }

    OutputDebugStringA(outBuf);

return_freeheap_outbuf:
    if (FALSE == HeapFreeS(outBuf))
        OutputDebugStringA(FLCSA "rrwindows foundational error: HeapFree failed.\n");
return_freeheap_msgbuf:
    if (FALSE == HeapFreeS(msgBuf))
        OutputDebugStringA(FLCSA "rrwindows foundational error: HeapFree failed.\n");
}

RRWINDOWS_API
VOID
WINAPI
VDebugPrintW(
    _In_z_                        LPCWSTR CONST           file,
    _In_                            CONST UINT            line,
    _In_                            CONST DebugPrintLevel level,
    _In_z_ _Printf_format_string_ LPCWSTR CONST           format,
    _In_                          va_list CONST           va)
{
    if (DpLevel < level)
        return;

    WCHAR lvlWord[12];
    switch (level) {
    case DEBUG_PRINT_FATAL:
        if (FAILED(StringCchCopyW(lvlWord, countof(lvlWord), L"fatal error"))) {
            OutputDebugStringW(FLCSW L"rrwindows foundational error: StringCchVPrintfA failed.\n");
            return;
        }
        break;
    case DEBUG_PRINT_ERROR:
        if (FAILED(StringCchCopyW(lvlWord, countof(lvlWord), L"error"))) {
            OutputDebugStringW(FLCSW L"rrwindows foundational error: StringCchVPrintfA failed.\n");
            return;
        }
        break;
    case DEBUG_PRINT_WARN:
        if (FAILED(StringCchCopyW(lvlWord, countof(lvlWord), L"warning"))) {
            OutputDebugStringW(FLCSW L"rrwindows foundational error: StringCchVPrintfA failed.\n");
            return;
        }
        break;
    case DEBUG_PRINT_INFO:
        if (FAILED(StringCchCopyW(lvlWord, countof(lvlWord), L"information"))) {
            OutputDebugStringW(FLCSW L"rrwindows foundational error: StringCchVPrintfA failed.\n");
            return;
        }
        break;
    case DEBUG_PRINT_DEBUG:
        if (FAILED(StringCchCopyW(lvlWord, countof(lvlWord), L"debug"))) {
            OutputDebugStringW(FLCSW L"rrwindows foundational error: StringCchVPrintfA failed.\n");
            return;
        }
        break;
    case DEBUG_PRINT_TRACE:
        if (FAILED(StringCchCopyW(lvlWord, countof(lvlWord), L"trace"))) {
            OutputDebugStringW(FLCSW L"rrwindows foundational error: StringCchVPrintfA failed.\n");
            return;
        }
        break;
    default:
        OutputDebugStringW(FLCSW L"rrwindows foundational error: unexpected switch route.\n");
        return;
    }

    CONST INT msgCnt = _vscwprintf(format, va) + 1/*'\0'*/;
    if (msgCnt < 0) {
        OutputDebugStringW(FLCSW L"rrwindows foundational error: _vscprintf failed.\n");
        return;
    }
    WCHAR *CONST msgBuf = HeapAllocS(msgCnt * sizeof(WCHAR));
    if (NULL == msgBuf) {
        OutputDebugStringW(FLCSW L"rrwindows foundational error: HeapAlloc failed.\n");
        return;
    }
    if (FAILED(StringCchVPrintfW(msgBuf, msgCnt, format, va))) {
        OutputDebugStringW(FLCSW L"rrwindows foundational error: StringCchVPrintfA failed.\n");
        goto return_freeheap_msgbuf;
    }

    CONST INT outCnt = _scwprintf(TEMPLATEW) + 1/*'\0'*/;
    if (outCnt < 0) {
        OutputDebugStringW(FLCSW L"rrwindows foundational error: _vscprintf failed.\n");
        goto return_freeheap_msgbuf;
    }
    WCHAR *CONST outBuf = HeapAllocS(outCnt * sizeof(WCHAR));
    if (NULL == outBuf) {
        OutputDebugStringW(FLCSW L"rrwindows foundational error: HeapAlloc failed.\n");
        goto return_freeheap_msgbuf;
    }
    if (FAILED(StringCchPrintfW(outBuf, outCnt, TEMPLATEW))) {
        OutputDebugStringW(FLCSW L"rrwindows foundational error: StringCchVPrintfA failed.\n");
        goto return_freeheap_outbuf;
    }

    OutputDebugStringW(outBuf);

return_freeheap_outbuf:
    if (FALSE == HeapFreeS(outBuf))
        OutputDebugStringW(FLCSW L"rrwindows foundational error: HeapFree failed.\n");
return_freeheap_msgbuf:
    if (FALSE == HeapFreeS(msgBuf))
        OutputDebugStringW(FLCSW L"rrwindows foundational error: HeapFree failed.\n");
}
