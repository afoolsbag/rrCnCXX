/*===-- GB2312 to UTF8  ----------------------------------------*- C -*-===*//**
 *
 * \defgroup g_gb2312_utf8 GB2312转UTF8
 * \ingroup g_unicode
 *
 * \sa [*字符集编码与 C/C++ 源文件字符编译乱弹*](http://jimmee.iteye.com/blog/2165685)
 * \sa [*UTF8 中文编码处理探究*](http://cnblogs.com/Esfog/p/MSVC_UTF8_CHARSET_HANDLE.html)
 *
 * \author zhengrr
 * \version 2018-2-23
 * \since 2018-1-11
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <Windows.h>

#ifndef CP_GB2312
#define CP_GB2312 936
#endif/* CP_GB2312*/

#ifndef CP_UTF8
#define CP_UTF8 65001
#endif/* CP_UTF8*/

/**
 * \brief 解析GB2312编码字符串，构造UTF8编码字符串
 *
 * \param[out] utf8     UTF8字符串
 * \param[in]  utf8size UTF8字符串尺寸
 * \param[in]  gb2312   GB2312字符串
 * \return 成功与否
 *
 * \sa ["MultiByteToWideChar function"](https://msdn.microsoft.com/library/dd319072). *Microsoft® Developer Network*.
 * \sa ["WideCharToMultiByte function"](https://msdn.microsoft.com/library/dd374130). *Microsoft® Developer Network*.
 * \sa ["Code Page Identifiers"](https://msdn.microsoft.com/library/dd317756). *Microsoft® Developer Network*.
 */
static BOOL gb2312_utf8(PSTR CONST utf8, CONST SIZE_T utf8size, PCSTR CONST gb2312)
{
    if (NULL == utf8 || NULL == gb2312 || 0 == utf8size)
        return FALSE;

    CONST SIZE_T gb2312len = strlen(gb2312);
    if (0 == gb2312len) {
        ZeroMemory(utf8, utf8size);
        return TRUE;
    }

    CONST SIZE_T utf16len = MultiByteToWideChar(CP_GB2312, 0, gb2312, gb2312len, NULL, 0);
    WCHAR *utf16 = (WCHAR *)calloc(utf16len, sizeof(WCHAR));
    if (!utf16)
        return FALSE;
    if (!MultiByteToWideChar(CP_GB2312, 0, gb2312, gb2312len, utf16, utf16len))
        goto FAILED_AND_FREE_UTF16;

    CONST SIZE_T utf8len = (SIZE_T)WideCharToMultiByte(CP_UTF8, 0, utf16, utf16len, NULL, 0, NULL, NULL);
    if (utf8size <= utf8len)
        goto FAILED_AND_FREE_UTF16;
    if (!WideCharToMultiByte(CP_UTF8, 0, utf16, utf16len, utf8, utf8len, NULL, NULL))
        goto FAILED_AND_FREE_UTF16;

    free(utf16);
    return TRUE;

FAILED_AND_FREE_UTF16:
    free(utf16);
    return FALSE;
}

/** @} */

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    CHAR gb2312[5] = {'\xC4', '\xE3', '\xBA', '\xC3', '\0'};  /* GB2312 "你好" */
    CHAR utf8[7] = {'\0'};
    gb2312_utf8(utf8, sizeof(utf8), gb2312);
    assert('\xE4' == utf8[0] && '\xBD' == utf8[1] && '\xA0' == utf8[2]);  /* UTF8 '你' */
    assert('\xE5' == utf8[3] && '\xA5' == utf8[4] && '\xBD' == utf8[5]);  /* UTF8 '好' */
    assert('\0' == utf8[6]);

    _tsystem(TEXT("chcp 936"));  /* CP_GB2312 */
    puts(TEXT("Changed code page to GB2312(936)."));
    puts(gb2312);
    _tsystem(TEXT("pause"));

    _tsystem(TEXT("chcp 65001"));  /* CP_UTF8 */
    puts(TEXT("Changed code page to UTF8(65001)."));
    puts(utf8);
    _tsystem(TEXT("pause"));

    return EXIT_SUCCESS;
}
