//===-- Console Application -------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief Qt 控制台应用程序入口。
//!
//! \version 2019-12-11
//! \sinve 2016-02-14
//! \authors zhengrr
//! \copyright Unlicense
//!
//===----------------------------------------------------------------------===//

#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QTimer>

//! \brief Qt 控制台应用程序入口。
//!
//! \param argc 参数计数（argument count）。
//! \param argv 参数矢量（argument vector）。
//! \returns 退出状态（exit status）。
int main(int argc, char *argv[])
{
    QCoreApplication app {argc, argv};

    qInfo() << QObject::tr("hello, world");

    QTimer::singleShot(0, &app, &QCoreApplication::quit);

    return app.exec();
}
