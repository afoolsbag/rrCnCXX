/// \copyright The MIT License

#include "stdafx.h"
#include "resource.h"
#include "MainDialog.h"

#include "conio.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_WM_CREATE()
    ON_WM_SIZE()
    ON_WM_CLOSE()
    ON_WM_DESTROY()

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
    _cputts(TEXT("MainDialog::Constructor\n"));
}

MainDialog::~MainDialog()
{
    _cputts(TEXT("MainDialog::Destructor\n"));
}

BOOL MainDialog::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    _tcprintf_s(TEXT("MainDialog::OnWndMsg(0x%X, %u, %ld, 0x%p)\n"), message, wParam, lParam, pResult);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainDialog::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    _cputts(TEXT("MainDialog::DoDataExchange\n"));
}

BOOL MainDialog::OnInitDialog()
{
    CDialog::OnInitDialog();
    _cputts(TEXT("MainDialog::OnInitDialog\n"));
    return TRUE;
}

INT MainDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CDialog::OnCreate(lpCreateStruct) == -1)
        return -1;
    _cputts(TEXT("MainDialog <WM_CREATE\n"));
    return 0;
}

VOID MainDialog::OnSize(UINT nType, INT cx, INT cy)
{
    CDialog::OnSize(nType, cx, cy);
    _cputts(TEXT("MainDialog <WM_SIZE\n"));
}

VOID MainDialog::OnClose()
{
    _cputts(TEXT("MainDialog <WM_CLOSE\n"));
    CDialog::OnClose();
}

VOID MainDialog::OnDestroy()
{
    CDialog::OnDestroy();
    _cputts(TEXT("MainDialog <WM_DESTROY\n"));
}

VOID MainDialog::OnBnClickedOk()
{
    _cputts(TEXT("MainDialog #IDOK\n"));
    CDialog::OnOK();
}

VOID MainDialog::OnBnClickedCancel()
{
    _cputts(TEXT("MainDialog #IDCANCEL\n"));
    CDialog::OnCancel();
}

VOID MainDialog::OnBnClickedAbort()
{
    _cputts(TEXT("MainDialog #IDABORT\n"));
}

VOID MainDialog::OnBnClickedRetry()
{
    _cputts(TEXT("MainDialog #IDRETRY\n"));
}

VOID MainDialog::OnBnClickedIgnore()
{
    _cputts(TEXT("MainDialog #IDIGNORE\n"));
}

VOID MainDialog::OnBnClickedYes()
{
    _cputts(TEXT("MainDialog #IDYES\n"));
}

VOID MainDialog::OnBnClickedNo()
{
    _cputts(TEXT("MainDialog #IDNO\n"));
}

VOID MainDialog::OnBnClickedClose()
{
    _cputts(TEXT("MainDialog #IDCLOSE\n"));
}

VOID MainDialog::OnBnClickedHelp()
{
    _cputts(TEXT("MainDialog #IDHELP\n"));
}

VOID MainDialog::OnBnClickedHandButton()
{
    _cputts(TEXT("MainDialog #IDC_HAND_BUTTON\n"));
    AfxMessageBox(TEXT("Hand"), MB_ICONHAND);
}

VOID MainDialog::OnBnClickedQuestionButton()
{
    _cputts(TEXT("MainDialog #IDC_QUESTION_BUTTON\n"));
    AfxMessageBox(TEXT("Question"), MB_ICONQUESTION);
}

VOID MainDialog::OnBnClickedExclamationButton()
{
    _cputts(TEXT("MainDialog #IDC_EXCLAMATION_BUTTON\n"));
    AfxMessageBox(TEXT("Exclamation"), MB_ICONEXCLAMATION);
}

VOID MainDialog::OnBnClickedAsteriskButton()
{
    _cputts(TEXT("MainDialog #IDC_ASTERISK_BUTTON\n"));
    AfxMessageBox(TEXT("Asterisk"), MB_ICONASTERISK);
}

