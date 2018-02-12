/// \copyright The MIT License

#include "ComboBoxList/stdafx.h"
#include "ComboBoxList/ComboBoxListCtrl.h"

#include <WinUser.h>

//
// 修改CComboBox控件自动匹配机制
//
WNDPROC OriginalListProc = NULL;
LRESULT CALLBACK MyListProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == LB_FINDSTRING) {
        msg = LB_FINDSTRINGEXACT;
    }

    if (OriginalListProc) {
        return CallWindowProc(OriginalListProc, hWnd, msg, wParam, lParam);
    }

    return 0;
}

// CComboBoxListCtrl

IMPLEMENT_DYNAMIC(CComboBoxListCtrl, CListCtrl)

CComboBoxListCtrl::CComboBoxListCtrl()
{
    VERIFY(font.CreateFont(
        14,                        // nHeight
        0,                         // nWidth
        0,                         // nEscapement
        0,                         // nOrientation
        FW_NORMAL,                 // nWeight
        FALSE,                     // bItalic
        FALSE,                     // bUnderline
        0,                         // cStrikeOut
        ANSI_CHARSET,              // nCharSet
        OUT_DEFAULT_PRECIS,        // nOutPrecision
        CLIP_DEFAULT_PRECIS,       // nClipPrecision
        DEFAULT_QUALITY,           // nQuality
        DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
        "Arial"));                 // lpszFacename

    ccb = NULL;
    for (int i = 0; i < MAXCOMOBOBOXROW; i++) {
        for (int j = 0; j < MAXCOMOBOBOXCOL; j++) {
            cbbContainer[i][j] = NULL;
            ccbVisible[i][j] = FALSE;
        }
    }
}

CComboBoxListCtrl::~CComboBoxListCtrl()
{
    for (int i = 0; i < MAXCOMOBOBOXROW; i++) {
        for (int j = 0; j < MAXCOMOBOBOXCOL; j++) {
            if (cbbContainer[i][j] != NULL) {
                cbbContainer[i][j]->RemoveAll();
                delete cbbContainer[i][j];
            }
        }
    }
}


BEGIN_MESSAGE_MAP(CComboBoxListCtrl, CListCtrl)
    //{{AFX_MSG_MAP(CComboBoxListCtrl)
    ON_WM_LBUTTONDOWN()
    //}}AFX_MSG_MAP
    ON_CBN_KILLFOCUS(CCBIDCNUM, OnKillfocusCmbBox)
    ON_WM_HSCROLL()		// OnHScroll
    ON_WM_VSCROLL()		// OnVScroll
    ON_CBN_SELCHANGE(CCBIDCNUM, OnCbnSelchangeCombo)
END_MESSAGE_MAP()

BOOL CComboBoxListCtrl::SetComboboxItem(int nRow, int nCol, const char * s_defaultitem, CStringArray& s_comboitem)
{
    if (nRow < 0 || nRow >= MAXCOMOBOBOXROW || nCol < 0 || nCol >= MAXCOMOBOBOXCOL) {
        return FALSE;
    }

    if (cbbContainer[nRow][nCol] != NULL) {
        cbbContainer[nRow][nCol]->RemoveAll();
        delete cbbContainer[nRow][nCol];
    }

    cbbContainer[nRow][nCol] = new CStringArray;
    for (int i = 0; i < s_comboitem.GetCount(); i++) {
        cbbContainer[nRow][nCol]->Add(s_comboitem.GetAt(i));
    }

    //设置初始值
    this->SetItemText(nRow, nCol, s_defaultitem);

    return TRUE;
}

void CComboBoxListCtrl::SetComboboxVisible(int nRow, int nCol, BOOL visible)
{
    if (nRow < 0 || nRow >= MAXCOMOBOBOXROW || nCol < 0 || nCol >= MAXCOMOBOBOXCOL) {
        return;
    }

    ccbVisible[nRow][nCol] = visible;
}

// CComboBoxListCtrl message handlers


