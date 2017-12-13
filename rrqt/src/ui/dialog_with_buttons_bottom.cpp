/** \copyright The MIT License */
#include "dialog_with_buttons_bottom.hpp"
#include "ui_dialog_with_buttons_bottom.h"

namespace rrdemo {
namespace cdom {
namespace qt {

DialogWithButtonsBottom::DialogWithButtonsBottom(QWidget *parent) :
QDialog(parent), ui {new Ui::DialogWithButtonsBottom}
{
    Q_CHECK_PTR(ui);
    ui->setupUi(this);
}

DialogWithButtonsBottom::~DialogWithButtonsBottom()
{
    delete ui;  ui = Q_NULLPTR;
}

}// namespace qt
}// namespace cdom
}// namespace rrdemo
