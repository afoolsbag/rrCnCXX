#pragma once

#include "Frame/Frame.h"

namespace rrMFC {

class Application: public CWinApp {
// Overridables
public:
    BOOL InitInstance() final
    {
        CWinApp::InitInstance();
        m_pMainWnd = DEBUG_NEW Frame;
        dynamic_cast<Frame *>(m_pMainWnd)->LoadFrame(Frame::IDR);
        m_pMainWnd->ShowWindow(m_nCmdShow);
        m_pMainWnd->UpdateWindow();
        return TRUE;
    }
};

}//namespace rrMFC
