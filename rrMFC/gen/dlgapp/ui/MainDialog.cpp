/// \copyright The MIT License

#include "stdafx.h"
#include "resource.h"
#include "MainDialog.h"

#include <conio.h>

#include "../sysmsgstr.inl"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_WM_NCCREATE()
    ON_WM_NCCALCSIZE()
    ON_WM_CREATE()
    ON_WM_SIZE()
    ON_WM_MOVE()
    ON_WM_WINDOWPOSCHANGING()
    ON_WM_WINDOWPOSCHANGED()
    ON_WM_ACTIVATEAPP()
    ON_WM_NCACTIVATE()
    ON_WM_ACTIVATE()
    ON_WM_CHANGEUISTATE()
    ON_WM_DWMNCRENDERINGCHANGED()
    ON_WM_SHOWWINDOW()
    ON_WM_NCPAINT()
    ON_WM_ERASEBKGND()
    ON_WM_PAINT()

    ON_WM_CLOSE()
    ON_WM_DESTROY()
    ON_WM_NCDESTROY()

    ON_BN_CLICKED(IDOK, &MainDialog::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &MainDialog::OnBnClickedCancel)
    ON_BN_CLICKED(IDABORT, &MainDialog::OnBnClickedAbort)
    ON_BN_CLICKED(IDRETRY, &MainDialog::OnBnClickedRetry)
    ON_BN_CLICKED(IDIGNORE, &MainDialog::OnBnClickedIgnore)
    ON_BN_CLICKED(IDYES, &MainDialog::OnBnClickedYes)
    ON_BN_CLICKED(IDNO, &MainDialog::OnBnClickedNo)
    ON_BN_CLICKED(IDCLOSE, &MainDialog::OnBnClickedClose)
    ON_BN_CLICKED(IDHELP, &MainDialog::OnBnClickedHelp)

    ON_BN_CLICKED(IDC_HAND_BUTTON, &MainDialog::OnBnClickedHandButton)
    ON_BN_CLICKED(IDC_QUESTION_BUTTON, &MainDialog::OnBnClickedQuestionButton)
    ON_BN_CLICKED(IDC_EXCLAMATION_BUTTON, &MainDialog::OnBnClickedExclamationButton)
    ON_BN_CLICKED(IDC_ASTERISK_BUTTON, &MainDialog::OnBnClickedAsteriskButton)
END_MESSAGE_MAP()

MainDialog::MainDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    _cputts(TEXT("\tMainDialog::Constructor\n"));
}

MainDialog::~MainDialog()
{
    _cputts(TEXT("\tMainDialog::Destructor\n"));
}

BOOL MainDialog::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    _tcprintf_s(TEXT("\tMainDialog::OnWndMsg 0x%04X(%s), with %u, %ld, 0x%p\n"), message, SysMsgStr(message), wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainDialog::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    _cputts(TEXT("\tMainDialog::DoDataExchange\n"));
}

BOOL MainDialog::OnInitDialog()
{
    CDialog::OnInitDialog();
    _cputts(TEXT("\tMainDialog::OnInitDialog\n"));
    return TRUE;
}

BOOL MainDialog::OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (!CDialog::OnNcCreate(lpCreateStruct))
        return FALSE;
    _cputts(TEXT("\tMainDialog::OnNcCreate\n"));
    return TRUE;
}

VOID MainDialog::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp)
{
    _cputts(TEXT("\tMainDialog::OnNcCalcSize\n"));
    CDialog::OnNcCalcSize(bCalcValidRects, lpncsp);
}

INT MainDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;
    _cputts(TEXT("\tMainDialog::OnCreate\n"));
    return 0;
}

VOID MainDialog::OnSize(UINT nType, INT cx, INT cy)
{
    CDialog::OnSize(nType, cx, cy);
    _cputts(TEXT("\tMainDialog::OnSize\n"));
}

VOID MainDialog::OnMove(INT x, INT y)
{
    CDialog::OnMove(x, y);
    _cputts(TEXT("\tMainDialog::OnMove\n"));
}

VOID MainDialog::OnWindowPosChanging(WINDOWPOS *lpwndpos)
{
    CDialog::OnWindowPosChanging(lpwndpos);
    _cputts(TEXT("\tMainDialog::OnWindowPosChanging\n"));
}

VOID MainDialog::OnWindowPosChanged(WINDOWPOS *lpwndpos)
{
    CDialog::OnWindowPosChanged(lpwndpos);
    _cputts(TEXT("\tMainDialog::OnWindowPosChanged\n"));
}

VOID MainDialog::OnActivateApp(BOOL bActive, DWORD dwThreadID)
{
    CDialog::OnActivateApp(bActive, dwThreadID);
    _cputts(TEXT("\tMainDialog::OnActivateApp\n"));
}

