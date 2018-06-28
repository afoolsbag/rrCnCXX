/// \copyright The MIT License

#include "stdafx.h"
#include "PropPg3.h"

#include "rrwindows/dbgcon.h"

//BEGIN_MESSAGE_MAP(PropertyPage3, CPropertyPage)
//END_MESSAGE_MAP()

#// Constructors

PropertyPage3::
PropertyPage3()
    : CPropertyPage(IDD)
{
    DcMeth();
}

PropertyPage3::
~PropertyPage3()
{
    DcMeth();
}

#// Overridables

BOOL PropertyPage3::
OnInitDialog()
{
    CPropertyPage::OnInitDialog();
    DcMeth();
    return TRUE;
}

BOOL PropertyPage3::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DcWndMsg();
    return CPropertyPage::OnWndMsg(message, wParam, lParam, pResult);
}

VOID PropertyPage3::
DoDataExchange(CDataExchange *pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    DcMeth();
}

VOID PropertyPage3::
OnOK()
{
    DcMeth();
    CPropertyPage::OnOK();
}

VOID PropertyPage3::
OnCancel()
{
    DcMeth();
    CPropertyPage::OnCancel();
}

BOOL PropertyPage3::
OnApply()
{
    DcMeth();
    return CPropertyPage::OnApply();
}

#// Message Handlers
