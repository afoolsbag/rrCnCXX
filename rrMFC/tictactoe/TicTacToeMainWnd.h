//===-- Class TicTacToe Main Window -----------------------------*- C++ -*-===//
///
/// \file
/// \brief TicTacToe主窗口类
///
/// \author zhengrr
/// \date 2018-2-12 – 13
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class TicTacToe Main Window
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class
class CTicTacToeMainWnd: public CWnd {
public:
    CTicTacToeMainWnd();

protected:
    enum PlaceState { kUnknown = -1, kBlank = 0, kEX = 1, kOH = 2 };
    PlaceState grid_[9] {};
    PlaceState next_ {kEX};

    /// \brief 检查胜利者
    ///
    /// \return 返回`kBlank`表示流局，`kEX`表示X获胜，`kOH`表示O获胜，`kUnknown`表示胜负未定
    PlaceState checkWinner();

    /// \brief 检查游戏状态
    VOID checkGame();

    static CONST CRect squares_[9];

    /// \brief 获取点所处方块的标识
    ///
    /// \param point 点
    /// \return 方块的标识，若不处于任何方块，则返回`-1`
    INT getSquareId(CPoint point);

    /// \brief 绘制X
    VOID drawEX(INT square_id, CDC &devctx);

    /// \brief 绘制O
    VOID drawOH(INT square_id, CDC &devctx);

    /// \brief 绘制棋盘
    VOID drawBoard(CDC &devctx);

    /// \brief 重置游戏
    VOID resetGame();

    /// \brief Post Non-Client Destroy
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#postncdestroy
    virtual VOID PostNcDestroy();

    /// \brief On Paint
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onpaint
    afx_msg VOID OnPaint();

    /// \brief On Left Button Down
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onlbuttondown
    afx_msg VOID OnLButtonDown(UINT nFlags, CPoint point);

    /// \brief On Left Button Double-Clicked
    ///
    /// \sa https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#onlbuttondblclk
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);

    DECLARE_MESSAGE_MAP()
};
