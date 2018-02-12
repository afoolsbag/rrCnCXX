/// \copyright The MIT License

#include "ComboBoxList/stdafx.h"
#include "ComboBoxList/ComboBoxListMainWnd.h"

#include "ComboBoxList/resource.h"

BEGIN_MESSAGE_MAP(CComboBoxListMainWnd, CFrameWnd)
    ON_WM_CREATE()
END_MESSAGE_MAP()

CComboBoxListMainWnd::CComboBoxListMainWnd()
{
    Create(NULL, TEXT("The Combo Box List Application"));
}

INT CComboBoxListMainWnd::OnCreate(LPCREATESTRUCT creating_info)
{
    if (-1 == CFrameWnd::OnCreate(creating_info))
        return -1;

    CRect client_area;
    GetClientRect(&client_area);

    //LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_HEADERDRAGDROP
    combo_box_list_ctrl_.CreateEx(
        LVS_EX_GRIDLINES,
        LVS_ALIGNLEFT | WS_BORDER | LVS_REPORT | WS_VISIBLE,
        client_area, this, IDC_COMBO_BOX_LIST);

    DWORD style;

    style = combo_box_list_ctrl_.GetStyle();
    TRACE("\nDEBUG: style: %lx\n", style);

    style = combo_box_list_ctrl_.GetExtendedStyle();
    TRACE("\nDEBUG: ex style: %lx\n", style);

    style |= LVS_EX_GRIDLINES;
    combo_box_list_ctrl_.SetExtendedStyle(style);
    style = combo_box_list_ctrl_.GetExtendedStyle();
    TRACE("\nDEBUG: ex style: %lx\n", style);

    combo_box_list_ctrl_.InsertColumn(0, TEXT("属性"), LVCFMT_LEFT, 80);
    combo_box_list_ctrl_.InsertColumn(1, TEXT("值"), LVCFMT_LEFT, 180);

    CStringArray commbo_values;
    commbo_values.Add("haha");
    commbo_values.Add("haha2");
    commbo_values.Add("haha3");
    combo_box_list_ctrl_.InsertItem(0, TEXT("TEST"));
    combo_box_list_ctrl_.SetComboboxItem(0, 1, "haha", commbo_values);
    //ctrl_combo_box_list_.SetItemText(0, 1, TEXT("TEST"));
    //ctrl_combo_box_list_.SetComboboxVisible(0, 1, TRUE);
    //ctrl_combo_box_list_.SetComboboxVisible(0, 2, TRUE);
    //ctrl_combo_box_list_.SetItemText(1, 1, TEXT("TEST2"));

    return 0;
}
