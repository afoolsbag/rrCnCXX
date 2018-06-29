/** \copyright The MIT License */

#define RRWINDOWS_EXPORTS
#include "syscodestr.h"

#include "syscode.h"

RRWINDOWS_API
LPCSTR
WINAPI
SystemMessageStringA(
    _In_ CONST UINT messageNumber)
{
    switch (messageNumber) {
#ifdef M
# error Macro name conflicts.
#endif/*M*/
#define M(msg) case msg: { static CONST CHAR str[] = #msg; return str; } break
        M(WM_NULL);                  /*    0x0 */
        M(WM_CREATE);                /*    0x1 */
        M(WM_DESTROY);               /*    0x2 */
        M(WM_MOVE);                  /*    0x3 */
        M(WM_SIZEWAIT);              /*    0x4 */
        M(WM_SIZE);                  /*    0x5 */
        M(WM_ACTIVATE);              /*    0x6 */
        M(WM_SETFOCUS);              /*    0x7 */
        M(WM_KILLFOCUS);             /*    0x8 */
        M(WM_SETVISIBLE);            /*    0x9 */
        M(WM_ENABLE);                /*    0xA */
        M(WM_SETREDRAW);             /*    0xB */
        M(WM_SETTEXT);               /*    0xC */
        M(WM_GETTEXT);               /*    0xD */
        M(WM_GETTEXTLENGTH);         /*    0xE */
        M(WM_PAINT);                 /*    0xF */

        M(WM_CLOSE);                 /*   0x10 */
        M(WM_QUERYENDSESSION);       /*   0x11 */
        M(WM_QUIT);                  /*   0x12 */
        M(WM_QUERYOPEN);             /*   0x13 */
        M(WM_ERASEBKGND);            /*   0x14 */
        M(WM_SYSCOLORCHANGE);        /*   0x15 */
        M(WM_ENDSESSION);            /*   0x16 */
        M(WM_SYSTEMERROR);           /*   0x17 */
        M(WM_SHOWWINDOW);            /*   0x18 */
        M(WM_CTLCOLOR);              /*   0x19 */
        M(WM_WININICHANGE);          /*   0x1A */
        M(WM_DEVMODECHANGE);         /*   0x1B */
        M(WM_ACTIVATEAPP);           /*   0x1C */
        M(WM_FONTCHANGE);            /*   0x1D */
        M(WM_TIMECHANGE);            /*   0x1E */
        M(WM_CANCELMODE);            /*   0x1F */

        M(WM_SETCURSOR);             /*   0x20 */
        M(WM_MOUSEACTIVATE);         /*   0x21 */
        M(WM_CHILDACTIVATE);         /*   0x22 */
        M(WM_QUEUESYNC);             /*   0x23 */
        M(WM_GETMINMAXINFO);         /*   0x24 */
        M(WM_LOGOFF);                /*   0x25 */
        M(WM_PAINTICON);             /*   0x26 */
        M(WM_ICONERASEBKGND);        /*   0x27 */
        M(WM_NEXTDLGCTL);            /*   0x28 */
        M(WM_ALTTABACTIVE);          /*   0x29 */
        M(WM_SPOOLERSTATUS);         /*   0x2A */
        M(WM_DRAWITEM);              /*   0x2B */
        M(WM_MEASUREITEM);           /*   0x2C */
        M(WM_DELETEITEM);            /*   0x2D */
        M(WM_VKEYTOITEM);            /*   0x2E */
        M(WM_CHARTOITEM);            /*   0x2F */

        M(WM_SETFONT);               /*   0x30 */
        M(WM_GETFONT);               /*   0x31 */
        M(WM_SETHOTKEY);             /*   0x32 */
        M(WM_GETHOTKEY);             /*   0x33 */
        M(WM_QUERYDRAGICON);         /*   0x37 */
        M(WM_COMPAREITEM);           /*   0x39 */
        M(WM_GETOBJECT);             /*   0x3D */

        M(WM_COMPACTING);            /*   0x41 */
        M(WM_COMMNOTIFY);            /*   0x44 */
        M(WM_WINDOWPOSCHANGING);     /*   0x46 */
        M(WM_WINDOWPOSCHANGED);      /*   0x47 */
        M(WM_POWER);                 /*   0x48 */
        M(WM_COPYDATA);              /*   0x4A */
        M(WM_CANCELJOURNAL);         /*   0x4B */
        M(WM_NOTIFY);                /*   0x4E */

        M(WM_INPUTLANGCHANGEREQUEST);/*   0x50 */
        M(WM_INPUTLANGCHANGE);       /*   0x51 */
        M(WM_TCARD);                 /*   0x52 */
        M(WM_HELP);                  /*   0x53 */
        M(WM_USERCHANGED);           /*   0x54 */
        M(WM_NOTIFYFORMAT);          /*   0x55 */

        M(WM_CONTEXTMENU);           /*   0x7B */
        M(WM_STYLECHANGING);         /*   0x7C */
        M(WM_STYLECHANGED);          /*   0x7D */
        M(WM_DISPLAYCHANGE);         /*   0x7E */
        M(WM_GETICON);               /*   0x7F */

        M(WM_SETICON);               /*   0x80 */
        M(WM_NCCREATE);              /*   0x81 */
        M(WM_NCDESTROY);             /*   0x82 */
        M(WM_NCCALCSIZE);            /*   0x83 */
        M(WM_NCHITTEST);             /*   0x84 */
        M(WM_NCPAINT);               /*   0x85 */
        M(WM_NCACTIVATE);            /*   0x86 */
        M(WM_GETDLGCODE);            /*   0x87 */
        M(WM_SYNCPAINT);             /*   0x88 */

        M(WM_UAHDESTROYWINDOW);      /*   0x90 */
        M(WM_UAHDRAWMENU);           /*   0x91 */
        M(WM_UAHDRAWMENUITEM);       /*   0x92 */
        M(WM_UAHINITMENU);           /*   0x93 */
        M(WM_UAHMEASUREMENUITEM);    /*   0x94 */

        M(WM_NCMOUSEMOVE);           /*   0xA0 */
        M(WM_NCLBUTTONDOWN);         /*   0xA1 */
        M(WM_NCLBUTTONUP);           /*   0xA2 */
        M(WM_NCLBUTTONDBLCLK);       /*   0xA3 */
        M(WM_NCRBUTTONDOWN);         /*   0xA4 */
        M(WM_NCRBUTTONUP);           /*   0xA5 */
        M(WM_NCRBUTTONDBLCLK);       /*   0xA6 */
        M(WM_NCMBUTTONDOWN);         /*   0xA7 */
        M(WM_NCMBUTTONUP);           /*   0xA8 */
        M(WM_NCMBUTTONDBLCLK);       /*   0xA9 */
                                     /*   0xAA */
        M(WM_NCXBUTTONDOWN);         /*   0xAB */
        M(WM_NCXBUTTONUP);           /*   0xAC */
        M(WM_NCXBUTTONDBLCLK);       /*   0xAD */
        M(WM_NCUAHDRAWCAPTION);      /*   0xAE */

        M(WM_INPUT_DEVICE_CHANGE);   /*   0xFE */
        M(WM_INPUT);                 /*   0xFF */

        M(WM_KEYDOWN);               /*  0x100 */
        M(WM_KEYUP);                 /*  0x101 */
        M(WM_CHAR);                  /*  0x102 */
        M(WM_DEADCHAR);              /*  0x103 */
        M(WM_SYSKEYDOWN);            /*  0x104 */
        M(WM_SYSKEYUP);              /*  0x105 */
        M(WM_SYSCHAR);               /*  0x106 */
        M(WM_SYSDEADCHAR);           /*  0x107 */
        M(WM_UNICHAR);               /*  0x109 */
        M(WM_IME_STARTCOMPOSITION);  /*  0x10D */
        M(WM_IME_ENDCOMPOSITION);    /*  0x10E */
        M(WM_IME_COMPOSITION);       /*  0x10F */

        M(WM_INITDIALOG);            /*  0x110 */
        M(WM_COMMAND);               /*  0x111 */
        M(WM_SYSCOMMAND);            /*  0x112 */
        M(WM_TIMER);                 /*  0x113 */
        M(WM_HSCROLL);               /*  0x114 */
        M(WM_VSCROLL);               /*  0x115 */
        M(WM_INITMENU);              /*  0x116 */
        M(WM_INITMENUPOPUP);         /*  0x117 */
        M(WM_GESTURE);               /*  0x119 */
        M(WM_GESTURENOTIFY);         /*  0x11A */
        M(WM_MENUSELECT);            /*  0x11F */

        M(WM_MENUCHAR);              /*  0x120 */
        M(WM_ENTERIDLE);             /*  0x121 */
        M(WM_MENURBUTTONUP);         /*  0x122 */
        M(WM_MENUDRAG);              /*  0x123 */
        M(WM_MENUGETOBJECT);         /*  0x124 */
        M(WM_UNINITMENUPOPUP);       /*  0x125 */
        M(WM_MENUCOMMAND);           /*  0x126 */
        M(WM_CHANGEUISTATE);         /*  0x127 */
        M(WM_UPDATEUISTATE);         /*  0x128 */
        M(WM_QUERYUISTATE);          /*  0x129 */

        M(WM_CTLCOLORMSGBOX);        /*  0x132 */
        M(WM_CTLCOLOREDIT);          /*  0x133 */
        M(WM_CTLCOLORLISTBOX);       /*  0x134 */
        M(WM_CTLCOLORBTN);           /*  0x135 */
        M(WM_CTLCOLORDLG);           /*  0x136 */
        M(WM_CTLCOLORSCROLLBAR);     /*  0x137 */
        M(WM_CTLCOLORSTATIC);        /*  0x138 */

        M(MN_GETHMENU);              /*  0x1E1 */

        M(WM_MOUSEMOVE);             /*  0x200 */
        M(WM_LBUTTONDOWN);           /*  0x201 */
        M(WM_LBUTTONUP);             /*  0x202 */
        M(WM_LBUTTONDBLCLK);         /*  0x203 */
        M(WM_RBUTTONDOWN);           /*  0x204 */
        M(WM_RBUTTONUP);             /*  0x205 */
        M(WM_RBUTTONDBLCLK);         /*  0x206 */
        M(WM_MBUTTONDOWN);           /*  0x207 */
        M(WM_MBUTTONUP);             /*  0x208 */
        M(WM_MBUTTONDBLCLK);         /*  0x209 */
        M(WM_MOUSEWHEEL);            /*  0x20A */
        M(WM_XBUTTONDOWN);           /*  0x20B */
        M(WM_XBUTTONUP);             /*  0x20C */
        M(WM_XBUTTONDBLCLK);         /*  0x20D */

        M(WM_PARENTNOTIFY);          /*  0x210 */
        M(WM_ENTERMENULOOP);         /*  0x211 */
        M(WM_EXITMENULOOP);          /*  0x212 */
        M(WM_NEXTMENU);              /*  0x213 */
        M(WM_SIZING);                /*  0x214 */
        M(WM_CAPTURECHANGED);        /*  0x215 */
        M(WM_MOVING);                /*  0x216 */
        M(WM_POWERBROADCAST);        /*  0x218 */
        M(WM_DEVICECHANGE);          /*  0x219 */

        M(WM_MDICREATE);             /*  0x220 */
        M(WM_MDIDESTROY);            /*  0x221 */
        M(WM_MDIACTIVATE);           /*  0x222 */
        M(WM_MDIRESTORE);            /*  0x223 */
        M(WM_MDINEXT);               /*  0x224 */
        M(WM_MDIMAXIMIZE);           /*  0x225 */
        M(WM_MDIICONARRANGE);        /*  0x228 */
        M(WM_MDIGETACTIVE);          /*  0x229 */

        M(WM_MDISETMENU);               /*  0x230 */
        M(WM_ENTERSIZEMOVE);            /*  0x231 */
        M(WM_EXITSIZEMOVE);             /*  0x232 */
        M(WM_DROPFILES);                /*  0x233 */
        M(WM_MDIREFRESHMENU);           /*  0x234 */
        M(WM_POINTERDEVICECHANGE);      /*  0x238 */
        M(WM_POINTERDEVICEINRANGE);     /*  0x239 */
        M(WM_POINTERDEVICEOUTOFRANGE);  /*  0x23A */

        M(WM_TOUCH);                 /*  0x240 */
        M(WM_NCPOINTERUPDATE);       /*  0x241 */
        M(WM_NCPOINTERDOWN);         /*  0x242 */
        M(WM_NCPOINTERUP);           /*  0x243 */
                                     /*  0x244 */
        M(WM_POINTERUPDATE);         /*  0x245 */
        M(WM_POINTERDOWN);           /*  0x246 */
        M(WM_POINTERUP);             /*  0x247 */
                                     /*  0x248 */
        M(WM_POINTERENTER);          /*  0x249 */
        M(WM_POINTERLEAVE);          /*  0x24A */
        M(WM_POINTERACTIVATE);       /*  0x24B */
        M(WM_POINTERCAPTURECHANGED); /*  0x24C */
        M(WM_TOUCHHITTESTING);       /*  0x24D */
        M(WM_POINTERWHEEL);          /*  0x24E */
        M(WM_POINTERHWHEEL);         /*  0x24F */

        M(DM_POINTERHITTEST);        /*  0x250 */
        M(WM_POINTERROUTEDTO);       /*  0x251 */
        M(WM_POINTERROUTEDAWAY);     /*  0x252 */
        M(WM_POINTERROUTEDRELEASED); /*  0x253 */

        M(WM_IME_SETCONTEXT);        /*  0x281 */
        M(WM_IME_NOTIFY);            /*  0x282 */
        M(WM_IME_CONTROL);           /*  0x283 */
        M(WM_IME_COMPOSITIONFULL);   /*  0x284 */
        M(WM_IME_SELECT);            /*  0x285 */
        M(WM_IME_CHAR);              /*  0x286 */
        M(WM_IME_REQUEST);           /*  0x288 */

        M(WM_IME_KEYDOWN);           /*  0x290 */
        M(WM_IME_KEYUP);             /*  0x291 */

        M(WM_NCMOUSEHOVER);          /*  0x2A0 */
        M(WM_MOUSEHOVER);            /*  0x2A1 */
        M(WM_NCMOUSELEAVE);          /*  0x2A2 */
        M(WM_MOUSELEAVE);            /*  0x2A3 */

        M(WM_WTSSESSION_CHANGE);     /*  0x2B1 */

        M(WM_TABLET_FIRST);          /*  0x2C0 */

        M(WM_TABLET_LAST);           /*  0x2DF */

        M(WM_DPICHANGED);               /*  0x2E0 */
        M(WM_DPICHANGED_BEFOREPARENT);  /*  0x2E2 */
        M(WM_DPICHANGED_AFTERPARENT);   /*  0x2E3 */
        M(WM_GETDPISCALEDSIZE);         /*  0x2E4 */

        M(WM_CUT);                   /*  0x300 */
        M(WM_COPY);                  /*  0x301 */
        M(WM_PASTE);                 /*  0x302 */
        M(WM_CLEAR);                 /*  0x303 */
        M(WM_UNDO);                  /*  0x304 */
        M(WM_RENDERFORMAT);          /*  0x305 */
        M(WM_RENDERALLFORMATS);      /*  0x306 */
        M(WM_DESTROYCLIPBOARD);      /*  0x307 */
        M(WM_DRAWCLIPBOARD);         /*  0x308 */
        M(WM_PAINTCLIPBOARD);        /*  0x309 */
        M(WM_VSCROLLCLIPBOARD);      /*  0x30A */
        M(WM_SIZECLIPBOARD);         /*  0x30B */
        M(WM_ASKCBFORMATNAME);       /*  0x30C */
        M(WM_CHANGECBCHAIN);         /*  0x30D */
        M(WM_HSCROLLCLIPBOARD);      /*  0x30E */
        M(WM_QUERYNEWPALETTE);       /*  0x30F */

        M(WM_PALETTEISCHANGING);     /*  0x310 */
        M(WM_PALETTECHANGED);        /*  0x311 */
        M(WM_HOTKEY);                /*  0x312 */
        M(WM_PRINT);                 /*  0x317 */
        M(WM_PRINTCLIENT);           /*  0x318 */
        M(WM_APPCOMMAND);            /*  0x319 */
        M(WM_THEMECHANGED);          /*  0x31A */
        M(WM_CLIPBOARDUPDATE);       /*  0x31D */
        M(WM_DWMCOMPOSITIONCHANGED); /*  0x31E */
        M(WM_DWMNCRENDERINGCHANGED); /*  0x31F */

        M(WM_DWMCOLORIZATIONCOLORCHANGED);     /*  0x320 */
        M(WM_DWMWINDOWMAXIMIZEDCHANGE);        /*  0x321 */
        M(WM_DWMSENDICONICTHUMBNAIL);          /*  0x323 */
        M(WM_DWMSENDICONICLIVEPREVIEWBITMAP);  /*  0x326 */

        M(WM_GETTITLEBARINFOEX);     /*  0x33F */

        M(WM_HANDHELDFIRST);         /*  0x358 */
        M(WM_HANDHELDLAST);          /*  0x35F */

        M(WM_AFXFIRST);              /*  0x360 */
        M(WM_AFX_reserved_361);      /*  0x361 */
        M(WM_AFX_reserved_362);      /*  0x362 */
        M(WM_AFX_reserved_363);      /*  0x363 */
        M(WM_AFX_reserved_364);      /*  0x364 */
        M(WM_AFX_reserved_36a);      /*  0x36A */
        M(WM_AFX_reserved_36b);      /*  0x36B */
        M(WM_AFX_reserved_36c);      /*  0x36C */
        M(WM_AFX_reserved_36d);      /*  0x36D */
        M(WM_AFX_reserved_36e);      /*  0x36E */
        M(WM_AFXLAST);               /*  0x37F */

        M(WM_PENWINFIRST);           /*  0x380 */
        M(WM_PENWINLAST);            /*  0x38F */

        M(WM_USER);                  /*  0x400 */

        M(WM_APP);                   /* 0x8000 */
#undef M
    default: {
        if (messageNumber < WM_USER) {
            static CONST CHAR str[] = "UNKNOWN_SYSTEM_MESSAGE"; return str;
        } else if (messageNumber < WM_APP) {
            static CONST CHAR str[] = "UNKNOWN_PRIVATE_MESSAGE"; return str;
        } else if (messageNumber < 0xC000) {
            static CONST CHAR str[] = "UNKNOWN_APPLICATION_MESSAGE"; return str;
        } else if (messageNumber < 0xFFFF) {
            static CONST CHAR str[] = "UNKNOWN_REGISTERED_MESSAGE"; return str;
        } else {
            static CONST CHAR str[] = "UNKNOWN_SYSTEM_MESSAGE"; return str;
        }
    } break;
    }/*switch*/
}

