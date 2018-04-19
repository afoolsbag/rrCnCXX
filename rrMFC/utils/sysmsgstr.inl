//===-- System Message String -----------------------------------*- C++ -*-===//
///
/// \file
/// \brief 系统消息字串。
///
/// \version 2018-04-19
/// \since 2018-04-13
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

#include "sysmsg.inl"

#define SysMsgStr SystemMessageString
/**
 * \brief System Message (Number) to String.
 */
static CString
SystemMessageString(CONST UINT msgNum)
{
    switch (msgNum) {
#ifdef m
# error Macro name conflicts.
#endif//m
#define m(msg) case msg: return TEXT(#msg); break
        m(WM_NULL);                  //    0x0
        m(WM_CREATE);                //    0x1
        m(WM_DESTROY);               //    0x2
        m(WM_MOVE);                  //    0x3
        m(WM_SIZEWAIT);              //    0x4
        m(WM_SIZE);                  //    0x5
        m(WM_ACTIVATE);              //    0x6
        m(WM_SETFOCUS);              //    0x7
        m(WM_KILLFOCUS);             //    0x8
        m(WM_SETVISIBLE);            //    0x9
        m(WM_ENABLE);                //    0xA
        m(WM_SETREDRAW);             //    0xB
        m(WM_SETTEXT);               //    0xC
        m(WM_GETTEXT);               //    0xD
        m(WM_GETTEXTLENGTH);         //    0xE
        m(WM_PAINT);                 //    0xF

        m(WM_CLOSE);                 //   0x10
        m(WM_QUERYENDSESSION);       //   0x11
        m(WM_QUIT);                  //   0x12
        m(WM_QUERYOPEN);             //   0x13
        m(WM_ERASEBKGND);            //   0x14
        m(WM_SYSCOLORCHANGE);        //   0x15
        m(WM_ENDSESSION);            //   0x16
        m(WM_SYSTEMERROR);           //   0x17
        m(WM_SHOWWINDOW);            //   0x18
        m(WM_CTLCOLOR);              //   0x19
        m(WM_WININICHANGE);          //   0x1A
        m(WM_DEVMODECHANGE);         //   0x1B
        m(WM_ACTIVATEAPP);           //   0x1C
        m(WM_FONTCHANGE);            //   0x1D
        m(WM_TIMECHANGE);            //   0x1E
        m(WM_CANCELMODE);            //   0x1F

        m(WM_SETCURSOR);             //   0x20
        m(WM_MOUSEACTIVATE);         //   0x21
        m(WM_CHILDACTIVATE);         //   0x22
        m(WM_QUEUESYNC);             //   0x23
        m(WM_GETMINMAXINFO);         //   0x24
        m(WM_LOGOFF);                //   0x25
        m(WM_PAINTICON);             //   0x26
        m(WM_ICONERASEBKGND);        //   0x27
        m(WM_NEXTDLGCTL);            //   0x28
        m(WM_ALTTABACTIVE);          //   0x29
        m(WM_SPOOLERSTATUS);         //   0x2A
        m(WM_DRAWITEM);              //   0x2B
        m(WM_MEASUREITEM);           //   0x2C
        m(WM_DELETEITEM);            //   0x2D
        m(WM_VKEYTOITEM);            //   0x2E
        m(WM_CHARTOITEM);            //   0x2F

        m(WM_SETFONT);               //   0x30
        m(WM_GETFONT);               //   0x31
        m(WM_SETHOTKEY);             //   0x32
        m(WM_GETHOTKEY);             //   0x33
        m(WM_QUERYDRAGICON);         //   0x37
        m(WM_COMPAREITEM);           //   0x39
        m(WM_GETOBJECT);             //   0x3D

        m(WM_COMPACTING);            //   0x41
        m(WM_COMMNOTIFY);            //   0x44
        m(WM_WINDOWPOSCHANGING);     //   0x46
        m(WM_WINDOWPOSCHANGED);      //   0x47
        m(WM_POWER);                 //   0x48
        m(WM_COPYDATA);              //   0x4A
        m(WM_CANCELJOURNAL);         //   0x4B
        m(WM_NOTIFY);                //   0x4E

        m(WM_INPUTLANGCHANGEREQUEST);//   0x50
        m(WM_INPUTLANGCHANGE);       //   0x51
        m(WM_TCARD);                 //   0x52
        m(WM_HELP);                  //   0x53
        m(WM_USERCHANGED);           //   0x54
        m(WM_NOTIFYFORMAT);          //   0x55

        m(WM_CONTEXTMENU);           //   0x7B
        m(WM_STYLECHANGING);         //   0x7C
        m(WM_STYLECHANGED);          //   0x7D
        m(WM_DISPLAYCHANGE);         //   0x7E
        m(WM_GETICON);               //   0x7F

        m(WM_SETICON);               //   0x80
        m(WM_NCCREATE);              //   0x81
        m(WM_NCDESTROY);             //   0x82
        m(WM_NCCALCSIZE);            //   0x83
        m(WM_NCHITTEST);             //   0x84
        m(WM_NCPAINT);               //   0x85
        m(WM_NCACTIVATE);            //   0x86
        m(WM_GETDLGCODE);            //   0x87
        m(WM_SYNCPAINT);             //   0x88

        m(WM_UAHDRAWMENU);           //   0x91
        m(WM_UAHDRAWMENUITEM);       //   0x92
        m(WM_UAHINITMENU);           //   0x93
        m(WM_UAHMEASUREMENUITEM);    //   0x94

        m(WM_NCMOUSEMOVE);           //   0xA0
        m(WM_NCLBUTTONDOWN);         //   0xA1
        m(WM_NCLBUTTONUP);           //   0xA2
        m(WM_NCLBUTTONDBLCLK);       //   0xA3
        m(WM_NCRBUTTONDOWN);         //   0xA4
        m(WM_NCRBUTTONUP);           //   0xA5
        m(WM_NCRBUTTONDBLCLK);       //   0xA6
        m(WM_NCMBUTTONDOWN);         //   0xA7
        m(WM_NCMBUTTONUP);           //   0xA8
        m(WM_NCMBUTTONDBLCLK);       //   0xA9
                                     //   0xAA
        m(WM_NCXBUTTONDOWN);         //   0xAB
        m(WM_NCXBUTTONUP);           //   0xAC
        m(WM_NCXBUTTONDBLCLK);       //   0xAD
        m(WM_NCUAHDRAWCAPTION);      //   0xAE

        m(WM_INPUT_DEVICE_CHANGE);   //   0xFE
        m(WM_INPUT);                 //   0xFF

        m(WM_KEYDOWN);               //  0x100
        m(WM_KEYUP);                 //  0x101
        m(WM_CHAR);                  //  0x102
        m(WM_DEADCHAR);              //  0x103
        m(WM_SYSKEYDOWN);            //  0x104
        m(WM_SYSKEYUP);              //  0x105
        m(WM_SYSCHAR);               //  0x106
        m(WM_SYSDEADCHAR);           //  0x107
        m(WM_UNICHAR);               //  0x109
        m(WM_IME_STARTCOMPOSITION);  //  0x10D
        m(WM_IME_ENDCOMPOSITION);    //  0x10E
        m(WM_IME_COMPOSITION);       //  0x10F

        m(WM_INITDIALOG);            //  0x110 
        m(WM_COMMAND);               //  0x111
        m(WM_SYSCOMMAND);            //  0x112
        m(WM_TIMER);                 //  0x113
        m(WM_HSCROLL);               //  0x114
        m(WM_VSCROLL);               //  0x115
        m(WM_INITMENU);              //  0x116
        m(WM_INITMENUPOPUP);         //  0x117
        m(WM_GESTURE);               //  0x119
        m(WM_GESTURENOTIFY);         //  0x11A
        m(WM_MENUSELECT);            //  0x11F

        m(WM_MENUCHAR);              //  0x120
        m(WM_ENTERIDLE);             //  0x121
        m(WM_MENURBUTTONUP);         //  0x122
        m(WM_MENUDRAG);              //  0x123
        m(WM_MENUGETOBJECT);         //  0x124
        m(WM_UNINITMENUPOPUP);       //  0x125
        m(WM_MENUCOMMAND);           //  0x126
        m(WM_CHANGEUISTATE);         //  0x127
        m(WM_UPDATEUISTATE);         //  0x128
        m(WM_QUERYUISTATE);          //  0x129

        m(WM_CTLCOLORMSGBOX);        //  0x132
        m(WM_CTLCOLOREDIT);          //  0x133
        m(WM_CTLCOLORLISTBOX);       //  0x134
        m(WM_CTLCOLORBTN);           //  0x135
        m(WM_CTLCOLORDLG);           //  0x136
        m(WM_CTLCOLORSCROLLBAR);     //  0x137
        m(WM_CTLCOLORSTATIC);        //  0x138

        m(MN_GETHMENU);              //  0x1E1

        m(WM_MOUSEMOVE);             //  0x200
        m(WM_LBUTTONDOWN);           //  0x201
        m(WM_LBUTTONUP);             //  0x202
        m(WM_LBUTTONDBLCLK);         //  0x203
        m(WM_RBUTTONDOWN);           //  0x204
        m(WM_RBUTTONUP);             //  0x205
        m(WM_RBUTTONDBLCLK);         //  0x206
        m(WM_MBUTTONDOWN);           //  0x207
        m(WM_MBUTTONUP);             //  0x208
        m(WM_MBUTTONDBLCLK);         //  0x209
        m(WM_MOUSEWHEEL);            //  0x20A
        m(WM_XBUTTONDOWN);           //  0x20B
        m(WM_XBUTTONUP);             //  0x20C
        m(WM_XBUTTONDBLCLK);         //  0x20D

        m(WM_PARENTNOTIFY);          //  0x210
        m(WM_ENTERMENULOOP);         //  0x211
        m(WM_EXITMENULOOP);          //  0x212
        m(WM_NEXTMENU);              //  0x213
        m(WM_SIZING);                //  0x214
        m(WM_CAPTURECHANGED);        //  0x215
        m(WM_MOVING);                //  0x216
        m(WM_POWERBROADCAST);        //  0x218
        m(WM_DEVICECHANGE);          //  0x219

        m(WM_MDICREATE);             //  0x220
        m(WM_MDIDESTROY);            //  0x221
        m(WM_MDIACTIVATE);           //  0x222
        m(WM_MDIRESTORE);            //  0x223
        m(WM_MDINEXT);               //  0x224
        m(WM_MDIMAXIMIZE);           //  0x225
        m(WM_MDIICONARRANGE);        //  0x228
        m(WM_MDIGETACTIVE);          //  0x229

        m(WM_MDISETMENU);               //  0x230
        m(WM_ENTERSIZEMOVE);            //  0x231
        m(WM_EXITSIZEMOVE);             //  0x232
        m(WM_DROPFILES);                //  0x233
        m(WM_MDIREFRESHMENU);           //  0x234
        m(WM_POINTERDEVICECHANGE);      //  0x238
        m(WM_POINTERDEVICEINRANGE);     //  0x239
        m(WM_POINTERDEVICEOUTOFRANGE);  //  0x23A

        m(WM_TOUCH);                 //  0x240
        m(WM_NCPOINTERUPDATE);       //  0x241
        m(WM_NCPOINTERDOWN);         //  0x242
        m(WM_NCPOINTERUP);           //  0x243
                                     //  0x244
        m(WM_POINTERUPDATE);         //  0x245
        m(WM_POINTERDOWN);           //  0x246
        m(WM_POINTERUP);             //  0x247
                                     //  0x248
        m(WM_POINTERENTER);          //  0x249
        m(WM_POINTERLEAVE);          //  0x24A
        m(WM_POINTERACTIVATE);       //  0x24B
        m(WM_POINTERCAPTURECHANGED); //  0x24C
        m(WM_TOUCHHITTESTING);       //  0x24D
        m(WM_POINTERWHEEL);          //  0x24E
        m(WM_POINTERHWHEEL);         //  0x24F

        m(DM_POINTERHITTEST);        //  0x250
        m(WM_POINTERROUTEDTO);       //  0x251
        m(WM_POINTERROUTEDAWAY);     //  0x252
        m(WM_POINTERROUTEDRELEASED); //  0x253

        m(WM_IME_SETCONTEXT);        //  0x281
        m(WM_IME_NOTIFY);            //  0x282
        m(WM_IME_CONTROL);           //  0x283
        m(WM_IME_COMPOSITIONFULL);   //  0x284
        m(WM_IME_SELECT);            //  0x285
        m(WM_IME_CHAR);              //  0x286
        m(WM_IME_REQUEST);           //  0x288

        m(WM_IME_KEYDOWN);           //  0x290
        m(WM_IME_KEYUP);             //  0x291

        m(WM_NCMOUSEHOVER);          //  0x2A0
        m(WM_MOUSEHOVER);            //  0x2A1
        m(WM_NCMOUSELEAVE);          //  0x2A2
        m(WM_MOUSELEAVE);            //  0x2A3

        m(WM_WTSSESSION_CHANGE);     //  0x2B1

        m(WM_TABLET_FIRST);          //  0x2C0

        m(WM_TABLET_LAST);           //  0x2DF

        m(WM_DPICHANGED);               //  0x2E0
        m(WM_DPICHANGED_BEFOREPARENT);  //  0x2E2
        m(WM_DPICHANGED_AFTERPARENT);   //  0x2E3
        m(WM_GETDPISCALEDSIZE);         //  0x2E4

        m(WM_CUT);                   //  0x300
        m(WM_COPY);                  //  0x301
        m(WM_PASTE);                 //  0x302
        m(WM_CLEAR);                 //  0x303
        m(WM_UNDO);                  //  0x304
        m(WM_RENDERFORMAT);          //  0x305
        m(WM_RENDERALLFORMATS);      //  0x306
        m(WM_DESTROYCLIPBOARD);      //  0x307
        m(WM_DRAWCLIPBOARD);         //  0x308
        m(WM_PAINTCLIPBOARD);        //  0x309
        m(WM_VSCROLLCLIPBOARD);      //  0x30A
        m(WM_SIZECLIPBOARD);         //  0x30B
        m(WM_ASKCBFORMATNAME);       //  0x30C
        m(WM_CHANGECBCHAIN);         //  0x30D
        m(WM_HSCROLLCLIPBOARD);      //  0x30E
        m(WM_QUERYNEWPALETTE);       //  0x30F

        m(WM_PALETTEISCHANGING);     //  0x310
        m(WM_PALETTECHANGED);        //  0x311
        m(WM_HOTKEY);                //  0x312
        m(WM_PRINT);                 //  0x317
        m(WM_PRINTCLIENT);           //  0x318
        m(WM_APPCOMMAND);            //  0x319
        m(WM_THEMECHANGED);          //  0x31A
        m(WM_CLIPBOARDUPDATE);       //  0x31D
        m(WM_DWMCOMPOSITIONCHANGED); //  0x31E
        m(WM_DWMNCRENDERINGCHANGED); //  0x31F

        m(WM_DWMCOLORIZATIONCOLORCHANGED);     //  0x320
        m(WM_DWMWINDOWMAXIMIZEDCHANGE);        //  0x321
        m(WM_DWMSENDICONICTHUMBNAIL);          //  0x323
        m(WM_DWMSENDICONICLIVEPREVIEWBITMAP);  //  0x326

        m(WM_GETTITLEBARINFOEX);     //  0x33F

        m(WM_HANDHELDFIRST);         //  0x358
        m(WM_HANDHELDLAST);          //  0x35F

        m(WM_AFXFIRST);              //  0x360
        m(WM_AFX_reserved_362);      //  0x362
        m(WM_AFX_reserved_363);      //  0x363
        m(WM_AFX_reserved_364);      //  0x364
        m(WM_AFX_reserved_36a);      //  0x36A
        m(WM_AFX_reserved_36d);      //  0x36D
        m(WM_AFX_reserved_36e);      //  0x36E
        m(WM_AFXLAST);               //  0x37F

        m(WM_PENWINFIRST);           //  0x380
        m(WM_PENWINLAST);            //  0x38F

        m(WM_USER);                  //  0x400

        m(WM_APP);                   // 0x8000
#undef m
    default: return TEXT("UNKNOWN"); break;
    }
}