void CComboBoxListCtrl::OnKillfocusCmbBox()
{
    CString selStr;
    if (ccb) {
        if (ccb->IsWindowVisible()) {
            ccb->GetWindowText(selStr);
            ccb->ShowWindow(SW_HIDE);

            this->SetItemText(c_row, c_col, selStr);
        }

        ccb->DestroyWindow();
        delete ccb;
        ccb = NULL;
    }

    Invalidate();
}

void CComboBoxListCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    if (GetFocus() != this)
        SetFocus();	// Force focus to finish editing

    CListCtrl::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CComboBoxListCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    if (GetFocus() != this)
        SetFocus();	// Force focus to finish editing

    CListCtrl::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CComboBoxListCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: Add your control notification handler code here
    //	LPNMLISTVIEW pNMTreeView = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
    POINT PT;
    GetCursorPos(&PT);
    this->ScreenToClient(&PT);

    LVHITTESTINFO hitInfo;
    hitInfo.pt = PT;
    int nItem = this->SubItemHitTest(&hitInfo);

    if (hitInfo.flags & LVHT_ONITEMLABEL) {
        if (cbbContainer[hitInfo.iItem][hitInfo.iSubItem] != NULL && ccbVisible[hitInfo.iItem][hitInfo.iSubItem]) {
            CString ItemText;
            ItemText = this->GetItemText(hitInfo.iItem, hitInfo.iSubItem);

            if (ccb != NULL) {
                CString selStr;
                ccb->GetWindowText(selStr);
                ccb->ShowWindow(SW_HIDE);

                this->SetItemText(c_row, c_col, selStr);

                ccb->DestroyWindow();
                delete ccb;
                ccb = NULL;
            }

            CRect rect;
            this->GetSubItemRect(hitInfo.iItem, hitInfo.iSubItem, LVIR_BOUNDS, rect);
            c_row = hitInfo.iItem;
            c_col = hitInfo.iSubItem;
            rect.bottom += 100;

            ccb = new CComboBox();
            ccb->Create(CBS_DROPDOWN | CBS_AUTOHSCROLL | CBS_NOINTEGRALHEIGHT | WS_VISIBLE | WS_CHILD | WS_BORDER | WS_VSCROLL, rect, this, CCBIDCNUM);
            ccb->LimitText(50);
            ccb->SetFont(&font);
            COMBOBOXINFO info;
            info.cbSize = sizeof(COMBOBOXINFO);
            HWND handleOfList;
            if (ccb->GetComboBoxInfo(&info)) {
                handleOfList = info.hwndList;
                OriginalListProc = (WNDPROC)SetWindowLongPtr(handleOfList, -4/*GWL_WNDPROC*/, (LONG_PTR)MyListProc);
            }

            int itemNum = cbbContainer[hitInfo.iItem][hitInfo.iSubItem]->GetCount();
            for (int i = 0; i < itemNum; i++) {
                ccb->AddString(cbbContainer[hitInfo.iItem][hitInfo.iSubItem]->GetAt(i));
            }
            ccb->SetCurSel(-1);
            ccb->MoveWindow(&rect, TRUE);
            ccb->ShowWindow(SW_NORMAL);
            ccb->BringWindowToTop();
            ccb->SetFocus();
            ccb->SetWindowText(ItemText);

            SetItemState(nItem, LVNI_FOCUSED | LVIS_SELECTED, LVNI_FOCUSED | LVIS_SELECTED);
        } else {
            CListCtrl::OnLButtonDown(nFlags, point);
        }
    } else {
        CListCtrl::OnLButtonDown(nFlags, point);
    }

}

void CComboBoxListCtrl::OnCbnSelchangeCombo()
{
    int nListItem = GetNextItem(-1, LVIS_SELECTED);
    int nComboboxItem = ccb->GetCurSel();
    if (nListItem >= 0 && nComboboxItem >= 0) {
        CString str;
        ccb->GetLBText(nComboboxItem, str);

        SetItemText(nListItem, 1, str);

        GetParent()->PostMessage(WM_USER_COMBO_SEL_CHANGED, nListItem, 0);
    }
}