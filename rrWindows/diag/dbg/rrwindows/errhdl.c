/** \copyright The MIT License */

#include "errhdl.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#define BUFFER_SIZE 350
#define BUFFER_OFFSET 2  /* for \r\n when empty string */

RRWINDOWS_ERRHDL_API
_Success_(return != NULL)
LPCSTR WINAPI
ErrorTextOfA(
    _In_ CONST DWORD errorCode)
{
    __declspec(thread) static CHAR StaticBuffer[BUFFER_SIZE];
    LPSTR CONST bfr = StaticBuffer + BUFFER_OFFSET;

    if (!FormatMessageA(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL,
        errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL),
        bfr, BUFFER_SIZE - BUFFER_OFFSET, NULL))
        return NULL;
    bfr[strlen(bfr) - 2] = '\0';
    return bfr;
}

RRWINDOWS_ERRHDL_API
_Success_(return != NULL)
LPCWSTR WINAPI
ErrorTextOfW(
    _In_ CONST DWORD errorCode)
{
    __declspec(thread) static WCHAR StaticBuffer[BUFFER_SIZE];
    LPWSTR CONST bfr = StaticBuffer + BUFFER_OFFSET;

    if (!FormatMessageW(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL,
        errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL),
        bfr, BUFFER_SIZE - BUFFER_OFFSET, NULL))
        return NULL;
    bfr[wcslen(bfr) - 2] = L'\0';
    return bfr;
}
