/// \copyright Unlicense

#include <clocale>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <gtest/gtest.h>

/// \brief 控制台应用入口
INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    UNREFERENCED_PARAMETER(envp);
#ifndef _UNICODE
    std::setlocale(LC_ALL, ".UTF-8");
#endif
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/// \brief 桌面应用入口
INT WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PTSTR lpCmdLine, INT nCmdShow)
{
    UNREFERENCED_PARAMETER(hInstance);
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    UNREFERENCED_PARAMETER(nCmdShow);
    return EXIT_SUCCESS;
}
