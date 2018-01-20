/**
 * \file
 * \brief 统一码与字符集
 * \sa ["Unicode and Character Sets"](https://msdn.microsoft.com/library/dd374083). *Microsoft® Developer Network*.
 * \sa [*字符集编码与 C/C++ 源文件字符编译乱弹*](http://jimmee.iteye.com/blog/2165685)
 * \sa [*UTF8 中文编码处理探究*](http://cnblogs.com/Esfog/p/MSVC_UTF8_CHARSET_HANDLE.html)
 * \author zhengrr
 * \date 2018-1-11 – 20
 * \copyright The MIT License
 */

#include <assert.h>

#include <tchar.h>
#include <Windows.h>

#ifndef CP_GB2312
#define CP_GB2312 936
#endif/* CP_GB2312*/
#ifndef CP_GB18030
#define CP_GB18030 54936
#endif/* CP_GB18030*/
#ifndef CP_UTF8
#define CP_UTF8 65001
#endif/* CP_UTF8*/

/**
* \brief 多字节字符串 转 多字节字符串
* \details 字符串由'\0'表示终止，字符串尺寸用于越界检查。
* \param[in]  bufOrig 原始字符串缓冲区
* \param[in]  sizOrig 原始字符串有效尺寸
* \param[in]  cpOrig  原始字符串编码代码页
* \param[out] bufConv 转换后字符串缓冲区
* \param[in]  sizConv 转换后字符串有效尺寸
* \param[in]  cpConv  转换后字符串编码代码页
* \return 成功或失败
* \sa [MultiByteToWideChar function](https://msdn.microsoft.com/library/dd319072). *Microsoft® Developer Network*.
* \sa [WideCharToMultiByte function](https://msdn.microsoft.com/library/dd374130). *Microsoft® Developer Network*.
* \sa [Code Page Identifiers](https://msdn.microsoft.com/library/dd317756). *Microsoft® Developer Network*.
*/
BOOL MultiByteToMultiByte(const CHAR *const bufOrig, const SIZE_T sizOrig, const UINT cpOrig,
			  CHAR *const bufConv, const SIZE_T sizConv, const UINT cpConv)
{
	if (NULL == bufOrig || 0 == sizOrig || NULL == bufConv || 0 == sizConv)
		return FALSE;

	/* Original String to UTF-16 String */
	const SIZE_T lenOrig = strlen(bufOrig) + 1/*'\0'*/;
	if (sizOrig < lenOrig)
		return FALSE;

	if (0 == lenOrig) {
		ZeroMemory(bufConv, sizConv);
		return TRUE;
	}

	const SIZE_T lenUtf16 = (SIZE_T) MultiByteToWideChar(cpOrig, 0, bufOrig, (int) lenOrig, NULL, 0);
	WCHAR *bufUtf16 = (WCHAR *) calloc(lenUtf16, sizeof(WCHAR));
	if (NULL == bufUtf16)
		return FALSE;

	if (!MultiByteToWideChar(cpOrig, 0, bufOrig, (int) lenOrig, bufUtf16, (int) lenUtf16))
		goto EXCEPTION_HANDLING_FREE_BUFUTF16;

	/* UTF-16 String to Converted String */
	const SIZE_T lenConv = (SIZE_T) WideCharToMultiByte(cpConv, 0, bufUtf16, (int) lenUtf16, NULL, 0, NULL, NULL);
	if (sizConv < lenConv)
		goto EXCEPTION_HANDLING_FREE_BUFUTF16;

	ZeroMemory(bufConv, sizConv);
	if (!WideCharToMultiByte(cpConv, 0, bufUtf16, (int) lenUtf16, bufConv, (int) lenConv, NULL, NULL))
		goto EXCEPTION_HANDLING_FREE_BUFUTF16;

	free(bufUtf16);
	return TRUE;

EXCEPTION_HANDLING_FREE_BUFUTF16:
	free(bufUtf16);
	return FALSE;
}

/**
 * \brief 国标简中字符集（GB 2312）字符串 转 八位统一码转换格式（UTF-8）字符串
 * \details 字符串由'\0'表示终止，字符串尺寸用于越界检查。
 * \param[in]  bufGb2312 原始字符串缓冲区
 * \param[in]  sizGb2312 原始字符串有效尺寸
 * \param[out] bufUtf8   转换后字符串缓冲区
 * \param[in]  sizUtf8   转换后字符串有效尺寸
 * \return 成功或失败
 */
inline BOOL Gb2312ToUtf8(const CHAR *const bufGb2312, const SIZE_T sizGb2312, CHAR *const bufUtf8, const SIZE_T sizUtf8)
{
	return MultiByteToMultiByte(bufGb2312, sizGb2312, CP_GB2312, bufUtf8, sizUtf8, CP_UTF8);
}

/**
 * \brief 国标中文字符集（GB 18030）字符串 转 八位统一码转换格式（UTF-8）字符串
 * \details 字符串由'\0'表示终止，字符串尺寸用于越界检查。
 * \param[in]  bufGb18030 原始字符串缓冲区
 * \param[in]  sizGb18030 原始字符串有效尺寸
 * \param[out] bufUtf8    转换后字符串缓冲区
 * \param[in]  sizUtf8    转换后字符串有效尺寸
 * \return 成功或失败
 */
inline BOOL Gb18030ToUtf8(const CHAR *const bufGb18030, const SIZE_T sizGb18030, CHAR *const bufUtf8, const SIZE_T sizUtf8)
{
	return MultiByteToMultiByte(bufGb18030, sizGb18030, CP_GB18030, bufUtf8, sizUtf8, CP_UTF8);
}

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
	CHAR ansi[5] = {'\xC4', '\xE3', '\xBA', '\xC3', '\0'};  /* GB 2312 "你好" */
	CHAR utf8[7] = {'\0'};

	Gb2312ToUtf8(ansi, sizeof(ansi), utf8, sizeof(utf8));

	assert(utf8[0] == '\xE4' && utf8[1] == '\xBD' && utf8[2] == '\xA0');  /* UTF-8 '你' */
	assert(utf8[3] == '\xE5' && utf8[4] == '\xA5' && utf8[5] == '\xBD');  /* UTF-8 '好' */
	assert(utf8[6] == '\0');

	return EXIT_SUCCESS;
}
