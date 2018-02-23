/*===-- Generate UUID ------------------------------------------*- C -*-===*//**
 *
 * \defgroup g_gen_uuid 生成通用唯一标识符
 * \ingroup g_rpc
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

#include <rpc.h>

#pragma comment(lib, "RpcRT4.Lib")

/**
 * \brief 生成通用唯一标识符
 * 
 * \sa ["UuidCreate function"](https://msdn.microsoft.com/library/aa379205). *Microsoft® Developer Network*.
 * \sa ["UuidToString function"](https://msdn.microsoft.com/library/aa379352). *Microsoft® Developer Network*.
 * \sa ["RpcStringFree function"](https://msdn.microsoft.com/library/aa378483). *Microsoft® Developer Network*.
 */
static VOID generate_uuid(VOID)
{
    UUID uuidbin;
    UuidCreate(&uuidbin);
    
    PTSTR uuidstr;
    UuidToString(&uuidbin, (RPC_CSTR *)&uuidstr);

    CharUpper(uuidstr);
    _putts(uuidstr);
    _tsystem(TEXT("pause"));

    RpcStringFree((RPC_CSTR *)&uuidstr);
}

/** @} */

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    generate_uuid();
}
