/// \copyright The MIT License

#include "stdafx.h"
#include "MainDialog.h"

#include "rrwindows/dbgcon.h"

IMPLEMENT_DYNCREATE(MainDialog, CDialog)

BEGIN_MESSAGE_MAP(MainDialog, CDialog)
    ON_CBN_SELCHANGE(IDC_COMBO_BOX, &MainDialog::OnCbnSelchangeComboBox)
    ON_BN_CLICKED(IDC_CHECK_BOX, &MainDialog::OnBnClickedCheckBox)
    ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATE_TIME_PICKER, &MainDialog::OnDtnDatetimechangeDateTimePicker)
    ON_NOTIFY(IPN_FIELDCHANGED, IDC_IP_ADDRESS, &MainDialog::OnIpnFieldchangedIpAddress)
    ON_LBN_SELCHANGE(IDC_LIST_BOX, &MainDialog::OnLbnSelchangeListBox)
    ON_NOTIFY(MCN_SELCHANGE, IDC_MONTH_CALENDAR, &MainDialog::OnMcnSelchangeMonthCalendar)
    ON_BN_CLICKED(IDC_RADIO_GROUP_1_BUTTON_1, &MainDialog::OnBnClickedRadioGroup1)
    ON_BN_CLICKED(IDC_RADIO_GROUP_1_BUTTON_2, &MainDialog::OnBnClickedRadioGroup1)
    ON_BN_CLICKED(IDC_RADIO_GROUP_1_BUTTON_3, &MainDialog::OnBnClickedRadioGroup1)
    ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER, &MainDialog::OnNMCustomdrawSlider)
    ON_EN_CHANGE(IDC_EDIT, &MainDialog::OnEnChangeEdit)
END_MESSAGE_MAP()

#// Constructors

MainDialog::
MainDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DbgConPrtMeth(Yellow);
}

MainDialog::
~MainDialog()
{
    DbgConPrtMeth(Yellow);
}

#// Overridables

BOOL MainDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DbgConPrtMeth(Yellow);

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

BOOL MainDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DbgConPrtMethWndMsg(Yellow);
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

VOID MainDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DbgConPrtMeth(Yellow);
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

VOID MainDialog::
OnCbnSelchangeComboBox()
{
    DbgConPrtMeth(Yellow);
    UpdateData(TRUE);
    DbgConPrt(White, TEXT("ComboIndex: %d, ComboText: %s.\n"), ComboIndex, static_cast<LPCTSTR>(ComboText));
}

VOID MainDialog::
OnBnClickedCheckBox()
{
    DbgConPrtMeth(Yellow);
    UpdateData(TRUE);
    DbgConPrt(White, TEXT("Checked: %s.\n"), Checked ? TEXT("TRUE") : TEXT("FALSE"));
}

VOID MainDialog::
OnDtnDatetimechangeDateTimePicker(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
    DbgConPrtMeth(Yellow);
    UpdateData(TRUE);
    DbgConPrt(White, TEXT("DateTime: %s.\n"), static_cast<LPCTSTR>(DateTime.Format(TEXT("%#c"))));
    *pResult = 0;
}

VOID MainDialog::
OnIpnFieldchangedIpAddress(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMIPADDRESS pIPAddr = reinterpret_cast<LPNMIPADDRESS>(pNMHDR);
    DbgConPrtMeth(Yellow);
    UpdateData(TRUE);
    DbgConPrt(White, TEXT("IpAddress: %lu.%lu.%lu.%lu.\n"),
              IpAddress >> 24 & 0xFF,
              IpAddress >> 16 & 0xFF,
              IpAddress >> 8 & 0xFF,
              IpAddress & 0xFF);
    *pResult = 0;
}

VOID MainDialog::
OnLbnSelchangeListBox()
{
    DbgConPrtMeth(Yellow);
    UpdateData(TRUE);
    DbgConPrt(White, TEXT("ListIndex: %d, ListText: %s.\n"), ListIndex, static_cast<LPCTSTR>(ListText));
}

VOID MainDialog::
OnMcnSelchangeMonthCalendar(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMSELCHANGE pSelChange = reinterpret_cast<LPNMSELCHANGE>(pNMHDR);
    DbgConPrtMeth(Yellow);
    UpdateData(TRUE);
    DbgConPrt(White, TEXT("Month: %s.\n"), static_cast<LPCTSTR>(Month.Format(TEXT("%#c"))));
    *pResult = 0;
}

VOID MainDialog::
OnBnClickedRadioGroup1()
{
    DbgConPrtMeth(Yellow);
    UpdateData(TRUE);
    DbgConPrt(White, TEXT("RadioGroup1: Radio%d.\n"), 1 + RadioGroup1);
}

VOID MainDialog::
OnNMCustomdrawSlider(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
    DbgConPrtMeth(Yellow);
    UpdateData(TRUE);
    DbgConPrt(White, TEXT("SliderValue: %d.\n"), SliderValue);
    *pResult = 0;
}

VOID MainDialog::
OnEnChangeEdit()
{
    DbgConPrtMeth(Yellow);
    UpdateData(TRUE);
    DbgConPrt(White, TEXT("Text: %s.\n"), static_cast<LPCTSTR>(EditText));
    StaticText = EditText;
    UpdateData(FALSE);
}
