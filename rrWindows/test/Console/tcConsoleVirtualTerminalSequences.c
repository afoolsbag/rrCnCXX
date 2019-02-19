/*===-- Console Virtual Terminal Sequences ---------------------*- C -*-===*//**
 *
 * \defgroup gConsoleVirtualTerminalSequences 控制台虚拟终端序列
 * \ingroup gConsole
 *
 * \sa <https://docs.microsoft.com/windows/console/console-virtual-terminal-sequences>
 *
 * \version 2018-11-19
 * \since 2018-06-07
 * \authors zhengrr
 * \copyright Unlicense
 *
 * @{
*//*===--------------------------------------------------------------------===*/

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check.h>

#include "rrwindows/rrwindows.h"
#include "tsConsole.h"

START_TEST(tfAllocErrorMessage)
{
    ck_assert(EnableVirtualTerminalMode());

    _putts(VTFRED _T("Red text") VTFDEF);
    _putts(VTFGRN _T("Green text") VTFDEF);
    _putts(VTFYEL _T("Yellow text") VTFDEF);
    _putts(VTFBLU _T("Blue text") VTFDEF);

    ck_assert(DisableVirtualTerminalMode());
}
END_TEST

/**
 * @}
 */

TCase *tcConsoleVirtualTerminalSequences(void)
{
    TCase *const tc = tcase_create(__func__);
    tcase_add_test(tc, tfAllocErrorMessage);
    return tc;
}
