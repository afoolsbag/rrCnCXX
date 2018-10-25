#include "stdafx.h"

#include "ListDialog.h"

namespace rrMFC {
class Application: public CWinApp {
// Overridables
public:
    BOOL InitInstance() final
    {
        CWinApp::InitInstance();
        m_pMainWnd = DEBUG_NEW ListDialog;
        dynamic_cast<ListDialog *>(m_pMainWnd)->DoModal();
        return FALSE;
    }
};
}//namespace rrMFC


namespace {
rrMFC::Application GlobalApplication;
}//namespace
