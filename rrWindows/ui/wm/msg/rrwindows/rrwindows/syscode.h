/*===-- System Code --------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 系统代码。
 *
 * \sa <http://blog.airesoft.co.uk/2009/11/wm_messages/>
 *
 * \version 2018-06-29
 * \since 2018-04-19
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

/*-System-Message-------------------------------------------------------------*/

#ifndef WM_SIZEWAIT
#define WM_SIZEWAIT                     0x0004
#endif
#ifndef WM_SETVISIBLE
#define WM_SETVISIBLE                   0x0009
#endif
#ifndef WM_SYSTEMERROR
#define WM_SYSTEMERROR                  0x0017
#endif
#ifndef WM_CTLCOLOR
#define WM_CTLCOLOR                     0x0019
#endif
#ifndef WM_LOGOFF
#define WM_LOGOFF                       0x0025
#endif
#ifndef WM_ALTTABACTIVE
#define WM_ALTTABACTIVE                 0x0029
#endif
#ifndef WM_UAHDESTROYWINDOW
#define WM_UAHDESTROYWINDOW             0x0090
#endif
#ifndef WM_UAHDRAWMENU
#define WM_UAHDRAWMENU                  0x0091
#endif
#ifndef WM_UAHDRAWMENUITEM
#define WM_UAHDRAWMENUITEM              0x0092
#endif
#ifndef WM_UAHINITMENU
#define WM_UAHINITMENU                  0x0093
#endif
#ifndef WM_UAHMEASUREMENUITEM
#define WM_UAHMEASUREMENUITEM           0x0094
#endif
#ifndef WM_NCUAHDRAWCAPTION
#define WM_NCUAHDRAWCAPTION             0x00AE
#endif
#ifndef DM_POINTERHITTEST
#define DM_POINTERHITTEST               0x0250
#endif
#ifndef WM_POINTERROUTEDTO
#define WM_POINTERROUTEDTO              0x0251
#endif
#ifndef WM_POINTERROUTEDAWAY
#define WM_POINTERROUTEDAWAY            0x0252
#endif
#ifndef WM_POINTERROUTEDRELEASED
#define WM_POINTERROUTEDRELEASED        0x0253
#endif
#ifndef WM_DPICHANGED
#define WM_DPICHANGED                   0x02E0
#endif
#ifndef WM_DPICHANGED_BEFOREPARENT
#define WM_DPICHANGED_BEFOREPARENT      0x02E2
#endif
#ifndef WM_DPICHANGED_AFTERPARENT
#define WM_DPICHANGED_AFTERPARENT       0x02E3
#endif
#ifndef WM_GETDPISCALEDSIZE
#define WM_GETDPISCALEDSIZE             0x02E4
#endif
#ifndef WM_AFX_reserved_361
#define WM_AFX_reserved_361             0x0361
#endif
#ifndef WM_AFX_reserved_362
#define WM_AFX_reserved_362             0x0362
#endif
#ifndef WM_AFX_reserved_363
#define WM_AFX_reserved_363             0x0363
#endif
#ifndef WM_AFX_reserved_364
#define WM_AFX_reserved_364             0x0364
#endif
#ifndef WM_AFX_reserved_36a
#define WM_AFX_reserved_36a             0x036A
#endif
#ifndef WM_AFX_reserved_36b
#define WM_AFX_reserved_36b             0x036B
#endif
#ifndef WM_AFX_reserved_36c
#define WM_AFX_reserved_36c             0x036C
#endif
#ifndef WM_AFX_reserved_36d
#define WM_AFX_reserved_36d             0x036D
#endif
#ifndef WM_AFX_reserved_36e
#define WM_AFX_reserved_36e             0x036E
#endif

/*-System-Command-Notification------------------------------------------------*/

#ifndef CN_COMMAND
#define CN_COMMAND              0
#endif
#ifndef CN_UPDATE_COMMAND_UI
#define CN_UPDATE_COMMAND_UI    ((UINT)(-1))
#endif
#ifndef CN_EVENT
#define CN_EVENT                ((UINT)(-2))
#endif
#ifndef CN_OLECOMMAND           
#define CN_OLECOMMAND           ((UINT)(-3))
#endif
#ifndef CN_OLE_UNREGISTER
#define CN_OLE_UNREGISTER       ((UINT)(-4))
#endif
