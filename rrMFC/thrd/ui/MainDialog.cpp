/// \copyright The MIT License

#include "stdafx.h"
#include "MainDialog.h"

#include "rrwindows/dbgcon.h"
#include "rrwindows/dbgprt.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_BN_CLICKED(IDC_START_BUTTON, &MainDialog::OnBnClickedStartButton)
    ON_BN_CLICKED(IDC_STOP_BUTTON, &MainDialog::OnBnClickedStopButton)
    ON_WM_TIMER()
END_MESSAGE_MAP()

#// Constructors

MainDialog::
MainDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrtMeth(Yellow);
}

MainDialog::
~MainDialog()
{
    DbgConPrtMeth(Yellow);
}

#// Overridables

BOOL MainDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConPrtMeth(Yellow);
    return TRUE;
}

BOOL MainDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtMethWndMsg(Yellow);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrtMeth(Yellow);
    DDX_Control(pDX, IDC_NUMBER_STATIC, NumberStaticControl);
    DDX_Text(pDX, IDC_NUMBER_STATIC, Number);
}

UINT MainDialog::
CountThreadFunction(LPVOID pParam)
{
    UNUSED_ALWAYS(pParam);
    while (CountThreadLoopFlag) {
        ++Count;
        Sleep(1);
    }
    return EXIT_SUCCESS;
}

UINT MainDialog::
CountThreadWrapper(LPVOID pObject)
{
    MainDialog *CONST self = reinterpret_cast<MainDialog*>(pObject);
    ASSERT(self);
    return self->CountThreadFunction(NULL);
}

VOID MainDialog::
OnTimer(UINT_PTR nIDEvent)
{
    switch (nIDEvent) {
    case REFRESH_UI:
        UpdateData(FALSE);
        break;
    case UPDATE_NUMBER_REFRESH_UI:
        Number = Count;
        UpdateData(FALSE);
        break;
    default:
        ASSERT(FALSE);
        DbgConPrt(White, TEXT("Unknown TimerId(%u) in MainDialog::OnTimer switch-case-default.\n"), nIDEvent);
        DbgPrtD(TEXT("Unknown TimerId(%u) in MainDialog::OnTimer switch-case-default.\n"), nIDEvent);
        break;
    }

    CDialog::OnTimer(nIDEvent);
}

VOID MainDialog::
OnBnClickedStartButton()
{
    DbgConPrtMeth(Yellow);
    if (!CountThreadLoopFlag) {
        CountThreadLoopFlag = TRUE;
        CountThread = AfxBeginThread(CountThreadWrapper, this);
        SetTimer(UPDATE_NUMBER_REFRESH_UI, 40, NULL);
    }
}

VOID MainDialog::
OnBnClickedStopButton()
{
    DbgConPrtMeth(Yellow);
    if (CountThreadLoopFlag) {
        CountThreadLoopFlag = FALSE;
        CountThread = NULL;
        KillTimer(UPDATE_NUMBER_REFRESH_UI);
    }
}
