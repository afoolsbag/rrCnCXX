/// \copyright The MIT License

#include "stdafx.h"
#include "PropPg2.h"

#include "rrwindows/dbgcon.h"

//BEGIN_MESSAGE_MAP(PropertyPage2, CPropertyPage)
//END_MESSAGE_MAP()

#// Constructors

PropertyPage2::
PropertyPage2()
    : CPropertyPage(IDD)
{
    DcMeth();
}

PropertyPage2::
~PropertyPage2()
{
    DcMeth();
}

#// Overridables

BOOL PropertyPage2::
OnInitDialog()
{
    CPropertyPage::OnInitDialog();
    DcMeth();
    return TRUE;
}

BOOL PropertyPage2::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DcWndMsg();
    return CPropertyPage::OnWndMsg(message, wParam, lParam, pResult);
}

VOID PropertyPage2::
DoDataExchange(CDataExchange *pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    DcMeth();
}

VOID PropertyPage2::
OnOK()
{
    DcMeth();
    CPropertyPage::OnOK();
}

VOID PropertyPage2::
OnCancel()
{
    DcMeth();
    CPropertyPage::OnCancel();
}

BOOL PropertyPage2::
OnApply()
{
    DcMeth();
    return CPropertyPage::OnApply();
}

#// Message Handlers
