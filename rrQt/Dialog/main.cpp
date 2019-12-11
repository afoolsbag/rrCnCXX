//===-- Dialog Widget -------------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief Qt 对话框小部件。
//!
//! \version 2019-12-11
//! \sinve 2019-12-11
//! \authors zhengrr
//! \copyright Unlicense
//!
//===----------------------------------------------------------------------===//

#include <QtWidgets/QApplication>

#include "Dialog.h"

int main(int argc, char *argv[])
{
    QApplication app {argc, argv};

    Dialog dlg;
    dlg.show();

    return app.exec();
}
