/// \copyright The MIT License

#include "stdafx.h"
#include "resource.h"
#include "MainDialog.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_WM_TIMER()
END_MESSAGE_MAP()

MainDialog::MainDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{}

VOID MainDialog::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_CONTEXT, ContextControl);
}

// https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#settimer
BOOL MainDialog::OnInitDialog()
{
    CDialog::OnInitDialog();

    SetTimer(TimerId::Increase, 1000/*ms*/, NULL);

    return TRUE;
}

// https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#ontimer
VOID MainDialog::OnTimer(UINT_PTR nIDEvent)
{
    switch (nIDEvent) {
    case TimerId::Increase: {
        static INT StaticNumber = 0;
        ++StaticNumber;
        CString text;
        text.Format(TEXT("%d"), StaticNumber);
        ContextControl.SetWindowText(text);
        break;
    }
    default:
        ASSERT(FALSE);
        break;
    }
}
