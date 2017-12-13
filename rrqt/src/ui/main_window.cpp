/** \copyright The MIT License */
#include "main_window.hpp"
#include "ui_main_window.h"

namespace rrdemo {
namespace cdom {
namespace qt {

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent), ui {new Ui::MainWindow}
{
    Q_CHECK_PTR(ui);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;  ui = Q_NULLPTR;
}

}// namespace qt
}// namespace cdom
}// namespace rrdemo
