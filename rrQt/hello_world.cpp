/** \file
 *  \author zhengrr
 *  \date 2016-11-30
 *  \copyright The MIT License
 */
#include <QApplication>
#include <QLabel>

namespace {
int MainAlpha(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel label(QStringLiteral("hello, world"));
    label.show();

    return app.exec();
}
}// namespace
#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return MainAlpha(argc, argv); }
#endif// ENTRY SWITCH

namespace {
int MainBeta(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel *label {new QLabel(QStringLiteral("hello, world"))};
    label->setAttribute(Qt::WA_DeleteOnClose);
    label->show();

    return app.exec();
}
}// namespace
#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return MainBeta(argc, argv); }
#endif// ENTRY SWITCH
