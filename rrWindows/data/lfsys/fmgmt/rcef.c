/*===-- Regularly Clearup Expired Files ------------------------*- C -*-===*//**
 *
 * \file
 * \brief 定时清理过期文件。
 * \version 2018-04-18
 * \date 2018-01-15
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>

#include <tchar.h>
#include <Windows.h>

/**
 * \brief 计算当日等价的秒数。
 */
INT DayToSeconds(CONST SYSTEMTIME *CONST day)
{
    return (day->wHour * 60 + day->wMinute) * 60 + day->wSecond;
}

/**
 * \brief 计算多日等价的100ns数。
 */
ULONGLONG DaysTo100ns(CONST SYSTEMTIME *CONST days)
{
    return (((days->wDay * 24LL + days->wHour) * 60LL + days->wMinute) * 60LL + days->wSecond) * 1000LL * 1000LL * 10LL;
}

/**
 * \brief 计算100ns等价的小时数。
 */
DOUBLE Ns100ToHours(CONST ULONGLONG Ns100)
{
    CONST ULONGLONG secs = Ns100 / 10LL / 1000LL / 1000LL;
    return (DOUBLE)secs / 60. / 60.;
}

/**
 * \brief 获取配置文件路径。
 */
static VOID GetIniPath(TCHAR *CONST iniPath, CONST size_t iniPathCount)
{
    TCHAR appPath[_MAX_PATH];
    TCHAR appDrive[_MAX_DRIVE];
    TCHAR appDir[_MAX_DIR];
    TCHAR appName[_MAX_FNAME];
    TCHAR appExt[_MAX_EXT];
    SecureZeroMemory(appPath, sizeof appPath);
    SecureZeroMemory(appDrive, sizeof appDrive);
    SecureZeroMemory(appDir, sizeof appDir);
    SecureZeroMemory(appName, sizeof appName);
    SecureZeroMemory(appExt, sizeof appExt);

    GetModuleFileName(NULL, appPath, _MAX_PATH);
    _tsplitpath_s(appPath, appDrive, _MAX_DRIVE, appDir, _MAX_DIR, appName, _MAX_FNAME, appExt, _MAX_EXT);
    _stprintf_s(iniPath, iniPathCount, "%s%srcef.ini", appDrive, appDir);
}

/**
 * \brief 读、写配置文件函数的参数结构体类型。
 */
struct IniStruct {
    SYSTEMTIME ClearupCycle;                /**< 清理周期（仅使用部分字段，不适用SystemTimeToFileTime）。 */
    DWORD      IdleWakeCycle;               /**< 闲置唤醒周期（ms）。 */
    SYSTEMTIME NoConsumeClockStart;         /**< 无消耗时段开始时刻。 */
    SYSTEMTIME NoConsumeClockEnd;           /**< 无消耗时段结束时刻。 */
    TCHAR      TargetFolderPath[MAX_PATH];  /**< 目标路径。 */
    BOOL       Recurse;                     /**< 递归处理。 */
    SYSTEMTIME ShelfLife;                   /**< 保质期（仅使用部分字段，不适用SystemTimeToFileTime）。 */
    DWORD      DeletePostDelay;             /**< 删除后置时延（ms）。 */
};

/**
 * \brief 读取配置文件。
 */
