/// \copyright The MIT License

#include "stdafx.h"
#include "resource.h"
#include "PageDialog.h"

IMPLEMENT_DYNCREATE(PageDialog, CDialog)

PageDialog::PageDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{}

VOID PageDialog::DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
}
