/** \copyright The MIT License */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/strxc.h"

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    UNREFERENCED_PARAMETER(argc);
    UNREFERENCED_PARAMETER(argv);
    UNREFERENCED_PARAMETER(envp);

    CHAR gb2312[5] = {'\xC4', '\xE3', '\xBA', '\xC3', '\0'};  /* GB2312 "你好" */
    CHAR utf8[7] = {'\0'};
    StringTranscode(CP_GB2312, gb2312, -1, CP_UTF8, utf8, _countof(utf8));
    assert('\xE4' == utf8[0] && '\xBD' == utf8[1] && '\xA0' == utf8[2]);  /* UTF8 '你' */
    assert('\xE5' == utf8[3] && '\xA5' == utf8[4] && '\xBD' == utf8[5]);  /* UTF8 '好' */
    assert('\0' == utf8[6]);

    _tsystem(_T("chcp 936"));  /* CP_GB2312 */
    _putts(_T("Changed code page to GB2312(936)."));
    _putts(gb2312);
    _tsystem(_T("pause"));

    _tsystem(_T("chcp 65001"));  /* CP_UTF8 */
    _putts(_T("Changed code page to UTF8(65001)."));
    _putts(utf8);
    _tsystem(_T("pause"));

    return EXIT_SUCCESS;
}
