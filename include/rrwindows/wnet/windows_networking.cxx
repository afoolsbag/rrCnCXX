/// \copyright Unlicense

#include "rrwindows/wnet/windows_networking.hxx"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <shellapi.h>
#pragma comment(lib, "Mpr.Lib")

#include "rrwindows/debug/error_handling.hxx"

using namespace std;

namespace rrwindows {

RRWINDOWS_API void RRWINDOWS_CALL connect_shared_folder(const char *shared_folder_path, const char *username, const char *password)
{
    if (!shared_folder_path)
        throw invalid_argument_exception(__FUNCTION__);

    string buf = shared_folder_path;

    NETRESOURCEA stNetRes {};
    stNetRes.dwType = RESOURCETYPE_DISK;
    stNetRes.lpRemoteName = buf.data();

    CONST DWORD dwError = WNetAddConnection2A(&stNetRes,
                                              reinterpret_cast<LPCSTR>(password),
                                              reinterpret_cast<LPCSTR>(username),
                                              CONNECT_TEMPORARY);

    if (dwError != NO_ERROR)
        throw system_error_exception("WNetAddConnection2A failed", dwError);
}

RRWINDOWS_API void RRWINDOWS_CALL connect_shared_folder(const wchar_t *shared_folder_path, const wchar_t *username, const wchar_t *password)
{
    if (!shared_folder_path)
        throw invalid_argument_exception(__FUNCTION__);

    wstring buf = shared_folder_path;

    NETRESOURCEW stNetRes {};
    stNetRes.dwType = RESOURCETYPE_DISK;
    stNetRes.lpRemoteName = buf.data();

    CONST DWORD dwError = WNetAddConnection2W(&stNetRes,
                                              reinterpret_cast<LPCWSTR>(password),
                                              reinterpret_cast<LPCWSTR>(username),
                                              CONNECT_TEMPORARY);

    if (dwError != NO_ERROR)
        throw system_error_exception("WNetAddConnection2W failed", dwError);
}

RRWINDOWS_API void RRWINDOWS_CALL disconnect_shared_folder(const char *shared_folder_path)
{
    CONST DWORD dwError = WNetCancelConnection2A(reinterpret_cast<LPCSTR>(shared_folder_path),
                                                 0,
                                                 TRUE);
    if (dwError != NO_ERROR)
        throw system_error_exception("WNetCancelConnection2A failed", dwError);
}

RRWINDOWS_API void RRWINDOWS_CALL disconnect_shared_folder(const wchar_t *shared_folder_path)
{
    CONST DWORD dwError = WNetCancelConnection2W(reinterpret_cast<LPCWSTR>(shared_folder_path),
                                                 0,
                                                 TRUE);
    if (dwError != NO_ERROR)
        throw system_error_exception("WNetCancelConnection2W failed", dwError);
}

}
