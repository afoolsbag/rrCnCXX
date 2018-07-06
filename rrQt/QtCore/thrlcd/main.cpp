//! \copyright The MIT License

#include "MnWnd.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    rrqt::threadlcd::MainWindow wnd;
    wnd.show();

    return app.exec();
}
