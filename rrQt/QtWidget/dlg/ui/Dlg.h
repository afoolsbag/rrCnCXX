//===-- Dialog --------------------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief 对话框（类）。
//!
//! \verison 2018-07-06
//! \since 2016-10-21
//! \authors zhengrr
//! \copyright The MIT License
//!
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRQT_DIALOG_UI_DLG_H_
#define RRQT_DIALOG_UI_DLG_H_

#include <QtWidgets/QDialog>

namespace rrqt {
namespace dialog {

namespace Ui {
class Dialog;
}

//!
//! \brief 对话框（类）。
//!
class Dialog: public QDialog {
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = Q_NULLPTR);
    virtual ~Dialog() override;
    Q_DISABLE_COPY(Dialog)

private:
    Ui::Dialog *ui {Q_NULLPTR};

};//class Dialog

}//namespace dialog
}//namespace qt

#endif//RRQT_DIALOG_UI_DLG_H_
