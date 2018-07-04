//! \copyright The MIT License

#include "Dlg.h"
#include "ui_Dlg.h"

namespace rrqt {
namespace dialog {

Dialog::
Dialog(QWidget *parent):
    QDialog(parent), ui {new Ui::Dialog}
{
    Q_CHECK_PTR(ui);
    ui->setupUi(this);
}

Dialog::
~Dialog()
{
    delete ui;
    ui = Q_NULLPTR;
}

}//namespace dialog
}//namespace qt
