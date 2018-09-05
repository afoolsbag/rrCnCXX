/// \copyright The Unlicense

#include "stdafx.h"
#include "DdxDialog.h"

#include "rrwindows/rrwindows.h"

namespace rrMFC {

BEGIN_MESSAGE_MAP(DdxDialog, CDialog)
    ON_CBN_SELCHANGE(IDC_COMBO_BOX, &DdxDialog::OnCbnSelchangeComboBox)
    ON_BN_CLICKED(IDC_CHECK_BOX, &DdxDialog::OnBnClickedCheckBox)
    ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATE_TIME_PICKER, &DdxDialog::OnDtnDatetimechangeDateTimePicker)
    ON_NOTIFY(IPN_FIELDCHANGED, IDC_IP_ADDRESS, &DdxDialog::OnIpnFieldchangedIpAddress)
    ON_LBN_SELCHANGE(IDC_LIST_BOX, &DdxDialog::OnLbnSelchangeListBox)
    ON_NOTIFY(MCN_SELCHANGE, IDC_MONTH_CALENDAR, &DdxDialog::OnMcnSelchangeMonthCalendar)
    ON_BN_CLICKED(IDC_RADIO_GROUP_1_BUTTON_1, &DdxDialog::OnBnClickedRadioGroup1)
    ON_BN_CLICKED(IDC_RADIO_GROUP_1_BUTTON_2, &DdxDialog::OnBnClickedRadioGroup1)
    ON_BN_CLICKED(IDC_RADIO_GROUP_1_BUTTON_3, &DdxDialog::OnBnClickedRadioGroup1)
    ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER, &DdxDialog::OnNMCustomdrawSlider)
    ON_EN_CHANGE(IDC_EDIT, &DdxDialog::OnEnChangeEdit)
END_MESSAGE_MAP()

#// Constructors

DdxDialog::
DdxDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DcMeth();
}

DdxDialog::
~DdxDialog()
{
    DcMeth();
}

#// Overridables

BOOL DdxDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DcMeth();

    ComboBox.AddString(TEXT("item 1"));
    ComboBox.AddString(TEXT("item 2"));
    ComboBox.AddString(TEXT("item 3"));
    ComboBox.AddString(TEXT("item 4"));

    ListBox.AddString(TEXT("item 1"));
    ListBox.AddString(TEXT("item 2"));
    ListBox.AddString(TEXT("item 3"));
    ListBox.AddString(TEXT("item 4"));

    VerticalScrollBar.SetScrollRange(0, 100, FALSE);
    HorizontalScrollBar.SetScrollRange(0, 100, FALSE);
    Slider.SetRange(0, 100, FALSE);

    return TRUE;
}

BOOL DdxDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DcWndMsg();
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID DdxDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DcMeth();

    DDX_Control(pDX, IDC_COMBO_BOX, ComboBox);
    DDX_CBString(pDX, IDC_COMBO_BOX, ComboText);
    DDX_CBIndex(pDX, IDC_COMBO_BOX, ComboIndex);

    DDX_Control(pDX, IDC_CHECK_BOX, CheckBox);
    DDX_Check(pDX, IDC_CHECK_BOX, Checked);

    DDX_Control(pDX, IDC_DATE_TIME_PICKER, DateTimePicker);
    DDX_DateTimeCtrl(pDX, IDC_DATE_TIME_PICKER, DateTime);

    DDX_Control(pDX, IDC_IP_ADDRESS, IpAddressEdit);
    DDX_IPAddress(pDX, IDC_IP_ADDRESS, IpAddress);

    DDX_Control(pDX, IDC_LIST_BOX, ListBox);
    DDX_LBString(pDX, IDC_LIST_BOX, ListText);
    DDX_LBIndex(pDX, IDC_LIST_BOX, ListIndex);

    DDX_Control(pDX, IDC_MONTH_CALENDAR, MonthCalendar);
    DDX_MonthCalCtrl(pDX, IDC_MONTH_CALENDAR, Month);

    DDX_Control(pDX, IDC_RADIO_GROUP_1_BUTTON_1, RadioGroup1Button1);
    DDX_Control(pDX, IDC_RADIO_GROUP_1_BUTTON_2, RadioGroup1Button2);
    DDX_Control(pDX, IDC_RADIO_GROUP_1_BUTTON_3, RadioGroup1Button3);
    DDX_Radio(pDX, IDC_RADIO_GROUP_1_BUTTON_1, RadioGroup1);

    DDX_Control(pDX, IDC_VERTICAL_SCROLL_BAR, VerticalScrollBar);
    DDX_Scroll(pDX, IDC_VERTICAL_SCROLL_BAR, VerticalScrollPosition);
    DDX_Control(pDX, IDC_HORIZONTAL_SCROLL_BAR, HorizontalScrollBar);
    DDX_Scroll(pDX, IDC_HORIZONTAL_SCROLL_BAR, HorizontalScrollPosition);

    DDX_Control(pDX, IDC_SLIDER, Slider);
    DDX_Slider(pDX, IDC_SLIDER, SliderValue);

    DDX_Control(pDX, IDC_EDIT, Edit);
    DDX_Text(pDX, IDC_EDIT, EditText);

    DDX_Control(pDX, IDC_STATIC_CONTROL, Static);
    DDX_Text(pDX, IDC_STATIC_CONTROL, StaticText);
}

