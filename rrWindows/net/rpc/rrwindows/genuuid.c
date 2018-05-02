/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "genuuid.h"

#include <stdlib.h>
#include <rpc.h>
#include <strsafe.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#pragma comment(lib, "RpcRT4.Lib")

#define BUFFER_SIZE 37

RRWINDOWS_API _Success_(return != NULL) LPCSTR WINAPI
GenerateUuidA(VOID)
{
    __declspec(thread) static CHAR StaticBuffer[BUFFER_SIZE];

    UUID uuidBin;
    UuidCreate(&uuidBin);
    LPSTR uuidStr;
    UuidToStringA(&uuidBin, (RPC_CSTR *)&uuidStr);
    StringCchCopyA(StaticBuffer, _countof(StaticBuffer), uuidStr);
    RpcStringFreeA((RPC_CSTR *)&uuidStr);

    return StaticBuffer;
}

RRWINDOWS_API _Success_(return != NULL) LPCWSTR WINAPI
GenerateUuidW(VOID)
{
    __declspec(thread) static WCHAR StaticBuffer[BUFFER_SIZE];

    UUID uuidBin;
    UuidCreate(&uuidBin);
    LPWSTR uuidStr;
    UuidToStringW(&uuidBin, (RPC_WSTR *)&uuidStr);
    StringCchCopyW(StaticBuffer, _countof(StaticBuffer), uuidStr);
    RpcStringFreeW((RPC_WSTR *)&uuidStr);

    return StaticBuffer;
}
