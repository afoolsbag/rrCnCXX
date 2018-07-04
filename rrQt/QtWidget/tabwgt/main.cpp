//! \copyright The MIT License

#include <QApplication>

#include "ui/TabWgt.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    rrqt::tabwidget::TabWidget wnd;
    wnd.show();

    return app.exec();
}
