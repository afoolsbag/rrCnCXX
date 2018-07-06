//! \copyright The MIT License

#include "ui/TabWgt.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    rrqt::tabwidget::TabWidget wnd;
    wnd.show();

    return app.exec();
}