RRWINDOWS_API
LPCWSTR
WINAPI
SystemMessageStringW(
    _In_ CONST UINT messageNumber)
{
    switch (messageNumber) {
#ifdef M
# error Macro name conflicts.
#endif/*M*/
#define M(msg) case msg: { static CONST WCHAR str[] = L#msg; return str; } break
        M(WM_NULL);                  /*    0x0 */
        M(WM_CREATE);                /*    0x1 */
        M(WM_DESTROY);               /*    0x2 */
        M(WM_MOVE);                  /*    0x3 */
        M(WM_SIZEWAIT);              /*    0x4 */
        M(WM_SIZE);                  /*    0x5 */
        M(WM_ACTIVATE);              /*    0x6 */
        M(WM_SETFOCUS);              /*    0x7 */
        M(WM_KILLFOCUS);             /*    0x8 */
        M(WM_SETVISIBLE);            /*    0x9 */
        M(WM_ENABLE);                /*    0xA */
        M(WM_SETREDRAW);             /*    0xB */
        M(WM_SETTEXT);               /*    0xC */
        M(WM_GETTEXT);               /*    0xD */
        M(WM_GETTEXTLENGTH);         /*    0xE */
        M(WM_PAINT);                 /*    0xF */

        M(WM_CLOSE);                 /*   0x10 */
        M(WM_QUERYENDSESSION);       /*   0x11 */
        M(WM_QUIT);                  /*   0x12 */
        M(WM_QUERYOPEN);             /*   0x13 */
        M(WM_ERASEBKGND);            /*   0x14 */
        M(WM_SYSCOLORCHANGE);        /*   0x15 */
        M(WM_ENDSESSION);            /*   0x16 */
        M(WM_SYSTEMERROR);           /*   0x17 */
        M(WM_SHOWWINDOW);            /*   0x18 */
        M(WM_CTLCOLOR);              /*   0x19 */
        M(WM_WININICHANGE);          /*   0x1A */
        M(WM_DEVMODECHANGE);         /*   0x1B */
        M(WM_ACTIVATEAPP);           /*   0x1C */
        M(WM_FONTCHANGE);            /*   0x1D */
        M(WM_TIMECHANGE);            /*   0x1E */
        M(WM_CANCELMODE);            /*   0x1F */

        M(WM_SETCURSOR);             /*   0x20 */
        M(WM_MOUSEACTIVATE);         /*   0x21 */
        M(WM_CHILDACTIVATE);         /*   0x22 */
        M(WM_QUEUESYNC);             /*   0x23 */
        M(WM_GETMINMAXINFO);         /*   0x24 */
        M(WM_LOGOFF);                /*   0x25 */
        M(WM_PAINTICON);             /*   0x26 */
        M(WM_ICONERASEBKGND);        /*   0x27 */
        M(WM_NEXTDLGCTL);            /*   0x28 */
        M(WM_ALTTABACTIVE);          /*   0x29 */
        M(WM_SPOOLERSTATUS);         /*   0x2A */
        M(WM_DRAWITEM);              /*   0x2B */
        M(WM_MEASUREITEM);           /*   0x2C */
        M(WM_DELETEITEM);            /*   0x2D */
        M(WM_VKEYTOITEM);            /*   0x2E */
        M(WM_CHARTOITEM);            /*   0x2F */

        M(WM_SETFONT);               /*   0x30 */
        M(WM_GETFONT);               /*   0x31 */
        M(WM_SETHOTKEY);             /*   0x32 */
        M(WM_GETHOTKEY);             /*   0x33 */
        M(WM_QUERYDRAGICON);         /*   0x37 */
        M(WM_COMPAREITEM);           /*   0x39 */
        M(WM_GETOBJECT);             /*   0x3D */

        M(WM_COMPACTING);            /*   0x41 */
        M(WM_COMMNOTIFY);            /*   0x44 */
        M(WM_WINDOWPOSCHANGING);     /*   0x46 */
        M(WM_WINDOWPOSCHANGED);      /*   0x47 */
        M(WM_POWER);                 /*   0x48 */
        M(WM_COPYDATA);              /*   0x4A */
        M(WM_CANCELJOURNAL);         /*   0x4B */
        M(WM_NOTIFY);                /*   0x4E */

        M(WM_INPUTLANGCHANGEREQUEST);/*   0x50 */
        M(WM_INPUTLANGCHANGE);       /*   0x51 */
        M(WM_TCARD);                 /*   0x52 */
        M(WM_HELP);                  /*   0x53 */
        M(WM_USERCHANGED);           /*   0x54 */
        M(WM_NOTIFYFORMAT);          /*   0x55 */

        M(WM_CONTEXTMENU);           /*   0x7B */
        M(WM_STYLECHANGING);         /*   0x7C */
        M(WM_STYLECHANGED);          /*   0x7D */
        M(WM_DISPLAYCHANGE);         /*   0x7E */
        M(WM_GETICON);               /*   0x7F */

        M(WM_SETICON);               /*   0x80 */
        M(WM_NCCREATE);              /*   0x81 */
        M(WM_NCDESTROY);             /*   0x82 */
        M(WM_NCCALCSIZE);            /*   0x83 */
        M(WM_NCHITTEST);             /*   0x84 */
        M(WM_NCPAINT);               /*   0x85 */
        M(WM_NCACTIVATE);            /*   0x86 */
        M(WM_GETDLGCODE);            /*   0x87 */
        M(WM_SYNCPAINT);             /*   0x88 */

        M(WM_UAHDESTROYWINDOW);      /*   0x90 */
        M(WM_UAHDRAWMENU);           /*   0x91 */
        M(WM_UAHDRAWMENUITEM);       /*   0x92 */
        M(WM_UAHINITMENU);           /*   0x93 */
        M(WM_UAHMEASUREMENUITEM);    /*   0x94 */

        M(WM_NCMOUSEMOVE);           /*   0xA0 */
        M(WM_NCLBUTTONDOWN);         /*   0xA1 */
        M(WM_NCLBUTTONUP);           /*   0xA2 */
        M(WM_NCLBUTTONDBLCLK);       /*   0xA3 */
        M(WM_NCRBUTTONDOWN);         /*   0xA4 */
        M(WM_NCRBUTTONUP);           /*   0xA5 */
        M(WM_NCRBUTTONDBLCLK);       /*   0xA6 */
        M(WM_NCMBUTTONDOWN);         /*   0xA7 */
        M(WM_NCMBUTTONUP);           /*   0xA8 */
        M(WM_NCMBUTTONDBLCLK);       /*   0xA9 */
                                     /*   0xAA */
        M(WM_NCXBUTTONDOWN);         /*   0xAB */
        M(WM_NCXBUTTONUP);           /*   0xAC */
        M(WM_NCXBUTTONDBLCLK);       /*   0xAD */
        M(WM_NCUAHDRAWCAPTION);      /*   0xAE */

        M(WM_INPUT_DEVICE_CHANGE);   /*   0xFE */
        M(WM_INPUT);                 /*   0xFF */

        M(WM_KEYDOWN);               /*  0x100 */
        M(WM_KEYUP);                 /*  0x101 */
        M(WM_CHAR);                  /*  0x102 */
        M(WM_DEADCHAR);              /*  0x103 */
        M(WM_SYSKEYDOWN);            /*  0x104 */
        M(WM_SYSKEYUP);              /*  0x105 */
        M(WM_SYSCHAR);               /*  0x106 */
        M(WM_SYSDEADCHAR);           /*  0x107 */
        M(WM_UNICHAR);               /*  0x109 */
        M(WM_IME_STARTCOMPOSITION);  /*  0x10D */
        M(WM_IME_ENDCOMPOSITION);    /*  0x10E */
        M(WM_IME_COMPOSITION);       /*  0x10F */

        M(WM_INITDIALOG);            /*  0x110 */
        M(WM_COMMAND);               /*  0x111 */
        M(WM_SYSCOMMAND);            /*  0x112 */
        M(WM_TIMER);                 /*  0x113 */
        M(WM_HSCROLL);               /*  0x114 */
        M(WM_VSCROLL);               /*  0x115 */
        M(WM_INITMENU);              /*  0x116 */
        M(WM_INITMENUPOPUP);         /*  0x117 */
        M(WM_GESTURE);               /*  0x119 */
        M(WM_GESTURENOTIFY);         /*  0x11A */
        M(WM_MENUSELECT);            /*  0x11F */

        M(WM_MENUCHAR);              /*  0x120 */
        M(WM_ENTERIDLE);             /*  0x121 */
        M(WM_MENURBUTTONUP);         /*  0x122 */
        M(WM_MENUDRAG);              /*  0x123 */
        M(WM_MENUGETOBJECT);         /*  0x124 */
        M(WM_UNINITMENUPOPUP);       /*  0x125 */
        M(WM_MENUCOMMAND);           /*  0x126 */
        M(WM_CHANGEUISTATE);         /*  0x127 */
        M(WM_UPDATEUISTATE);         /*  0x128 */
        M(WM_QUERYUISTATE);          /*  0x129 */

        M(WM_CTLCOLORMSGBOX);        /*  0x132 */
        M(WM_CTLCOLOREDIT);          /*  0x133 */
        M(WM_CTLCOLORLISTBOX);       /*  0x134 */
        M(WM_CTLCOLORBTN);           /*  0x135 */
        M(WM_CTLCOLORDLG);           /*  0x136 */
        M(WM_CTLCOLORSCROLLBAR);     /*  0x137 */
        M(WM_CTLCOLORSTATIC);        /*  0x138 */

        M(MN_GETHMENU);              /*  0x1E1 */

        M(WM_MOUSEMOVE);             /*  0x200 */
        M(WM_LBUTTONDOWN);           /*  0x201 */
        M(WM_LBUTTONUP);             /*  0x202 */
        M(WM_LBUTTONDBLCLK);         /*  0x203 */
        M(WM_RBUTTONDOWN);           /*  0x204 */
        M(WM_RBUTTONUP);             /*  0x205 */
        M(WM_RBUTTONDBLCLK);         /*  0x206 */
        M(WM_MBUTTONDOWN);           /*  0x207 */
        M(WM_MBUTTONUP);             /*  0x208 */
        M(WM_MBUTTONDBLCLK);         /*  0x209 */
        M(WM_MOUSEWHEEL);            /*  0x20A */
        M(WM_XBUTTONDOWN);           /*  0x20B */
        M(WM_XBUTTONUP);             /*  0x20C */
        M(WM_XBUTTONDBLCLK);         /*  0x20D */

        M(WM_PARENTNOTIFY);          /*  0x210 */
        M(WM_ENTERMENULOOP);         /*  0x211 */
        M(WM_EXITMENULOOP);          /*  0x212 */
        M(WM_NEXTMENU);              /*  0x213 */
        M(WM_SIZING);                /*  0x214 */
        M(WM_CAPTURECHANGED);        /*  0x215 */
        M(WM_MOVING);                /*  0x216 */
        M(WM_POWERBROADCAST);        /*  0x218 */
        M(WM_DEVICECHANGE);          /*  0x219 */

        M(WM_MDICREATE);             /*  0x220 */
        M(WM_MDIDESTROY);            /*  0x221 */
        M(WM_MDIACTIVATE);           /*  0x222 */
        M(WM_MDIRESTORE);            /*  0x223 */
        M(WM_MDINEXT);               /*  0x224 */
        M(WM_MDIMAXIMIZE);           /*  0x225 */
        M(WM_MDIICONARRANGE);        /*  0x228 */
        M(WM_MDIGETACTIVE);          /*  0x229 */

        M(WM_MDISETMENU);               /*  0x230 */
        M(WM_ENTERSIZEMOVE);            /*  0x231 */
        M(WM_EXITSIZEMOVE);             /*  0x232 */
        M(WM_DROPFILES);                /*  0x233 */
        M(WM_MDIREFRESHMENU);           /*  0x234 */
        M(WM_POINTERDEVICECHANGE);      /*  0x238 */
        M(WM_POINTERDEVICEINRANGE);     /*  0x239 */
        M(WM_POINTERDEVICEOUTOFRANGE);  /*  0x23A */

        M(WM_TOUCH);                 /*  0x240 */
        M(WM_NCPOINTERUPDATE);       /*  0x241 */
        M(WM_NCPOINTERDOWN);         /*  0x242 */
        M(WM_NCPOINTERUP);           /*  0x243 */
                                     /*  0x244 */
        M(WM_POINTERUPDATE);         /*  0x245 */
        M(WM_POINTERDOWN);           /*  0x246 */
        M(WM_POINTERUP);             /*  0x247 */
                                     /*  0x248 */
        M(WM_POINTERENTER);          /*  0x249 */
        M(WM_POINTERLEAVE);          /*  0x24A */
        M(WM_POINTERACTIVATE);       /*  0x24B */
        M(WM_POINTERCAPTURECHANGED); /*  0x24C */
        M(WM_TOUCHHITTESTING);       /*  0x24D */
        M(WM_POINTERWHEEL);          /*  0x24E */
        M(WM_POINTERHWHEEL);         /*  0x24F */

        M(DM_POINTERHITTEST);        /*  0x250 */
        M(WM_POINTERROUTEDTO);       /*  0x251 */
        M(WM_POINTERROUTEDAWAY);     /*  0x252 */
        M(WM_POINTERROUTEDRELEASED); /*  0x253 */

        M(WM_IME_SETCONTEXT);        /*  0x281 */
        M(WM_IME_NOTIFY);            /*  0x282 */
        M(WM_IME_CONTROL);           /*  0x283 */
        M(WM_IME_COMPOSITIONFULL);   /*  0x284 */
        M(WM_IME_SELECT);            /*  0x285 */
        M(WM_IME_CHAR);              /*  0x286 */
        M(WM_IME_REQUEST);           /*  0x288 */

        M(WM_IME_KEYDOWN);           /*  0x290 */
        M(WM_IME_KEYUP);             /*  0x291 */

        M(WM_NCMOUSEHOVER);          /*  0x2A0 */
        M(WM_MOUSEHOVER);            /*  0x2A1 */
        M(WM_NCMOUSELEAVE);          /*  0x2A2 */
        M(WM_MOUSELEAVE);            /*  0x2A3 */

        M(WM_WTSSESSION_CHANGE);     /*  0x2B1 */

        M(WM_TABLET_FIRST);          /*  0x2C0 */

        M(WM_TABLET_LAST);           /*  0x2DF */

        M(WM_DPICHANGED);               /*  0x2E0 */
        M(WM_DPICHANGED_BEFOREPARENT);  /*  0x2E2 */
        M(WM_DPICHANGED_AFTERPARENT);   /*  0x2E3 */
        M(WM_GETDPISCALEDSIZE);         /*  0x2E4 */

        M(WM_CUT);                   /*  0x300 */
        M(WM_COPY);                  /*  0x301 */
        M(WM_PASTE);                 /*  0x302 */
        M(WM_CLEAR);                 /*  0x303 */
        M(WM_UNDO);                  /*  0x304 */
        M(WM_RENDERFORMAT);          /*  0x305 */
        M(WM_RENDERALLFORMATS);      /*  0x306 */
        M(WM_DESTROYCLIPBOARD);      /*  0x307 */
        M(WM_DRAWCLIPBOARD);         /*  0x308 */
        M(WM_PAINTCLIPBOARD);        /*  0x309 */
        M(WM_VSCROLLCLIPBOARD);      /*  0x30A */
        M(WM_SIZECLIPBOARD);         /*  0x30B */
        M(WM_ASKCBFORMATNAME);       /*  0x30C */
        M(WM_CHANGECBCHAIN);         /*  0x30D */
        M(WM_HSCROLLCLIPBOARD);      /*  0x30E */
        M(WM_QUERYNEWPALETTE);       /*  0x30F */

        M(WM_PALETTEISCHANGING);     /*  0x310 */
        M(WM_PALETTECHANGED);        /*  0x311 */
        M(WM_HOTKEY);                /*  0x312 */
        M(WM_PRINT);                 /*  0x317 */
        M(WM_PRINTCLIENT);           /*  0x318 */
        M(WM_APPCOMMAND);            /*  0x319 */
        M(WM_THEMECHANGED);          /*  0x31A */
        M(WM_CLIPBOARDUPDATE);       /*  0x31D */
        M(WM_DWMCOMPOSITIONCHANGED); /*  0x31E */
        M(WM_DWMNCRENDERINGCHANGED); /*  0x31F */

        M(WM_DWMCOLORIZATIONCOLORCHANGED);     /*  0x320 */
        M(WM_DWMWINDOWMAXIMIZEDCHANGE);        /*  0x321 */
        M(WM_DWMSENDICONICTHUMBNAIL);          /*  0x323 */
        M(WM_DWMSENDICONICLIVEPREVIEWBITMAP);  /*  0x326 */

        M(WM_GETTITLEBARINFOEX);     /*  0x33F */

        M(WM_HANDHELDFIRST);         /*  0x358 */
        M(WM_HANDHELDLAST);          /*  0x35F */

        M(WM_AFXFIRST);              /*  0x360 */
        M(WM_AFX_reserved_361);      /*  0x361 */
        M(WM_AFX_reserved_362);      /*  0x362 */
        M(WM_AFX_reserved_363);      /*  0x363 */
        M(WM_AFX_reserved_364);      /*  0x364 */
        M(WM_AFX_reserved_36a);      /*  0x36A */
        M(WM_AFX_reserved_36b);      /*  0x36B */
        M(WM_AFX_reserved_36c);      /*  0x36C */
        M(WM_AFX_reserved_36d);      /*  0x36D */
        M(WM_AFX_reserved_36e);      /*  0x36E */
        M(WM_AFXLAST);               /*  0x37F */

        M(WM_PENWINFIRST);           /*  0x380 */
        M(WM_PENWINLAST);            /*  0x38F */

        M(WM_USER);                  /*  0x400 */

        M(WM_APP);                   /* 0x8000 */
#undef M
    default: {
        if (messageNumber < WM_USER) {
            static CONST WCHAR str[] = L"UNKNOWN_SYSTEM_MESSAGE"; return str;
        } else if (messageNumber < WM_APP) {
            static CONST WCHAR str[] = L"UNKNOWN_PRIVATE_MESSAGE"; return str;
        } else if (messageNumber < 0xC000) {
            static CONST WCHAR str[] = L"UNKNOWN_APPLICATION_MESSAGE"; return str;
        } else if (messageNumber < 0xFFFF) {
            static CONST WCHAR str[] = L"UNKNOWN_REGISTERED_MESSAGE"; return str;
        } else {
            static CONST WCHAR str[] = L"UNKNOWN_SYSTEM_MESSAGE"; return str;
        }
    } break;
    }/*switch*/
}

