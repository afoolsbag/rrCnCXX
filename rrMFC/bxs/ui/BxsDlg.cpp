/// \copyright The MIT License

#include "stdafx.h"
#include "BxsDlg.h"

#include <functional>
#include <random>

#include "rrwindows/dbgcon.h"
#include "rrwindows/dbgprt.h"

#include "ddxdlg/DdxDlg.h"
#include "propdlg/PropPg1.h"
#include "propdlg/PropPg2.h"
#include "propdlg/PropPg3.h"

BEGIN_MESSAGE_MAP(BoxesDialog, CDialog)
    ON_BN_CLICKED(IDC_DDX_BUTTON, &BoxesDialog::OnBnClickedDdx)
    ON_BN_CLICKED(IDC_PROGRESS_BUTTON, &BoxesDialog::OnBnClickedProgress)
    ON_BN_CLICKED(IDC_PROPERTY_BUTTON, &BoxesDialog::OnBnClickedProperty)
END_MESSAGE_MAP()

#// Constructors

BoxesDialog::
BoxesDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DcMeth();
}

BoxesDialog::
~BoxesDialog()
{
    DcMeth();
}

#// Overridables

BOOL BoxesDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DcMeth();
    return TRUE;
}

BOOL BoxesDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DcWndMsg();
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID BoxesDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DcMeth();
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

    std::random_device rndDev;
    std::mt19937 rndGen(rndDev());
    std::uniform_int_distribution<> rndDist(1, 6);
    while (TRUE) {
        current += rndDist(rndGen);
        if (100 <= current) {
            current -= 100;
            ++total;
        }
        pProgressDialog->SetCurrent(current);
        pProgressDialog->SetTotal(total);
        if (100 <= total)
            break;
        Sleep(1);
    }
    return EXIT_SUCCESS;
}

VOID BoxesDialog::
OnBnClickedDdx()
{
    DcMeth();
    DdxDialog dlg;
    dlg.DoModal();
}

VOID BoxesDialog::
OnBnClickedProgress()
{
    DcMeth();
    ProgressDialog dlg;
    dlg.SetThreadFunction(std::bind(&BoxesDialog::ThreadFunction, this, std::placeholders::_1));
    dlg.DoModal();
}

VOID BoxesDialog::
OnBnClickedProperty()
{
    DcMeth();

    auto &option = reinterpret_cast<BoxesApplication *>(AfxGetApp())->option;

    CPropertySheet propertySheetDialog(TEXT("Properties Sheet"));

    PropertyPage1 propertyPage1;
    propertyPage1.ReadFrom(option);
    propertySheetDialog.AddPage(&propertyPage1);

    PropertyPage2 propertyPage2;
    propertySheetDialog.AddPage(&propertyPage2);

    PropertyPage3 propertyPage3;
    propertySheetDialog.AddPage(&propertyPage3);

    CONST INT_PTR result = propertySheetDialog.DoModal();
    switch (result) {
    case IDOK:
        propertyPage1.WriteTo(&option);
        break;
    case IDCANCEL:
        break;
    default:
        DpErrorSwitchUnknown(result);
        break;
    }
}
