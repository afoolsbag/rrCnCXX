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
ThreadFunction(ProgressBox *CONST pProgBox)
{
    pProgBox->SetTitle(TEXT("Target"));
    pProgBox->SetTotal(TEXT("Total progress"));
    pProgBox->SetTotal(0, 100);
    pProgBox->SetCurrent(TEXT("Current progress"));
    pProgBox->SetCurrent(0, 100);
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
        pProgBox->SetCurrent(current);
        pProgBox->SetTotal(total);
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
    ProgressBox box;
    box.SetThreadFunction(std::bind(&BoxesDialog::ThreadFunction, this, std::placeholders::_1));
    box.DoModal();
}

VOID BoxesDialog::
OnBnClickedProperty()
{
    DcMeth();

    auto CONST pApp = reinterpret_cast<BoxesApplication *>(AfxGetApp());
    pApp->ReadOptionFromProfile();

    CPropertySheet sheet(TEXT("Properties Sheet"));

    PropertyPage1 page1;
    page1.ReadFrom(pApp->Option);
    sheet.AddPage(&page1);

    PropertyPage2 page2;
    page2.ReadFrom(pApp->Option);
    sheet.AddPage(&page2);

    PropertyPage3 page3;
    page3.ReadFrom(pApp->Option);
    sheet.AddPage(&page3);

    CONST INT_PTR result = sheet.DoModal();
    switch (result) {
    case IDOK:
        page1.WriteTo(&pApp->Option);
        page2.WriteTo(&pApp->Option);
        page3.WriteTo(&pApp->Option);
        pApp->WriteOptionToProfile();
        break;
    case IDCANCEL:
        break;
    default:
        DpErrorSwitchUnknown(result);
        break;
    }
}
