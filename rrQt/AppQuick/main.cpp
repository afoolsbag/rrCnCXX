//===-- Quick Application ---------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief Qt 快速应用程序入口。
//!
//! \author zhengrr
//! \version 2018-10-25
//! \sinve 2018-03-19
//! \copyright The Unlicense
//!
//===----------------------------------------------------------------------===//

#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>

//! \brief Qt快速应用程序入口。
//!
//! \param argc 参数计数（argument count）。
//! \param argv 参数矢量（argument vector）。
//! \returns 退出状态（exit status）。
int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return EXIT_FAILURE;

    return app.exec();
}
