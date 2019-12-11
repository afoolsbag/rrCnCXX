//===-- MainWindow Widget ---------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief Qt 主窗口小部件。
//!
//! \version 2019-12-11
//! \sinve 2019-12-11
//! \authors zhengrr
//! \copyright Unlicense
//!
//===----------------------------------------------------------------------===//

#include <QtWidgets/QApplication>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app {argc, argv};

    MainWindow wnd;
    wnd.show();

    return app.exec();
}
