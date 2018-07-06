//===-- Widget --------------------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief 部件（类）。
//!
//! \verison 2018-07-06
//! \since 2016-10-21
//! \authors zhengrr
//! \copyright The MIT License
//!
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRQT_WIDGET_UI_WGT_H_
#define RRQT_WIDGET_UI_WGT_H_

#include <QtWidgets/QWidget>

namespace rrqt {
namespace widget {

namespace Ui {
class Widget;
}

//!
//! \brief 部件（类）。
//!
class Widget: public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = Q_NULLPTR);
    virtual ~Widget() override;
    Q_DISABLE_COPY(Widget)

private:
    Ui::Widget *ui {Q_NULLPTR};

};//class Widget

}//namespace widget
}//namespace rrqt

#endif//RRQT_WIDGET_UI_WGT_H_
