#pragma once

#include "TabDialog/TabDialog.h"

namespace rrMFC {

class Application: public CWinApp {
// Overridables
public:
    BOOL InitInstance() final
    {
        CWinApp::InitInstance();
        m_pMainWnd = DEBUG_NEW TabDialog;
        dynamic_cast<TabDialog *>(m_pMainWnd)->DoModal();
        return FALSE;
    }
};

}//namespace rrMFC
