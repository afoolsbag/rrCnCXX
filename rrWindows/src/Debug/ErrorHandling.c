/** \copyright Unlicense */

#define RRWINDOWS_EXPORTS
#include "rrWindows/Debug/ErrorHandling.h"

#include "rrWindows/MenuRc/Strings.h"

enum { BufferSize = 255 };

_Ret_notnull_
PCSTR
WINAPI
VolatileErrorMessageA(
    _In_ DWORD errorCode)
{
    __declspec(thread) static CHAR ThreadStaticBuffer[BufferSize];
    if (FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                       NULL, errorCode, LANG_USER_DEFAULT,
                       ThreadStaticBuffer, countof(ThreadStaticBuffer), NULL) == 0)
        StringCchPrintfA(ThreadStaticBuffer, countof(ThreadStaticBuffer),
                         "%s failed: %ld", __FUNCTION__, GetLastError());
    return ThreadStaticBuffer;
}

_Ret_notnull_
PCWSTR
WINAPI
VolatileErrorMessageW(
    _In_ DWORD errorCode)
{
    __declspec(thread) static WCHAR ThreadStaticBuffer[BufferSize];
    if (FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                       NULL, errorCode, LANG_USER_DEFAULT,
                       ThreadStaticBuffer, countof(ThreadStaticBuffer), NULL) == 0)
        StringCchPrintfW(ThreadStaticBuffer, countof(ThreadStaticBuffer),
                         L"%s failed: %ld", __FUNCTIONW__, GetLastError());
    return ThreadStaticBuffer;
}
