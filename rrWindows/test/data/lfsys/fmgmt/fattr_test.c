/** \copyright The MIT License */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check/check.h>
#include "rrwindows/rrwindows.h"

#include "_test.h"

/**
 * \sa ["WIN32_FILE_ATTRIBUTE_DATA structure"](https://msdn.microsoft.com/library/aa365739). *Microsoft Developer Network*.
 * \sa ["GetFileAttributesEx function"](https://msdn.microsoft.com/library/aa364946). *Microsoft Developer Network*.
 * \sa ["FileTimeToSystemTime function"](https://msdn.microsoft.com/library/ms724280). *Microsoft Developer Network*.
 */
START_TEST(TestFAttr)
{
    WIN32_FILE_ATTRIBUTE_DATA attr;
    if (!GetFileAttributesEx(ExecutablePath(), GetFileExInfoStandard, &attr)) {
        DpWarnFwLE(_T("GetFileAttributesEx"));
        ck_abort();
        return;
    }

    FILETIME ftLocal;
    FileTimeToLocalFileTime(&attr.ftCreationTime, &ftLocal);
    SYSTEMTIME stLocal;
    FileTimeToSystemTime(&ftLocal, &stLocal);
    DpInfo(_T("%s creation time: %hu:%hu:%hu."), ExecutableName(), stLocal.wHour, stLocal.wMinute, stLocal.wSecond);
}
END_TEST

TCase *TCaseFAttr(void)
{
    TCase *tcase = tcase_create("FAttr");
    tcase_add_test(tcase, TestFAttr);
    return tcase;
}
