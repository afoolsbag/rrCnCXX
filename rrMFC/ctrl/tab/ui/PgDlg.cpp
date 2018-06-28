/// \copyright The MIT License

#include "stdafx.h"
#include "PgDlg.h"

#include "rrwindows/dbgcon.h"

#// Constructors

PageDialog::
PageDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DcMeth();
}

PageDialog::
~PageDialog()
{
    DcMeth();
}

#// Overridables

VOID PageDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
}
