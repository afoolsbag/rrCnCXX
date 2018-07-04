//===-- Main Window ---------------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief 窗口（类）。
//!
//! \verison 2018-07-04
//! \since 2016-10-20
//! \authors zhengrr
//! \copyright The MIT License
//!
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRQT_QTMAINWINDOW_UI_MNWND_HXX_
#define RRQT_QTMAINWINDOW_UI_MNWND_HXX_

#include <QMainWindow>

namespace rrqt {
namespace qtmainwindow {

namespace Ui {
class MainWindow;
}

//!
//! 主界面。
//!
class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = Q_NULLPTR);
    virtual ~MainWindow() override;
    Q_DISABLE_COPY(MainWindow);
    explicit MainWindow(MainWindow &&) Q_DECL_EQ_DELETE;
    MainWindow &operator=(MainWindow &&) Q_DECL_EQ_DELETE;

private:
    Ui::MainWindow *ui {Q_NULLPTR};

};//class MainWindow

}//namespace qtmainwindow
}//namespace rrqt

#endif//RRQT_QTMAINWINDOW_UI_MNWND_HXX_
