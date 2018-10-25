#include "stdafx.h"

#include "Dialog.h"

namespace rrMFC {
class Application: public CWinApp {
// Overridables
public:
    BOOL InitInstance() final
    {
        CWinApp::InitInstance();
        m_pMainWnd = DEBUG_NEW Dialog;
        dynamic_cast<Dialog *>(m_pMainWnd)->DoModal();
        return FALSE;
    }
};
}//namespace rrMFC

namespace {
rrMFC::Application GlobalApplication;
}//namespace
