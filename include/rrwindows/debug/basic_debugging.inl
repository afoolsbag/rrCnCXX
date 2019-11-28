/// \copyright Unlicense

#pragma once
#include "basic_debugging.hxx"

#include <string>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/debug/error_handling.hxx"
#include "rrwindows/sysinfo/system_information.hxx"

namespace rrwindows {

inline void launch_debugger()
{
    const auto vsjitdebugger = system_directory_path() / L"vsjitdebugger.exe";
    auto cmd = vsjitdebugger.wstring().append(L" -p ").append(std::to_wstring(GetCurrentProcessId()));

    STARTUPINFOW stStartupInfo {};
    stStartupInfo.cb = sizeof(stStartupInfo);

    PROCESS_INFORMATION stProcInfo {};

    if (!CreateProcessW(reinterpret_cast<LPCWSTR>(vsjitdebugger.wstring().c_str()),
                        reinterpret_cast<LPWSTR>(cmd.data()),
                        nullptr,
                        nullptr,
                        FALSE,
                        0,
                        nullptr,
                        nullptr,
                        &stStartupInfo,
                        &stProcInfo))
        throw system_error_exception("CreateProcessW failed", GetLastError());
    CloseHandle(stProcInfo.hThread);
    CloseHandle(stProcInfo.hProcess);

    while (!IsDebuggerPresent())
        Sleep(1000 / 25);

    DebugBreak();
}

}
