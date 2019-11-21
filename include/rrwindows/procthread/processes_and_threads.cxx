/// \copyright Unlicense

#include "rrwindows/procthread/processes_and_threads.hxx"

#include <gsl/gsl>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#undef UNICODE
#include <TlHelp32.h>
#include <WtsApi32.h>
#pragma comment(lib, "WtsApi32.Lib")

#include "rrwindows/debug/error_handling.hxx"
#include "rrwindows/menurc/strings.hxx"

using namespace std;
using namespace gsl;

namespace rrwindows {

RRWINDOWS_API void RRWINDOWS_CALL run_executable(const char *path, const char *args, const char *start_in, bool show)
{
    if (!path)
        throw invalid_argument_exception(__FUNCTION__);

    string cmd {path};
    if (args)
        cmd.append(" ").append(args);

    STARTUPINFOA stStartupInfo {};
    stStartupInfo.cb = sizeof(stStartupInfo);
    stStartupInfo.dwFlags = STARTF_USESHOWWINDOW;
    stStartupInfo.wShowWindow = show ? SW_SHOW : SW_HIDE;

    PROCESS_INFORMATION stProcInfo;

    if (!CreateProcessA(reinterpret_cast<LPCSTR>(path),
                        reinterpret_cast<LPSTR>(cmd.data()),
                        nullptr,
                        nullptr,
                        FALSE,
                        CREATE_NEW_CONSOLE,
                        nullptr,
                        reinterpret_cast<LPCSTR>(start_in),
                        &stStartupInfo,
                        &stProcInfo))
        throw system_error_exception("CreateProcessA failed", GetLastError());
    CloseHandle(stProcInfo.hProcess);
    CloseHandle(stProcInfo.hThread);
}

RRWINDOWS_API void RRWINDOWS_CALL run_executable(const wchar_t *path, const wchar_t *args, const wchar_t *start_in, bool show)
{
    if (!path)
        throw invalid_argument_exception(__FUNCTION__);

    wstring cmd {path};
    if (args)
        cmd.append(L" ").append(args);

    STARTUPINFOW stStartupInfo {};
    stStartupInfo.cb = sizeof(stStartupInfo);
    stStartupInfo.dwFlags = STARTF_USESHOWWINDOW;
    stStartupInfo.wShowWindow = show ? SW_SHOW : SW_HIDE;

    PROCESS_INFORMATION stProcInfo;

    if (!CreateProcessW(reinterpret_cast<LPCWSTR>(path),
                        reinterpret_cast<LPWSTR>(cmd.data()),
                        nullptr,
                        nullptr,
                        FALSE,
                        CREATE_NEW_CONSOLE,
                        nullptr,
                        reinterpret_cast<LPCWSTR>(start_in),
                        &stStartupInfo,
                        &stProcInfo))
        throw system_error_exception("CreateProcessW failed", GetLastError());
    CloseHandle(stProcInfo.hProcess);
    CloseHandle(stProcInfo.hThread);
}

RRWINDOWS_API void RRWINDOWS_CALL run_executable_as_active(const char *path, const char *args, const char *start_in, bool show)
{
    if (!path)
        throw invalid_argument_exception(__FUNCTION__);

    string cmd;
    cmd.append(path);
    if (args)
        cmd.append(" ").append(args);

    CONST DWORD dwActiveSessionId {WTSGetActiveConsoleSessionId()};
    HANDLE hActiveToken = nullptr;
    if (!WTSQueryUserToken(dwActiveSessionId, &hActiveToken))
        throw system_error_exception("WTSQueryUserToken failed", GetLastError());
    const auto finally_close_token = finally([&] { CloseHandle(hActiveToken); });

    CHAR lpDesktop[] {"WinSta0\\Default"};
    STARTUPINFOA stStartupInfo {};
    stStartupInfo.cb = sizeof stStartupInfo;
    stStartupInfo.lpDesktop = lpDesktop;
    stStartupInfo.dwFlags = STARTF_USESHOWWINDOW;
    stStartupInfo.wShowWindow = show ? SW_SHOW : SW_HIDE;

    PROCESS_INFORMATION stProcInfo;

    if (!CreateProcessAsUserA(hActiveToken,
                              reinterpret_cast<LPCSTR>(path),
                              reinterpret_cast<LPSTR>(cmd.data()),
                              nullptr,
                              nullptr,
                              FALSE,
                              CREATE_NEW_CONSOLE,
                              nullptr,
                              reinterpret_cast<LPCSTR>(start_in),
                              &stStartupInfo,
                              &stProcInfo))
        throw system_error_exception("CreateProcessAsUserA failed", GetLastError());
    CloseHandle(stProcInfo.hProcess);
    CloseHandle(stProcInfo.hThread);
}

RRWINDOWS_API void RRWINDOWS_CALL run_executable_as_active(const wchar_t *path, const wchar_t *args, const wchar_t *start_in, bool show)
{
    if (!path)
        throw invalid_argument_exception(__FUNCTION__);

    wstring cmd;
    cmd.append(path);
    if (args)
        cmd.append(L" ").append(args);

    CONST DWORD dwActiveSessionId {WTSGetActiveConsoleSessionId()};
    HANDLE hActiveToken = nullptr;
    if (!WTSQueryUserToken(dwActiveSessionId, &hActiveToken))
        throw system_error_exception("WTSQueryUserToken failed", GetLastError());
    const auto finally_close_token = finally([&] { CloseHandle(hActiveToken); });

    WCHAR lpDesktop[] {L"WinSta0\\Default"};
    STARTUPINFOW stStartupInfo {};
    stStartupInfo.cb = sizeof stStartupInfo;
    stStartupInfo.lpDesktop = lpDesktop;
    stStartupInfo.dwFlags = STARTF_USESHOWWINDOW;
    stStartupInfo.wShowWindow = show ? SW_SHOW : SW_HIDE;

    PROCESS_INFORMATION stProcInfo;

    if (!CreateProcessAsUserW(hActiveToken,
                              reinterpret_cast<LPCWSTR>(path),
                              reinterpret_cast<LPWSTR>(cmd.data()),
                              nullptr,
                              nullptr,
                              FALSE,
                              CREATE_NEW_CONSOLE,
                              nullptr,
                              reinterpret_cast<LPCWSTR>(start_in),
                              &stStartupInfo,
                              &stProcInfo))
        throw system_error_exception("CreateProcessAsUserW failed", GetLastError());
    CloseHandle(stProcInfo.hProcess);
    CloseHandle(stProcInfo.hThread);
}

RRWINDOWS_API std::size_t RRWINDOWS_CALL kill_executable(const char *executable_name)
{
    if (!executable_name)
        throw invalid_argument_exception(__FUNCTION__);

    CONST HANDLE hSnapshot {CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0)};
    if (hSnapshot == INVALID_HANDLE_VALUE)
        throw system_error_exception("CreateToolhelp32Snapshot failed", GetLastError());
    const auto finally_close_snapshot = finally([&] { CloseHandle(hSnapshot); });


