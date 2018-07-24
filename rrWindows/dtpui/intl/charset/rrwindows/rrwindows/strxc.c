/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "strxc.h"

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
    _In_                                          CONST INT   outputBytesCount)
{
    CONST size_t uRqdCnt = MultiByteToWideChar(inputCodePage, 0, inputString, inputBytesCount, NULL, 0);
    if (0 == uRqdCnt)
        return 0;

    WCHAR *CONST uStr = (WCHAR *)HeapAlloc(GetProcessHeap(), 0, uRqdCnt * sizeof(WCHAR));
    if (NULL == uStr) {
        SetLastError(ERROR_OUTOFMEMORY);
        return 0;
    }

    CONST size_t uCnt = MultiByteToWideChar(inputCodePage, 0, inputString, inputBytesCount, uStr, uRqdCnt);
    if (0 == uCnt) {
        HeapFree(GetProcessHeap(), 0, uStr);
        return 0;
    }

    CONST size_t bCnt = WideCharToMultiByte(outputCodePage, 0, uStr, uCnt, outputString, outputBytesCount, NULL, NULL);
    HeapFree(GetProcessHeap(), 0, uStr);
    return bCnt;
}
