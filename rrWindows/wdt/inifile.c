/**
 * \copyright Unlicense
 */

#include "inifile.h"

#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")

#include "rrWindows/rrWindows.h"

#include "eventlog.h"

VOID WINAPI AllocBones(Bones *pBones)
{
    TCHAR path[MAX_PATH];
    GetModuleFileName(NULL, path, countof(path));
    PathRenameExtension(path, _T(".ini"));

    CONST INT count = GetPrivateProfileInt(_T("Index"), _T("Count"), 0, path);

    pBones->Count = count;
    pBones->Data = HeapAllocS(count * sizeof(Bone));

    for (int i = 0; i < count; ++i)
    {
        TCHAR section[50];
        StringCchPrintf(section, countof(section), _T("Item%d"), i + 1);

        TCHAR tmp[MAX_PATH];
        size_t cnt = 0;

        Bone *ref = pBones->Data + i;
        ref->IsValid = TRUE;

        /* read from ini */
        ref->IsService = GetPrivateProfileInt(section, _T("IsService"), FALSE, path);

        GetPrivateProfileString(section, _T("Name"), NULL, tmp, countof(tmp), path);
        cnt = StringCchLengthS(tmp);
        if (cnt) {
            ref->Name = HeapAllocS(++cnt * sizeof(TCHAR));
            StringCchCopy(ref->Name, cnt, tmp);
        } else {
            ref->Name = NULL;
            ref->IsValid = FALSE;
            EventLogReadItemFailed(section, _T("missing Name."));
        }

        GetPrivateProfileString(section, _T("Path"), NULL, tmp, countof(tmp), path);
        cnt = StringCchLengthS(tmp);
        if (cnt) {
            ref->Path = HeapAllocS(++cnt * sizeof(TCHAR));
            StringCchCopy(ref->Path, cnt, tmp);
        } else {
            ref->Path = NULL;
            if (!ref->IsService) {
                ref->IsValid = FALSE;
                EventLogReadItemFailed(section, _T("missing Path when isn't service."));
            }
        }

        GetPrivateProfileString(section, _T("Args"), NULL, tmp, countof(tmp), path);
        cnt = StringCchLengthS(tmp);
        if (cnt) {
            ref->Args = HeapAllocS(++cnt * sizeof(TCHAR));
            StringCchCopy(ref->Args, cnt, tmp);
        } else {
            ref->Args = NULL;
        }

        GetPrivateProfileString(section, _T("StartIn"), NULL, tmp, countof(tmp), path);
        cnt = StringCchLengthS(tmp);
        if (cnt) {
            ref->StartIn = HeapAllocS(++cnt * sizeof(TCHAR));
            StringCchCopy(ref->Args, cnt, tmp);
        } else {
            ref->StartIn = NULL;
        }

        ref->RetryInterval.QuadPart =
            GetPrivateProfileInt(section, _T("RetryInterval"), 60, path) * TimeOneSecond.QuadPart;

        ref->EnableKillPerDay = GetPrivateProfileInt(section, _T("EnableKillPerDay"), FALSE, path);
        ref->KillPerDayHour = GetPrivateProfileInt(section, _T("KillPerDayHour"), 0, path);
        ref->KillPerDayMinute = GetPrivateProfileInt(section, _T("KillPerDayMinute"), 0, path);
        ref->KillPerDaySecond = GetPrivateProfileInt(section, _T("KillPerDaySecond"), 0, path);
        if (ref->EnableKillPerDay) {
            if (0 <= ref->KillPerDayHour && ref->KillPerDayHour <= 23 &&
                0 <= ref->KillPerDayMinute && ref->KillPerDayMinute <= 59 &&
                0 <= ref->KillPerDaySecond && ref->KillPerDaySecond <= 59) {

                SYSTEMTIME currentTime;
                GetLocalTime(&currentTime);

                GetLocalTime(&ref->NextKillAt);
                ref->NextKillAt.wHour = (WORD)ref->KillPerDayHour;
                ref->NextKillAt.wMinute = (WORD)ref->KillPerDayMinute;
                ref->NextKillAt.wSecond = (WORD)ref->KillPerDaySecond;

                while (TimeCompare(&ref->NextKillAt, &currentTime) == TIME_LESS_THAN)
                    TimeAdd(&ref->NextKillAt, &TimeOneDay);

            } else {
                ref->IsValid = FALSE;
                EventLogReadItemFailed(section, _T("invalid time when KillPerDay enabled, the range is [0, 23], [0, 59] & [0, 59]."));
            }
        }

        CONST FILETIME initTime = {0};
        FileTimeToSystemTime(&initTime, &ref->LastTryAt);
    }
}

VOID WINAPI FreeBones(Bones *pBones)
{
    for (int i = 0; i < pBones->Count; ++i)
    {
        Bone *ref = pBones->Data +i;

        if (ref->Name)
            HeapFreeS(ref->Name);
        if (ref->Path)
            HeapFreeS(ref->Path);
        if (ref->Args)
            HeapFreeS(ref->Args);
        if (ref->StartIn)
            HeapFreeS(ref->StartIn);
    }
    HeapFreeS(pBones->Data);
}
