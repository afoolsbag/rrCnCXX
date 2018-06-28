/// \copyright The MIT License

#include "stdafx.h"
#include "PropPg1.h"

#include "rrwindows/dbgcon.h"

//BEGIN_MESSAGE_MAP(PropertyPage1, CPropertyPage)
//END_MESSAGE_MAP()

#// Constructors

PropertyPage1::
PropertyPage1()
    : CPropertyPage(IDD)
{
    DcMeth();
}

PropertyPage1::
~PropertyPage1()
{
    DcMeth();
}

#// Overridables

BOOL PropertyPage1::
OnInitDialog()
{
    CPropertyPage::OnInitDialog();
    DcMeth();
    return TRUE;
}

BOOL PropertyPage1::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DcWndMsg();
    return CPropertyPage::OnWndMsg(message, wParam, lParam, pResult);
}

VOID PropertyPage1::
DoDataExchange(CDataExchange *pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    DcMeth();
}

VOID PropertyPage1::
OnOK()
{
    DcMeth();
    CPropertyPage::OnOK();
}

VOID PropertyPage1::
OnCancel()
{
    DcMeth();
    CPropertyPage::OnCancel();
}

BOOL PropertyPage1::
OnApply()
{
    DcMeth();
    return CPropertyPage::OnApply();
}

#// Message Handlers