static VOID ReadIniFromFile(struct IniStruct *CONST ini)
{
    TCHAR iniPath[MAX_PATH];
    TCHAR tmpBuf[256];
    UINT  tmpDays = 0;
    UINT  tmpHours = 0;
    UINT  tmpMinutes = 0;
    UINT  tmpSeconds = 0;
    UINT  tmpUint = 0;
    DWORD fileAttr = 0;
    SecureZeroMemory(iniPath, sizeof iniPath);
    SecureZeroMemory(tmpBuf, sizeof tmpBuf);

    GetIniPath(iniPath, _countof(iniPath));

    GetPrivateProfileString(_T("RCEF"), _T("ClearupCycle"), _T("0d6h0m0s"), tmpBuf, _countof(tmpBuf), iniPath);
    _stscanf_s(tmpBuf, _T(" %ud %uh %um %us "), &tmpDays, &tmpHours, &tmpMinutes, &tmpSeconds);
    ini->ClearupCycle.wYear = 0;
    ini->ClearupCycle.wMonth = 0;
    ini->ClearupCycle.wDayOfWeek = 0;
    ini->ClearupCycle.wDay = min(max(0, tmpDays), 365);
    ini->ClearupCycle.wHour = min(max(0, tmpHours), 7 * 24);
    ini->ClearupCycle.wMinute = min(max(0, tmpMinutes), 24 * 60);
    ini->ClearupCycle.wSecond = min(max(0, tmpSeconds), 60 * 60);
    ini->ClearupCycle.wMilliseconds = 0;

    GetPrivateProfileString(_T("RCEF"), _T("IdleWakeCycle"), _T("60000ms"), tmpBuf, _countof(tmpBuf), iniPath);
    _stscanf_s(tmpBuf, _T(" %lums "), &tmpUint);
    ini->IdleWakeCycle = min(max(0, tmpUint), 5 * 60 * 1000);

    GetPrivateProfileString(_T("RCEF"), _T("NoConsumeClockStart"), _T("00:00:00"), tmpBuf, _countof(tmpBuf), iniPath);
    _stscanf_s(tmpBuf, _T(" %u:%u:%u "), &tmpHours, &tmpMinutes, &tmpSeconds);
    ini->NoConsumeClockStart.wYear = 1601;
    ini->NoConsumeClockStart.wMonth = 1;
    ini->NoConsumeClockStart.wDayOfWeek = 0;
    ini->NoConsumeClockStart.wDay = 1;
    ini->NoConsumeClockStart.wHour = min(max(0, tmpHours), 23);
    ini->NoConsumeClockStart.wMinute = min(max(0, tmpMinutes), 59);
    ini->NoConsumeClockStart.wSecond = min(max(0, tmpSeconds), 59);
    ini->NoConsumeClockStart.wMilliseconds = 0;

    GetPrivateProfileString(_T("RCEF"), _T("NoConsumeClockEnd"), _T("00:00:00"), tmpBuf, _countof(tmpBuf), iniPath);
    _stscanf_s(tmpBuf, _T(" %u:%u:%u "), &tmpHours, &tmpMinutes, &tmpSeconds);
    ini->NoConsumeClockEnd.wYear = 1601;
    ini->NoConsumeClockEnd.wMonth = 1;
    ini->NoConsumeClockEnd.wDayOfWeek = 0;
    ini->NoConsumeClockEnd.wDay = 1;
    ini->NoConsumeClockEnd.wHour = min(max(0, tmpHours), 23);
    ini->NoConsumeClockEnd.wMinute = min(max(0, tmpMinutes), 59);
    ini->NoConsumeClockEnd.wSecond = min(max(0, tmpSeconds), 59);
    ini->NoConsumeClockEnd.wMilliseconds = 0;

    GetPrivateProfileString(_T("RCEF"), _T("TargetFolderPath"), _T("C:\\path\\to\\example_folder"), ini->TargetFolderPath, _countof(ini->TargetFolderPath), iniPath);
    fileAttr = GetFileAttributes(ini->TargetFolderPath);

    GetPrivateProfileString(_T("RCEF"), _T("Recurse"), _T("ON"), tmpBuf, _countof(tmpBuf), iniPath);
    ini->Recurse = !_tcscmp(tmpBuf, _T("ON")) || !_tcscmp(tmpBuf, _T("TRUE")) || !_tcscmp(tmpBuf, _T("YES")) || !_tcscmp(tmpBuf, _T("1")) ? TRUE : FALSE;

    GetPrivateProfileString(_T("RCEF"), _T("ShelfLife"), _T("7d0h0m0s"), tmpBuf, _countof(tmpBuf), iniPath);
    _stscanf_s(tmpBuf, _T(" %ud %uh %um %us "), &tmpDays, &tmpHours, &tmpMinutes, &tmpSeconds);
    ini->ShelfLife.wYear = 0;
    ini->ShelfLife.wMonth = 0;
    ini->ShelfLife.wDayOfWeek = 0;
    ini->ShelfLife.wDay = min(max(0, tmpDays), 365);
    ini->ShelfLife.wHour = min(max(0, tmpHours), 7 * 24);
    ini->ShelfLife.wMinute = min(max(0, tmpMinutes), 24 * 60);
    ini->ShelfLife.wSecond = min(max(0, tmpSeconds), 60 * 60);
    ini->ShelfLife.wMilliseconds = 0;

    GetPrivateProfileString(_T("RCEF"), _T("DeletePostDelay"), _T("350ms"), tmpBuf, _countof(tmpBuf), iniPath);
    _stscanf_s(tmpBuf, _T(" %lums "), &tmpUint);
    ini->DeletePostDelay = min(max(0, tmpUint), 20 * 1000);
}

/**
 * \brief 写入配置文件。
 */
