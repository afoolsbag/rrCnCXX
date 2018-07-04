//! \copyright The MIT License

#include "DlgBtBtn.h"
#include "ui_DlgBtBtn.h"

namespace rrqt {
namespace dialog {

DialogWithBottomButtons::
DialogWithBottomButtons(QWidget *parent):
    QDialog(parent), ui {new Ui::DialogWithBottomButtons}
{
    Q_CHECK_PTR(ui);
    ui->setupUi(this);
}

DialogWithBottomButtons::
~DialogWithBottomButtons()
{
    delete ui;
    ui = Q_NULLPTR;
}

}//namespace dialog
}//namespace qt
