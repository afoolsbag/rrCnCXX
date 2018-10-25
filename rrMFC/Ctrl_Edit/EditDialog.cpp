/// \copyright The Unlicense

#include "stdafx.h"
#include "EditDialog.h"
#include "ui.rc.h"

namespace rrMFC {

BEGIN_MESSAGE_MAP(EditDialog, CDialog)
    ON_EN_CHANGE(IDC_EDIT, &EditDialog::OnEnChangeEdit)
END_MESSAGE_MAP()

// Attributes

const unsigned EditDialog::IDD {IDD_EDIT_DIALOG};

// Overridables

void EditDialog::
DoDataExchange(CDataExchange *pDX)
{
    CDialog::DoDataExchange(pDX);
    TRACE(__FUNCTION__ "\n");
    DDX_Control(pDX, IDC_EDIT, EditControl);
}

void EditDialog::
OnEnChangeEdit()
{
    TRACE(__FUNCTION__ "\n");
}

}//namespace rrMFC
