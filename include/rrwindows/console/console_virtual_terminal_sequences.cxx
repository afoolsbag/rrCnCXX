/// \copyright Unlicense

#include "rrwindows/console/console_virtual_terminal_sequences.hxx"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/debug/error_handling.hxx"

using namespace std;

namespace rrwindows {

RRWINDOWS_API void RRWINDOWS_CALL enable_virtual_terminal_mode()
{
    DWORD dwMode;

    CONST HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE)
        throw system_error_exception("GetStdHandle failed", GetLastError());
    if (!GetConsoleMode(hStdOut, &dwMode))
        throw system_error_exception("GetConsoleMode failed", GetLastError());
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hStdOut, dwMode))
        throw system_error_exception("SetConsoleMode failed", GetLastError());

    const auto hStdErr = GetStdHandle(STD_ERROR_HANDLE);
    if (hStdErr == INVALID_HANDLE_VALUE)
        throw system_error_exception("GetStdHandle failed", GetLastError());
    if (!GetConsoleMode(hStdErr, &dwMode))
        throw system_error_exception("GetConsoleMode failed", GetLastError());
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hStdErr, dwMode))
        throw system_error_exception("SetConsoleMode failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL disable_virtual_terminal_mode()
{
    DWORD dwMode;

    const auto hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE)
        throw system_error_exception("GetStdHandle failed", GetLastError());
    if (!GetConsoleMode(hStdOut, &dwMode))
        throw system_error_exception("GetConsoleMode failed", GetLastError());
    dwMode &= ~static_cast<DWORD>(ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    if (!SetConsoleMode(hStdOut, dwMode))
        throw system_error_exception("SetConsoleMode failed", GetLastError());

    const auto hStdErr = GetStdHandle(STD_ERROR_HANDLE);
    if (hStdErr == INVALID_HANDLE_VALUE)
        throw system_error_exception("GetStdHandle failed", GetLastError());
    if (!GetConsoleMode(hStdErr, &dwMode))
        throw system_error_exception("GetConsoleMode failed", GetLastError());
    dwMode &= ~static_cast<DWORD>(ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    if (!SetConsoleMode(hStdErr, dwMode))
        throw system_error_exception("SetConsoleMode failed", GetLastError());
}

}
