//===-- Console Virtual Terminal Sequences ----------------------*- C++ -*-===//
///
/// \file
/// \brief 控制台虚拟终端序列。
///
/// \sa <https://docs.microsoft.com/windows/console/console-virtual-terminal-sequences>
/// \sa <https://vt100.net/>
///
/// \version 2019-07-08
/// \since 2018-06-07
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

#include <tchar.h>

#include "rrwindows/api.hxx"

namespace rrwindows {

/// \brief 启用虚拟终端模式。
/// \details 在 ``stdout`` 和 ``stderr`` 上启用虚拟终端模式。
RRWINDOWS_API void RRWINDOWS_CALL enable_virtual_terminal_mode();

/// \brife 禁用虚拟终端模式。
/// \details 在 ``stdout`` 和 ``stderr`` 上禁用虚拟终端模式。
RRWINDOWS_API void RRWINDOWS_CALL disable_virtual_terminal_mode();

// ANSISYS ANSI.SYS
// DEC     Digital Equipment Corporation
// VT      Virtual Terminal

#define VTESC       _T("\x1B")  /* Escape */
#define VTCSI VTESC _T("[")     /* Control Sequence Introducer */
#define VTOSC VTESC _T("]")     /* Operating System Command */

// 光标定位

#define VTCUU1  VTESC _T("A")  /* Cursor Up by 1 */
#define VTCUD1  VTESC _T("B")  /* Cursor Down by 1 */
#define VTCUF1  VTESC _T("C")  /* Cursor Forward by 1 */
#define VTCUB1  VTESC _T("D")  /* Cursor Backward by 1 */
#define VTRI    VTESC _T("M")  /* Reverse Index */
#define VTDECSC VTESC _T("7")  /* DEC Save Cursor */
#define VTDECRC VTESC _T("8")  /* DEC Restore Cursor */

#define VTCUU(n)    VTCSI _T(#n)                _T("A")  /* Cursor Up */
#define VTCUD(n)    VTCSI _T(#n)                _T("B")  /* Cursor Down */
#define VTCUF(n)    VTCSI _T(#n)                _T("C")  /* Cursor Forward */
#define VTCUB(n)    VTCSI _T(#n)                _T("D")  /* Cursor Backward */
#define VTCNL(n)    VTCSI _T(#n)                _T("E")  /* Cursor Next Line */
#define VTCPL(n)    VTCSI _T(#n)                _T("F")  /* Cursor Previous Line */
#define VTCHA(n)    VTCSI _T(#n)                _T("G")  /* Cursor Horizontal Absolute */
#define VTCUP(y, x) VTCSI _T(#y) _T(";") _T(#x) _T("H")  /* Cursor Position */
#define VTVPA(n)    VTCSI _T(#n)                _T("d")  /* Vertical Position Absolute */
#define VTHVP(y, x) VTCSI _T(#y) _T(";") _T(#x) _T("f")  /* Horizontal Vertical Position */
#define VTANSISYSSC VTCSI                       _T("s")  /* ANSI.SYS Save Cursorn */
#define VTANSISYSRC VTCSI                       _T("u")  /* ANSI.SYS Restore Cursor */

// 光标可见性

#define VTTCEBH VTCSI _T("?12h")  /* Text Cursor Enable Blinking: ON */
#define VTTCEBL VTCSI _T("?12l")  /* Text Cursor Enable Blinking: OFF */
#define VTTCEMH VTCSI _T("?25h")  /* DEC Text Cursor Enable Mode: ON */
#define VTTCEML VTCSI _T("?25l")  /* DEC Text Cursor Enable Mode: OFF */

// 视口定位

#define VTSU(n) VTCSI _T(#n) _T("S")  /* Scroll Up */
#define VTSD(n) VTCSI _T(#n) _T("T")  /* Scroll Down */

// 文本修改

#define VTICH(n) VTCSI _T(#n)  _T("@")  /* Insert Character */
#define VTDCH(n) VTCSI _T(#n)  _T("P")  /* Delete Character */
#define VTECH(n) VTCSI _T(#n)  _T("X")  /* Erase Character */

#define VTIL(n)  VTCSI _T(#n)  _T("L")  /* Insert Line */
#define VTDL(n)  VTCSI _T(#n)  _T("M")  /* Delete Line */
#define VTEL0    VTCSI _T("0") _T("K")  /* Erase Line to Cursor */
#define VTEL1    VTCSI _T("1") _T("K")  /* Erase Line from Cursor */
#define VTEL2    VTCSI _T("2") _T("K")  /* Erase Line */

#define VTED0    VTCSI _T("0") _T("J")  /* Erase Display to Cursor */
#define VTED1    VTCSI _T("1") _T("J")  /* Erase Display from Cursor */
#define VTED2    VTCSI _T("2") _T("J")  /* Erase Display */

// 文本格式

#define VTSGR(n) VTCSI _T(#n) _T("m")  /* Set Graphics Rendition */

#define VTDEF    VTSGR(0)   /* Default */
#define VTBLD    VTSGR(1)   /* Bold */
#define VTBLDOFF VTSGR(22)  /* Bold Off */
#define VTUND    VTSGR(4)   /* Underline */
#define VTUNDOFF VTSGR(24)  /* Underline Off */
#define VTBLI    VTSGR(5)   /* Blinking */
#define VTBLIOFF VTSGR(25)  /* Blinking Off */
#define VTNEG    VTSGR(7)   /* Negative */
#define VTNEGOFF VTSGR(27)  /* Negative Off */
#define VTINV    VTSGR(8)   /* Invisible */
#define VTINVOFF VTSGR(28)  /* Invisible Off */

#define VTFBLK          VTSGR(30)                                                       /* Foreground Black */
#define VTFRED          VTSGR(31)                                                       /* Foreground Red */
#define VTFGRN          VTSGR(32)                                                       /* Foreground Green */
#define VTFYEL          VTSGR(33)                                                       /* Foreground Yellow */
#define VTFBLU          VTSGR(34)                                                       /* Foreground Blue */
#define VTFMAG          VTSGR(35)                                                       /* Foreground Magenta */
#define VTFCYA          VTSGR(36)                                                       /* Foreground Cyan */
#define VTFWHT          VTSGR(37)                                                       /* Foreground White */
#define VTFEXT(r, g, b) VTCSI _T("38;2;") _T(#r) _T(";") _T(#g) _T(";") _T(#b) _T("m")  /* Foreground Extended */
#define VTFDEF          VTSGR(39)                                                       /* Foreground Default */
#define VTFBLKB         VTSGR(90)                                                       /* Foreground Black Bright */
#define VTFREDB         VTSGR(91)                                                       /* Foreground Red Bright */
#define VTFGRNB         VTSGR(92)                                                       /* Foreground Green Bright */
#define VTFYELB         VTSGR(93)                                                       /* Foreground Yellow Bright */
#define VTFBLUB         VTSGR(94)                                                       /* Foreground Blue Bright */
#define VTFMAGB         VTSGR(95)                                                       /* Foreground Magenta Bright */
#define VTFCYAB         VTSGR(96)                                                       /* Foreground Cyan Bright */
#define VTFWHTB         VTSGR(97)                                                       /* Foreground White Bright */

#define VTBBLK          VTSGR(40)                                                       /* Background Black */
#define VTBRED          VTSGR(41)                                                       /* Background Red */
#define VTBGRN          VTSGR(42)                                                       /* Background Green */
#define VTBYEL          VTSGR(43)                                                       /* Background Yellow */
#define VTBBLU          VTSGR(44)                                                       /* Background Blue */
#define VTBMAG          VTSGR(45)                                                       /* Background Magenta */
#define VTBCYA          VTSGR(46)                                                       /* Background Cyan */
#define VTBWHT          VTSGR(47)                                                       /* Background White */
#define VTBEXT(r, g, b) VTCSI _T("48;2;") _T(#r) _T(";") _T(#g) _T(";") _T(#b) _T("m")  /* Background Extended */
#define VTBDEF          VTSGR(49)                                                       /* Background Default */
#define VTBBLKB         VTSGR(100)                                                      /* Background Black Bright */
#define VTBREDB         VTSGR(101)                                                      /* Background Red Bright */
#define VTBGRNB         VTSGR(102)                                                      /* Background Green Bright */
#define VTBYELB         VTSGR(103)                                                      /* Background Yellow Bright */
#define VTBBLUB         VTSGR(104)                                                      /* Background Blue Bright */
#define VTBMAGB         VTSGR(105)                                                      /* Background Magenta Bright */
#define VTBCYAB         VTSGR(106)                                                      /* Background Cyan Bright */
#define VTBWHTB         VTSGR(107)                                                      /* Background White Bright */

// 屏幕颜色

// 模式更改

// 查询状态

// 缩进

// 指定字符集

// 滚动边距

// 窗口标题

// 替代屏幕缓冲区

// 窗口宽度

// 软复位

// 输入序列

}
