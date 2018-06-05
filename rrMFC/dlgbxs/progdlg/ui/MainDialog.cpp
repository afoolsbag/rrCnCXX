/// \copyright The MIT License

#include "stdafx.h"
#include "MainDialog.h"

#include <functional>

#include "rrwindows/dbgcon.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_BN_CLICKED(IDC_BUTTON, &MainDialog::OnBnClickedButton)
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
}

UINT MainDialog::
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

VOID MainDialog::
OnBnClickedButton()
{
    DbgConPrtMeth(Yellow);
    ProgressDialog Dlg;
    ThreadLoopFlag = TRUE;
    Dlg.SetThreadFunction(std::bind(&MainDialog::ThreadFunction, this, std::placeholders::_1));
    Dlg.DoModal();
}
