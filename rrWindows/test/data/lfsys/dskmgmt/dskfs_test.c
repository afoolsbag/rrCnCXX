/*===-- Disk Free Space ----------------------------------------*- C -*-===*//**
 *
 * \defgroup gDskFS 磁盘可用空间
 * \ingroup gDskMgmt
 *
 * \author zhengrr
 * \version 2018-08-08
 * \since 2018-06-15
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>
#include "rrwindows/rrwindows.h"

#include "_test.h"

START_TEST(TestDskFS)
{
    ULARGE_INTEGER availableFreeBytes;
    ULARGE_INTEGER totalBytes;
    ULARGE_INTEGER freeBytes;
    if (!GetDiskFreeSpaceEx(_T("C:\\"), &availableFreeBytes, &totalBytes, &freeBytes)) {
        DpWarnFwLE(_T("GetDiskFreeSpaceEx"));
        DpTrace(_T("444"));
        ck_abort();
        return;
    }
    DpInfo(_T("Available free bytes %llu, total %llu, free %llu."), availableFreeBytes.QuadPart, totalBytes.QuadPart, freeBytes.QuadPart);
}
END_TEST

/** @} */

TCase *TCaseDskFS(void)
{
    TCase *tcase = tcase_create("DskFS");
    tcase_add_test(tcase, TestDskFS);
    return tcase;
}
