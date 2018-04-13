//===-- System Message String -----------------------------------*- C++ -*-===//
///
/// \file
/// \brief 系统消息字串。
///
/// \version 2018-04-13
/// \since 2018-04-13
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

static CString SysMsgStr(CONST UINT msgNum)
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
                                     //    0x4
        m(WM_SIZE);                  //    0x5
        m(WM_ACTIVATE);              //    0x6
        m(WM_SETFOCUS);              //    0x7
        m(WM_KILLFOCUS);             //    0x8
                                     //    0x9
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
                                     //   0x17
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
                                     //   0x25
        m(WM_PAINTICON);             //   0x26
        m(WM_ICONERASEBKGND);        //   0x27
        m(WM_NEXTDLGCTL);            //   0x28
                                     //   0x29
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

        m(WM_INITDIALOG);
        m(WM_COMMAND);
        m(WM_SYSCOMMAND);
        m(WM_TIMER);
        m(WM_HSCROLL);
        m(WM_VSCROLL);
        m(WM_INITMENU);
        m(WM_INITMENUPOPUP);
        m(WM_GESTURE);
        m(WM_GESTURENOTIFY);
        m(WM_MENUSELECT);

        m(WM_MENUCHAR);
        m(WM_ENTERIDLE);
        m(WM_MENURBUTTONUP);
        m(WM_MENUDRAG);
        m(WM_MENUGETOBJECT);
        m(WM_UNINITMENUPOPUP);
        m(WM_MENUCOMMAND);
        m(WM_CHANGEUISTATE);
        m(WM_UPDATEUISTATE);
        m(WM_QUERYUISTATE);

        m(WM_CTLCOLORMSGBOX);
        m(WM_CTLCOLOREDIT);
        m(WM_CTLCOLORLISTBOX);
        m(WM_CTLCOLORBTN);
        m(WM_CTLCOLORDLG);
        m(WM_CTLCOLORSCROLLBAR);
        m(WM_CTLCOLORSTATIC);

        m(MN_GETHMENU);

        m(WM_MOUSEMOVE);
        m(WM_LBUTTONDOWN);
        m(WM_LBUTTONUP);
        m(WM_LBUTTONDBLCLK);
        m(WM_RBUTTONDOWN);
        m(WM_RBUTTONUP);
        m(WM_RBUTTONDBLCLK);
        m(WM_MBUTTONDOWN);
        m(WM_MBUTTONUP);
        m(WM_MBUTTONDBLCLK);
        m(WM_MOUSEWHEEL);
        m(WM_XBUTTONDOWN);
        m(WM_XBUTTONUP);
        m(WM_XBUTTONDBLCLK);

        m(WM_PARENTNOTIFY);
        m(WM_ENTERMENULOOP);
        m(WM_EXITMENULOOP);
        m(WM_NEXTMENU);
        m(WM_SIZING);
        m(WM_CAPTURECHANGED);
        m(WM_MOVING);
        m(WM_POWERBROADCAST);
        m(WM_DEVICECHANGE);

        m(WM_MDICREATE);
        m(WM_MDIDESTROY);
        m(WM_MDIACTIVATE);
        m(WM_MDIRESTORE);
        m(WM_MDINEXT);
        m(WM_MDIMAXIMIZE);
        m(WM_MDIICONARRANGE);
        m(WM_MDIGETACTIVE);

        m(WM_MDISETMENU);
        m(WM_ENTERSIZEMOVE);
        m(WM_EXITSIZEMOVE);
        m(WM_DROPFILES);
        m(WM_MDIREFRESHMENU);
        m(WM_POINTERDEVICECHANGE);
        m(WM_POINTERDEVICEINRANGE);
        m(WM_POINTERDEVICEOUTOFRANGE);

        m(WM_TOUCH);
        m(WM_NCPOINTERUPDATE);
        m(WM_NCPOINTERDOWN);
        m(WM_NCPOINTERUP);
        m(WM_POINTERUPDATE);
        m(WM_POINTERDOWN);
        m(WM_POINTERUP);
        m(WM_POINTERENTER);
        m(WM_POINTERLEAVE);
        m(WM_POINTERACTIVATE);
        m(WM_POINTERCAPTURECHANGED);
        m(WM_TOUCHHITTESTING);
        m(WM_POINTERWHEEL);
        m(WM_POINTERHWHEEL);

        m(DM_POINTERHITTEST);
        m(WM_POINTERROUTEDTO);
        m(WM_POINTERROUTEDAWAY);
        m(WM_POINTERROUTEDRELEASED);

        m(WM_IME_SETCONTEXT);
        m(WM_IME_NOTIFY);
        m(WM_IME_CONTROL);
        m(WM_IME_COMPOSITIONFULL);
        m(WM_IME_SELECT);
        m(WM_IME_CHAR);
        m(WM_IME_REQUEST);

        m(WM_IME_KEYDOWN);
        m(WM_IME_KEYUP);

        m(WM_NCMOUSEHOVER);
        m(WM_NCMOUSELEAVE);
        m(WM_MOUSEHOVER);
        m(WM_MOUSELEAVE);

        m(WM_WTSSESSION_CHANGE);

        m(WM_TABLET_FIRST);

        m(WM_TABLET_LAST);

        m(WM_DPICHANGED);
        m(WM_DPICHANGED_BEFOREPARENT);
        m(WM_DPICHANGED_AFTERPARENT);
        m(WM_GETDPISCALEDSIZE);

        m(WM_CUT);
        m(WM_COPY);
        m(WM_PASTE);
        m(WM_CLEAR);
        m(WM_UNDO);
        m(WM_RENDERFORMAT);
        m(WM_RENDERALLFORMATS);
        m(WM_DESTROYCLIPBOARD);
        m(WM_DRAWCLIPBOARD);
        m(WM_PAINTCLIPBOARD);
        m(WM_VSCROLLCLIPBOARD);
        m(WM_SIZECLIPBOARD);
        m(WM_ASKCBFORMATNAME);
        m(WM_CHANGECBCHAIN);
        m(WM_HSCROLLCLIPBOARD);
        m(WM_QUERYNEWPALETTE);

        m(WM_PALETTEISCHANGING);
        m(WM_PALETTECHANGED);
        m(WM_HOTKEY);
        m(WM_PRINT);
        m(WM_PRINTCLIENT);
        m(WM_APPCOMMAND);
        m(WM_THEMECHANGED);
        m(WM_CLIPBOARDUPDATE);
        m(WM_DWMCOMPOSITIONCHANGED);
        m(WM_DWMNCRENDERINGCHANGED);

        m(WM_DWMCOLORIZATIONCOLORCHANGED);
        m(WM_DWMWINDOWMAXIMIZEDCHANGE);
        m(WM_DWMSENDICONICTHUMBNAIL);
        m(WM_DWMSENDICONICLIVEPREVIEWBITMAP);

        m(WM_GETTITLEBARINFOEX);

        m(WM_HANDHELDFIRST);
        m(WM_HANDHELDLAST);

        m(WM_AFXFIRST);
        m(WM_AFXLAST);

        m(WM_PENWINFIRST);
        m(WM_PENWINLAST);

        m(WM_USER);                  //  0x400

        m(WM_APP);                   // 0x8000
#undef m
    default: return TEXT("UNKNOWN"); break;
    }
}
