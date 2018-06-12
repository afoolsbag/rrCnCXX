/// \copyright The MIT License

#include "stdafx.h"
#include "Wnd.h"

#include "rrwindows/dbgcon.h"

#include "WndApp.h"

#// Private Message

/// \brief 定制私有消息。
#define PM_CUSTOM_PRIVATE_MESSAGE (WM_USER + 1)

BEGIN_MESSAGE_MAP(Window, CWnd)
    // CREATE & DESTROY
    ON_WM_NCCREATE()
    ON_WM_CREATE()
    ON_WM_DESTROY()
    ON_WM_NCDESTROY()

    // MOVE & SIZE
    ON_WM_GETMINMAXINFO()
    ON_WM_ENTERSIZEMOVE()
    ON_WM_MOVING()
    ON_WM_SIZING()
    ON_WM_WINDOWPOSCHANGING()
    ON_WM_EXITSIZEMOVE()

    ON_WM_MOVE()
    ON_WM_NCCALCSIZE()
    ON_WM_SIZE()
    ON_WM_WINDOWPOSCHANGED()

    // STATE & STATUS
    ON_WM_ACTIVATEAPP()
    ON_WM_NCACTIVATE()
    ON_WM_ACTIVATE()

    // PAINT
    ON_WM_NCPAINT()
    ON_WM_ERASEBKGND()
    ON_WM_PAINT()

    // TIMER
    ON_WM_TIMER()

    // CUSTOM
    ON_MESSAGE(PM_CUSTOM_PRIVATE_MESSAGE, &Window::OnCustomPrivateMessage)
    ON_MESSAGE(AM_CUSTOM_APPLICATION_MESSAGE, &Window::OnCustomApplicationMessage)
    ON_REGISTERED_MESSAGE(RM_CUSTOM_REGISTER_MESSAGE, &Window::OnCustomRegisterMessage)
END_MESSAGE_MAP()

#// Constructors

Window::
Window()
{
    DbgConMeth();

    CString wndClassName = AfxRegisterWndClass(
        CS_DBLCLKS,
        AfxGetApp()->LoadStandardCursor(IDC_ARROW),
        reinterpret_cast<HBRUSH>(COLOR_3DFACE + 1),
        AfxGetApp()->LoadStandardIcon(IDI_WINLOGO)
    );

    CreateEx(0, wndClassName, TEXT("Window"),
             WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX | WS_THICKFRAME,
             CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
             NULL, NULL);
}

BOOL Window::
Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, CONST RECT &rect, CWnd *pParentWnd, UINT nID, CCreateContext *pContext /*=NULL*/)
{
    DbgConMeth();
    return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

BOOL Window::
CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, INT x, INT y, INT nWidth, INT nHeight, HWND hWndParent, HMENU nIDorHMenu, LPVOID lpParam /*=NULL*/)
{
    DbgConMeth();
    return CWnd::CreateEx(dwExStyle, lpszClassName, lpszWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, nIDorHMenu, lpParam);
}

BOOL Window::
CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, CONST RECT &rect, CWnd *pParentWnd, UINT nID, LPVOID lpParam)
{
    DbgConMeth();
    return CWnd::CreateEx(dwExStyle, lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, lpParam);
}

Window::
~Window()
{
    DbgConMeth();
}

#// Overridables

BOOL Window::
PreCreateWindow(CREATESTRUCT &cs)
{
    DbgConMeth();
    return CWnd::PreCreateWindow(cs);
}

BOOL Window::
OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DbgConCmdMsg();
    return CWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL Window::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    DbgConWndMsg();
    return CWnd::OnWndMsg(message, wParam, lParam, pResult);
}

VOID Window::
DoDataExchange(CDataExchange *pDX)
{
    CWnd::DoDataExchange(pDX);
    DbgConMeth();
}

VOID Window::
PostNcDestroy()
{
    DbgConMeth();
    CWnd::PostNcDestroy();
}

#// Message Handlers
// See sub-source files.
