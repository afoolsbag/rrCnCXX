//===-- Property Page 2 -----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 资源页 2 类。
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
/// \brief 资源页 2 类。
///
class PropertyPage2: public CPropertyPage {

#// Constructors
public:
    PropertyPage2();
    virtual ~PropertyPage2() override;

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
    BOOL StretchMatching = FALSE;
    BOOL ToneshiftMatching = FALSE;
    BOOL SharpenMatching = FALSE;
    BOOL ContrastMatching = FALSE;

    INT  Operation = -1;

    CSliderCtrl ConfidenceSlider;
    CEdit       ConfidenceEdit;
    INT         Confidence = 0;

#// Message Handlers
protected:
    afx_msg VOID OnNMCustomdrawConfidenceSlider(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg VOID OnEnChangeConfidenceEdit();

    DECLARE_MESSAGE_MAP()
};

}//namespace Test
}//namespace rrMFC
