/*===-- Console Virtual Terminal Sequences ---------------------*- C -*-===*//**
 *
 * \file
 * \brief 控制台虚拟终端序列。
 *
 * \sa <https://docs.microsoft.com/windows/console/console-virtual-terminal-sequences>
 * \sa <https://vt100.net/>
 *
 * \version 2018-08-23
 * \since 2018-06-07
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include "rrwindows/api.h"

#ifdef __cplusplus
extern "C" {;
#endif

/**
 * \brief 启用虚拟终端模式。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
EnableVirtualTerminalMode(VOID);

/**
 * \brife 禁用虚拟终端模式。
 */
RRWINDOWS_API
_Success_(return != FALSE)
BOOL
WINAPI
DisableVirtualTerminalMode(VOID);

#ifdef __cplusplus
}
#endif

#define VTS_ESC _T("\x1B")
#define VTS_CSI _T("\x1B[")  /* Control Sequence Introducer */

/* Simple Cursor Positioning */
#define VTS_CUU1  _T("\x1BA")  /* Cursor Up by 1 */
#define VTS_CUD1  _T("\x1BB")  /* Cursor Down by 1 */
#define VTS_CUF1  _T("\x1BC")  /* Cursor Forward (Right) by 1 */
#define VTS_CUB1  _T("\x1BD")  /* Cursor Backward (Left) by 1 */
#define VTS_RI    _T("\x1BM")  /* Reverse Index*/
#define VTS_DECSC _T("\x1B7")  /* Save Cursor Position in Memory */
#define VTS_DECRC _T("\x1B8")  /* Restore Cursor Position from Memory */

/* Cursor Positioning */
#define VTS_CUU(n)    _T("\x1B[") _T(#n)                _T("A")  /* Cursor Up */
#define VTS_CUD(n)    _T("\x1B[") _T(#n)                _T("B")  /* Cursor Down*/
#define VTS_CUF(n)    _T("\x1B[") _T(#n)                _T("C")  /* Cursor Forward */
#define VTS_CUB(n)    _T("\x1B[") _T(#n)                _T("D")  /* Cursor Backward */
#define VTS_CNL(n)    _T("\x1B[") _T(#n)                _T("E")  /* Cursor Next Line */
#define VTS_CPL(n)    _T("\x1B[") _T(#n)                _T("F")  /* Cursor Previous Line */
#define VTS_CHA(n)    _T("\x1B[") _T(#n)                _T("G")  /* Cursor Horizontal Absolute */
#define VTS_VPA(n)    _T("\x1B[") _T(#n)                _T("d")  /* Vertical Position Absolute */
#define VTS_CUP(y, x) _T("\x1B[") _T(#y) _T(";") _T(#x) _T("H")  /* Cursor Position */
#define VTS_HVP(y, x) _T("\x1B[") _T(#y) _T(";") _T(#x) _T("f")  /* Horizontal Vertical Position */
#define VTS_ANSISYSSC _T("\x1B[s")                               /* Save Cursor – Ansi.sys emulation */
#define VTS_ANSISYSRC _T("\x1B[u")                               /* Restore Cursor – Ansi.sys emulation */

#define VTS_CNL1      _T("\x1B[E")                               /* Cursor Next Line by 1 */
#define VTS_CPL1      _T("\x1B[F")                               /* Cursor Previous Line by 1 */
#define VTS_CHA1      _T("\x1B[G")                               /* Cursor Horizontal Absolute by 1 */
#define VTS_VPA1      _T("\x1B[d")                               /* Vertical Position Absolute by 1 */
#define VTS_CUP11     _T("\x1B[H")                               /* Cursor Position by 1, 1 */
#define VTS_HVP11     _T("\x1B[f")                               /* Horizontal Vertical Position by 1, 1 */

/* Cursor Visibility */
#define VTS_ATT160_ON   _T("\x1B[?12h")  /* Text Cursor Enable Blinking: ON */
#define VTS_ATT160_OFF  _T("\x1B[?12l")  /* Text Cursor Enable Blinking: OFF */
#define VTS_DECTCEM_ON  _T("\x1B[?25h")  /* Text Cursor Enable Mode: ON */
#define VTS_DECTCEM_OFF _T("\x1B[?25l")  /* Text Cursor Enable Mode: OFF */

/* Viewport Positioning */
#define VTS_SU(n) _T("\x1B[") _T(#n) _T("S")  /* Scroll Up */
#define VTS_SD(n) _T("\x1B[") _T(#n) _T("T")  /* Scroll Down */

