//===-- Tab Widget ----------------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief 标签页部件（类）。
//!
//! \verison 2018-07-06
//! \since 2016-10-21
//! \authors zhengrr
//! \copyright The MIT License
//!
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRQT_TABWIDGET_UI_TABWGT_H_
#define RRQT_TABWIDGET_UI_TABWGT_H_

#include <QtWidgets/QTabWidget>

namespace rrqt {
namespace tabwidget {

namespace Ui {
class TabWidget;
}

//!
//! \brief 标签页部件（类）。
//!
class TabWidget: public QTabWidget {
    Q_OBJECT

public:
    explicit TabWidget(QWidget *parent = Q_NULLPTR);
    virtual ~TabWidget() override;
    Q_DISABLE_COPY(TabWidget)

private:
    Ui::TabWidget *ui {Q_NULLPTR};

};//class TabWidget

}//namespace tabwidget
}//namespace rrqt

#endif//RRQT_TABWIDGET_UI_TABWGT_H_
