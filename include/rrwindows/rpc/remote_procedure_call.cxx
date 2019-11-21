/// \copyright Unlicense

#include "rrwindows/rpc/remote_procedure_call.hxx"

#include <gsl/gsl>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <rpc.h>
#pragma comment(lib, "RpcRT4.Lib")
#include <strsafe.h>

#include "rrwindows/debug/error_handling.hxx"

using namespace std;
using namespace gsl;

namespace rrwindows {

RRWINDOWS_API std::string RRWINDOWS_CALL generate_uuid_string()
{
    UUID stBin; {
        CONST RPC_STATUS lError {UuidCreate(&stBin)};
        if (lError != RPC_S_OK)
            throw system_error_exception("UuidCreate failed", lError);
    }

    RPC_CSTR pStr; {
        CONST RPC_STATUS lError {UuidToStringA(&stBin, &pStr)};
        if (lError != RPC_S_OK)
            throw system_error_exception("UuidToStringA field", lError);
    }
    const auto finally_free_str = finally([&] { RpcStringFreeA(&pStr); });

    return reinterpret_cast<LPSTR>(pStr);
}

RRWINDOWS_API std::wstring RRWINDOWS_CALL generate_uuid_wstring()
{
    UUID stBin; {
        CONST RPC_STATUS lError {UuidCreate(&stBin)};
        if (lError != RPC_S_OK)
            throw system_error_exception("UuidCreate failed", lError);
    }

    RPC_WSTR pStr; {
        CONST RPC_STATUS lError {UuidToStringW(&stBin, &pStr)};
        if (lError != RPC_S_OK)
            throw system_error_exception("UuidToStringW failed", lError);
    }
    const auto finally_free_str = finally([&] { RpcStringFreeW(&pStr); });

    return reinterpret_cast<LPWSTR>(pStr);
}

}