RRWINDOWS_API
LPCSTR
WINAPI
SystemCommandStringA(
    _In_ CONST UINT commandId)
{
    if (0x8000 <= commandId && commandId <= 0xDFFF) {
        static CONST CHAR str[] = "CUSTOM_COMMAND"; return str;
    } else {
        static CONST CHAR str[] = "SYSTEM_COMMAND"; return str;
    }
}

RRWINDOWS_API
LPCWSTR
WINAPI
SystemCommandStringW(
    _In_ CONST UINT commandId)
{
    if (0x8000 <= commandId && commandId <= 0xDFFF) {
        static CONST WCHAR str[] = L"CUSTOM_COMMAND"; return str;
    } else {
        static CONST WCHAR str[] = L"SYSTEM_COMMAND"; return str;
    }
}


RRWINDOWS_API
LPCSTR
WINAPI
SystemCommandNotificationStringA(
    _In_ CONST INT commandNotificationCode)
{
    switch (commandNotificationCode) {
#ifdef M
# error Macro name conflicts.
#endif/*M*/
#define M(code) case code: { static CONST CHAR str[] = #code; return str; } break
        M(CN_COMMAND);
        M(CN_UPDATE_COMMAND_UI);
        M(CN_EVENT);
        M(CN_OLECOMMAND);
        M(CN_OLE_UNREGISTER);
#undef M
    default: {
        if (commandNotificationCode < 0) {
            static CONST CHAR str[] = "SYSTEM_COMMAND_NOTIFICATION"; return str;
        } else if (0 < commandNotificationCode) {
            static CONST CHAR str[] = "CONTROL_COMMAND_NOTIFICATION"; return str;
        } else {
            static CONST CHAR str[] = "CN_COMMAND"; return str;
        }
    } break;
    }/*switch*/
}

RRWINDOWS_API
LPCWSTR
WINAPI
SystemCommandNotificationStringW(
    _In_ CONST INT commandNotificationCode)
{
    switch (commandNotificationCode) {
#ifdef M
# error Macro name conflicts.
#endif/*M*/
#define M(code) case code: { static CONST WCHAR str[] = L#code; return str; } break
        M(CN_COMMAND);
        M(CN_UPDATE_COMMAND_UI);
        M(CN_EVENT);
        M(CN_OLECOMMAND);
        M(CN_OLE_UNREGISTER);
#undef M
    default: {
        if (commandNotificationCode < 0) {
            static CONST WCHAR str[] = L"SYSTEM_COMMAND_NOTIFICATION"; return str;
        } else if (0 < commandNotificationCode) {
            static CONST WCHAR str[] = L"CONTROL_COMMAND_NOTIFICATION"; return str;
        } else {
            static CONST WCHAR str[] = L"CN_COMMAND"; return str;
        } break;
    }/*switch*/
    }
}
