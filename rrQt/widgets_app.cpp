/*
 * zhengrr
 * 2016-2-14 – 2018-1-31
 * The MIT License
 */

#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>

/*!
    \fn int main(int argc, char *argv[])

    Qt小部件应用程序入口。

    \a argc 参数计数（argument count）；

    \a argv 参数矢量（argument vector）；

    返回退出状态（exit status）。
 */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel label(QStringLiteral("Hello, world."));
    label.show();

    return app.exec();
}
