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

namespace rrMFC {
namespace Test {

///
/// \brief 资源页 3 类。
///
class PropertyPage3: public CPropertyPage {

#// Constructors
public:
    PropertyPage3();
    ~PropertyPage3() final;

#// Attributes
public:
    static const unsigned IDD;

#// Operations
public:
    void ReadFrom(const Configurations &configs);
    void WriteTo(Configurations *const pConfigs) const;

#// Overridables
public:
    BOOL OnInitDialog() final;
protected:
    BOOL OnWndMsg(unsigned message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) final;
    void DoDataExchange(CDataExchange *pDX) final;

    void OnOK() final;
    void OnCancel() final;
    BOOL OnApply() final;

#// Implementation
protected:
    DWORD PostgreIpaddr = 0uL;
    unsigned  PostgreIpport = 0u;

    DWORD RedisIpaddr = 0uL;
    unsigned  RedisIpport = 0u;

    DWORD RabbitIpaddr = 0uL;
    unsigned  RabbitIpport = 0u;

    DWORD HumanIpaddr = 0uL;
    unsigned  HumanIpport = 0u;

    DWORD VehicleIpaddr = 0uL;
    unsigned  VehicleIpport = 0u;

#// Message Handlers
protected:

};

}//namespace Test
}//namespace rrMFC
