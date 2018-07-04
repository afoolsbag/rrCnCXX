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

#// Operations

VOID PropertyPage1::
ReadFrom(CONST BoxesOption& opt)
{
    DcMeth();
#ifdef M
# error Macro name conflicts.
#endif/*M*/
#define M(prop) (prop = opt.prop)
    M(ServiceIpaddr);
    M(ServiceIpport);
#undef M
}

VOID PropertyPage1::
WriteTo(BoxesOption *CONST pOpt) CONST
{
    DcMeth();
#ifdef M
# error Macro name conflicts.
#endif/*M*/
#define M(prop) (pOpt->prop = prop)
    M(ServiceIpaddr);
    M(ServiceIpport);
#undef M
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

    DDX_IPAddress(pDX, IDC_SERVICE_IPADDR, ServiceIpaddr);
    DDX_Text(pDX, IDC_SERVICE_IPPORT, ServiceIpport);
    DDV_MinMaxUInt(pDX, ServiceIpport, 0, 65535);
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
