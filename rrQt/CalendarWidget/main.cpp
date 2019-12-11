//===-- Calendar Widget -----------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief Qt 日历小部件。
//!
//! \version 2019-12-11
//! \sinve 2019-12-11
//! \authors zhengrr
//! \copyright Unlicense
//!
//===----------------------------------------------------------------------===//

#include <QtWidgets/QApplication>

#include "CalendarWidget.h"

//! \brief Qt 小部件应用程序入口。
//!
//! \param argc 参数计数（argument count）。
//! \param argv 参数矢量（argument vector）。
//! \return 返回退出状态（exit status）。
int main(int argc, char *argv[])
{
    QApplication app {argc, argv};

    CalendarWidget wgt;
    wgt.show();

    return app.exec();
}
