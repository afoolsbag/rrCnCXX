//===-- Property Page 1 -----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 资源页 1 类。
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

///
/// \brief 资源页 1 类。
///
class PropertyPage1: public CPropertyPage {

#// Constructors
public:
    PropertyPage1();
    virtual ~PropertyPage1() override;

#// Attributes
public:
    static const UINT IDD;

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
    DWORD ServiceIpaddr = 0uL;
    UINT  ServiceIpport = 0u;

#// Message Handlers
protected:

};

}//namespace rrMFC
