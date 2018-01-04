/** \file
 *  \brief “问好”（Ｗｉｎｄｏｗｓ动态链接库简单示例）
 *  \author zhengrr
 *  \date 2018-1-3
 *  \copyright The MIT License */

#include <windows.h>
#include <tchar.h>

#include <stdio.h>

#include "DiceLib.h"

INT _tmain(INT argc, _TCHAR *argv[], _TCHAR *envp[])
{
        _tprintf(_T("Dicing... %d!"), Dice());

        return EXIT_SUCCESS;
}
