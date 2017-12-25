/**
 * \file
 * \brief hello, world
 * \author zhengrr
 * \date 2016-10-12 – 14
 * \copyright The MIT License
 */
#include <windows.h>    // include the basic windows header file

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nShowCmd) {
   // create a "Hello World" message box using MessageBox()
   MessageBox(NULL,
              "Hello World!",
              "Just another Hello World program!",
              MB_ICONEXCLAMATION | MB_OK);

   // return 0 to Windows
   return 0;
}
