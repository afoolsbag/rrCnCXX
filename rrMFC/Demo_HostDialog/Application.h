#pragma once

#include "TreeDialog/TreeDialog.h"

namespace rrMFC {

class Application: public CWinApp {
// Overridables
public:
    BOOL InitInstance() final
    {
        CWinApp::InitInstance();
        m_pMainWnd = DEBUG_NEW TreeDialog;
        dynamic_cast<TreeDialog *>(m_pMainWnd)->DoModal();
        return FALSE;
    }
};

}//namespace rrMFC
