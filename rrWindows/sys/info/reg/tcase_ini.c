/*===-- Initialization File ------------------------------------*- C -*-===*//**
 *
 * \defgroup gIni 初始化文件
 * \ingroup gReg
 *
 * \author zhengrr
 * \version 2018-06-02
 * \since 2018-01-15
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <stdlib.h>
#include <strsafe.h>
#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

#include "rrwindows/dbgprt.h"
#include "rrwindows/errtxt.h"
#include "rrwindows/exepath.h"
#include "tsuite_reg.h"

/**
 * \sa ["WritePrivateProfileString function"](https://msdn.microsoft.com/library/ms725501). *Microsoft® Developer Network*.
 * \sa ["GetPrivateProfileString function"](https://msdn.microsoft.com/library/ms724353). *Microsoft® Developer Network*.
 * \sa ["GetPrivateProfileInt"](https://msdn.microsoft.com/library/ms724345). *Microsoft® Developer Network*.
 */
START_TEST(TestIni)
{
    TCHAR iniPath[MAX_PATH];
    if (FAILED(StringCchCopy(iniPath, _countof(iniPath), InitializationPath())))
        goto out_abort;

    if (!WritePrivateProfileString(_T("app"), _T("str"), _T("wow"), iniPath))
        goto out_dbgprt;
    if (!WritePrivateProfileString(_T("app"), _T("int"), _T("666"), iniPath))
        goto out_dbgprt;

    TCHAR txt[4];
    *txt = _T('\0');
    SetLastError(ERROR_SUCCESS);
    if (!GetPrivateProfileString(_T("app"), _T("str"), NULL, txt, _countof(txt), iniPath))
        goto out_dbgprt;
    ck_assert_str_eq(txt, _T("wow"));

    INT num = GetPrivateProfileInt(_T("app"), _T("int"), 0, iniPath);
    ck_assert_int_eq(num, 666);

    return;

out_dbgprt:
    DbgPrtD(_T("*PrivateProfile* failed, %lu, %s\n"), GetLastError(), GetLastErrorText());
out_abort:
    ck_abort();
    return;
}
END_TEST

/** @} */

TCase *TCaseIni(void)
{
    TCase *tcase = tcase_create("Ini");
    tcase_add_test(tcase, TestIni);
    return tcase;
}
