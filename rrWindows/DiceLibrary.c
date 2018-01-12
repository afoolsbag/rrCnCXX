/** \copyright The MIT License */

#include <windows.h>

#include "DiceLibrary.h"

#include <time.h>

INT WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, PVOID pvReserved)
{
        return TRUE;
}

EXPORT INT CALLBACK DiceA()
{
        srand((unsigned) time(NULL));
        return rand() % 6;
}

EXPORT INT CALLBACK DiceW()
{
        srand((unsigned) time(NULL));
        return rand() % 6;
}
