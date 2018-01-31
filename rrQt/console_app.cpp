/*
 * zhengrr
 * 2016-2-14 – 2018-1-31
 * The MIT License
 */

#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QTimer>

/*!
    \fn int main(int argc, char *argv[])

    Qt控制台应用程序入口。

    \a argc 参数计数（argument count）；

    \a argv 参数矢量（argument vector）；

    返回退出状态（exit status）。
 */
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qInfo() << "Hello, world.";

    QTimer::singleShot(1000, &app, &QCoreApplication::quit);

    return app.exec();
}
