/** \file
 *  \sa <http://doc.qt.io/qt-5/qguiapplication.html>
 *  \sa <http://doc.qt.io/qt-5/qqmlapplicationengine.html>
 *  \author zhengrr
 *  \date 2016-11-29 – 12-9
 *  \copyright The MIT License
 */
#include <QGuiApplication>
#include <QQmlApplicationEngine>

namespace {
int altmain(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
}// namespace

#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return altmain(argc, argv); }
#endif// ENTRY SWITC
