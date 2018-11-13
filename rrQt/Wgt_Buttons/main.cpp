//===-- Button Widgets ------------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief 按钮小部件。
//!
//! \author zhengrr
//! \version 2018-11-13
//! \sinve 2016-11-13
//! \copyright Unlicense
//!
//===----------------------------------------------------------------------===//

#include <QtWidgets/QApplication>

#include "Dialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Dialog dlg;
    dlg.show();

    return app.exec();
}
