/// \copyright The MIT License

#include "stdafx.h"
#include "PageDlg.h"

#include "resource.h"

IMPLEMENT_DYNCREATE(CPageDlg, CDialog)

//BEGIN_MESSAGE_MAP(CPageDlg, CDialog)
//END_MESSAGE_MAP()

CPageDlg::CPageDlg(CWnd *pParent /*=NULL*/)
    : CDialog(IDD_PAGE_DLG, pParent)
{}

void CPageDlg::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
}
