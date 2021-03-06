#include "stdafx.h"

#include "ButtonDialog.h"

namespace rrMFC {
class Application: public CWinApp {
// Overridables
public:
    BOOL InitInstance() final
    {
        CWinApp::InitInstance();
        m_pMainWnd = DEBUG_NEW ButtonDialog;
        dynamic_cast<ButtonDialog *>(m_pMainWnd)->DoModal();
        return FALSE;
    }
};
}//namespace rrMFC

namespace {
rrMFC::Application GlobalApplication;
}//namespace
