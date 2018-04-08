//===-- Page Dialog ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief （标签）页对话框类
///
/// \verison 2018-04-08
/// \since 2017-04-08
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief Class Page Dialog
class CPageDlg: public CDialog {
public:
    CPageDlg(CWnd *pParent = NULL);

protected:
    virtual void DoDataExchange(CDataExchange *pDX);

    //DECLARE_MESSAGE_MAP();
};