static VOID WriteIniToFile(CONST struct IniStruct *CONST ini)
{
    TCHAR iniPath[MAX_PATH];
    TCHAR tmpBuf[256];
    SecureZeroMemory(iniPath, sizeof iniPath);
    SecureZeroMemory(tmpBuf, sizeof tmpBuf);

    GetIniPath(iniPath, _countof(iniPath));

    _stprintf_s(tmpBuf, _countof(tmpBuf), _T("%ud %uh %um %us"), ini->ClearupCycle.wDay, ini->ClearupCycle.wHour, ini->ClearupCycle.wMinute, ini->ClearupCycle.wSecond);
    WritePrivateProfileString(_T("RCEF"), _T("ClearupCycle"), tmpBuf, iniPath);

    _stprintf_s(tmpBuf, _countof(tmpBuf), _T("%lums"), ini->IdleWakeCycle);
    WritePrivateProfileString(_T("RCEF"), _T("IdleWakeCycle"), tmpBuf, iniPath);

    _stprintf_s(tmpBuf, _countof(tmpBuf), _T("%02u:%02u:%02u"), ini->NoConsumeClockStart.wHour, ini->NoConsumeClockStart.wMinute, ini->NoConsumeClockStart.wSecond);
    WritePrivateProfileString(_T("RCEF"), _T("NoConsumeClockStart"), tmpBuf, iniPath);

    _stprintf_s(tmpBuf, _countof(tmpBuf), _T("%02u:%02u:%02u"), ini->NoConsumeClockEnd.wHour, ini->NoConsumeClockEnd.wMinute, ini->NoConsumeClockEnd.wSecond);
    WritePrivateProfileString(_T("RCEF"), _T("NoConsumeClockEnd"), tmpBuf, iniPath);

    WritePrivateProfileString(_T("RCEF"), _T("TargetFolderPath"), ini->TargetFolderPath, iniPath);

    _stprintf_s(tmpBuf, _countof(tmpBuf), _T("%s"), ini->Recurse ? _T("ON") : _T("OFF"));
    WritePrivateProfileString(_T("RCEF"), _T("Recurse"), tmpBuf, iniPath);

    _stprintf_s(tmpBuf, _countof(tmpBuf), _T("%ud %uh %um %us"), ini->ShelfLife.wDay, ini->ShelfLife.wHour, ini->ShelfLife.wMinute, ini->ShelfLife.wSecond);
    WritePrivateProfileString(_T("RCEF"), _T("ShelfLife"), tmpBuf, iniPath);

    _stprintf_s(tmpBuf, _countof(tmpBuf), _T("%lums"), ini->DeletePostDelay);
    WritePrivateProfileString(_T("RCEF"), _T("DeletePostDelay"), tmpBuf, iniPath);
}

/**
 * \brief 打印配置文件。
 */
static VOID PrintIni(CONST struct IniStruct *CONST ini)
{
    _tprintf_s(_T(" ClearupCycle:        %ud %uh %um %us\n"), ini->ClearupCycle.wDay, ini->ClearupCycle.wHour, ini->ClearupCycle.wMinute, ini->ClearupCycle.wSecond);
    _tprintf_s(_T(" IdleWakeCycle:       %lums\n"), ini->IdleWakeCycle);
    _tprintf_s(_T(" NoConsumeClockStart: %02u:%02u:%02u\n"), ini->NoConsumeClockStart.wHour, ini->NoConsumeClockStart.wMinute, ini->NoConsumeClockStart.wSecond);
    _tprintf_s(_T(" NoConsumeClockEnd:   %02u:%02u:%02u\n"), ini->NoConsumeClockEnd.wHour, ini->NoConsumeClockEnd.wMinute, ini->NoConsumeClockEnd.wSecond);
    _tprintf_s(_T(" TargetFolderPath:    %s\n"), ini->TargetFolderPath);
    _tprintf_s(_T(" Recurse:             %s\n"), ini->Recurse ? _T("ON") : _T("OFF"));
    _tprintf_s(_T(" ShelfLift:           %ud %uh %um %us\n"), ini->ShelfLife.wDay, ini->ShelfLife.wHour, ini->ShelfLife.wMinute, ini->ShelfLife.wSecond);
    _tprintf_s(_T(" DeletePostDelay:     %lums\n"), ini->DeletePostDelay);
}

#// 当前时刻相关
static SYSTEMTIME     CurClkSys;      /**< 共用的当前时刻（SYSTEM） */
static FILETIME       CurClkFile;     /**< 共用的当前时刻（FILE） */
static ULARGE_INTEGER CurClk100ns;    /**< 共用的当前时刻（100ns） */
static TCHAR          CurClkStr[17];  /**< 共用的当前时刻（字串） */
/**
 * \brief 更新当前时刻相关变量。
 */
