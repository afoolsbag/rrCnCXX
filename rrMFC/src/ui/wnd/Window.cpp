/// \copyright The Unlicense

#include "stdafx.h"
#include "Window.h"

#include "rrwindows/rrwindows.h"

#include "Application.h"

namespace rrMFC {

/// \brief 私有消息。
namespace PrivateMessages {

/// \brief 定制私有消息。
constexpr UINT Custom {WM_USER + 1};

}//namespace PrivateMessages

BEGIN_MESSAGE_MAP(Window, CWnd)
    ON_WM_NCCREATE()
    ON_WM_CREATE()
    ON_WM_DESTROY()
    ON_WM_NCDESTROY()

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

    ON_WM_ACTIVATEAPP()
    ON_WM_NCACTIVATE()
    ON_WM_ACTIVATE()

    ON_WM_NCPAINT()
    ON_WM_ERASEBKGND()
    ON_WM_PAINT()

    ON_WM_TIMER()

    ON_MESSAGE(rrMFC::PrivateMessages::Custom, &Window::OnCustomPrivateMessage)
    ON_MESSAGE(rrMFC::ApplicationMessages::Custom, &Window::OnCustomApplicationMessage)
    ON_REGISTERED_MESSAGE(rrMFC::RegisteredMessages::Custom, &Window::OnCustomRegisteredMessage)
END_MESSAGE_MAP()

#// Constructors

Window::
Window()
{
    DcMeth();

    CONST CString wndClassName = AfxRegisterWndClass(
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
Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT &rect, CWnd *pParentWnd, UINT nID, CCreateContext *pContext /*=NULL*/)
{
    DcMeth();
    return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

BOOL Window::
CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, INT x, INT y, INT nWidth, INT nHeight, HWND hWndParent, HMENU nIDorHMenu, LPVOID lpParam /*=NULL*/)
{
    DcMeth();
    return CWnd::CreateEx(dwExStyle, lpszClassName, lpszWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, nIDorHMenu, lpParam);
}

BOOL Window::
CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT &rect, CWnd *pParentWnd, UINT nID, LPVOID lpParam)
{
    DcMeth();
    return CWnd::CreateEx(dwExStyle, lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, lpParam);
}

Window::
~Window()
{
    DcMeth();
}

#// Overridables

BOOL Window::
PreCreateWindow(CREATESTRUCT &cs)
{
    DcMeth();
    return CWnd::PreCreateWindow(cs);
}

BOOL Window::
OnCmdMsg(UINT nID, INT nCode, void *pExtra, AFX_CMDHANDLERINFO *pHandlerInfo)
{
    DcCmdMsg();
    return CWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

BOOL Window::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    DcWndMsg();
    return CWnd::OnWndMsg(message, wParam, lParam, pResult);
}

void Window::
DoDataExchange(CDataExchange *pDX)
{
    CWnd::DoDataExchange(pDX);
    DcMeth();
}

void Window::
PostNcDestroy()
{
    DcMeth();
    CWnd::PostNcDestroy();
}

#// Message Handlers

BOOL Window::
OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (!CWnd::OnNcCreate(lpCreateStruct))
        return FALSE;
    DcMeth();
    return TRUE;
}

INT Window::
OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
    DcMeth();
    return 0;
}

void Window::
OnDestroy()
{
    CWnd::OnDestroy();
    DcMeth();
}

void Window::
OnNcDestroy()
{
    CWnd::OnNcDestroy();
    DcMeth();
}

void Window::
OnGetMinMaxInfo(MINMAXINFO *lpMMI)
{
    DcMeth();
    CWnd::OnGetMinMaxInfo(lpMMI);
}

void Window::
OnEnterSizeMove()
{
    DcMeth();
    CWnd::OnEnterSizeMove();
}

void Window::
OnMoving(UINT fwSide, LPRECT pRect)
{
    CWnd::OnMoving(fwSide, pRect);
    DcMeth();
}

void Window::
OnSizing(UINT fwSide, LPRECT pRect)
{
    CWnd::OnSizing(fwSide, pRect);
    DcMeth();
}

void Window::
OnWindowPosChanging(WINDOWPOS *lpwndpos)
{
    CWnd::OnWindowPosChanging(lpwndpos);
    DcMeth();
}

void Window::
OnExitSizeMove()
{
    DcMeth();
    CWnd::OnExitSizeMove();
}

void Window::
OnMove(INT x, INT y)
{
    CWnd::OnMove(x, y);
    DcMeth();
}

void Window::
OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp)
{
    DcMeth();
    CWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}

void Window::
OnSize(UINT nType, INT cx, INT cy)
{
    CWnd::OnSize(nType, cx, cy);
    DcMeth();
}

void Window::
OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
    CWnd::OnWindowPosChanged(lpwndpos);
    DcMeth();
}

void Window::
OnActivateApp(BOOL bActive, DWORD dwThreadID)
{
    CWnd::OnActivateApp(bActive, dwThreadID);
    DcMeth();
}

BOOL Window::
OnNcActivate(BOOL bActive)
{
    DcMeth();
    return CWnd::OnNcActivate(bActive);
}

void Window::
OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
    CWnd::OnActivate(nState, pWndOther, bMinimized);
    DcMeth();
}

void Window::
OnNcPaint()
{
    CWnd::OnNcPaint();
    DcMeth();
}

BOOL Window::
OnEraseBkgnd(CDC *pDC)
{
    DcMeth();
    return CWnd::OnEraseBkgnd(pDC);
}

void Window::
OnPaint()
{
    CWnd::OnPaint();
    DcMeth();
}

void Window::
OnTimer(UINT_PTR nIDEvent)
{
    DcMeth();
    switch (nIDEvent) {
    case ALPHA: break;
    case BETA: break;
    case GAMMA: break;
    default: break;
    }
    CWnd::OnTimer(nIDEvent);
}

LRESULT Window::
OnCustomPrivateMessage(WPARAM wParam, LPARAM lParam)
{
    DcMeth();
    UNUSED(wParam);
    UNUSED(lParam);
    return 0;
}

LRESULT Window::
OnCustomApplicationMessage(WPARAM wParam, LPARAM lParam)
{
    DcMeth();
    UNUSED(wParam);
    UNUSED(lParam);
    return 0;
}

LRESULT Window::
OnCustomRegisteredMessage(WPARAM wParam, LPARAM lParam)
{
    DcMeth();
    UNUSED(wParam);
    UNUSED(lParam);
    return 0;
}

}//namespace rrMFC
