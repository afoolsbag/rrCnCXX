/// \copyright The Unlicense

#include "stdafx.h"
#include "PageDialog.h"

#include "rrwindows/rrwindows.h"

namespace rrMFC {

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

}//namespace rrMFC
