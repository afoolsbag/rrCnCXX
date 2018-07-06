//===-- Dialog with Bottom Buttons ------------------------------*- C++ -*-===//
//!
//! \file
//! \brief 带右侧按钮的对话框（类）。
//!
//! \verison 2018-07-06
//! \since 2016-10-21
//! \authors zhengrr
//! \copyright The MIT License
//!
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRQT_DIALOG_UI_DIALOGWITHRIGHTBUTTONS_H_
#define RRQT_DIALOG_UI_DIALOGWITHRIGHTBUTTONS_H_

#include <QtWidgets/QDialog>

namespace rrqt {
namespace dialog {

namespace Ui {
class DialogWithRightButtons;
}

//!
//! \brief 带右侧按钮的对话框（类）。
//!
class DialogWithRightButtons: public QDialog {
    Q_OBJECT

public:
    explicit DialogWithRightButtons(QWidget *parent = Q_NULLPTR);
    virtual ~DialogWithRightButtons() override;
    Q_DISABLE_COPY(DialogWithRightButtons)

private:
    Ui::DialogWithRightButtons *ui {Q_NULLPTR};

};//class DialogWithRightButtons

}//namespace dialog
}//namespace qt

#endif//RRQT_DIALOG_UI_DIALOGWITHRIGHTBUTTONS_H_
