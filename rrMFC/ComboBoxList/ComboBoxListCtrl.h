//===-- Class Combo Box List Control ----------------------------*- C++ -*-===//
///
/// \file
/// \brief 组合框列表控件类
///
/// \sa ["CGridListCtrlEx"](https://codeproject.com/Articles/29064/CGridListCtrlEx). *CodeProject*.
///
/// \author zhengrr
/// \date 2018-2-8 – 11
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#define CCBIDCNUM 713		    //给combobox分配的IDC
#define MAXCOMOBOBOXROW 1024    //最大行数
#define MAXCOMOBOBOXCOL 3	    //最大列数

#define WM_USER_COMBO_SEL_CHANGED WM_USER + 6001

#include <afxwin.h>
#include <afxcmn.h>

/// \brief Class Combo Box List Control
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/clistctrl-class
/// \sa https://docs.microsoft.com/cpp/mfc/reference/ccombobox-class
class CComboBoxListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CComboBoxListCtrl)

public:
	CComboBoxListCtrl();
	virtual ~CComboBoxListCtrl();

    //nRow 行(0~)
    //nCol 列(0~)
    //s_defaultitem(初始值)
    //s_comboitem(列表数组)
	BOOL SetComboboxItem(int nRow, int nCol, const char * s_defaultitem, CStringArray& s_comboitem);
    void SetComboboxVisible(int nRow, int nCol, BOOL visible);

	afx_msg void OnKillfocusCmbBox();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnCbnSelchangeCombo();

public:
	CComboBox *ccb;
	int c_row;
	int c_col;
	CFont font;
    CStringArray* cbbContainer[MAXCOMOBOBOXROW][MAXCOMOBOBOXCOL];
    BOOL ccbVisible[MAXCOMOBOBOXROW][MAXCOMOBOBOXCOL];

protected:
	DECLARE_MESSAGE_MAP()
};


