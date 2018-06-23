/*===-- String Transcode ---------------------------------------*- C -*-===*//**
 *
 * \defgroup gStrXc 字串转码
 * \ingroup gCharSet
 *
 * \sa [*字符集编码与 C/C++ 源文件字符编译乱弹*](http://jimmee.iteye.com/blog/2165685)
 * \sa [*UTF8 中文编码处理探究*](http://cnblogs.com/Esfog/p/MSVC_UTF8_CHARSET_HANDLE.html)
 *
 * \version 2018-06-23
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

EXTERN_C_START

/**
 * \brief 字串转码。
 *        以指定代码页解码输入字串，然后以指定代码页编码输出字串。
 *
 * \param[in]  inputCodePage    输入字串的编码页，如`CP_GB2312`。
 * \param[in]  inputString      输入字串的指针。
 * \param[in]  inputBytesCount  输入字串的尺寸，为`-1`则自适应空终止字串。
 * \param[in]  outputCodePage   输出字串的编码页，如`CP_UTF8`。
 * \param[out] outputString     输出缓存的指针。
 * \param[in]  outputBytesCount 输出缓存的尺寸，为`0`则返回编码所需字节数。
 * \returns 若成功，返回编码写入的字节数；
 *          或若输出缓存尺寸为`0`，返回编码所需的字节数。
 *          若失败，返回`0`，调用`GetLastError()`获取错误码。
 *
 * \sa ["MultiByteToWideChar function"](https://msdn.microsoft.com/library/dd319072). *Microsoft® Developer Network*.
 * \sa ["WideCharToMultiByte function"](https://msdn.microsoft.com/library/dd374130). *Microsoft® Developer Network*.
 * \sa ["Code Page Identifiers"](https://msdn.microsoft.com/library/dd317756). *Microsoft® Developer Network*.
 *
 * \version 2018-06-11
 * \since 2018-04-26
 * \authors zhengrr
 */
RRWINDOWS_API
_Success_(return != 0)
    _When_(inputBytesCount==-1 && outputBytesCount!=0, _Post_equal_to_(_String_length_(outputString)+1))
INT WINAPI
StringTranscode(
    _In_                                           CONST UINT  inputCodePage,
    _In_NLS_string_(inputBytesCount)              LPCSTR CONST inputString,
    _In_                                           CONST INT   inputBytesCount,
    _In_                                           CONST UINT  outputCodePage,
    _Out_writes_to_opt_(outputBytesCount, return)  LPSTR CONST outputString,
    _In_                                           CONST INT   outputBytesCount);

EXTERN_C_END

#ifdef __cplusplus
# include <memory>
# include <string>

template <std::size_t isz, std::size_t osz>
inline INT StringTranscode(
    CONST UINT inputCodePage,
    CONST CHAR(&inputString)[isz],
    CONST UINT outputCodePage,
    CHAR(&outputString)[osz])
{
    return StringTranscode(inputCodePage, inputString, isz, outputCodePage, outputString, osz);
}

inline std::string StringTranscode(
    CONST UINT inputCodePage,
    CONST std::string &inputString,
    CONST UINT outputCodePage)
{
    CONST INT uRqdCnt = MultiByteToWideChar(inputCodePage, 0, inputString.c_str(), inputString.length(), NULL, 0);
    if (0 == uRqdCnt) return std::string();

    std::unique_ptr<WCHAR[]> CONST uStr(new WCHAR[uRqdCnt]);
    if (NULL == uStr) { SetLastError(ERROR_OUTOFMEMORY); return std::string(); }

    CONST INT uCnt = MultiByteToWideChar(inputCodePage, 0, inputString.c_str(), inputString.length(), uStr.get(), uRqdCnt);
    if (0 == uCnt) return std::string();

    CONST INT bRqdCnt = WideCharToMultiByte(outputCodePage, 0, uStr.get(), uCnt, NULL, 0, NULL, NULL);
    if (0 == bRqdCnt) return std::string();

    std::unique_ptr<CHAR[]> CONST bStr(new CHAR[bRqdCnt]);
    if (NULL == bStr) { SetLastError(ERROR_OUTOFMEMORY); return std::string(); }

    CONST INT bCnt = WideCharToMultiByte(outputCodePage, 0, uStr.get(), uCnt, bStr.get(), bRqdCnt, NULL, NULL);
    if (0 == bCnt) return std::string();

    return std::string(bStr.get(), bCnt);
}
#endif

/** @} */
