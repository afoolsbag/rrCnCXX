//===-- Main View -----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 主视图（类）。
///
/// \verison 2018-04-13
/// \since 2018-04-11
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

/// \brief 主视图（类）。
class MainView: public CWnd {
#// Constructors
public:
    MainView();

#// Attributes
public:

#// Operations
public:

#// Overridables
public:
    virtual ~MainView();
protected:
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT *pResult);

#// Implementation
protected:

#// Message Handlers
protected:
    //DECLARE_MESSAGE_MAP()
};
