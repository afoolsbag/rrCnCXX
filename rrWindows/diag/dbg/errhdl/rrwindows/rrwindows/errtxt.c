/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "errtxt.h"

#include <stdlib.h>
#include <strsafe.h>

#include "rrwindows/winstr.h"

#define BUFFER_SIZE 100
#define BUFFER_OFFSET (_countof("\r\n") - 1)

RRWINDOWS_API
_Success_(return != NULL)
LPCSTR WINAPI
ErrorTextOfA(
    _In_ CONST DWORD errorCode)
{
    __declspec(thread) static CHAR StaticBuffer[BUFFER_SIZE];

    LPSTR CONST bfr = StaticBuffer + BUFFER_OFFSET;
    if (!FormatMessageA(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL,
        errorCode, LANG_USER_DEFAULT,
        bfr, _countof(StaticBuffer) - BUFFER_OFFSET, NULL))
        return NULL;
    bfr[StrLenA(bfr) - BUFFER_OFFSET] = '\0';
    return bfr;
}

RRWINDOWS_API
_Success_(return != NULL)
LPCWSTR WINAPI
ErrorTextOfW(
    _In_ CONST DWORD errorCode)
{
    __declspec(thread) static WCHAR StaticBuffer[BUFFER_SIZE];

    LPWSTR CONST bfr = StaticBuffer + BUFFER_OFFSET;
    if (!FormatMessageW(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL,
        errorCode, LANG_USER_DEFAULT,
        bfr, _countof(StaticBuffer) - BUFFER_OFFSET, NULL))
        return NULL;
    bfr[StrLenW(bfr) - BUFFER_OFFSET] = L'\0';
    return bfr;
}
