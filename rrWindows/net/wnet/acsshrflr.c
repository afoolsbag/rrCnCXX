/*===-- Access Shared Folder -----------------------------------*- C -*-===*//**
 *
 * \defgroup gAcsShrFlr 访问共享文件夹
 * \ingroup gWnet
 *
 * \version 2018-04-19
 * \since 2018-02-23
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdlib.h>
#include <shellapi.h>
#include <tchar.h>

#pragma comment(lib, "Mpr.Lib")

/**
 * \brief 打开共享文件夹（权限）。
 *
 * \param sharedFolderPath 共享文件夹路径。
 * \param username         用户名。
 * \param password         密码。
 * \returns 错误码。
 *
 * \sa ["NETRESOURCE structure"](https://msdn.microsoft.com/library/aa385353). *Microsoft® Developer Network*.
 * \sa ["WNetAddConnection2 function"](https://msdn.microsoft.com/library/aa385413). *Microsoft® Developer Network*.
 */
_Success_(return == NOERROR)
static DWORD
OpenSharedFolder(
    _In_z_ CONST PCTSTR sharedFolderPath,
    _In_z_ CONST PCTSTR username,
    _In_z_ CONST PCTSTR password)
{
    if (MAX_PATH < _tcslen(sharedFolderPath) + 1)
        return CO_E_PATHTOOLONG;

    TCHAR sharedFolderPathZ[MAX_PATH];
    _tcscpy_s(sharedFolderPathZ, _countof(sharedFolderPathZ), sharedFolderPath);

    NETRESOURCE netRes;
    SecureZeroMemory(&netRes, sizeof(netRes));
    netRes.dwType = RESOURCETYPE_DISK;
    netRes.lpLocalName = NULL;
    netRes.lpRemoteName = sharedFolderPathZ;
    netRes.lpProvider = NULL;
    return WNetAddConnection2(&netRes, password, username, CONNECT_TEMPORARY);
}

/**
 * \brief 关闭共享文件夹（权限）。
 * \warning 该操作将强制关闭链接，不论链接是否正在被使用。
 *
 * \param sharedFolderPath 共享文件夹路径。
 * \returns 错误码。
 *
 * \sa ["WNetCancelConnection2 function"](https://msdn.microsoft.com/library/aa385427). *Microsoft® Developer Network*.
 */
_Success_(return == NOERROR)
static DWORD
CloseSharedFolder(
    _In_z_ CONST PCTSTR sharedFolderPath)
{
    return WNetCancelConnection2(sharedFolderPath, 0, TRUE);
}

/**
 * \brief 复制文件到共享文件夹。
 * \warning 此操作将关闭共享文件夹。
 *
 * \param filePath         文件（全）路径。
 * \param sharedFolderPath 共享文件夹（全）路径。
 * \param username         用户名。
 * \param password         密码。
 * \return 错误码。
 *
 * \sa ["SHFILEOPSTRUCT structure"](https://msdn.microsoft.com/library/bb759795). *Microsoft® Developer Network*.
 * \sa ["SHFileOperation function"](https://msdn.microsoft.com/library/bb762164). *Microsoft® Developer Network*.
 */
_Success_(return == NOERROR)
static DWORD
CopyFileToSharedFolder(
    _In_z_ CONST PCTSTR filePath,
    _In_z_ CONST PCTSTR sharedFolderPath,
    _In_z_ CONST PCTSTR username,
    _In_z_ CONST PCTSTR password)
{
    DWORD winErrNo = NOERROR;

    // Check path length for double NULL
    if (MAX_PATH < _tcslen(filePath) + 2 || MAX_PATH < _tcslen(sharedFolderPath) + 2)
        return CO_E_PATHTOOLONG;

    // Add connection
    if ((winErrNo = OpenSharedFolder(sharedFolderPath, username, password)) != NOERROR)
        return winErrNo;

    // Copy file
    TCHAR filePathZz[MAX_PATH];
    _tcscpy_s(filePathZz, _countof(filePathZz), filePath);
    filePathZz[_tcslen(filePath) + 1] = _T('\0');

    TCHAR sharedFolderPathZz[MAX_PATH];
    _tcscpy_s(sharedFolderPathZz, _countof(sharedFolderPathZz), sharedFolderPath);
    sharedFolderPathZz[_tcslen(sharedFolderPath) + 1] = _T('\0');

    SHFILEOPSTRUCT shFOp;
    SecureZeroMemory(&shFOp, sizeof(shFOp));
    shFOp.wFunc = FO_COPY;
    shFOp.pFrom = filePathZz;
    shFOp.pTo = sharedFolderPathZz;
    shFOp.fFlags = FOF_NO_UI;
    SHFileOperation(&shFOp);

    // Cancel connection
    winErrNo = CloseSharedFolder(sharedFolderPath);

    return winErrNo;
}

/** @} */

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    CopyFileToSharedFolder(
        _T("C:\\path\\to\\file.ext"),
        _T("\\\\192.168.0.1\\path\\to\\folder"),
        _T("username"),
        _T("password"));
}
