/// \copyright Unlicense

#include "rrwindows/console/consoles.hxx"

#include <cstdarg>
#include <functional>
#include <memory>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <strsafe.h>

#include "rrwindows/debug/error_handling.hxx"
#include "rrwindows/menurc/strings.hxx"

using namespace std;

namespace {

/// \brief 获取控制台背景色。
/// \param hConsoleOutput 控制台句柄。
rrwindows::console_color get_console_back_ground_color(HANDLE hConsoleOutput)
{
    CONSOLE_SCREEN_BUFFER_INFO stInfo;
    if (!GetConsoleScreenBufferInfo(hConsoleOutput, &stInfo))
        throw rrwindows::system_error_exception("GetConsoleScreenBufferInfo failed", GetLastError());
    return static_cast<rrwindows::console_color>((stInfo.wAttributes & 0x00F0) >> 4);
}

/// \brief 获取控制台前景色。
/// \param hConsoleOutput 控制台句柄。
rrwindows::console_color get_console_fore_ground_color(HANDLE hConsoleOutput)
{
    CONSOLE_SCREEN_BUFFER_INFO stInfo;
    if (!GetConsoleScreenBufferInfo(hConsoleOutput, &stInfo))
        throw rrwindows::system_error_exception("GetConsoleScreenBufferInfo failed", GetLastError());
    return static_cast<rrwindows::console_color>(stInfo.wAttributes & 0x000F);
}

/// \brief 设定控制台背景色。
/// \param hConsoleOutput    控制台句柄。
/// \param back_ground_color 背景色。
void set_console_back_ground_color(HANDLE hConsoleOutput, rrwindows::console_color back_ground_color)
{
    CONSOLE_SCREEN_BUFFER_INFO stInfo;
    if (!GetConsoleScreenBufferInfo(hConsoleOutput, &stInfo))
        throw rrwindows::system_error_exception("GetConsoleScreenBufferInfo failed", GetLastError());
    stInfo.wAttributes &= 0xFF0F;
    stInfo.wAttributes |= static_cast<WORD>(back_ground_color) << 4;
    if (!SetConsoleTextAttribute(hConsoleOutput, stInfo.wAttributes))
        throw rrwindows::system_error_exception("SetConsoleScreenBufferInfo failed", GetLastError());
}

/// \brief 设定控制台前景色。
/// \param hConsoleOutput    控制台句柄。
/// \param fore_ground_color 前景色。
void set_console_fore_ground_color(HANDLE hConsoleOutput, rrwindows::console_color fore_ground_color)
{
    CONSOLE_SCREEN_BUFFER_INFO stInfo;
    if (!GetConsoleScreenBufferInfo(hConsoleOutput, &stInfo))
        throw rrwindows::system_error_exception("GetConsoleScreenBufferInfo failed", GetLastError());
    stInfo.wAttributes &= 0xFFF0;
    stInfo.wAttributes |= static_cast<WORD>(fore_ground_color);
    if (!SetConsoleTextAttribute(hConsoleOutput, stInfo.wAttributes))
        throw rrwindows::system_error_exception("SetConsoleScreenBufferInfo failed", GetLastError());
}

}

