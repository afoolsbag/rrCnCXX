//===-- Property Page 1 -----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 资源页1（类）。
///
/// \verison 2018-06-28
/// \since 2018-05-31
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "BxsApp.h"
#include "propdlg.resource.h"

/// \brief 资源页1（类）。
class PropertyPage1: public CPropertyPage {

#// Constructors
public:
    PropertyPage1();
    virtual ~PropertyPage1() override;

#// Attributes
public:
    enum { IDD = IDD_PROPERTY_PAGE_1 };

#// Operations
public:
    VOID ReadFrom(CONST BoxesOption &opt);
    VOID WriteTo(BoxesOption *CONST pOpt);

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
    CIPAddressCtrl ServiceIpaddressEdit;
    DWORD          ServiceIpaddress = 0uL;

    CEdit          ServiceIpportEdit;
    UINT           ServiceIpport = 0u;

#// Message Handlers
protected:

    //DECLARE_MESSAGE_MAP()
};
