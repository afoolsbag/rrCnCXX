/// \copyright Unlicense

#include "rrwindows/debug/structured_exception_handling.hxx"

#include <filesystem>
#include <gsl/gsl>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <ImageHlp.h>
#pragma comment(lib, "DbgHelp.Lib")
#include <strsafe.h>

#include "rrwindows/debug/error_handling.hxx"
#include "rrwindows/dlls/dynamic_link_library.hxx"
#include "rrwindows/fileio/file_management.hxx"
#include "rrwindows/menurc/version_information.hxx"

using namespace std;
using namespace gsl;

namespace {

filesystem::path temp_dump_path()
{
    const auto exe_path = rrwindows::executable_path();

    // %TMP%/Dump
    const auto dump_dir = rrwindows::temp_path() / L"Dump";
    CreateDirectoryW(dump_dir.c_str(), nullptr);

    // %TMP%/Dump/ExeBaseName
    auto dump_path = dump_dir / exe_path.stem();

    // %TMP%/Dump/ExeBaseName[_m.n.p.t]
    try {
        const auto ver = rrwindows::get_file_file_version_information(exe_path);
        WCHAR achBuf[25] {};
        const auto hr = StringCchPrintfW(achBuf, _countof(achBuf), L"_%hu.%hu.%hu.%hu",
                                         ver[0], ver[1], ver[2], ver[3]);
        if (FAILED(hr))
            throw rrwindows::system_error_exception("StringCchPrintfW failed", HRESULT_CODE(hr));
        dump_path += achBuf;
    } catch (...) {
        // ignore
    }

    // %TMP%/Dump/ExeBaseName[_m.n.p.t]_YYYYMMDD_hhmmss
    {
        SYSTEMTIME stTime;
        GetLocalTime(&stTime);
        WCHAR achBuf[17];
        const auto hr = StringCchPrintfW(achBuf, _countof(achBuf), L"_%04hu%02hu%02hu_%02hu%02hu%02hu",
                                         stTime.wYear, stTime.wMonth, stTime.wDay, stTime.wHour, stTime.wMinute, stTime.wSecond);
        if (FAILED(hr))
            throw rrwindows::system_error_exception("StringCchPrintfW failed", HRESULT_CODE(hr));
        dump_path += achBuf;
    }

    // %TEMP%/dump/ExeBaseName[_m.n.p.t]_YYYYMMDD_hhmmss.dmp
    dump_path += L".dmp";

    return dump_path;
}

LONG CALLBACK CrashDumpFilter(PEXCEPTION_POINTERS pstExceptionInfo) noexcept
{
    const wstring path = [] {
        try {
            return temp_dump_path().c_str();
        } catch (...) {
            return L"crash.dmp";
        }
    }();

    CONST HANDLE hFile = CreateFileW(reinterpret_cast<LPCWSTR>(path.c_str()),
                                     GENERIC_WRITE,
                                     0,
                                     nullptr,
                                     CREATE_ALWAYS,
                                     FILE_ATTRIBUTE_NORMAL,
                                     nullptr);
    if (hFile == INVALID_HANDLE_VALUE)
        return EXCEPTION_EXECUTE_HANDLER;
    const auto finally_close_file {finally([&] { CloseHandle(hFile); })};

    MINIDUMP_EXCEPTION_INFORMATION stDumpInfo;
    stDumpInfo.ThreadId = GetCurrentThreadId();
    stDumpInfo.ExceptionPointers = pstExceptionInfo;
    stDumpInfo.ClientPointers = TRUE;
    if (FAILED(MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, MiniDumpNormal, &stDumpInfo, nullptr, nullptr)))
        return EXCEPTION_EXECUTE_HANDLER;

    return EXCEPTION_EXECUTE_HANDLER;
}

}

namespace rrwindows {

RRWINDOWS_API void RRWINDOWS_CALL set_crash_dump_filter()
{
    SetUnhandledExceptionFilter(CrashDumpFilter);
}

RRWINDOWS_API void RRWINDOWS_CALL reset_unhandled_exception_filter()
{
    SetUnhandledExceptionFilter(nullptr);
}

}
