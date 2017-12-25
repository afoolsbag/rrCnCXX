/** \copyright The MIT License */
#include "dialog_without_buttons.hpp"
#include "ui_dialog_without_buttons.h"

namespace rrdemo {
namespace cdom {
namespace qt {

DialogWithoutButtons::DialogWithoutButtons(QWidget *parent) :
QDialog(parent), ui {new Ui::DialogWithoutButtons}
{
    Q_CHECK_PTR(ui);
    ui->setupUi(this);
}

DialogWithoutButtons::~DialogWithoutButtons()
{
    delete ui;  ui = Q_NULLPTR;
}

}// namespace qt
}// namespace cdom
}// namespace rrdemo
