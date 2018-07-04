/** \copyright The MIT License */
#include "MnWnd.hxx"
#include "ui_MnWnd.h"

namespace rrqt {
namespace qtmainwindow {

MainWindow::
MainWindow(QWidget *parent):
    QMainWindow(parent), ui {new Ui::MainWindow}
{
    Q_CHECK_PTR(ui);
    ui->setupUi(this);
}

MainWindow::
~MainWindow()
{
    delete ui;
    ui = Q_NULLPTR;
}

}//namespace qtmainwindow
}//namespace rrqt
