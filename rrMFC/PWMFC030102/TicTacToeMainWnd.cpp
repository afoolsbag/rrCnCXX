/// \copyright The MIT License

#include "stdafx.h"
#include "TicTacToeMainWnd.h"

namespace {
//       0 16 112 128 224 240 336 352
//   0  .--------------------------.
//  16  |  .---.   .---.   .---.   |
// 112  |  '-0-'   '-1-'   '-2-'   | 120
// 128  |  .---.   .---.   .---.   |
// 224  |  '-3-'   '-4-'   '-5-'   |
// 240  |  .---.   .---.   .---.   | 232
// 336  |  '-6-'   '-7-'   '-8-'   |
// 352  '--------------------------'
//              120     232

CONST INT kBoardLeft {0};
CONST INT kBoardTop {0};
CONST INT kBoardRight {352};
CONST INT kBoardBottom {352};
CONST INT kHrz1Left {16};
CONST INT kHrz1Right {112};
CONST INT kHrz12Line {120};
CONST INT kHrz2Left {128};
CONST INT kHrz2Right {224};
CONST INT kHrz23Line {232};
CONST INT kHrz3Left {240};
CONST INT kHrz3Right {336};
CONST INT kVrt1Top {16};
CONST INT kVrt1Bottom {112};
CONST INT kVrt12Line {120};
CONST INT kVrt2Top {128};
CONST INT kVrt2Bottom {224};
CONST INT kVrt23Line {232};
CONST INT kVrt3Top {240};
CONST INT kVrt3Bottom {336};
}// namespace

BEGIN_MESSAGE_MAP(CTicTacToeMainWnd, CWnd)
    ON_WM_PAINT()
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

CTicTacToeMainWnd::CTicTacToeMainWnd()
{
    // 注册框架窗口类
    // 类样式
    // 窗口光标
    // 窗口背景色
    // 窗口图标
    CONST CString wnd_class_name = AfxRegisterWndClass(
        CS_DBLCLKS,
        AfxGetApp()->LoadStandardCursor(IDC_ARROW),
        (HBRUSH)(COLOR_3DFACE + 1),
        AfxGetApp()->LoadStandardIcon(IDI_WINLOGO)
    );

    // 创建窗口
    // 无扩展样式，自定义框架，自定义标题
    // 标题边框、标题、系统菜单、最小化
    // 初始位置，初始尺寸
    CreateEx(
        0, wnd_class_name, TEXT("The Tic-Tac-Toe Application"),
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL
    );

    CRect rect(kBoardLeft, kBoardTop, kBoardRight, kBoardBottom);
    CalcWindowRect(&rect);
    // 设置窗口位置
    // 位置，尺寸
    // 不前置后置（Z轴）、不移动（忽略位置参数）、不重绘
    SetWindowPos(
        NULL,
        0, 0, rect.Width(), rect.Height(),
        SWP_NOZORDER | SWP_NOMOVE | SWP_NOREDRAW
    );
}

CTicTacToeMainWnd::PlaceState CTicTacToeMainWnd::checkWinner()
{
    static INT pattern[8][3] {
        0, 1, 2, 3, 4, 5, 6, 7, 8,
        0, 3, 6, 1, 4, 7, 2, 5, 8,
        0, 4, 8, 2, 4, 6
    };

    for (INT i = 0; i < 8; i++) {
        if (kEX == grid_[pattern[i][0]]
            && kEX == grid_[pattern[i][1]]
            && kEX == grid_[pattern[i][2]])
            return kEX;

        if (kOH == grid_[pattern[i][0]]
            && kOH == grid_[pattern[i][1]]
            && kOH == grid_[pattern[i][2]])
            return kOH;
    }

    for (INT id = 0; id < 9; id++)
        if (kBlank == grid_[id])
            return kUnknown;

    return kBlank;
}

VOID CTicTacToeMainWnd::checkGame()
{
    CString msg;

    switch (checkWinner()) {
    case kBlank: msg = TEXT("It's a draw!"); break;
    case kEX: msg = TEXT("X wins!"); break;
    case kOH: msg = TEXT("O wins!"); break;
    default: return; break;
    }

    MessageBox(msg, TEXT("Game Over"), MB_ICONEXCLAMATION | MB_OK);
    resetGame();
}

