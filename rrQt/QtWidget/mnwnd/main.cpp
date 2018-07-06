//! \copyright The MIT License

#include "ui/MnWnd.h"
#include "ui/ComMnWnd.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    rrqt::mainwindow::MainWindow wnd;
    wnd.show();

    rrqt::mainwindow::CompactMainWindow wnd2;
    wnd2.initialize();
    wnd2.show();

    return app.exec();
}
