//===-- TabWidget -----------------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief Qt 标签页小部件。
//!
//! \version 2019-12-16
//! \sinve 2019-12-11
//! \authors zhengrr
//! \copyright Unlicense
//!
//===----------------------------------------------------------------------===//

#include <QtWidgets/QApplication>

#include "TabWidget.h"

int main(int argc, char *argv[])
{
    QApplication app {argc, argv};

    TabWidget wgt;
    wgt.show();

    return app.exec();
}
