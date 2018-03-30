/*===-- Access Shared Folder -----------------------------------*- C -*-===*//**
 *
 * \defgroup g_acs_shr_flr 访问共享文件夹
 * \ingroup g_wnet
 *
 * \version 2018-03-29
 * \since 2018-02-23
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <Windows.h>

#include <shellapi.h>

#pragma comment(lib, "Mpr.Lib")

/**
 * \brief 复制文件到共享文件夹
 *
 * \param filepath   文件（全）路径
 * \param shrflrpath 共享文件夹（全）路径
 * \param usr        账号
 * \param pwd        口令
 * \return 成功与否
 *
 * \sa ["NETRESOURCE structure"](https://msdn.microsoft.com/library/aa385353). *Microsoft® Developer Network*.
 * \sa ["WNetAddConnection2 function"](https://msdn.microsoft.com/library/aa385413). *Microsoft® Developer Network*.
 * \sa ["WNetCancelConnection2 function"](https://msdn.microsoft.com/library/aa385427). *Microsoft® Developer Network*.
 *
 * \sa ["SHFILEOPSTRUCT structure"](https://msdn.microsoft.com/library/bb759795). *Microsoft® Developer Network*.
 * \sa ["SHFileOperation function"](https://msdn.microsoft.com/library/bb762164). *Microsoft® Developer Network*.
 */
static BOOL copy_file_to_shared_folder(PCTSTR CONST filepath, PCTSTR CONST shrflrpath, PCTSTR CONST usr, PCTSTR CONST pwd)
{
    // 检查输入
    if (MAX_PATH - 2/*double `NULL`*/ <= _tcslen(filepath) ||
        MAX_PATH - 2/*double `NULL`*/ <= _tcslen(shrflrpath))
        return FALSE;

    // 连接网络资源
    NETRESOURCE netres;
    ZeroMemory(&netres, sizeof(netres));
    netres.dwType = RESOURCETYPE_DISK;
    netres.lpLocalName = NULL;
    netres.lpRemoteName = shrflrpath;
    netres.lpProvider = NULL;
    DWORD errc = WNetAddConnection2(&netres, usr, pwd, CONNECT_TEMPORARY);
    if (NO_ERROR != errc)
        return FALSE;

    // 复制文件到共享文件夹
    TCHAR filepathzz[MAX_PATH];
    _tcscpy_s(filepathzz, MAX_PATH, filepath);
    filepathzz[_tcslen(filepath) + 1] = TEXT('\0');

    TCHAR shrflrpathzz[MAX_PATH];
    _tcscpy_s(shrflrpathzz, MAX_PATH, shrflrpath);
    shrflrpathzz[_tcslen(shrflrpath) + 1] = TEXT('\0');

    SHFILEOPSTRUCT shfop;
    ZeroMemory(&shfop, sizeof(shfop));
    shfop.wFunc = FO_COPY;
    shfop.pFrom = filepathzz;
    shfop.pTo = shrflrpathzz;
    shfop.fFlags = FOF_NO_UI;
    SHFileOperation(&shfop);
    // 中断网络资源
    WNetCancelConnection2(shrflrpath, 0, TRUE);

    return TRUE;
}

/** @} */

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    copy_file_to_shared_folder(
        TEXT("D:\\testfile.txt"),
        TEXT("\\\\192.168.101.121\\result_test\\httptest"),
        TEXT("viecas_user"),
        TEXT("viecas_user"));
}
