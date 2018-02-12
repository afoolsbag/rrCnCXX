/// \copyright The MIT License

#include "Frame/stdafx.h"
#include "Frame/FrameApp.h"

#include "Frame/FrameMainWnd.h"

BOOL CFrameApp::InitInstance()
{
    // �˺������ຯ��Ĭ�ϲ���ֱ�ӷ���`TURE`������������
    CWinApp::InitInstance();

    // ����������
    m_pMainWnd = new CFrameMainWnd;
    // https://docs.microsoft.com/cpp/mfc/reference/cwinthread-class#m_pmainwnd

    // ��������ʽ����ʾ����
    m_pMainWnd->ShowWindow(m_nCmdShow);
    // https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#showwindow

    // �ػ洰��
    m_pMainWnd->UpdateWindow();
    // https://docs.microsoft.com/cpp/mfc/reference/cwnd-class#updatewindow

    // ����`FALSE`�ɹر�Ӧ��
    return TRUE;
}

INT CFrameApp::ExitInstance()
{
    // ���û��ຯ�����˺�������ֵ����Ϊ�˳�����
    return CWinApp::ExitInstance();
}