BOOL MainDialog::OnNcActivate(BOOL bActive)
{
    _cputts(TEXT("\tMainDialog::OnNcActivate\n"));
    return CDialog::OnNcActivate(bActive);
}

VOID MainDialog::OnActivate(UINT nState, CWnd *pWndOther, BOOL bMinimized)
{
    CDialog::OnActivate(nState, pWndOther, bMinimized);
    _cputts(TEXT("\tMainDialog::OnActivate\n"));
}

VOID MainDialog::OnChangeUIState(UINT nAction, UINT nUIElement)
{
    CDialog::OnChangeUIState(nAction, nUIElement);
    _cputts(TEXT("\tMainDialog::OnChangeUIState\n"));
}

VOID MainDialog::OnNcRenderingChanged(BOOL bIsRendering)
{
    _cputts(TEXT("\tMainDialog::OnNcRenderingChanged\n"));
    CDialog::OnNcRenderingChanged(bIsRendering);
}

VOID MainDialog::OnShowWindow(BOOL bShow, UINT nStatus)
{
    CDialog::OnShowWindow(bShow, nStatus);
    _cputts(TEXT("\tMainDialog::OnShowWindow\n"));
}

VOID MainDialog::OnNcPaint()
{
    CDialog::OnNcPaint();
    _cputts(TEXT("\tMainDialog::OnNcPaint\n"));
}

BOOL MainDialog::OnEraseBkgnd(CDC *pDC)
{
    _cputts(TEXT("\tMainDialog::OnEraseBkgnd\n"));
    return CDialog::OnEraseBkgnd(pDC);
}

VOID MainDialog::OnPaint()
{
    CDialog::OnPaint();
    _cputts(TEXT("\tMainDialog::OnPaint\n"));
}

VOID MainDialog::OnClose()
{
    _cputts(TEXT("\tMainDialog::OnClose\n"));
    CDialog::OnClose();
}

VOID MainDialog::OnDestroy()
{
    CDialog::OnDestroy();
    _cputts(TEXT("\tMainDialog::OnDestroy\n"));
}

VOID MainDialog::OnNcDestroy()
{
    CDialog::OnNcDestroy();
    _cputts(TEXT("\tMainDialog::OnNcDestroy\n"));
}

VOID MainDialog::OnBnClickedOk()
{
    _cputts(TEXT("\tMainDialog>>IDOK\n"));
    CDialog::OnOK();
}

VOID MainDialog::OnBnClickedCancel()
{
    _cputts(TEXT("\tMainDialog>>IDCANCEL\n"));
    CDialog::OnCancel();
}

VOID MainDialog::OnBnClickedAbort()
{
    _cputts(TEXT("\tMainDialog>>IDABORT\n"));
}

VOID MainDialog::OnBnClickedRetry()
{
    _cputts(TEXT("\tMainDialog>>IDRETRY\n"));
}

VOID MainDialog::OnBnClickedIgnore()
{
    _cputts(TEXT("\tMainDialog>>IDIGNORE\n"));
}

VOID MainDialog::OnBnClickedYes()
{
    _cputts(TEXT("\tMainDialog>>IDYES\n"));
}

VOID MainDialog::OnBnClickedNo()
{
    _cputts(TEXT("\tMainDialog>>IDNO\n"));
}

VOID MainDialog::OnBnClickedClose()
{
    _cputts(TEXT("\tMainDialog>>IDCLOSE\n"));
}

VOID MainDialog::OnBnClickedHelp()
{
    _cputts(TEXT("\tMainDialog>>IDHELP\n"));
}

VOID MainDialog::OnBnClickedHandButton()
{
    _cputts(TEXT("\tMainDialog>>IDC_HAND_BUTTON\n"));
    AfxMessageBox(TEXT("Hand"), MB_ICONHAND);
}

VOID MainDialog::OnBnClickedQuestionButton()
{
    _cputts(TEXT("\tMainDialog>>IDC_QUESTION_BUTTON\n"));
    AfxMessageBox(TEXT("Question"), MB_ICONQUESTION);
}

VOID MainDialog::OnBnClickedExclamationButton()
{
    _cputts(TEXT("\tMainDialog>>IDC_EXCLAMATION_BUTTON\n"));
    AfxMessageBox(TEXT("Exclamation"), MB_ICONEXCLAMATION);
}

VOID MainDialog::OnBnClickedAsteriskButton()
{
    _cputts(TEXT("\tMainDialog>>IDC_ASTERISK_BUTTON\n"));
    AfxMessageBox(TEXT("Asterisk"), MB_ICONASTERISK);
}
