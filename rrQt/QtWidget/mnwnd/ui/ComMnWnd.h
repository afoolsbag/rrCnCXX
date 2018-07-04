//===-- Compact Main Window -------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief 紧凑主窗口（类）。
//!
//! \verison 2018-07-04
//! \since 2016-10-21
//! \authors zhengrr
//! \copyright The MIT License
//!
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRQT_MAINWINDOW_UI_COMMNWND_H_
#define RRQT_MAINWINDOW_UI_COMMNWND_H_

#include <QMainWindow>

namespace rrqt {
namespace mainwindow {

namespace Ui {
class CompactMainWindow;
}

//!
//! \brief 紧凑主窗口（类）。
//!
class CompactMainWindow: public QMainWindow {
    Q_OBJECT

public:
    explicit CompactMainWindow(QWidget *parent = Q_NULLPTR);
    virtual ~CompactMainWindow() override;
    void initialize();

    Q_DISABLE_COPY(CompactMainWindow);
    explicit CompactMainWindow(CompactMainWindow &&) Q_DECL_EQ_DELETE;
    CompactMainWindow &operator=(CompactMainWindow &&) Q_DECL_EQ_DELETE;

private:
    bool initialized {false};

private Q_SLOTS:
    /// 标题栏最小化按钮。
    void on_titleBarMinimizeButton_clicked() const;
    /// 标题栏最大化按钮。
    void on_titleBarMaximizeButton_clicked() const;
    /// 标题栏关闭按钮。
    void on_titleBarCloseButton_clicked() const;

private:
    Ui::CompactMainWindow *ui {Q_NULLPTR};

};//class CompactMainWindow

}//namespace mainwindow
}//namespace rrqt

#endif//RRQT_MAINWINDOW_UI_COMMNWND_H_
