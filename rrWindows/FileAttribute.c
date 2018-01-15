/**
 * \file
 * \brief Windows® 文件属性
 * \author zhengrr
 * \date 2018-1-15
 * \copyright The MIT License
 */

#include <tchar.h>
#include <windows.h>

#include "Error.h"

/**
 * \sa [WIN32_FILE_ATTRIBUTE_DATA structure](https://msdn.microsoft.com/library/aa365739)
 * \sa [GetFileAttributesEx function](https://msdn.microsoft.com/library/aa364946)
 * \sa [FileTimeToSystemTime function](https://msdn.microsoft.com/library/ms724280)
 */
INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
        WIN32_FILE_ATTRIBUTE_DATA attributes = {0};
        FILETIME ftimeLocal = {0};
        SYSTEMTIME stimeLocal = {0};

	GetFileAttributesEx("FilePath", GetFileExInfoStandard, &attributes);

        FileTimeToLocalFileTime(&attributes.ftCreationTime, &ftimeLocal);
        FileTimeToSystemTime(&ftimeLocal, &stimeLocal);
        _tprintf_s(TEXT("CreationTime: %d:%d:%d\n"), stimeLocal.wHour, stimeLocal.wMinute, stimeLocal.wSecond);
}
