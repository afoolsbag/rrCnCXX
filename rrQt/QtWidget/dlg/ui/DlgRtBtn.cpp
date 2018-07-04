//! \copyright The MIT License

#include "DlgRtBtn.h"
#include "ui_DlgRtBtn.h"

namespace rrqt {
namespace dialog {

DialogWithRightButtons::
DialogWithRightButtons(QWidget *parent):
    QDialog(parent), ui {new Ui::DialogWithRightButtons}
{
    Q_CHECK_PTR(ui);
    ui->setupUi(this);
}

DialogWithRightButtons::
~DialogWithRightButtons()
{
    delete ui;
    ui = Q_NULLPTR;
}

}//namespace dialog
}//namespace qt
