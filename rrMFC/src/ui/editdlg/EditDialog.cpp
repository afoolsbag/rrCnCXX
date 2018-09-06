/// \copyright The Unlicense

#include "stdafx.h"
#include "EditDialog.h"
#include "EditDialog.rc.h"

#include "rrwindows/rrwindows.h"

namespace rrMFC {

const UINT EditDialog::IDD {IDD_EDIT_DIALOG};

BEGIN_MESSAGE_MAP(EditDialog, CDialog)
    ON_EN_CHANGE(IDC_EDIT, &EditDialog::OnEnChangeEdit)
END_MESSAGE_MAP()

#// Constructors

EditDialog::
EditDialog(CWnd *pParent /*=NULL*/)
    : CDialog(IDD, pParent)
{
    DcMeth();
}

EditDialog::
~EditDialog()
{
    DcMeth();
}

#// Overridables

BOOL EditDialog::
OnInitDialog()
{
    CDialog::OnInitDialog();
    DcMeth();
    return TRUE;
}

BOOL EditDialog::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DcWndMsg();
    return CDialog::OnWndMsg(message, wParam, lParam, pResult);
}

void EditDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    DcMeth();
    DDX_Control(pDX, IDC_EDIT, EditControl);
}

void EditDialog::
OnEnChangeEdit()
{
    DcMeth();
}

}//namespace rrMFC