static VOID RefreshCurrentClock(VOID)
{
    GetLocalTime(&CurClkSys);
    SystemTimeToFileTime(&CurClkSys, &CurClkFile);
    CurClk100ns.LowPart = CurClkFile.dwLowDateTime;
    CurClk100ns.HighPart = CurClkFile.dwHighDateTime;
    _stprintf_s(CurClkStr, _countof(CurClkStr), _T("%04d-%02d-%02d %02d:%02d"),
                CurClkSys.wYear, CurClkSys.wMonth, CurClkSys.wDay, CurClkSys.wHour, CurClkSys.wMinute);
}

#// 统计相关
static INT ThisTimeDeleteCount;
static INT ThisTimePassCount;

/**
 * \brief 清理过期文件函数的参数结构体类型。
 */
struct ArgStruct {
    SYSTEMTIME     NoConsumeClockStart;         /**< 无消耗时段开始时刻。 */
    SYSTEMTIME     NoConsumeClockEnd;           /**< 无消耗时段结束时刻。 */
    BOOL           Recurse;                     /**< 递归处理。 */
    ULARGE_INTEGER ShelfLift100ns;              /**< 保质期（100ns）。 */
    DWORD          DeletePostDelay;             /**< 删除后置时延（ms）。 */
};

/**
 * \brief 清理过期文件。
 */
