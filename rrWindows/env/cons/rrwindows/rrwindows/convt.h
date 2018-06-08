/*===-- Console Virtual Terminal Sequences ---------------------*- C -*-===*//**
 *
 * \file
 * \brief 控制台虚拟终端序列。
 *
 * \sa <https://docs.microsoft.com/windows/console/console-virtual-terminal-sequences>
 * \sa <https://vt100.net/>
 *
 * \version 2018-06-08
 * \since 2018-06-07
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "rrwindows/rrwindowsapi.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief 启用虚拟终端模式。
 */
RRWINDOWS_API _Success_(return != FALSE) BOOL WINAPI
EnableVirtualTerminalMode(VOID);

/**
 * \brife 禁用虚拟终端模式。
 */
RRWINDOWS_API _Success_(return != FALSE) BOOL WINAPI
DisableVirtualTerminalMode(VOID);

#ifdef __cplusplus
}
#endif

#define ESC _T("\0x1B")
#define CSI ESC _T("[")  /* Control Sequence Introducer */

/* Simple Cursor Positioning */
#define CUU1  ESC _T("A")  /* Cursor Up by 1 */
#define CUD1  ESC _T("B")  /* Cursor Down by 1 */
#define CUF1  ESC _T("C")  /* Cursor Forward (Right) by 1 */
#define CUB1  ESC _T("D")  /* Cursor Backward (Left) by 1 */
#define RI    ESC _T("M")  /* Reverse Index*/
#define DECSC ESC _T("7")  /* Save Cursor Position in Memory */
#define DECRC ESC _T("8")  /* Restore Cursor Position from Memory */

/* Cursor Positioning */
#define CUU(n)    CSI _T(#n)                _T("A")  /* Cursor Up */
#define CUD(n)    CSI _T(#n)                _T("B")  /* Cursor Down*/
#define CUF(n)    CSI _T(#n)                _T("C")  /* Cursor Forward */
#define CUB(n)    CSI _T(#n)                _T("D")  /* Cursor Backward */
#define CNL(n)    CSI _T(#n)                _T("E")  /* Cursor Next Line */
#define CPL(n)    CSI _T(#n)                _T("F")  /* Cursor Previous Line */
#define CHA(n)    CSI _T(#n)                _T("G")  /* Cursor Horizontal Absolute */
#define VPA(n)    CSI _T(#n)                _T("d")  /* Vertical Line Position Absolute */
#define CUP(y, x) CSI _T(#y) _T(";") _T(#x) _T("H")  /* Cursor Position */
#define HVP(y, x) CSI _T(#y) _T(";") _T(#x) _T("f")  /* Horizontal Vertical Position */
#define ANSISYSSC CSI                       _T("s")  /* Save Cursor – Ansi.sys emulation */
#define ANSISYSRC CSI                       _T("u")  /* Restore Cursor – Ansi.sys emulation */

/* Cursor Visibility */
#define ATT160Y  CSI _T("?12h")  /* Text Cursor Enable Blinking: YES */
#define ATT160N  CSI _T("?12l")  /* Text Cursor Enable Blinking: NO */
#define DECTCEMS CSI _T("?25h")  /* Text Cursor Enable Mode: Show */
#define DECTCEMH CSI _T("?25l")  /* Text Cursor Enable Mode: Hide */

/* Viewport Positioning */
#define SU(n) CSI _T(#n) _T("S")  /* Scroll Up */
#define SD(n) CSI _T(#n) _T("T")  /* Scroll Down */

/* Text Modification */
#define ICH(n) CSI _T(#n) _T("@")  /* Insert Character */
#define DCH(n) CSI _T(#n) _T("P")  /* Delete Character */
#define ECH(n) CSI _T(#n) _T("X")  /* Erase Character */
#define IL(n)  CSI _T(#n) _T("L")  /* Insert Line */
#define DL(n)  CSI _T(#n) _T("M")  /* Delete Line */
#define ED(n)  CSI _T(#n) _T("J")  /* Erase in Display */
#define EL(n)  CSI _T(#n) _T("K")  /* Erase in Line */

/* Text Formatting */

/* Mode Changes */

/* Query State */

/* Tabs */

/* Designate Character Set */

/* Scrolling Margins */

/* Window Title */

/* Alternate Screen Buffer */

/* Window Width */

/* Input Sequences */

/* Soft Reset */
#define DECSTR CSI _T("!p")  /* Soft Terminal Reset */
