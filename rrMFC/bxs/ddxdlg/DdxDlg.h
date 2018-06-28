//===-- Main Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 数据交换对话框（类）。
///
/// \verison 2018-06-28
/// \since 2018-05-30
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "ddxdlg.resource.h"

/// \brief 数据交换对话框（类）。
class DdxDialog: public CDialog {

#// Constructors
public:
    DdxDialog(CWnd *pParent = NULL);
    virtual ~DdxDialog() override;

#// Attributes
public:
    enum { IDD = IDD_DDX_DIALOG };

#// Operations
public:

#// Overridables
public:
    virtual BOOL OnInitDialog() override;
protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) override;
    virtual VOID DoDataExchange(CDataExchange *pDX) override;

#// Implementation
protected:
    CComboBox      ComboBox;
    CString        ComboText;
    INT            ComboIndex = 0;

    CButton        CheckBox;
    BOOL           Checked = FALSE;

    CDateTimeCtrl  DateTimePicker;
    CTime          DateTime = CTime::GetCurrentTime();

    CIPAddressCtrl IpAddressEdit;
    DWORD          IpAddress = 0uL;

    CListBox       ListBox;
    CString        ListText;
    INT            ListIndex = -1;

    CMonthCalCtrl  MonthCalendar;
    CTime          Month = CTime::GetCurrentTime();

    CButton        RadioGroup1Button1;
    CButton        RadioGroup1Button2;
    CButton        RadioGroup1Button3;
    INT            RadioGroup1 = -1;

    CScrollBar     VerticalScrollBar;
    INT            VerticalScrollPosition = 0;
    CScrollBar     HorizontalScrollBar;
    INT            HorizontalScrollPosition = 0;

    CSliderCtrl    Slider;
    INT            SliderValue = 0;

    CEdit          Edit;
    CString        EditText;

    CStatic        Static;
    CString        StaticText;

#// Message Handlers
protected:
    afx_msg VOID OnCbnSelchangeComboBox();
    afx_msg VOID OnBnClickedCheckBox();
    afx_msg VOID OnDtnDatetimechangeDateTimePicker(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg VOID OnIpnFieldchangedIpAddress(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg VOID OnLbnSelchangeListBox();
    afx_msg VOID OnMcnSelchangeMonthCalendar(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg VOID OnBnClickedRadioGroup1();
    afx_msg VOID OnNMCustomdrawSlider(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg VOID OnEnChangeEdit();

    DECLARE_MESSAGE_MAP()
public:
};
