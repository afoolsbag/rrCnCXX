//===-- Property Page 2 -----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 资源页2（类）。
///
/// \verison 2018-05-31
/// \since 2018-05-31
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "resource.h"

/// \brief 资源页2（类）。
class PropertyPage2: public CPropertyPage {
    DECLARE_DYNCREATE(PropertyPage2)

#// Constructors
public:
    PropertyPage2();
    virtual ~PropertyPage2() override;

#// Attributes
public:
    enum { IDD = IDD_PROPERTY_PAGE_2 };

#// Operations
public:

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

#// Message Handlers
protected:

    //DECLARE_MESSAGE_MAP()
};
