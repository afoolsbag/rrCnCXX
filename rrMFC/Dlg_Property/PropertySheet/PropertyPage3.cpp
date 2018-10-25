/// \copyright The Unlicense

#include "stdafx.h"
#include "PropertyPage3.h"
#include "PropertySheet.rc.h"

#include "rrwindows/rrwindows.h"

namespace rrMFC {
namespace Test {

const UINT PropertyPage3::IDD {IDD_PROPERTY_PAGE_3};

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
ReadFrom(CONST Configurations &configs)
{
    DcMeth();
#ifdef M
# error Macro name conflicts.
#endif/*M*/
#define M(prop) (prop = configs.prop)
    M(PostgreIpaddr);
    M(PostgreIpport);
    M(RedisIpaddr);
    M(RedisIpport);
    M(RabbitIpaddr);
    M(RabbitIpport);
    M(HumanIpaddr);
    M(HumanIpport);
    M(VehicleIpaddr);
    M(VehicleIpport);
#undef M
}

VOID PropertyPage3::
WriteTo(Configurations *CONST pConfigs) CONST
{
    DcMeth();
#ifdef M
# error Macro name conflicts.
#endif/*M*/
#define M(prop) (pConfigs->prop = prop)
    M(PostgreIpaddr);
    M(PostgreIpport);
    M(RedisIpaddr);
    M(RedisIpport);
    M(RabbitIpaddr);
    M(RabbitIpport);
    M(HumanIpaddr);
    M(HumanIpport);
    M(VehicleIpaddr);
    M(VehicleIpport);
#undef M
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

    DDX_IPAddress(pDX, IDC_POSTGRE_IPADDR, PostgreIpaddr);
    DDX_Text(pDX, IDC_POSTGRE_IPPORT, PostgreIpport);
    DDV_MinMaxUInt(pDX, PostgreIpport, 0, 65535);

    DDX_IPAddress(pDX, IDC_REDIS_IPADDR, RedisIpaddr);
    DDX_Text(pDX, IDC_REDIS_IPPORT, RedisIpport);
    DDV_MinMaxUInt(pDX, RedisIpport, 0, 65535);

    DDX_IPAddress(pDX, IDC_RABBIT_IPADDR, RabbitIpaddr);
    DDX_Text(pDX, IDC_RABBIT_IPPORT, RabbitIpport);
    DDV_MinMaxUInt(pDX, RabbitIpport, 0, 65535);

    DDX_IPAddress(pDX, IDC_HUMAN_IPADDR, HumanIpaddr);
    DDX_Text(pDX, IDC_HUMAN_IPPORT, HumanIpport);
    DDV_MinMaxUInt(pDX, HumanIpport, 0, 65535);

    DDX_IPAddress(pDX, IDC_VEHICLE_IPADDR, VehicleIpaddr);
    DDX_Text(pDX, IDC_VEHICLE_IPPORT, VehicleIpport);
    DDV_MinMaxUInt(pDX, VehicleIpport, 0, 65535);
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

}//namespace Test
}//namespace rrMFC
