#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#if _WIN32_WINNT_WIN8 <= _WIN32_WINNT
#include <PathCch.h>
#pragma comment(lib, "pathcch.lib")
#else
#include <Shlwapi.h>
#pragma comment(lib, "ShLwApi.lib")
#endif

#include <VersionHelpers.h>

#include <check.h>

#include "rrwindows/rrwindows.h"
#include "tsShell.h"

/**
 * \addtogroup gShell
 * @{
 */

START_TEST(tfPathCchRemoveFileSpec)
{
#if _WIN32_WINNT_WIN8 <= _WIN32_WINNT
    WCHAR td[5][2][255] = {
        {L"C:\\path1",               L"C:\\"},
        {L"C:\\path1\\",             L"C:\\path1"},
        {L"C:\\path1\\path2",        L"C:\\path1"},
        {L"\\\\path1\\path2\\path3", L"\\\\path1\\path2"},
        {L"\\path1",                 L"\\"},
    };

    for (INT i = 0; i < 5; ++i) {
        PathCchRemoveFileSpec(td[i][0], 255);
        ck_assert(CompareString_Simplify(td[i][0], td[i][1]) == CSTR_EQUAL);
    }
#else
    TCHAR td[5][2][255] = {
        {_T("C:\\path1"),               _T("C:\\")},
        {_T("C:\\path1\\"),             _T("C:\\path1")},
        {_T("C:\\path1\\path2"),        _T("C:\\path1")},
        {_T("\\\\path1\\path2\\path3"), _T("\\\\path1\\path2")},
        {_T("\\path1"),                 _T("\\")},
    };

    for (INT i = 0; i < 5; ++i) {
        PathRemoveFileSpec(td[i][0]);
        ck_assert(CompareString_Simplify(td[i][0], td[i][1]) == CSTR_EQUAL);
    }
#endif

}
END_TEST

/**
 * @}
 */

TCase *tcWindowsShell(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tfPathCchRemoveFileSpec);
    return tc;
}