CONST CRect CTicTacToeMainWnd::squares_[9] {
    CRect(kHrz1Left, kVrt1Top, kHrz1Right, kVrt1Bottom),
    CRect(kHrz2Left, kVrt1Top, kHrz2Right, kVrt1Bottom),
    CRect(kHrz3Left, kVrt1Top, kHrz3Right, kVrt1Bottom),
    CRect(kHrz1Left, kVrt2Top, kHrz1Right, kVrt2Bottom),
    CRect(kHrz2Left, kVrt2Top, kHrz2Right, kVrt2Bottom),
    CRect(kHrz3Left, kVrt2Top, kHrz3Right, kVrt2Bottom),
    CRect(kHrz1Left, kVrt3Top, kHrz1Right, kVrt3Bottom),
    CRect(kHrz2Left, kVrt3Top, kHrz2Right, kVrt3Bottom),
    CRect(kHrz3Left, kVrt3Top, kHrz3Right, kVrt3Bottom)
};

INT CTicTacToeMainWnd::getSquareId(CPoint point)
{
    for (INT id = 0; id < 9; id++)
        if (squares_[id].PtInRect(point))
            return id;
    return -1;
}

VOID CTicTacToeMainWnd::drawEX(INT square_id, CDC &devctx)
{
    CPen pen(PS_SOLID, 16, RGB(255, 0, 0)/*红色*/);
    CPen *oldpen = devctx.SelectObject(&pen);

    CRect rect = squares_[square_id];
    rect.DeflateRect(16, 16);
    devctx.MoveTo(rect.left, rect.top);
    devctx.LineTo(rect.right, rect.bottom);
    devctx.MoveTo(rect.left, rect.bottom);
    devctx.LineTo(rect.right, rect.top);

    devctx.SelectObject(oldpen);
}

VOID CTicTacToeMainWnd::drawOH(INT square_id, CDC &devctx)
{
    CPen pen(PS_SOLID, 16, RGB(0, 0, 255)/*蓝色*/);
    CPen *oldpen = devctx.SelectObject(&pen);
    devctx.SelectStockObject(NULL_BRUSH);

    CRect rect = squares_[square_id];
    rect.DeflateRect(16, 16);
    devctx.Ellipse(rect);

    devctx.SelectObject(oldpen);
}

VOID CTicTacToeMainWnd::drawBoard(CDC &devctx)
{
    CPen pen(PS_SOLID, 16, RGB(0, 0, 0));
    CPen *oldpen = devctx.SelectObject(&pen);

    devctx.MoveTo(kHrz12Line, kVrt1Top);
    devctx.LineTo(kHrz12Line, kVrt3Bottom);

    devctx.MoveTo(kHrz23Line, kVrt1Top);
    devctx.LineTo(kHrz23Line, kVrt3Bottom);

    devctx.MoveTo(kHrz1Left, kVrt12Line);
    devctx.LineTo(kHrz3Right, kVrt12Line);

    devctx.MoveTo(kHrz1Left, kVrt23Line);
    devctx.LineTo(kHrz3Right, kVrt23Line);

    for (INT id = 0; id < 9; id++) {
        if (kEX == grid_[id])
            drawEX(id, devctx);
        else if (kOH == grid_[id])
            drawOH(id, devctx);
    }

    devctx.SelectObject(oldpen);
}

VOID CTicTacToeMainWnd::resetGame()
{
    ZeroMemory(grid_, sizeof(grid_));
    next_ = kEX;
    Invalidate();
}

void CTicTacToeMainWnd::PostNcDestroy()
{
    delete this;
}

VOID CTicTacToeMainWnd::OnPaint()
{
    CPaintDC devctx(this);
    drawBoard(devctx);
}

VOID CTicTacToeMainWnd::OnLButtonDown(UINT keys, CPoint point)
{
    INT id = getSquareId(point);
    if (-1 == id || kBlank != grid_[id])
        return;

    grid_[id] = next_;
    CClientDC devctx(this);
    if (kEX == next_) {
        drawEX(id, devctx);
        next_ = kOH;
    } else {
        drawOH(id, devctx);
        next_ = kEX;
    }
    checkGame();
}

VOID CTicTacToeMainWnd::OnLButtonDblClk(UINT keys, CPoint point)
{
    CClientDC devctx(this);
    if (devctx.GetPixel(point) == RGB(0, 0, 0))
        resetGame();
}
