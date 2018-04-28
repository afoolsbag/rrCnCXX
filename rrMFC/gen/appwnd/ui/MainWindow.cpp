/// \copyright The MIT License

#include "stdafx.h"
#include "MainWindow.h"

#include "utils/dbgcon.h"

IMPLEMENT_DYNCREATE(MainWindow, CWnd)

BEGIN_MESSAGE_MAP(MainWindow, CWnd)
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
END_MESSAGE_MAP()

#// Constructors

MainWindow::
MainWindow()
{
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("Constructor\n"));

    CString strWndClass = AfxRegisterWndClass(
        CS_DBLCLKS,
        AfxGetApp()->LoadStandardCursor(IDC_ARROW),
        (HBRUSH)(COLOR_3DFACE + 1),
        AfxGetApp()->LoadStandardIcon(IDI_WINLOGO)
    );

    CreateEx(0, strWndClass, TEXT("Main Window"),
             WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX | WS_THICKFRAME,
             CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
             NULL, NULL);
}

BOOL MainWindow::
Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, CONST RECT &rect, CWnd *pParentWnd, UINT nID, CCreateContext *pContext /*=NULL*/)
{
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(White, TEXT("Create\n"));
    return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

BOOL MainWindow::
CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, INT x, INT y, INT nWidth, INT nHeight, HWND hWndParent, HMENU nIDorHMenu, LPVOID lpParam /*=NULL*/)
{
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(White, TEXT("CreateEx\n"));
    return CWnd::CreateEx(dwExStyle, lpszClassName, lpszWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, nIDorHMenu, lpParam);
}

BOOL MainWindow::
CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, CONST RECT &rect, CWnd *pParentWnd, UINT nID, LPVOID lpParam)
{
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(White, TEXT("CreateEx\n"));
    return CWnd::CreateEx(dwExStyle, lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, lpParam);
}

MainWindow::
~MainWindow()
{
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("Destructor\n"));
}

#// Overridables

BOOL MainWindow::
PreCreateWindow(CREATESTRUCT &cs)
{
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("PreCreateWindow\n"));
    cs.cx = 400;
    cs.cy = 300;
    return CWnd::PreCreateWindow(cs);
}

BOOL MainWindow::
OnCmdMsg(UINT nID, INT nCode, VOID *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrtCmdMsg(LightYellow, TEXT("OnCmdMsg"), nID, nCode, pExtra, pHandlerInfo);
    return CWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL MainWindow::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrtWndMsg(Yellow, TEXT("OnWndMsg"), message, wParam, lParam, pResult);
    return CWnd::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainWindow::
DoDataExchange(CDataExchange *pDX)
{
    CWnd::DoDataExchange(pDX);
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("DoDataExchange\n"));
}

VOID MainWindow::
PostNcDestroy()
{
    DbgConPrt(Yellow, TEXT("MainWindow::"));
    DbgConPrt(LightYellow, TEXT("PostNcDestroy\n"));
    CWnd::PostNcDestroy();
}

#// Message Handlers
// See sub-source files.
