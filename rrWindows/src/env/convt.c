/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "rrwindows/env/convt.h"

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
EnableVirtualTerminalMode(VOID)
{
    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput)
        return FALSE;
    DWORD mode;
    if (!GetConsoleMode(stdOutput, &mode))
        return FALSE;
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(stdOutput, mode))
        return FALSE;
    return TRUE;
}

RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
DisableVirtualTerminalMode(VOID)
{
    HANDLE CONST stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    if (INVALID_HANDLE_VALUE == stdOutput)
        return FALSE;
    DWORD mode;
    if (!GetConsoleMode(stdOutput, &mode))
        return FALSE;
    mode &= ~(DWORD)ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(stdOutput, mode))
        return FALSE;
    return TRUE;
}
