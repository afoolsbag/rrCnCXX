/** \file
 *  \brief 统一码
 *  \sa [字符集编码与 C/C++ 源文件字符编译乱弹](http://jimmee.iteye.com/blog/2165685)
 *  \sa [UTF8 中文编码处理探究](http://cnblogs.com/Esfog/p/MSVC_UTF8_CHARSET_HANDLE.html)
 *  \author zhengrr
 *  \date 2018-1-11
 *  \copyright The MIT License */

#include <windows.h>
#include <tchar.h>

/** \brief 本地编码转统一码
 *  \param[in] originalString 原始字符串，Native ANSI
 *  \param[out] convertedString 转换后字符串容器，UTF-16
 *  \param[in] convertedSize 转换后字符串容器尺寸（而非字符串长度） */
BOOL NativeToUnicode(PCSTR originalString,
		     PWSTR convertedString, const SIZE_T convertedSize)
{
	if (NULL == originalString || NULL == convertedString)
		return FALSE;

	SIZE_T originalLength = strlen(originalString);

	if (originalLength == 0) {
		ZeroMemory(convertedString, convertedSize);
		return TRUE;
	}/* else*/

	if (!MultiByteToWideChar(CP_ACP, 0,
				 originalString, (int)originalLength,
				 convertedString, (int)convertedSize)) {
		return FALSE;
	}

	return TRUE;
}

INT _tmain(INT argc, _TCHAR *argv[], _TCHAR *envp[])
{
	system("chcp 65001");

	PSTR originalString = "你好";
	PWSTR convertedString[3];

	NativeToUnicode(originalString, convertedString, sizeof(convertedString));

	return EXIT_SUCCESS;
}
