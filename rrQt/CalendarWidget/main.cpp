//===-- Calendar Widget -----------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief Qt 日历小部件。
//!
//! \version 2019-12-12
//! \sinve 2019-12-11
//! \authors zhengrr
//! \copyright Unlicense
//!
//===----------------------------------------------------------------------===//

#include <QtWidgets/QApplication>

#include "CalendarWidget.h"

int main(int argc, char *argv[])
{
    QApplication app {argc, argv};

    CalendarWidget wgt;
    wgt.show();

    return app.exec();
}
