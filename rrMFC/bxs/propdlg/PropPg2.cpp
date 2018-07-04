/// \copyright The MIT License

#include "stdafx.h"
#include "PropPg2.h"

#include "rrwindows/dbgcon.h"

BEGIN_MESSAGE_MAP(PropertyPage2, CPropertyPage)
    ON_NOTIFY(NM_CUSTOMDRAW, IDC_CONFIDENCE_SLIDER, &PropertyPage2::OnNMCustomdrawConfidenceSlider)
    ON_EN_CHANGE(IDC_CONFIDENCE_EDIT, &PropertyPage2::OnEnChangeConfidenceEdit)
END_MESSAGE_MAP()

#// Constructors

PropertyPage2::
PropertyPage2()
    : CPropertyPage(IDD)
{
    DcMeth();
}

PropertyPage2::
~PropertyPage2()
{
    DcMeth();
}

#// Operations

VOID PropertyPage2::
ReadFrom(CONST BoxesOption& opt)
{
    DcMeth();
#ifdef M
# error Macro name conflicts.
#endif/*M*/
#define M(prop) (prop = opt.prop)
    M(StretchMatching);
    M(ToneshiftMatching);
    M(SharpenMatching);
    M(ContrastMatching);
    M(Operation);
    M(Confidence);
#undef M
}

VOID PropertyPage2::
WriteTo(BoxesOption *CONST pOpt) CONST
{
    DcMeth();
#ifdef M
# error Macro name conflicts.
#endif/*M*/
#define M(prop) (pOpt->prop = prop)
    M(StretchMatching);
    M(ToneshiftMatching);
    M(SharpenMatching);
    M(ContrastMatching);
    M(Operation);
    M(Confidence);
#undef M
}

#// Overridables

BOOL PropertyPage2::
OnInitDialog()
{
    CPropertyPage::OnInitDialog();
    DcMeth();

    ConfidenceSlider.SetRange(0, 100, FALSE);

    return TRUE;
}

BOOL PropertyPage2::
OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult)
{
    DcWndMsg();
    return CPropertyPage::OnWndMsg(message, wParam, lParam, pResult);
}

VOID PropertyPage2::
DoDataExchange(CDataExchange *pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    DcMeth();

    DDX_Check(pDX, IDC_STRETCH_MATCHING, StretchMatching);
    DDX_Check(pDX, IDC_TONESHIFT_MATCHING, ToneshiftMatching);
    DDX_Check(pDX, IDC_SHARPEN_MATCHING, SharpenMatching);
    DDX_Check(pDX, IDC_CONTRAST_MATCHING, ContrastMatching);

    DDX_Radio(pDX, IDC_CPU_SERIAL, Operation);

    DDX_Control(pDX, IDC_CONFIDENCE_SLIDER, ConfidenceSlider);
    DDX_Slider(pDX, IDC_CONFIDENCE_SLIDER, Confidence);
    DDX_Control(pDX, IDC_CONFIDENCE_EDIT, ConfidenceEdit);
    DDX_Text(pDX, IDC_CONFIDENCE_EDIT, Confidence);
    DDV_MinMaxInt(pDX, Confidence, 0, 100);
}

VOID PropertyPage2::
OnOK()
{
    DcMeth();
    CPropertyPage::OnOK();
}

VOID PropertyPage2::
OnCancel()
{
    DcMeth();
    CPropertyPage::OnCancel();
}

BOOL PropertyPage2::
OnApply()
{
    DcMeth();
    return CPropertyPage::OnApply();
}

#// Message Handlers

VOID PropertyPage2::
OnNMCustomdrawConfidenceSlider(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
    DcMeth();

    INT tmp = ConfidenceSlider.GetPos();
    CString txt;
    txt.Format(TEXT("%d"), tmp);
    ConfidenceEdit.SetWindowText(txt);

    *pResult = 0;
}

VOID PropertyPage2::
OnEnChangeConfidenceEdit()
{
    DcMeth();

    CString txt;
    ConfidenceEdit.GetWindowText(txt);
    INT tmp = static_cast<INT>(_tcstol(txt, NULL, 10));
    tmp = min(max(0, tmp), 100);
    ConfidenceSlider.SetPos(tmp);
}