namespace rrwindows {

RRWINDOWS_API void RRWINDOWS_CALL puts(const char *text)
{
    CONST HANDLE hStdOut {GetStdHandle(STD_OUTPUT_HANDLE)};
    if (hStdOut == INVALID_HANDLE_VALUE)
        throw system_error_exception("GetStdHandle failed", GetLastError());
    if (!WriteConsoleA(hStdOut,
                       reinterpret_cast<CONST VOID *>(text),
                       static_cast<DWORD>(strlen(text)),
                       nullptr,
                       nullptr))
        throw system_error_exception("WriteConsoleA failed", GetLastError());
    if (!WriteConsoleA(hStdOut,
                       reinterpret_cast<CONST VOID *>("\n"),
                       static_cast<DWORD>(1),
                       nullptr,
                       nullptr))
        throw system_error_exception("WriteConsoleA failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL puts(const wchar_t *text)
{
    CONST HANDLE hStdOut {GetStdHandle(STD_OUTPUT_HANDLE)};
    if (hStdOut == INVALID_HANDLE_VALUE)
        throw system_error_exception("GetStdHandle failed", GetLastError());
    if (!WriteConsoleW(hStdOut,
                       reinterpret_cast<CONST VOID *>(text),
                       static_cast<DWORD>(strlen(text)),
                       nullptr,
                       nullptr))
        throw system_error_exception("WriteConsoleW failed", GetLastError());
    if (!WriteConsoleW(hStdOut,
                       reinterpret_cast<CONST VOID *>("\n"),
                       static_cast<DWORD>(1),
                       nullptr,
                       nullptr))
        throw system_error_exception("WriteConsoleW failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL eputs(const char *text)
{
    CONST HANDLE hStdErr = GetStdHandle(STD_ERROR_HANDLE);
    if (hStdErr == INVALID_HANDLE_VALUE)
        throw system_error_exception("GetStdHandle failed", GetLastError());
    if (!WriteConsoleA(hStdErr,
                       reinterpret_cast<CONST VOID *>(text),
                       static_cast<DWORD>(strlen(text)),
                       nullptr,
                       nullptr))
        throw system_error_exception("WriteConsoleA failed", GetLastError());
    if (!WriteConsoleA(hStdErr,
                       reinterpret_cast<CONST VOID *>("\n"),
                       static_cast<DWORD>(1),
                       nullptr,
                       nullptr))
        throw system_error_exception("WriteConsoleA failed", GetLastError());
}

RRWINDOWS_API void RRWINDOWS_CALL eputs(const wchar_t *text)
{
    CONST HANDLE hStdErr = GetStdHandle(STD_ERROR_HANDLE);
    if (hStdErr == INVALID_HANDLE_VALUE)
        throw system_error_exception("GetStdHandle failed", GetLastError());
    if (!WriteConsoleW(hStdErr,
                       reinterpret_cast<CONST VOID *>(text),
                       static_cast<DWORD>(strlen(text)),
                       nullptr,
                       nullptr))
        throw system_error_exception("WriteConsoleW failed", GetLastError());
    if (!WriteConsoleW(hStdErr,
                       reinterpret_cast<CONST VOID *>("\n"),
                       static_cast<DWORD>(1),
                       nullptr,
                       nullptr))
        throw system_error_exception("WriteConsoleW failed", GetLastError());
}

}

namespace {

/// \brief 格式化写入控制台：variadic console (wide) print format
/// \param hConsoleOutput 控制台句柄。
/// \param pszFormat      格式。
/// \param vaArgList      参数。
void vcprintf(HANDLE hConsoleOutput, STRSAFE_LPCSTR pszFormat, va_list vaArgList)
{
    unique_ptr<CHAR[]> buf {};
    for (size_t cchCnt = 128; ; cchCnt *= 2) {
        buf = make_unique<CHAR[]>(cchCnt);
        if (!buf)
            throw bad_alloc();
        const auto hr = StringCchVPrintfA(reinterpret_cast<STRSAFE_LPSTR>(buf.get()),
                                          cchCnt,
                                          pszFormat,
                                          vaArgList);
        if (SUCCEEDED(hr)) {
            if (!WriteConsoleA(hConsoleOutput,
                               reinterpret_cast<CONST VOID *>(buf.get()),
                               static_cast<DWORD>(strlen(buf.get())),
                               nullptr,
                               nullptr))
                throw rrwindows::system_error_exception("WriteConsoleA failed", GetLastError());
            return;
        }
        if (hr != STRSAFE_E_INSUFFICIENT_BUFFER)
            throw rrwindows::system_error_exception("StringCchVPrintfA failed", HRESULT_CODE(hr));
    }
}
void vcprintf(HANDLE hConsoleOutput, STRSAFE_LPCWSTR pszFormat, va_list vaArgList)
{
    unique_ptr<WCHAR[]> buf {};
    for (size_t cchCnt = 128; ; cchCnt *= 2) {
        buf = make_unique<WCHAR[]>(cchCnt);
        if (!buf)
            throw bad_alloc();
        const auto hr = StringCchVPrintfW(reinterpret_cast<STRSAFE_LPWSTR>(buf.get()),
                                          cchCnt,
                                          pszFormat,
                                          vaArgList);
        if (SUCCEEDED(hr)) {
            if (!WriteConsoleW(hConsoleOutput,
                               reinterpret_cast<CONST VOID *>(buf.get()),
                               static_cast<DWORD>(wcslen(buf.get())),
                               nullptr,
                               nullptr))
                throw rrwindows::system_error_exception("WriteConsoleW failed", GetLastError());
            return;
        }
        if (hr != STRSAFE_E_INSUFFICIENT_BUFFER)
            throw rrwindows::system_error_exception("StringCchVPrintfW failed", HRESULT_CODE(hr));
    }
}

}

namespace rrwindows {

RRWINDOWS_API void RRWINDOWS_CALLV printf(const char *format, ...)
{
    CONST HANDLE hStdOut {GetStdHandle(STD_OUTPUT_HANDLE)};
    if (hStdOut == INVALID_HANDLE_VALUE)
        throw system_error_exception("GetStdHandle failed", GetLastError());
    va_list va;
    va_start(va, format);
    try {
        vcprintf(hStdOut, format, va);
    } catch (...) {
        va_end(va);
        throw;
    }
    va_end(va);
}

RRWINDOWS_API void RRWINDOWS_CALLV printf(const wchar_t *format, ...)
{
    CONST HANDLE hStdOut {GetStdHandle(STD_OUTPUT_HANDLE)};
    if (hStdOut == INVALID_HANDLE_VALUE)
        throw system_error_exception("GetStdHandle failed", GetLastError());
    va_list va;
    va_start(va, format);
    try {
        vcprintf(hStdOut, format, va);
    } catch (...) {
        va_end(va);
        throw;
    }
    va_end(va);
}

RRWINDOWS_API void RRWINDOWS_CALLV eprintf(const char *format, ...)
{
    CONST HANDLE hStdErr = GetStdHandle(STD_ERROR_HANDLE);
    if (hStdErr == INVALID_HANDLE_VALUE)
        throw system_error_exception("GetStdHandle failed", GetLastError());
    va_list va;
    va_start(va, format);
    try {
        vcprintf(hStdErr, format, va);
    } catch (...) {
        va_end(va);
        throw;
    }
    va_end(va);
}

RRWINDOWS_API void RRWINDOWS_CALLV eprintf(const wchar_t *format, ...)
{
    CONST HANDLE hStdErr = GetStdHandle(STD_ERROR_HANDLE);
    if (hStdErr == INVALID_HANDLE_VALUE)
        throw system_error_exception("GetStdHandle failed", GetLastError());
    va_list va;
    va_start(va, format);
    try {
        vcprintf(hStdErr, format, va);
    } catch (...) {
        va_end(va);
        throw;
    }
    va_end(va);
}

}

namespace {

/// \brief 清空控制台屏幕。
/// \param hConsoleOutput 控制台句柄。
void clear_console_screen(HANDLE hConsoleOutput)
{
    CONSOLE_SCREEN_BUFFER_INFO stInfo;
    if (!GetConsoleScreenBufferInfo(hConsoleOutput, &stInfo))
        throw rrwindows::system_error_exception("GetConsoleScreenBufferInfo failed", GetLastError());

    const DWORD dwSize {static_cast<DWORD>(stInfo.dwSize.X * stInfo.dwSize.Y)};
    const COORD stCoord {0, 0};
    DWORD dwCharsWritten;
    if (!FillConsoleOutputCharacterW(hConsoleOutput, L' ', dwSize, stCoord, &dwCharsWritten))
        throw rrwindows::system_error_exception("FillConsoleOutputCharacterW failed", GetLastError());
    if (!FillConsoleOutputAttribute(hConsoleOutput, stInfo.wAttributes, dwSize, stCoord, &dwCharsWritten))
        throw rrwindows::system_error_exception("FillConsoleOutputAttribute failed", GetLastError());
    if (!SetConsoleCursorPosition(hConsoleOutput, stCoord))
        throw rrwindows::system_error_exception("SetConsoleCursorPosition failed", GetLastError());
}

}

namespace rrwindows {

RRWINDOWS_API void RRWINDOWS_CALL clear_stdout_screen()
{
    CONST HANDLE hStdOut {GetStdHandle(STD_OUTPUT_HANDLE)};
    if (hStdOut == INVALID_HANDLE_VALUE)
        throw system_error_exception("GetStdHandle failed", GetLastError());
    return clear_console_screen(hStdOut);
}

RRWINDOWS_API void RRWINDOWS_CALL clear_stderr_screen()
{
    CONST HANDLE hStdErr = GetStdHandle(STD_ERROR_HANDLE);
    if (hStdErr == INVALID_HANDLE_VALUE)
        throw system_error_exception("GetStdHandle failed", GetLastError());
    return clear_console_screen(hStdErr);
}

}
