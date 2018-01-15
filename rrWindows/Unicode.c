/**
 * \file
 * \brief 统一码
 * \sa [*字符集编码与 C/C++ 源文件字符编译乱弹*](http://jimmee.iteye.com/blog/2165685)
 * \sa [*UTF8 中文编码处理探究*](http://cnblogs.com/Esfog/p/MSVC_UTF8_CHARSET_HANDLE.html)
 * \author zhengrr
 * \date 2018-1-11 – 15
 * \copyright The MIT License
 */

#include <assert.h>

#include <tchar.h>
#include <windows.h>

/**
 * \brief 美国国家标准学会代码页（ACP）转八位元统一码转换格式（UTF-8）
 * \details 将一C风格字符串，由ACP编码转为UTF-8编码。
 *          字符串由'\0'表示终止，输入的字符串尺寸用于越界检查。
 * \param[in]  bufferAcpString  原始字符串缓冲区
 * \param[in]  sizeAcpString    原始字符串有效尺寸
 * \param[out] bufferUtf8String 转换后字符串缓冲区
 * \param[in]  sizeUtf8String   转换后字符串有效尺寸
 * \return 成功或失败
 * \sa [MultiByteToWideChar function](https://msdn.microsoft.com/library/windows/desktop/dd319072). *Microsoft® Developer Network*.
 * \sa [WideCharToMultiByte function](https://msdn.microsoft.com/library/windows/desktop/dd374130). *Microsoft® Developer Network*.
 */
BOOL AnsiToUtf8(PCSTR bufferAcpString, const SIZE_T sizeAcpString,
		PSTR bufferUtf8String, const SIZE_T sizeUtf8String)
{
	if (NULL == bufferAcpString || 0 == sizeAcpString ||
	    NULL == bufferUtf8String || 0 == sizeUtf8String)
		return FALSE;

	/* ACP String to UTF-16 String */
	const SIZE_T lengthAcpString = strlen(bufferAcpString) + 1/*'\n'*/;
	if (sizeAcpString < lengthAcpString)
		return FALSE;

	if (1 == lengthAcpString) {
		ZeroMemory(bufferUtf8String, sizeUtf8String);
		return TRUE;
	}

	const SIZE_T lengthUtf16String = (SIZE_T) MultiByteToWideChar(
		CP_ACP, 0, bufferAcpString, (int) lengthAcpString, NULL, 0);

	const SIZE_T sizeUtf16String = lengthUtf16String * sizeof(WCHAR);

	PWSTR bufferUtf16String = (PWSTR) malloc(sizeUtf16String);
	if (NULL == bufferUtf16String)
		return FALSE;

	ZeroMemory(bufferUtf16String, sizeUtf16String);

	if (!MultiByteToWideChar(CP_ACP, 0,
				 bufferAcpString, (int) lengthAcpString,
				 bufferUtf16String, (int) lengthUtf16String))
		goto FAILED_AND_FREE_BUFFER_UTF_16_STRING;


	/* UTF-16 String to UTF-8 String */
	const SIZE_T lengthUtf8String = (SIZE_T) WideCharToMultiByte(
		CP_UTF8, 0, bufferUtf16String, (int) lengthUtf16String,
		NULL, 0, NULL, NULL);
	if (sizeUtf8String < lengthUtf8String)
		goto FAILED_AND_FREE_BUFFER_UTF_16_STRING;

	ZeroMemory(bufferUtf8String, sizeUtf8String);

	if (!WideCharToMultiByte(CP_UTF8, 0,
				 bufferUtf16String, (int) lengthUtf16String,
				 bufferUtf8String, (int) lengthUtf8String,
				 NULL, NULL))
		goto FAILED_AND_FREE_BUFFER_UTF_16_STRING;

	free(bufferUtf16String);
	return TRUE;

FAILED_AND_FREE_BUFFER_UTF_16_STRING:
	free(bufferUtf16String);
	return FALSE;
}

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
	CHAR ansi[5] = "你好";
	CHAR utf8[7] = {'\0'};

	assert(ansi[0] == '\xC4' && ansi[1] == '\xE3');
	assert(ansi[2] == '\xBA' && ansi[3] == '\xC3');
	assert(ansi[4] == '\0');

	AnsiToUtf8(ansi, sizeof(ansi), utf8, sizeof(utf8));

	assert(utf8[0] == '\xE4' && utf8[1] == '\xBD' && utf8[2] == '\xA0');
	assert(utf8[3] == '\xE5' && utf8[4] == '\xA5' && utf8[5] == '\xBD');
	assert(utf8[6] == '\0');

	return EXIT_SUCCESS;
}
