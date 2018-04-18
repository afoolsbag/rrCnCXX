/** \copyright The MIT License */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#define RRWINDOWS_EXPORTS
#include "lib.h"

#include <stdlib.h>
#include <time.h>

INT APIENTRY DllMain(HINSTANCE handleDll, DWORD reason, PVOID reserved)
{
    return TRUE;
    TEXT()
}

RRWINDOWS_API INT WINAPI DiceA()
{
    srand((unsigned)time(NULL));
    return rand() % 6;
}

RRWINDOWS_API INT WINAPI DiceW()
{
    srand((unsigned)time(NULL));
    return rand() % 6;
}