#define VTS_SU1   _T("\x1B[S")                /* Scroll Up by 1 */
#define VTS_SD1   _T("\x1B[T")                /* Scroll Down by 1 */

/* Text Modification */
#define VTS_ICH(n) _T("\x1B[") _T(#n) _T("@")  /* Insert Character */
#define VTS_DCH(n) _T("\x1B[") _T(#n) _T("P")  /* Delete Character */
#define VTS_ECH(n) _T("\x1B[") _T(#n) _T("X")  /* Erase Character */
#define VTS_IL(n)  _T("\x1B[") _T(#n) _T("L")  /* Insert Line */
#define VTS_DL(n)  _T("\x1B[") _T(#n) _T("M")  /* Delete Line */
#define VTS_EDTC   _T("\x1B[0J")               /* Erase in Display To Cursor */
#define VTS_EDFC   _T("\x1B[1J")               /* Erase in Display From Cursor */
#define VTS_ED     _T("\x1B[2J")               /* Erase in Display */
#define VTS_ELTC   _T("\x1B[0K")               /* Erase in Line To Cursor */
#define VTS_ELFC   _T("\x1B[1K")               /* Erase in Line From Cursor */
#define VTS_EL     _T("\x1B[2K")               /* Erase in Line */

#define VTS_ICH1   _T("\x1B[@")                /* Insert Character by 1 */
#define VTS_DCH1   _T("\x1B[P")                /* Delete Character by 1 */
#define VTS_ECH1   _T("\x1B[X")                /* Erase Character by 1 */
#define VTS_IL1    _T("\x1B[L")                /* Insert Line by 1 */
#define VTS_DL1    _T("\x1B[M")                /* Delete Line by 1 */

/* Text Formatting */
#define VTS_SGR(n) _T("\x1B[") _T(#n) _T("m")  /* Set Graphics Rendition */
#define VTS_DEF            _T("\x1B[0m")    /* Default */
#define VTS_BLD            _T("\x1B[1m")    /* Bold */
#define VTS_UND            _T("\x1B[4m")    /* Underline */
#define VTS_NEG            _T("\x1B[7m")    /* Negative */
#define VTS_NOUND          _T("\x1B[24m")   /* No Underline */
#define VTS_NONEG          _T("\x1B[27m")   /* No Negative */
#define VTS_FGBLK          _T("\x1B[30m")   /* Foreground Black */
#define VTS_FGRED          _T("\x1B[31m")   /* Foreground Red */
#define VTS_FGGRN          _T("\x1B[32m")   /* Foreground Green */
#define VTS_FGYEL          _T("\x1B[33m")   /* Foreground Yellow */
#define VTS_FGBLU          _T("\x1B[34m")   /* Foreground Blue */
#define VTS_FGMAG          _T("\x1B[35m")   /* Foreground Magenta */
#define VTS_FGCYA          _T("\x1B[36m")   /* Foreground Cyan */
#define VTS_FGWHT          _T("\x1B[37m")   /* Foreground White */
#define VTS_FGEXT(r, g, b) _T("\x1B[38;2;") _T(#r) _T(";") _T(#g) _T(";") _T(#b) _T("m")  /* Foreground Extended */
#define VTS_FGDEF          _T("\x1B[39m")   /* Foreground Default */
#define VTS_BGBLK          _T("\x1B[40m")   /* Background Black */
#define VTS_BGRED          _T("\x1B[41m")   /* Background Red */
#define VTS_BGGRN          _T("\x1B[42m")   /* Background Green */
#define VTS_BGYEL          _T("\x1B[43m")   /* Background Yellow */
#define VTS_BGBLU          _T("\x1B[44m")   /* Background Blue */
#define VTS_BGMAG          _T("\x1B[45m")   /* Background Magenta */
#define VTS_BGCYA          _T("\x1B[46m")   /* Background Cyan */
#define VTS_BGWHT          _T("\x1B[47m")   /* Background White */
#define VTS_BGEXT(r, g, b) _T("\x1B[48;2;") _T(#r) _T(";") _T(#g) _T(";") _T(#b) _T("m")  /* Background Extended */
#define VTS_BGDEF          _T("\x1B[49m")   /* Background Default */
#define VTS_FGBLKB         _T("\x1B[90m")   /* Foreground Black Bright */
#define VTS_FGREDB         _T("\x1B[91m")   /* Foreground Red Bright */
#define VTS_FGGRNB         _T("\x1B[92m")   /* Foreground Green Bright */
#define VTS_FGYELB         _T("\x1B[93m")   /* Foreground Yellow Bright */
#define VTS_FGBLUB         _T("\x1B[94m")   /* Foreground Blue Bright */
#define VTS_FGMAGB         _T("\x1B[95m")   /* Foreground Magenta Bright */
#define VTS_FGCYAB         _T("\x1B[96m")   /* Foreground Cyan Bright */
#define VTS_FGWHTB         _T("\x1B[97m")   /* Foreground White Bright */
#define VTS_BGBLKB         _T("\x1B[100m")  /* Background Black Bright */
#define VTS_BGREDB         _T("\x1B[101m")  /* Background Red Bright */
#define VTS_BGGRNB         _T("\x1B[102m")  /* Background Green Bright */
#define VTS_BGYELB         _T("\x1B[103m")  /* Background Yellow Bright */
#define VTS_BGBLUB         _T("\x1B[104m")  /* Background Blue Bright */
#define VTS_BGMAGB         _T("\x1B[105m")  /* Background Magenta Bright */
#define VTS_BGCYAB         _T("\x1B[106m")  /* Background Cyan Bright */
#define VTS_BGWHTB         _T("\x1B[107m")  /* Background White Bright */

