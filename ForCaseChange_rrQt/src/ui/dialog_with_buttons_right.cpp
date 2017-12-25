/** \copyright The MIT License */
#include "dialog_with_buttons_right.hpp"
#include "ui_dialog_with_buttons_right.h"

namespace rrdemo {
namespace cdom {
namespace qt {

DialogWithButtonsRight::DialogWithButtonsRight(QWidget *parent) :
QDialog(parent), ui {new Ui::DialogWithButtonsRight}
{
    Q_CHECK_PTR(ui);
    ui->setupUi(this);
}

DialogWithButtonsRight::~DialogWithButtonsRight()
{
    delete ui;  ui = Q_NULLPTR;
}

}// namespace qt
}// namespace cdom
}// namespace rrdemo
