/// \copyright The MIT License

#include "stdafx.h"
#include "HelloApp.h"

#include "HelloMainWnd.h"

BOOL CHelloApp::InitInstance()
{
    // �˺������ຯ��Ĭ�ϲ���ֱ�ӷ���`TURE`������������
    CWinApp::InitInstance();

    // ����������
    m_pMainWnd = new CHelloMainWnd;
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

INT CHelloApp::ExitInstance()
{
    // ���û��ຯ�����˺�������ֵ����Ϊ�˳�����
    return CWinApp::ExitInstance();
}
