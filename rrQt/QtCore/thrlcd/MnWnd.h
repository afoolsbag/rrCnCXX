//===-- Main Window ---------------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief 主窗口（类）。
//!
//! \verison 2018-07-06
//! \since 2016-11-30
//! \authors zhengrr
//! \copyright The MIT License
//!
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRQT_THREADLCD_MNWND_H_
#define RRQT_THREADLCD_MNWND_H_

#include <QtWidgets/QMainWindow>

namespace rrqt {
namespace threadlcd {

//!
//! \brief 主窗口（类）。
//!
class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = Q_NULLPTR);
    virtual ~MainWindow() override Q_DECL_EQ_DEFAULT;
    Q_DISABLE_COPY(MainWindow)

};//class MainWindow

}//namespace rrqt
}//namespace threadlcd

#endif//RRQT_THREADLCD_MNWND_H_
