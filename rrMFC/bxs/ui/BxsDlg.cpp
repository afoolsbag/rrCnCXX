/// \copyright The MIT License

#include "stdafx.h"
#include "BxsDlg.h"

#include <functional>

#include "rrwindows/dbgcon.h"

BEGIN_MESSAGE_MAP(BoxesDialog, CDialog)
    ON_BN_CLICKED(IDC_PROGRESS_BUTTON, &BoxesDialog::OnBnClickedButton)
END_MESSAGE_MAP()

#// Constructors

BoxesDialog::
BoxesDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConMeth();
}

BoxesDialog::
~BoxesDialog()
{
    DbgConMeth();
}

#// Overridables

BOOL BoxesDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConMeth();
    return TRUE;
}

BOOL BoxesDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConWndMsg();
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID BoxesDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConMeth();
}

UINT BoxesDialog::
ThreadFunction(ProgressDialog *CONST pProgressDialog)
{
    pProgressDialog->SetTitle(TEXT("Target"));
    pProgressDialog->SetTotal(TEXT("Total progress"));
    pProgressDialog->SetTotal(0, 100);
    pProgressDialog->SetCurrent(TEXT("Current progress"));
    pProgressDialog->SetCurrent(0, 100);
    INT total = 0;
    INT current = 0;
    while (ThreadLoopFlag) {
        ++current;
        if (100 < current) {
            current -= 100;
            ++total;
        }
        pProgressDialog->SetCurrent(current);
        pProgressDialog->SetTotal(total);
        if (100 == total && 100 == current)
            break;
        Sleep(1);
    }
    return EXIT_SUCCESS;
}

VOID BoxesDialog::
OnBnClickedButton()
{
    DbgConMeth();
    ProgressDialog dlg;
    ThreadLoopFlag = TRUE;
    dlg.SetThreadFunction(std::bind(&BoxesDialog::ThreadFunction, this, std::placeholders::_1));
    dlg.DoModal();
}