static VOID ClearupExpiredFiles(CONST TCHAR *CONST flrPath, CONST struct ArgStruct *CONST arg)
{
    TCHAR flrPathWildcard[MAX_PATH];
    TCHAR itemPath[MAX_PATH];

    HANDLE findHdl = INVALID_HANDLE_VALUE;
    WIN32_FIND_DATA findData;

    WIN32_FILE_ATTRIBUTE_DATA fileAttrs;
    FILETIME fileClkFile;
    ULARGE_INTEGER fileClk100ns;

    SecureZeroMemory(flrPathWildcard, sizeof flrPathWildcard);
    SecureZeroMemory(itemPath, sizeof itemPath);
    SecureZeroMemory(&findData, sizeof findData);
    SecureZeroMemory(&fileAttrs, sizeof fileAttrs);
    SecureZeroMemory(&fileClkFile, sizeof fileClk100ns);
    SecureZeroMemory(&fileClk100ns, sizeof fileClk100ns);

    RefreshCurrentClock();
    if (DayToSeconds(&arg->NoConsumeClockStart) < DayToSeconds(&arg->NoConsumeClockEnd)) {
        if (DayToSeconds(&arg->NoConsumeClockStart) < DayToSeconds(&CurClkSys) && DayToSeconds(&CurClkSys) < DayToSeconds(&arg->NoConsumeClockEnd)) {
            _tprintf_s(_T("%s At no consume clock, skip this.\n"), CurClkStr);
            return;
        }
    }
    if (DayToSeconds(&arg->NoConsumeClockStart) > DayToSeconds(&arg->NoConsumeClockEnd)) {
        if (DayToSeconds(&arg->NoConsumeClockStart) < DayToSeconds(&CurClkSys) || DayToSeconds(&CurClkSys) < DayToSeconds(&arg->NoConsumeClockEnd)) {
            _tprintf_s(_T("%s At no consume clock, skip this.\n"), CurClkStr);
            return;
        }
    }

    if (_tcscpy_s(flrPathWildcard, _countof(flrPathWildcard), flrPath)) {
        _tprintf_s(_T("%s FolderPath too long: %s.\n"), CurClkStr, flrPath);
        return;
    }
    if (_tcscat_s(flrPathWildcard, _countof(flrPathWildcard), _T("\\*"))) {
        _tprintf_s(_T("%s FolderPath\\* too long: %s\\*.\n"), CurClkStr, flrPath);
        return;
    }

    if ((findHdl = FindFirstFile(flrPathWildcard, &findData)) == INVALID_HANDLE_VALUE) {
        if (GetLastError() == ERROR_NO_MORE_FILES) {
            FindClose(findHdl);
            return;
        } else {
            _tprintf_s(_T("%s FindFirstFile faild with code %lu and %s.\n"), CurClkStr, GetLastError(), flrPathWildcard);
            return;
        }
    }
    _tprintf_s(_T("%s In folder %s:\n"), CurClkStr, flrPath);

    do {
        if (_tcscpy_s(itemPath, _countof(itemPath), flrPath)) {
            _tprintf_s(_T("%s FolderPath too long: %s.\n"), CurClkStr, flrPath);
            return;
        }
        if (_tcscat_s(itemPath, _countof(itemPath), _T("\\"))) {
            _tprintf_s(_T("%s FolderPath\\ too long: %s\\.\n"), CurClkStr, flrPath);
            return;
        }
        if (_tcscat_s(itemPath, _countof(itemPath), findData.cFileName)) {
            _tprintf_s(_T("%s FolderPath\\ItemName too long: %s\\%s.\n"), CurClkStr, flrPath, findData.cFileName);
            return;
        }
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (_tcscmp(findData.cFileName, _T(".")) && _tcscmp(findData.cFileName, _T("..")) && arg->Recurse)
                ClearupExpiredFiles(itemPath, arg);
        } else {
            GetFileAttributesEx(itemPath, GetFileExInfoStandard, &fileAttrs);
            FileTimeToLocalFileTime(&fileAttrs.ftCreationTime, &fileClkFile);
            fileClk100ns.LowPart = fileClkFile.dwLowDateTime;
            fileClk100ns.HighPart = fileClkFile.dwHighDateTime;
            if (arg->ShelfLift100ns.QuadPart < CurClk100ns.QuadPart - fileClk100ns.QuadPart) {
                if (DeleteFile(itemPath)) {
                    _tprintf_s(_T("%s Delete %s.\n"), CurClkStr, itemPath);
                    ++ThisTimeDeleteCount;
                } else {
                    _tprintf_s(_T("%s Delete failed with code %lu and %s.\n"), CurClkStr, GetLastError(), itemPath);
                }
                if (arg->DeletePostDelay)
                    Sleep(arg->DeletePostDelay);
            } else {
                _tprintf_s(_T("%s Pass %s.\n"), CurClkStr, itemPath);
                ++ThisTimePassCount;
            }
        }
    } while (FindNextFile(findHdl, &findData));

    if (GetLastError() != ERROR_NO_MORE_FILES)
        _tprintf_s(_T("%s FindFirstFile faild with %lu and %s.\n"), CurClkStr, GetLastError(), flrPathWildcard);

    FindClose(findHdl);
    _tprintf_s(_T("%s Out folder %s.\n"), CurClkStr, flrPath);
}

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    struct IniStruct ini;
    struct ArgStruct arg;
    ULARGE_INTEGER lastClk100ns;
    HANDLE hMutex = INVALID_HANDLE_VALUE;
    SecureZeroMemory(&ini, sizeof ini);
    SecureZeroMemory(&arg, sizeof arg);
    SecureZeroMemory(&lastClk100ns, sizeof lastClk100ns);

    hMutex = OpenMutex(MUTEX_ALL_ACCESS, 0, "RegularlyClearupExpiredFiles");
    if (!hMutex)
        hMutex = CreateMutex(0, 0, "RegularlyClearupExpiredFiles");
    else
        return EXIT_SUCCESS;

    ReadIniFromFile(&ini);
    WriteIniToFile(&ini);
    memcpy_s(&arg.NoConsumeClockStart, sizeof arg.NoConsumeClockStart, &ini.NoConsumeClockStart, sizeof ini.NoConsumeClockStart);
    memcpy_s(&arg.NoConsumeClockEnd, sizeof arg.NoConsumeClockEnd, &ini.NoConsumeClockEnd, sizeof ini.NoConsumeClockEnd);
    arg.Recurse = ini.Recurse;
    arg.ShelfLift100ns.QuadPart = DaysTo100ns(&ini.ShelfLife);
    arg.DeletePostDelay = ini.DeletePostDelay;

    for (;;) {

        RefreshCurrentClock();

        if (CurClk100ns.QuadPart - lastClk100ns.QuadPart < DaysTo100ns(&ini.ClearupCycle)) {
            _tprintf_s(_T("%s The next clearup at %.2lf hour(s) later.\n"), CurClkStr, Ns100ToHours(DaysTo100ns(&ini.ClearupCycle) - (CurClk100ns.QuadPart - lastClk100ns.QuadPart)));
            _tprintf_s(_T("\n"));
            Sleep(ini.IdleWakeCycle);
            continue;
        }

        _tprintf_s(_T("%s Start clearup:\n"), CurClkStr);
        PrintIni(&ini);

        ThisTimePassCount = 0;
        ThisTimeDeleteCount = 0;
        ClearupExpiredFiles(ini.TargetFolderPath, &arg);
        lastClk100ns.QuadPart = CurClk100ns.QuadPart;
        _tprintf_s(TEXT("%s This time delete %d item(s), pass %d item(s).\n"), CurClkStr, ThisTimeDeleteCount, ThisTimePassCount);
    };

    return EXIT_SUCCESS;
}
