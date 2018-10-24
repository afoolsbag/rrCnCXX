#pragma once

#include "Window/Window.h"

namespace rrMFC {

namespace ApplicationMessages {
/// \brief 定制应用消息。
constexpr unsigned Custom {WM_APP + 1};
}//namespace ApplicationMessages

class Application: public CWinApp {
// Overridables
public:
    BOOL InitInstance() final
    {
        CWinApp::InitInstance();
        m_pMainWnd = DEBUG_NEW Window;
        m_pMainWnd->ShowWindow(m_nCmdShow);
        m_pMainWnd->UpdateWindow();
        return TRUE;
    }
};

}//namespace rrMFC
