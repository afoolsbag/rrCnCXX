/*===-- Convert String to Upper  -------------------------------*- C -*-===*//**
 *
 * \defgroup g_cnv_upr 将字符串转换为大写
 * \ingroup g_str
 *
 * \author zhengrr
 * \version 2018-2-23
 * \since 2018-2-23
 * \copyright The MIT License
 *
 * @{
**//*===-------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <tchar.h>
#include <Windows.h>

/**
 * \brief 将字符串转换为大写
 * 
 * \sa ["CharUpper function"](https://msdn.microsoft.com/library/ms647474). *Microsoft® Developer Network*.
 */
static VOID convert_string_to_upper(VOID)
{
    PTSTR txt = TEXT("lower");
    CharUpper(txt);
    _putts(txt);
    _tsystem(TEXT("pause"));
}

/** @} */

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    convert_string_to_upper();
}
