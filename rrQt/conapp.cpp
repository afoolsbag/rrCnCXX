//===-- Console Application -------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief Qt小部件应用程序入口
//!
//! \author zhengrr
//! \version 2018-07-04
//! \sinve 2016-02-14
//! \copyright The MIT License
//!
//===----------------------------------------------------------------------===//

#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QTimer>

//! \brief Qt控制台应用程序入口
//!
//! \param argc 参数计数（argument count）
//! \param argv 参数矢量（argument vector）
//! \returns 退出状态（exit status）
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qInfo() << "Hello, world.";

    QTimer::singleShot(1000, &app, &QCoreApplication::quit);

    return app.exec();
}
