/// \copyright The MIT License

#include "stdafx.h"
#include "PropertyPage2.h"

#include "rrwindows/dbgcon.h"

IMPLEMENT_DYNCREATE(PropertyPage2, CPropertyPage)

//BEGIN_MESSAGE_MAP(PropertyPage2, CPropertyPage)
//END_MESSAGE_MAP()

#// Constructors

PropertyPage2::
PropertyPage2()
    : CPropertyPage(IDD)
{
    DbgConPrtMeth(Yellow);
}

PropertyPage2::
~PropertyPage2()
{
    DbgConPrtMeth(Yellow);
}

#// Overridables

BOOL PropertyPage2::
OnInitDialog()
{
    CPropertyPage::OnInitDialog();
    DbgConPrtMeth(Yellow);
    return TRUE;
}

BOOL PropertyPage2::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtMethWndMsg(Yellow);
    return CPropertyPage::OnWndMsg(message, wParam, lParam, pResult);
}

VOID PropertyPage2::
DoDataExchange(CDataExchange *pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    DbgConPrtMeth(Yellow);
}

VOID PropertyPage2::
OnOK()
{
    DbgConPrtMeth(Yellow);
    CPropertyPage::OnOK();
}

VOID PropertyPage2::
OnCancel()
{
    DbgConPrtMeth(Yellow);
    CPropertyPage::OnCancel();
}

BOOL PropertyPage2::
OnApply()
{
    DbgConPrtMeth(Yellow);
    return CPropertyPage::OnApply();
}

#// Message Handlers
