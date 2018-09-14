//===-- DDX Dialog ----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 数据交换对话框类。
///
/// \verison 2018-09-14
/// \since 2018-05-30
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

namespace rrMFC {
namespace Test {

///
/// \brief 数据交换对话框类。
///
class DdxDialog: public CDialog {

#// Constructors
public:
    DdxDialog(CWnd *pParent = nullptr);
    ~DdxDialog() final;

#// Attributes
public:
    static const unsigned IDD;

#// Operations
public:

#// Overridables
public:
    BOOL OnInitDialog() final;
protected:
    BOOL OnWndMsg(unsigned message, WPARAM wParam, LPARAM lParam, LRESULT *pResult) final;
    void DoDataExchange(CDataExchange *pDX) final;

#// Implementation
protected:
    CComboBox      ComboBox;
    CString        ComboText;
    int            ComboIndex {0};

    CButton        CheckBox;
    BOOL           Checked {FALSE};

    CDateTimeCtrl  DateTimePicker;
    CTime          DateTime {CTime::GetCurrentTime()};

    CIPAddressCtrl IpAddressEdit;
    DWORD          IpAddress {0uL};

    CListBox       ListBox;
    CString        ListText;
    int            ListIndex {-1};

    CMonthCalCtrl  MonthCalendar;
    CTime          Month {CTime::GetCurrentTime()};

    CButton        RadioGroup1Button1;
    CButton        RadioGroup1Button2;
    CButton        RadioGroup1Button3;
    int            RadioGroup1 {-1};

    CScrollBar     VerticalScrollBar;
    int            VerticalScrollPosition {0};
    CScrollBar     HorizontalScrollBar;
    int            HorizontalScrollPosition {0};

    CSliderCtrl    Slider;
    int            SliderValue {0};

    CEdit          Edit;
    CString        EditText;

    CStatic        Static;
    CString        StaticText;

#// Message Handlers
protected:
    afx_msg void OnCbnSelchangeComboBox();
    afx_msg void OnBnClickedCheckBox();
    afx_msg void OnDtnDatetimechangeDateTimePicker(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnIpnFieldchangedIpAddress(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnLbnSelchangeListBox();
    afx_msg void OnMcnSelchangeMonthCalendar(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnBnClickedRadioGroup1();
    afx_msg void OnNMCustomdrawSlider(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnEnChangeEdit();

    DECLARE_MESSAGE_MAP()
};

}//namespace Test
}//namespace rrMFC
