#include "stdafx.h"

#include "EditDialog.h"

namespace rrMFC {
class Application: public CWinApp {
// Overridables
public:
    BOOL InitInstance() final
    {
        CWinApp::InitInstance();
        m_pMainWnd = DEBUG_NEW EditDialog;
        dynamic_cast<EditDialog *>(m_pMainWnd)->DoModal();
        return FALSE;
    }
};
}//namespace rrMFC

namespace {
rrMFC::Application GlobalApplication;
}//namespace
