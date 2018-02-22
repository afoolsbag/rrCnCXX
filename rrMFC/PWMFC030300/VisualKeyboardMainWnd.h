//===-- Class VisualKeyboard Main Window ------------------------*- C++ -*-===//
///
/// \file
/// \brief VisualKeyboard主窗口类
///
/// \author zhengrr
/// \date 2018-2-13
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class VisualKeyboard Main Window
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cframewnd-class
class CVisualKeyboardMainWnd: public CWnd {
public:
    CVisualKeyboardMainWnd();

protected:
    HCURSOR kArrowCursor;
    HCURSOR kIbeamCursor;

    INT kCharWd;  ///< Char width
    INT kCharHt;  ///< Char height
    INT kLineHt;  ///< Line height

    CRect kWndPadBox;            ///< Window padding box
    CONST INT kWndBoxPadL {16};  ///< Window box padding left
    CONST INT kWndBoxPadT {16};  ///< Window box padding top
    CONST INT kWndBoxPadR {16};  ///< Window box padding right
    CONST INT kWndBoxPadB {16};  ///< Window box padding bottom

    CRect kTxtPadBox;  ///< Text padding box
    CRect kTxtEltBox;  ///< Text element box

    CRect kMsgPadBox;  ///< Message padding box

    CONST INT kMaxMsgs {12};  ///< Max messages

    /// \brief Post Non-Client Destroy
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#postncdestroy
    virtual VOID PostNcDestroy();

    /// \brief On Create
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#oncreate
    afx_msg INT OnCreate(LPCREATESTRUCT lpCreateStruct);

    /// \brief On Paint
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint
    afx_msg VOID OnPaint();

    /// \brief On Set Focus
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsetfocus
    afx_msg VOID OnSetFocus(CWnd *pOldWnd);

    /// \brief On Kill Focus
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onkillfocus
    afx_msg VOID OnKillFocus(CWnd *pNewWnd);

    /// \brief On Set Cursor
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsetcursor
    afx_msg BOOL OnSetCursor(CWnd *pWnd, UINT nHitTest, UINT message);

    /// \brief On Left Button Down
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onlbuttondown
    afx_msg VOID OnLButtonDown(UINT nFlags, CPoint point);

    /// \brief On Key Down
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onkeydown
    afx_msg VOID OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

    /// \brief On Char
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onchar
    afx_msg VOID OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);

    /// \brief On Key Up
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onkeyup
    afx_msg VOID OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);

    /// \brief On System Key Down
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsyskeydown
    afx_msg VOID OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

    /// \brief On System Char
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsyschar
    afx_msg VOID OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags);

    /// \brief On System Key Up
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onsyskeyup
    afx_msg VOID OnSysKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);

    DECLARE_MESSAGE_MAP()
};
