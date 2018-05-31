/// \copyright The MIT License

#include "stdafx.h"
#include "PropertyPage1.h"

#include "rrwindows/dbgcon.h"

IMPLEMENT_DYNCREATE(PropertyPage1, CPropertyPage)

//BEGIN_MESSAGE_MAP(PropertyPage1, CPropertyPage)
//END_MESSAGE_MAP()

#// Constructors

PropertyPage1::
PropertyPage1()
    : CPropertyPage(IDD)
{
    DbgConPrtMeth(Yellow);
}

PropertyPage1::
~PropertyPage1()
{
    DbgConPrtMeth(Yellow);
}

#// Overridables

BOOL PropertyPage1::
OnInitDialog()
{
    CPropertyPage::OnInitDialog();
    DbgConPrtMeth(Yellow);
    return TRUE;
}

BOOL PropertyPage1::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtMethWndMsg(Yellow);
    return CPropertyPage::OnWndMsg(message, wParam, lParam, pResult);
}

VOID PropertyPage1::
DoDataExchange(CDataExchange *pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    DbgConPrtMeth(Yellow);
}

VOID PropertyPage1::
OnOK()
{
    DbgConPrtMeth(Yellow);
    CPropertyPage::OnOK();
}

VOID PropertyPage1::
OnCancel()
{
    DbgConPrtMeth(Yellow);
    CPropertyPage::OnCancel();
}

BOOL PropertyPage1::
OnApply()
{
    DbgConPrtMeth(Yellow);
    return CPropertyPage::OnApply();
}

#// Message Handlers
