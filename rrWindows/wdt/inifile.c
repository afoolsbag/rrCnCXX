/**
 * \copyright Unlicense
 */

#include "inifile.h"

#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")

#include "rrWindows/rrWindows.h"

PBones WINAPI AllocBones(VOID)
{
    TCHAR path[MAX_PATH];
    GetModuleFileName(NULL, path, countof(path));
    PathRenameExtension(path, _T(".ini"));

    CONST INT count = GetPrivateProfileInt(_T("Index"), _T("Count"), 0, path);

    CONST PBones bones = HeapAllocS(sizeof(Bones));
    bones->Count = count;
    bones->Data = HeapAllocS(count * sizeof(Bone));

    for (int i = 0; i < count; ++i)
    {
        TCHAR section[10];
        StringCchPrintf(section, countof(section), _T("Item%d"), i + 1);

        TCHAR tmp[MAX_PATH];
        size_t cnt = 0;

        GetPrivateProfileString(section, _T("ExeName"), NULL, tmp, countof(tmp), path);
        cnt = StringCchLengthS(tmp) + 1;
        bones->Data[i].ExeName = HeapAllocS(cnt * sizeof(TCHAR));
        StringCchCopy(bones->Data[i].ExeName, cnt, tmp);

        GetPrivateProfileString(section, _T("ExePath"), NULL, tmp, countof(tmp), path);
        cnt = StringCchLengthS(tmp) + 1;
        bones->Data[i].ExePath = HeapAllocS(cnt * sizeof(TCHAR));
        StringCchCopy(bones->Data[i].ExePath, cnt, tmp);

        GetPrivateProfileString(section, _T("ExeArgs"), NULL, tmp, countof(tmp), path);
        cnt = StringCchLengthS(tmp) + 1;
        if (1 < cnt) {
            bones->Data[i].ExeArgs = HeapAllocS(cnt * sizeof(TCHAR));
            StringCchCopy(bones->Data[i].ExeArgs, cnt, tmp);
        } else {
            bones->Data[i].ExeArgs = NULL;
        }

        GetPrivateProfileString(section, _T("ExeStartIn"), NULL, tmp, countof(tmp), path);
        cnt = StringCchLengthS(tmp) + 1;
        if (1 < cnt) {
            bones->Data[i].ExeStartIn = HeapAllocS(cnt * sizeof(TCHAR));
            StringCchCopy(bones->Data[i].ExeStartIn, cnt, tmp);
        } else {
            bones->Data[i].ExeStartIn = NULL;
        }

        bones->Data[i].ExeShow = GetPrivateProfileInt(section, _T("ExeShow"), FALSE, path);

        bones->Data[i].RetryInterval.QuadPart =
            GetPrivateProfileInt(section, _T("RetryInterval"), 60, path) * TimeOneSecond.QuadPart;

        bones->Data[i].EnableKillAtTime = GetPrivateProfileInt(section, _T("EnableKillAtTime"), FALSE, path);
        bones->Data[i].KillAtHour = GetPrivateProfileInt(section, _T("KillAtHour"), 0, path);
        bones->Data[i].KillAtMinute = GetPrivateProfileInt(section, _T("KillAtMinute"), 0, path);
        bones->Data[i].KillAtSecond = GetPrivateProfileInt(section, _T("KillAtSecond"), 0, path);

        SYSTEMTIME currentTime;
        GetLocalTime(&currentTime);

        GetLocalTime(&bones->Data[i].NextKillAt);
        bones->Data[i].NextKillAt.wHour = (WORD)bones->Data[i].KillAtHour;
        bones->Data[i].NextKillAt.wMinute = (WORD)bones->Data[i].KillAtMinute;
        bones->Data[i].NextKillAt.wSecond = (WORD)bones->Data[i].KillAtSecond;

        while (TimeCompare(&bones->Data[i].NextKillAt, &currentTime) == TIME_LESS_THAN)
            TimeAdd(&bones->Data[i].NextKillAt, &TimeOneDay);

        FILETIME initTime = {0};
        FileTimeToSystemTime(&initTime, &bones->Data[i].LastTryAt);
    }

    return bones;
}

VOID WINAPI FreeBones(Bones *pBones)
{
    for (int i = 0; i < pBones->Count; ++i)
    {
        if (pBones->Data[i].ExeName)
            HeapFreeS(pBones->Data[i].ExeName);
        if (pBones->Data[i].ExePath)
            HeapFreeS(pBones->Data[i].ExePath);
        if (pBones->Data[i].ExeArgs)
            HeapFreeS(pBones->Data[i].ExeArgs);
        if (pBones->Data[i].ExeStartIn)
            HeapFreeS(pBones->Data[i].ExeStartIn);
    }
    HeapFreeS(pBones->Data);
    HeapFreeS(pBones);
}
