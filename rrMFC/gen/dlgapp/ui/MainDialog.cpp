/// \copyright The MIT License

#include "stdafx.h"
#include "resource.h"
#include "MainDialog.h"

#include <conio.h>

#include "../concol.inl"
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
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::Constructor\n"));
}

MainDialog::~MainDialog()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::Destructor\n"));
}

BOOL MainDialog::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    SetConsoleForeFroundColor(Yellow);
    _tcprintf_s(TEXT("MainDialog::OnWndMsg 0x%04X(%s), with %u, %ld, 0x%p\n"), message, SysMsgStr(message), wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainDialog::PreInitDialog()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::PreInitDialog\n"));
    CDialog::PreInitDialog();
}

VOID MainDialog::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::DoDataExchange\n"));
}

BOOL MainDialog::OnInitDialog()
{
    CDialog::OnInitDialog();
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnInitDialog\n"));
    return TRUE;
}

VOID MainDialog::PostNcDestroy()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::PostNcDestroy\n"));
    CDialog::PostNcDestroy();
}

BOOL MainDialog::OnNcCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (!CDialog::OnNcCreate(lpCreateStruct))
        return FALSE;
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnNcCreate\n"));
    return TRUE;
}

VOID MainDialog::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS *lpncsp)
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnNcCalcSize\n"));
    CDialog::OnNcCalcSize(bCalcValidRects, lpncsp);
}

INT MainDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnCreate\n"));
    return 0;
}

VOID MainDialog::OnSize(UINT nType, INT cx, INT cy)
{
    CDialog::OnSize(nType, cx, cy);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnSize\n"));
}

VOID MainDialog::OnMove(INT x, INT y)
{
    CDialog::OnMove(x, y);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnMove\n"));
}

VOID MainDialog::OnWindowPosChanging(WINDOWPOS *lpwndpos)
{
    CDialog::OnWindowPosChanging(lpwndpos);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnWindowPosChanging\n"));
}

VOID MainDialog::OnWindowPosChanged(WINDOWPOS *lpwndpos)
{
    CDialog::OnWindowPosChanged(lpwndpos);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnWindowPosChanged\n"));
}

VOID MainDialog::OnActivateApp(BOOL bActive, DWORD dwThreadID)
{
    CDialog::OnActivateApp(bActive, dwThreadID);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnActivateApp\n"));
}

BOOL MainDialog::OnNcActivate(BOOL bActive)
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnNcActivate\n"));
    return CDialog::OnNcActivate(bActive);
}

VOID MainDialog::OnActivate(UINT nState, CWnd *pWndOther, BOOL bMinimized)
{
    CDialog::OnActivate(nState, pWndOther, bMinimized);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnActivate\n"));
}

VOID MainDialog::OnChangeUIState(UINT nAction, UINT nUIElement)
{
    CDialog::OnChangeUIState(nAction, nUIElement);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnChangeUIState\n"));
}

VOID MainDialog::OnNcRenderingChanged(BOOL bIsRendering)
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnNcRenderingChanged\n"));
    CDialog::OnNcRenderingChanged(bIsRendering);
}

VOID MainDialog::OnShowWindow(BOOL bShow, UINT nStatus)
{
    CDialog::OnShowWindow(bShow, nStatus);
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnShowWindow\n"));
}

VOID MainDialog::OnNcPaint()
{
    CDialog::OnNcPaint();
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnNcPaint\n"));
}

BOOL MainDialog::OnEraseBkgnd(CDC *pDC)
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnEraseBkgnd\n"));
    return CDialog::OnEraseBkgnd(pDC);
}

VOID MainDialog::OnPaint()
{
    CDialog::OnPaint();
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnPaint\n"));
}

VOID MainDialog::OnClose()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnClose\n"));
    CDialog::OnClose();
}

VOID MainDialog::OnDestroy()
{
    CDialog::OnDestroy();
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnDestroy\n"));
}

VOID MainDialog::OnNcDestroy()
{
    CDialog::OnNcDestroy();
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog::OnNcDestroy\n"));
}

VOID MainDialog::OnBnClickedOk()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog>>IDOK\n"));
    CDialog::OnOK();
}

VOID MainDialog::OnBnClickedCancel()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog>>IDCANCEL\n"));
    CDialog::OnCancel();
}

VOID MainDialog::OnBnClickedAbort()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog>>IDABORT\n"));
}

VOID MainDialog::OnBnClickedRetry()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog>>IDRETRY\n"));
}

VOID MainDialog::OnBnClickedIgnore()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog>>IDIGNORE\n"));
}

VOID MainDialog::OnBnClickedYes()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog>>IDYES\n"));
}

VOID MainDialog::OnBnClickedNo()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog>>IDNO\n"));
}

VOID MainDialog::OnBnClickedClose()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog>>IDCLOSE\n"));
}

VOID MainDialog::OnBnClickedHelp()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog>>IDHELP\n"));
}

VOID MainDialog::OnBnClickedHandButton()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog>>IDC_HAND_BUTTON\n"));
    AfxMessageBox(TEXT("Hand"), MB_ICONHAND);
}

VOID MainDialog::OnBnClickedQuestionButton()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog>>IDC_QUESTION_BUTTON\n"));
    AfxMessageBox(TEXT("Question"), MB_ICONQUESTION);
}

VOID MainDialog::OnBnClickedExclamationButton()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog>>IDC_EXCLAMATION_BUTTON\n"));
    AfxMessageBox(TEXT("Exclamation"), MB_ICONEXCLAMATION);
}

VOID MainDialog::OnBnClickedAsteriskButton()
{
    SetConsoleForeFroundColor(LightYellow);
    _cputts(TEXT("MainDialog>>IDC_ASTERISK_BUTTON\n"));
    AfxMessageBox(TEXT("Asterisk"), MB_ICONASTERISK);
}

