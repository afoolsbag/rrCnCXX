//===-- Property Page 3 -----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 资源页 3 类。
///
/// \verison 2018-09-05
/// \since 2018-05-31
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include "Application.h"
#include "PropertySheet.rc.h"

namespace rrMFC {

///
/// \brief 资源页 3 类。
///
class PropertyPage3: public CPropertyPage {

#// Constructors
public:
    PropertyPage3();
    virtual ~PropertyPage3() override;

#// Attributes
public:
    enum { IDD = IDD_PROPERTY_PAGE_3 };

#// Operations
public:
    VOID ReadFrom(CONST Configurations &configs);
    VOID WriteTo(Configurations *CONST pConfigs) CONST;

#// Overridables
public:
    virtual BOOL OnInitDialog() override;
protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) override;
    virtual VOID DoDataExchange(CDataExchange *pDX) override;

    virtual VOID OnOK() override;
    virtual VOID OnCancel() override;
    virtual BOOL OnApply() override;

#// Implementation
protected:
    DWORD PostgreIpaddr = 0uL;
    UINT  PostgreIpport = 0u;

    DWORD RedisIpaddr = 0uL;
    UINT  RedisIpport = 0u;

    DWORD RabbitIpaddr = 0uL;
    UINT  RabbitIpport = 0u;

    DWORD HumanIpaddr = 0uL;
    UINT  HumanIpport = 0u;

    DWORD VehicleIpaddr = 0uL;
    UINT  VehicleIpport = 0u;

#// Message Handlers
protected:

};

}//namespace rrMFC
