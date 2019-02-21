/**
 * \copyright Unlicense
 */

#define RRWINDOWS_EXPORTS
#include "rrWindows/Rpc/RemoteProcedureCall.h"

#include <rpc.h>
#pragma comment(lib, "RpcRT4.Lib")
#include <strsafe.h>

RRWINDOWS_API
HRESULT
WINAPI
GenerateUuidStringA(
    _Out_  PSTR CONST  buf,
    _In_  CONST SIZE_T cnt)
{
    RPC_STATUS ec = RPC_S_OK;

    UUID bin;
    if ((ec = UuidCreate(&bin)) != RPC_S_OK)
        goto exit;

    RPC_CSTR str;
    if ((ec = UuidToStringA(&bin, &str)) != RPC_S_OK)
        goto exit;

    CONST HRESULT hr = StringCchCopyA(buf, cnt, (PSTR)str);
    if (FAILED(hr)) {
        ec = HRESULT_CODE(hr);
        goto exit_free;
    }

exit_free:
    RpcStringFreeA(&str);

exit:
    return MAKE_HRESULT(ec == RPC_S_OK ? SEVERITY_SUCCESS : SEVERITY_ERROR, FACILITY_NULL, ec);
}

RRWINDOWS_API
HRESULT
WINAPI
GenerateUuidStringW(
    _Out_ PWSTR CONST  buf,
    _In_  CONST SIZE_T cnt)
{
    RPC_STATUS ec = RPC_S_OK;

    UUID bin;
    if ((ec = UuidCreate(&bin)) != RPC_S_OK)
        goto exit;

    RPC_WSTR str;
    if ((ec = UuidToStringW(&bin, &str)) != RPC_S_OK)
        goto exit;

    CONST HRESULT hr = StringCchCopyW(buf, cnt, (PWSTR)str);
    if (FAILED(hr)) {
        ec = HRESULT_CODE(hr);
        goto exit_free;
    }

exit_free:
    RpcStringFreeW(&str);

exit:
    return MAKE_HRESULT(ec == RPC_S_OK ? SEVERITY_SUCCESS : SEVERITY_ERROR, FACILITY_NULL, ec);
}

RRWINDOWS_API
_Success_(return != NULL)
PCSTR
WINAPI
UuidStringA(VOID)
{
    __declspec(thread) static CHAR Buffer[UUID_STRING_COUNT];

    UUID bin;
    if (UuidCreate(&bin) != RPC_S_OK)
        return NULL;

    RPC_CSTR str;
    if (UuidToStringA(&bin, &str) != RPC_S_OK)
        return NULL;

    if (FAILED(StringCchCopyA(Buffer, countof(Buffer), (PSTR)str))) {
        RpcStringFreeA(&str);
        return NULL;
    }

    RpcStringFreeA(&str);

    return Buffer;
}

RRWINDOWS_API
_Success_(return != NULL)
PCWSTR
WINAPI
UuidStringW(VOID)
{
    __declspec(thread) static WCHAR Buffer[UUID_STRING_COUNT];

    UUID bin;
    if (UuidCreate(&bin) != RPC_S_OK)
        return NULL;

    RPC_WSTR str;
    if (UuidToStringW(&bin, &str) != RPC_S_OK)
        return NULL;

    if (FAILED(StringCchCopyW(Buffer, countof(Buffer), (PWSTR)str))) {
        RpcStringFreeW(&str);
        return NULL;
    }

    RpcStringFreeW(&str);

    return Buffer;
}
