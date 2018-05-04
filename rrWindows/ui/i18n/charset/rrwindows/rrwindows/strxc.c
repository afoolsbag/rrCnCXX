/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "strxc.h"

#include <stdlib.h>

RRWINDOWS_API
_Success_(return != 0)
    _When_(inputBytesCount==-1 && outputBytesCount!=0,
           _Post_equal_to_(_String_length_(outputString)+1))
INT WINAPI
StringTranscode(
    _In_                                           CONST UINT  inputCodePage,
    _In_NLS_string_(inputBytesCount)              LPCSTR CONST inputString,
    _In_                                           CONST INT   inputBytesCount,
    _In_                                           CONST UINT  outputCodePage,
    _Out_writes_to_opt_(outputBytesCount, return)  LPSTR CONST outputString,
    _In_                                           CONST INT   outputBytesCount)
{
    INT rv = 0;
    
    rv = MultiByteToWideChar(inputCodePage, 0, inputString, inputBytesCount, NULL, 0);
    if (!rv)
        goto out;

    CONST SIZE_T ucnt = rv;
    WCHAR *ustr = (WCHAR *)calloc(ucnt, sizeof(WCHAR));
    if (!ustr) {
        SetLastError(ERROR_OUTOFMEMORY);
        rv = 0;
        goto out;
    }

    rv = MultiByteToWideChar(inputCodePage, 0, inputString, inputBytesCount, ustr, ucnt);
    if (!rv)
        goto out_free_ustr;
    
    rv = WideCharToMultiByte(outputCodePage, 0, ustr, ucnt, outputString, outputBytesCount, NULL, NULL);

out_free_ustr:
    free(ustr);
out:
    return rv;
}
