/** \file
 *  \brief *Programming Windows with MFC* 1.1.2.
 *  \author zhengrr
 *  \date 2017-12-8
 *  \copyright The MIT License
 */
#ifdef MAIN_PWMFC

#include <windows.h>

LONG WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR     lpszCmdLine,
        int       nCmdShow)
{
        WNDCLASS wc;
        HWND     hwnd;
        MSG      msg;

        wc.style = 0;
        wc.lpfnWndProc = (WNDPROC) WndProc;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = hInstance;
        wc.hIcon = LoadIcon(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH) (COLOR_WINDOW +1);
        wc.lpszMenuName = NULL;
        wc.lpszClassName = "MyWndClass";

        RegisterClass(&wc);
        hwnd = CreateWindow("MyWndClass",
                            "SDK Application",
                            WS_OVERLAPPEDWINDOW,
                            CW_USEDEFAULT,
                            CW_USEDEFAULT,
                            CW_USEDEFAULT,
                            CW_USEDEFAULT,
                            HWND_DESKTOP,
                            NULL,
                            hInstance,
                            NULL);

        ShowWindow(hwnd, nCmdShow);
        UpdateWindow(hwnd);

        while (GetMessage(&msg, NULL, 0, 0)) {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
        }
        return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
        PAINTSTRUCT ps;
        HDC hdc;

        switch (msg) {
        case WM_PAINT:
                hdc = BeginPaint (hwnd, &ps);
                Ellipse(hdc, 0, 0, 200, 100);
                EndPaint(hwnd, &ps);
                return 0;
        case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
        }
        return DefWindowProc(hwnd, msg, wParam, lParam);
}

#endif// MAIN PWMFC
