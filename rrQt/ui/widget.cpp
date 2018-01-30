/** \copyright The MIT License */
#include "widget.hpp"
#include "ui_widget.h"

namespace rrdemo {
namespace cdom {
namespace qt {

Widget::Widget(QWidget *parent) :
QWidget(parent), ui {new Ui::Widget}
{
    Q_CHECK_PTR(ui);
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;  ui = Q_NULLPTR;
}

}// namespace qt
}// namespace cdom
}// namespace rrdemo