VOID DdxDialog::
OnCbnSelchangeComboBox()
{
    DcMeth();
    UpdateData(TRUE);
    DcKPrint(White, TEXT("ComboIndex: %d, ComboText: %s.\n"), ComboIndex, static_cast<LPCTSTR>(ComboText));
}

VOID DdxDialog::
OnBnClickedCheckBox()
{
    DcMeth();
    UpdateData(TRUE);
    DcKPrint(White, TEXT("Checked: %s.\n"), Checked ? TEXT("TRUE") : TEXT("FALSE"));
}

VOID DdxDialog::
OnDtnDatetimechangeDateTimePicker(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
    DcMeth();
    UpdateData(TRUE);
    DcKPrint(White, TEXT("DateTime: %s.\n"), static_cast<LPCTSTR>(DateTime.Format(TEXT("%#c"))));
    *pResult = 0;
}

VOID DdxDialog::
OnIpnFieldchangedIpAddress(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMIPADDRESS pIPAddr = reinterpret_cast<LPNMIPADDRESS>(pNMHDR);
    DcMeth();
    UpdateData(TRUE);
    DcKPrint(White, TEXT("IpAddress: %lu.%lu.%lu.%lu.\n"),
             IpAddress >> 24 & 0xFF,
             IpAddress >> 16 & 0xFF,
             IpAddress >> 8 & 0xFF,
             IpAddress & 0xFF);
    *pResult = 0;
}

VOID DdxDialog::
OnLbnSelchangeListBox()
{
    DcMeth();
    UpdateData(TRUE);
    DcKPrint(White, TEXT("ListIndex: %d, ListText: %s.\n"), ListIndex, static_cast<LPCTSTR>(ListText));
}

VOID DdxDialog::
OnMcnSelchangeMonthCalendar(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMSELCHANGE pSelChange = reinterpret_cast<LPNMSELCHANGE>(pNMHDR);
    DcMeth();
    UpdateData(TRUE);
    DcKPrint(White, TEXT("Month: %s.\n"), static_cast<LPCTSTR>(Month.Format(TEXT("%#c"))));
    *pResult = 0;
}

VOID DdxDialog::
OnBnClickedRadioGroup1()
{
    DcMeth();
    UpdateData(TRUE);
    DcKPrint(White, TEXT("RadioGroup1: Radio%d.\n"), 1 + RadioGroup1);
}

VOID DdxDialog::
OnNMCustomdrawSlider(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
    DcMeth();
    UpdateData(TRUE);
    DcKPrint(White, TEXT("SliderValue: %d.\n"), SliderValue);
    *pResult = 0;
}

VOID DdxDialog::
OnEnChangeEdit()
{
    DcMeth();
    UpdateData(TRUE);
    DcKPrint(White, TEXT("Text: %s.\n"), static_cast<LPCTSTR>(EditText));
    StaticText = EditText;
    UpdateData(FALSE);
}

}//namespace rrMFC
