/*===-- String Transcode ---------------------------------------*- C -*-===*//**
 *
 * \defgroup gStrXc 字串转码
 * \ingroup gCharSet
 *
 * \sa [*字符集编码与 C/C++ 源文件字符编译乱弹*](http://jimmee.iteye.com/blog/2165685)
 * \sa [*UTF8 中文编码处理探究*](http://cnblogs.com/Esfog/p/MSVC_UTF8_CHARSET_HANDLE.html)
 *
 * \version 2018-07-13
 * \since 2018-01-11
 * \authors zhengrr
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/rrwindowsapi.h"

#ifndef CP_GB2312
#define CP_GB2312                   936
#endif/*CP_GB2312*/
#ifndef CP_BIG5
#define CP_BIG5                     950
#endif/*CP_BIG5*/
#ifndef CP_GB18030
#define CP_GB18030                54936
#endif/*CP_GB18030*/
#ifndef CP_UTF8
#define CP_UTF8                   65001
#endif/*CP_UTF8*/

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 字串转码。
 * \details 以指定代码页解码输入字符串，然后以指定代码页编码输出字符串。
 *          不适用于宽字节字符串。
 *
 * \param[in]  inputCodePage    输入字符串的编码页，如`CP_GB2312`。
 * \param[in]  inputString      输入字符串的指针。
 * \param[in]  inputBytesCount  输入字符串的尺寸，为`-1`则自适应空终止字符串。
 * \param[in]  outputCodePage   输出字符串的编码页，如`CP_UTF8`。
 * \param[out] outputString     输出缓存的指针。
 * \param[in]  outputBytesCount 输出缓存的尺寸，为`0`则返回编码所需字节数。
 * \returns 0< 编码写入的字节数或编码所需的字节数；\n
 *          0  失败，可调用`GetLastError()`获取扩展错误信息。
 *
 * \sa <https://docs.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar>
 * \sa <https://docs.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-widechartomultibyte>
 * \sa <https://docs.microsoft.com/windows/desktop/Intl/code-page-identifiers>
 *
 * \version 2018-07-13
 * \since 2018-04-26
 * \authors zhengrr
 */
RRWINDOWS_API
_Success_(return != 0)
_When_(inputBytesCount == -1 && outputBytesCount != 0, _Post_equal_to_(_String_length_(outputString) + 1))
INT
WINAPI
StringTranscode(
    _In_                                          CONST UINT  inputCodePage,
    _In_NLS_string_(inputBytesCount)             LPCSTR CONST inputString,
    _In_                                          CONST INT   inputBytesCount,
    _In_                                          CONST UINT  outputCodePage,
    _Out_writes_to_opt_(outputBytesCount, return) LPSTR CONST outputString,
    _In_                                          CONST INT   outputBytesCount);

#ifdef __cplusplus
}
#endif

/** @} */
