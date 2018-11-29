//===-- Widgets Application -------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief Qt 小部件应用程序入口。
//!
//! \author zhengrr
//! \version 2018-11-28
//! \sinve 2016-02-14
//! \copyright Unlicense
//!
//===----------------------------------------------------------------------===//

#include <QtWidgets/QApplication>

#include "Widget.h"

//! \brief Qt 小部件应用程序入口。
//!
//! \param argc 参数计数（argument count）。
//! \param argv 参数矢量（argument vector）。
//! \return 返回退出状态（exit status）。
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Widget wgt;
    wgt.show();

    return app.exec();
}
