/// \copyright The MIT License

#include "stdafx.h"
#include "PageDialog.h"

#include "resource.h"

IMPLEMENT_DYNCREATE(PageDialog, CDialog)

PageDialog::PageDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD_PAGE_DIALOG, pParent)
{}

VOID PageDialog::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
}
