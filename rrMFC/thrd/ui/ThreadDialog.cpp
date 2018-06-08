/// \copyright The MIT License

#include "stdafx.h"
#include "ThreadDialog.h"

#include "rrwindows/dbgcon.h"
#include "rrwindows/dbgprt.h"

IMPLEMENT_DYNAMIC(ThreadDialog, CDialog)

BEGIN_MESSAGE_MAP(ThreadDialog, CDialog)
    ON_BN_CLICKED(IDC_START_BUTTON, &ThreadDialog::OnBnClickedStartButton)
    ON_BN_CLICKED(IDC_STOP_BUTTON, &ThreadDialog::OnBnClickedStopButton)
    ON_WM_TIMER()
END_MESSAGE_MAP()

#// Constructors

ThreadDialog::
ThreadDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrtMeth(Yellow);
}

ThreadDialog::
~ThreadDialog()
{
    DbgConPrtMeth(Yellow);
}

#// Overridables

BOOL ThreadDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConPrtMeth(Yellow);
    return TRUE;
}

BOOL ThreadDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtMethWndMsg(Yellow);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID ThreadDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrtMeth(Yellow);
    DDX_Control(pDX, IDC_NUMBER_STATIC, NumberStaticControl);
    DDX_Text(pDX, IDC_NUMBER_STATIC, Number);
}

UINT ThreadDialog::
CountThreadFunction(LPVOID pParam)
{
    UNUSED_ALWAYS(pParam);
    while (CountThreadLoopFlag) {
        ++Number;
        Sleep(1);
    }
    return EXIT_SUCCESS;
}

UINT ThreadDialog::
CountThreadWrapper(LPVOID pObject)
{
    ThreadDialog *CONST self = reinterpret_cast<ThreadDialog*>(pObject);
    if (!self || !self->IsKindOf(RUNTIME_CLASS(ThreadDialog))) {
        ASSERT(FALSE);
        DbgPrtD(TEXT("Failed with invalid self pointer.\n"));
        return EXIT_FAILURE;
    }
    return self->CountThreadFunction(NULL);
}

VOID ThreadDialog::
OnTimer(UINT_PTR nIDEvent)
{
    switch (nIDEvent) {
    case REFRESH_UI:
        UpdateData(FALSE);
        break;
    default:
        ASSERT(FALSE);
        DbgPrtD(TEXT("Failed with unknown switch-case-route: nIDEvent=%u.\n"), nIDEvent);
        break;
    }

    CDialog::OnTimer(nIDEvent);
}

VOID ThreadDialog::
OnBnClickedStartButton()
{
    DbgConPrtMeth(Yellow);
    if (!CountThread) {
        CountThreadLoopFlag = TRUE;
        CountThread = AfxBeginThread(CountThreadWrapper, this);
        SetTimer(REFRESH_UI, 40, NULL);
    }
}

VOID ThreadDialog::
OnBnClickedStopButton()
{
    DbgConPrtMeth(Yellow);
    if (CountThread) {
        CountThreadLoopFlag = FALSE;
        CountThread = NULL;
        KillTimer(REFRESH_UI);
    }
}
