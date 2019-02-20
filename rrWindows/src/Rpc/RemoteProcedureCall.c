/**
 * \copyright Unlicense
 */

#define RRWINDOWS_EXPORTS
#include "rrwindows/Rpc/RemoteProcedureCall.h"

#include <rpc.h>
#pragma comment(lib, "RpcRT4.Lib")
#include <strsafe.h>

#include "rrwindows/Memory/MemoryManagement.h"

RRWINDOWS_API
HRESULT
WINAPI
GenerateUuidA(
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
GenerateUuidW(
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
PSTR
WINAPI
AllocUuidStringCA(
    _Out_opt_ PSIZE_T CONST cnt)
{
    UUID bin;
    if (UuidCreate(&bin) != RPC_S_OK)
        return NULL;

    RPC_CSTR str;
    if (UuidToStringA(&bin, &str) != RPC_S_OK)
        return NULL;

    CONST SIZE_T siz = UUID_STRING_COUNT * sizeof(CHAR);
    PSTR CONST buf = HeapAllocS(siz);
    if (!buf) {
        RpcStringFreeA(&str);
        return NULL;
    }

    if (FAILED(StringCchCopyA(buf, UUID_STRING_COUNT, (PSTR)str))) {
        HeapFreeS(buf);
        RpcStringFreeA(&str);
        return NULL;
    }

    RpcStringFreeA(&str);

    *cnt = UUID_STRING_COUNT;
    return buf;
}

RRWINDOWS_API
_Success_(return != NULL)
PWSTR
WINAPI
AllocUuidStringCW(
    _Out_opt_ PSIZE_T CONST cnt)
{
    UUID bin;
    if (UuidCreate(&bin) != RPC_S_OK)
        return NULL;

    RPC_WSTR str;
    if (UuidToStringW(&bin, &str) != RPC_S_OK)
        return NULL;

    CONST SIZE_T siz = UUID_STRING_COUNT * sizeof(WCHAR);
    PWSTR CONST buf = HeapAllocS(siz);
    if (!buf) {
        RpcStringFreeW(&str);
        return NULL;
    }

    if (FAILED(StringCchCopyW(buf, UUID_STRING_COUNT, (PWSTR)str))) {
        HeapFreeS(buf);
        RpcStringFreeW(&str);
        return NULL;
    }

    RpcStringFreeW(&str);

    *cnt = UUID_STRING_COUNT;
    return buf;
}