#ifdef VTS_ACRONYM
# define UND(text) VTS_UND _T(text) VTS_NOUND
# define NEG(text) VTS_NEG _T(text) VTS_NONEG
# define BLK(text) VTS_FGBLK _T(text) VTS_FGDEF
# define RED(text) VTS_FGRED _T(text) VTS_FGDEF
# define GRN(text) VTS_FGGRN _T(text) VTS_FGDEF
# define YEL(text) VTS_FGYEL _T(text) VTS_FGDEF
# define BLU(text) VTS_FGBLU _T(text) VTS_FGDEF
# define MAG(text) VTS_FGMAG _T(text) VTS_FGDEF
# define CYA(text) VTS_FGCYA _T(text) VTS_FGDEF
# define WHT(text) VTS_FGWHT _T(text) VTS_FGDEF
# define BLKB(text) VTS_FGBLKB _T(text) VTS_FGDEF
# define REDB(text) VTS_FGREDB _T(text) VTS_FGDEF
# define GRNB(text) VTS_FGGRNB _T(text) VTS_FGDEF
# define YELB(text) VTS_FGYELB _T(text) VTS_FGDEF
# define BLUB(text) VTS_FGBLUB _T(text) VTS_FGDEF
# define MAGB(text) VTS_FGMAGB _T(text) VTS_FGDEF
# define CYAB(text) VTS_FGCYAB _T(text) VTS_FGDEF
# define WHTB(text) VTS_FGWHTB _T(text) VTS_FGDEF
#endif

/* Mode Changes */
#define VTS_DECKPAM    _T("\x1B=")     /* Keypad Application Mode */
#define VTS_DECKPNM    _T("\x1B>")     /* Keypad Numeric Mode */
#define VTS_DECCKM_ON  _T("\x1B[?1h")  /* Cursor Keys Application Mode: ON */
#define VTS_DECCKM_OFF _T("\x1B[?1l")  /* Cursor Keys Application Mode: OFF */

/* Query State */
#define VTS_DECXCPR _T("\x1B[6n")  /* Report Cursor Position */
#define VTS_DA      _T("\x1B[0c")  /* Device Attributes */

/* Tabs */
#define VTS_HTS    _T("\x1BH")                 /* Horizontal Tab Set */
#define VTS_CHT(n) _T("\x1B[") _T(#n) _T("I")  /* Cursor Horizontal Tab */
#define VTS_CBT(n) _T("\x1B[") _T(#n) _T("Z")  /* Cursor Backwards Tab */
#define VTS_TBCC   _T("\x1B[0g")               /* Tab Clear (current column) */
#define VTS_TBCA   _T("\x1B[3g")               /* Tab Clear (all columns) */

/* Designate Character Set */

/* Scrolling Margins */
#define VTS_DECSTBM

/* Window Title */

/* Alternate Screen Buffer */

/* Window Width */
#define VTS_DECCOLM_132
#define VTS_DECCOLM_80

/* Soft Reset */
#define VTS_DECSTR _T("\x1B[!p")  /* Soft Terminal Reset */

/* Input Sequences */
