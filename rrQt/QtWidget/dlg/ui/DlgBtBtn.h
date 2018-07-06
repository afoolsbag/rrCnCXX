//===-- Dialog with Bottom Buttons ------------------------------*- C++ -*-===//
//!
//! \file
//! \brief 带底部按钮的对话框（类）。
//!
//! \verison 2018-07-06
//! \since 2016-10-21
//! \authors zhengrr
//! \copyright The MIT License
//!
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRQT_DIALOG_UI_DIALOGWITHBOTTOMBUTTONS_H_
#define RRQT_DIALOG_UI_DIALOGWITHBOTTOMBUTTONS_H_

#include <QtWidgets/QDialog>

namespace rrqt {
namespace dialog {

namespace Ui {
class DialogWithBottomButtons;
}

//!
//! \brief 带底部按钮的对话框（类）。
//!
class DialogWithBottomButtons: public QDialog {
    Q_OBJECT

public:
    explicit DialogWithBottomButtons(QWidget *parent = Q_NULLPTR);
    virtual ~DialogWithBottomButtons() override;
    Q_DISABLE_COPY(DialogWithBottomButtons)

private:
    Ui::DialogWithBottomButtons *ui {Q_NULLPTR};

};//class DialogWithBottomButtons

}//namespace dialog
}//namespace qt

#endif//RRQT_DIALOG_UI_DIALOGWITHBOTTOMBUTTONS_H_
