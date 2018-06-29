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
    ServiceIpaddress = opt.ServiceIpaddress;
    ServiceIpport = opt.ServiceIpport;
    UpdateData(FALSE);
}

VOID PropertyPage1::
WriteTo(BoxesOption *CONST pOpt)
{
    DcMeth();
    UpdateData(FALSE);
    pOpt->ServiceIpaddress = ServiceIpaddress;
    pOpt->ServiceIpport = ServiceIpport;
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

    DDX_Control(pDX, IDC_SERVICE_IPADDRESS, ServiceIpaddressEdit);
    DDX_IPAddress(pDX, IDC_SERVICE_IPADDRESS, ServiceIpaddress);

    DDX_Control(pDX, IDC_SERVICE_IPPORT, ServiceIpportEdit);
    DDX_Text(pDX, IDC_SERVICE_IPPORT, ServiceIpport);
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
