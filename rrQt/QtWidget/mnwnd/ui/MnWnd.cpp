//! \copyright The MIT License

#include "MnWnd.h"
#include "ui_MnWnd.h"

namespace rrqt {
namespace mainwindow {

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

}//namespace mainwindow
}//namespace rrqt
