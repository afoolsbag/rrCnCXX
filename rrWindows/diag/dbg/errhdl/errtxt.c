/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "errtxt.h"

#include <strsafe.h>

#include "rrWindows/def.h"
#include "rrWindows/dtpui/menurc/str/strsim.h"

#define BUFFER_SIZE 100
#define BUFFER_OFFSET (countof("\r\n") - 1)

RRWINDOWS_API
_Success_(return != NULL)
LPCSTR
WINAPI
ErrorTextOfA(
    _In_ CONST DWORD errorCode)
{
    __declspec(thread) static CHAR StaticBuffer[BUFFER_SIZE];

    LPSTR CONST bfr = StaticBuffer + BUFFER_OFFSET;
    if (0 == FormatMessageA(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL,
        errorCode, LANG_USER_DEFAULT,
        bfr, countof(StaticBuffer) - BUFFER_OFFSET, NULL))
        return NULL;
    bfr[StringCchLengthAs(bfr) - BUFFER_OFFSET] = '\0';
    return bfr;
}

RRWINDOWS_API
_Success_(return != NULL)
LPCWSTR
WINAPI
ErrorTextOfW(
    _In_ CONST DWORD errorCode)
{
    __declspec(thread) static WCHAR StaticBuffer[BUFFER_SIZE];

    LPWSTR CONST bfr = StaticBuffer + BUFFER_OFFSET;
    if (0 == FormatMessageW(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL,
        errorCode, LANG_USER_DEFAULT,
        bfr, countof(StaticBuffer) - BUFFER_OFFSET, NULL))
        return NULL;
    bfr[StringCchLengthWs(bfr) - BUFFER_OFFSET] = L'\0';
    return bfr;
}
