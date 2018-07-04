//! \copyright The MIT License

#include "Wgt.h"
#include "ui_Wgt.h"

namespace rrqt {
namespace widget {

Widget::
Widget(QWidget *parent):
    QWidget(parent), ui {new Ui::Widget}
{
    Q_CHECK_PTR(ui);
    ui->setupUi(this);
}

Widget::
~Widget()
{
    delete ui;  ui = Q_NULLPTR;
}

}//namespace widget
}//namespace rrqt
