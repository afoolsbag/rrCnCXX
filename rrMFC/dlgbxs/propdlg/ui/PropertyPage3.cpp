/// \copyright The MIT License

#include "stdafx.h"
#include "PropertyPage3.h"

#include "rrwindows/dbgcon.h"

IMPLEMENT_DYNCREATE(PropertyPage3, CPropertyPage)

//BEGIN_MESSAGE_MAP(PropertyPage3, CPropertyPage)
//END_MESSAGE_MAP()

#// Constructors

PropertyPage3::
PropertyPage3()
    : CPropertyPage(IDD)
{
    DbgConPrtMeth(Yellow);
}

PropertyPage3::
~PropertyPage3()
{
    DbgConPrtMeth(Yellow);
}

#// Overridables

BOOL PropertyPage3::
OnInitDialog()
{
    CPropertyPage::OnInitDialog();
    DbgConPrtMeth(Yellow);
    return TRUE;
}

BOOL PropertyPage3::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtMethWndMsg(Yellow);
    return CPropertyPage::OnWndMsg(message, wParam, lParam, pResult);
}

VOID PropertyPage3::
DoDataExchange(CDataExchange *pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    DbgConPrtMeth(Yellow);
}

VOID PropertyPage3::
OnOK()
{
    DbgConPrtMeth(Yellow);
    CPropertyPage::OnOK();
}

VOID PropertyPage3::
OnCancel()
{
    DbgConPrtMeth(Yellow);
    CPropertyPage::OnCancel();
}

BOOL PropertyPage3::
OnApply()
{
    DbgConPrtMeth(Yellow);
    return CPropertyPage::OnApply();
}

#// Message Handlers
