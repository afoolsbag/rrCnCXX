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

#// Operations

VOID PropertyPage3::
ReadFrom(CONST BoxesOption& opt)
{
    DcMeth();
    RedisIpaddr = opt.RedisIpaddr;
    RedisIpport = opt.RedisIpport;
    RabbitIpaddr = opt.RabbitIpaddr;
    RabbitIpport = opt.RabbitIpport;
}

VOID PropertyPage3::
WriteTo(BoxesOption *CONST pOpt) CONST
{
    DcMeth();
    pOpt->RedisIpaddr = RedisIpaddr;
    pOpt->RedisIpport = RedisIpport;
    pOpt->RabbitIpaddr = RabbitIpaddr;
    pOpt->RabbitIpport = RabbitIpport;
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

    DDX_Control(pDX, IDC_REDIS_IPADDR, RedisIpaddrEdit);
    DDX_IPAddress(pDX, IDC_REDIS_IPADDR, RedisIpaddr);

    DDX_Control(pDX, IDC_REDIS_IPPORT, RedisIpportEdit);
    DDX_Text(pDX, IDC_REDIS_IPPORT, RedisIpport);
    DDV_MinMaxUInt(pDX, RedisIpport, 0, 65535);

    DDX_Control(pDX, IDC_RABBIT_IPADDR, RabbitIpaddrEdit);
    DDX_IPAddress(pDX, IDC_RABBIT_IPADDR, RabbitIpaddr);

    DDX_Control(pDX, IDC_RABBIT_IPPORT, RabbitIpportEdit);
    DDX_Text(pDX, IDC_RABBIT_IPPORT, RabbitIpport);
    DDV_MinMaxUInt(pDX, RabbitIpport, 0, 65535);
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
