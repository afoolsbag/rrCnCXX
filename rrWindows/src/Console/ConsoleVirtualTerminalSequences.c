/** \copyright Unlicense */

#define RRWINDOWS_EXPORTS
#include "rrwindows/Console/ConsoleVirtualTerminalSequences.h"

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
EnableVirtualTerminalMode(VOID)
{
    DWORD mode;

    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput)
        return FALSE;
    if (!GetConsoleMode(stdOutput, &mode))
        return FALSE;
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(stdOutput, mode))
        return FALSE;

    HANDLE CONST stdError = GetStdHandle(STD_ERROR_HANDLE);
    if (INVALID_HANDLE_VALUE == stdError)
        return FALSE;
    if (!GetConsoleMode(stdError, &mode))
        return FALSE;
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(stdError, mode))
        return FALSE;

    return TRUE;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
DisableVirtualTerminalMode(VOID)
{
    DWORD mode;

    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput)
        return FALSE;
    if (!GetConsoleMode(stdOutput, &mode))
        return FALSE;
    mode &= ~(DWORD)ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(stdOutput, mode))
        return FALSE;

    HANDLE CONST stdError = GetStdHandle(STD_ERROR_HANDLE);
    if (INVALID_HANDLE_VALUE == stdError)
        return FALSE;
    if (!GetConsoleMode(stdError, &mode))
        return FALSE;
    mode &= ~(DWORD)ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(stdError, mode))
        return FALSE;

    return TRUE;
}