    PROCESSENTRY32 stProcessEntry;
    stProcessEntry.dwSize = sizeof(stProcessEntry);

    SIZE_T sizLeft {0};
    if (!Process32First(hSnapshot, &stProcessEntry)) {
        CONST DWORD dwError {GetLastError()};
        if (dwError == ERROR_NO_MORE_FILES)
            return sizLeft;
        throw system_error_exception("Process32First failed", GetLastError());
    }
    do {
        if (strcmp(executable_name, stProcessEntry.szExeFile) != 0)
            continue;
        CONST HANDLE hProc = OpenProcess(PROCESS_TERMINATE, FALSE, stProcessEntry.th32ProcessID);
        if (!hProc) {
            ++sizLeft;
            continue;
        }
        const auto finally_close_proc = finally([&] { CloseHandle(hProc); });
        if (!TerminateProcess(hProc, EXIT_FAILURE)) {
            ++sizLeft;
            continue;
        }
    } while (Process32Next(hSnapshot, &stProcessEntry));

    return sizLeft;
}

RRWINDOWS_API std::size_t RRWINDOWS_CALL kill_executable(const wchar_t *executable_name)
{
    if (!executable_name)
        throw invalid_argument_exception(__FUNCTION__);

    CONST HANDLE hSnapshot {CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0)};
    if (hSnapshot == INVALID_HANDLE_VALUE)
        throw system_error_exception("CreateToolhelp32Snapshot failed", GetLastError());
    const auto finally_close_snapshot = finally([&] { CloseHandle(hSnapshot); });

    PROCESSENTRY32W stProcessEntry;
    stProcessEntry.dwSize = sizeof(stProcessEntry);

    SIZE_T sizLeft {0};
    if (!Process32FirstW(hSnapshot, &stProcessEntry)) {
        CONST DWORD dwError {GetLastError()};
        if (dwError == ERROR_NO_MORE_FILES)
            return sizLeft;
        throw system_error_exception("Process32First failed", GetLastError());
    }
    do {
        if (strcmp(executable_name, stProcessEntry.szExeFile) != 0)
            continue;
        CONST HANDLE hProc = OpenProcess(PROCESS_TERMINATE, FALSE, stProcessEntry.th32ProcessID);
        if (!hProc) {
            ++sizLeft;
            continue;
        }
        const auto finally_close_proc = finally([&] { CloseHandle(hProc); });
        if (!TerminateProcess(hProc, EXIT_FAILURE)) {
            ++sizLeft;
            continue;
        }
    } while (Process32NextW(hSnapshot, &stProcessEntry));

    return sizLeft;
}

}
