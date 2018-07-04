//! \copyright The MIT License

#include <QApplication>

#include "ui/MnWnd.h"
#include "ui/ComMnWnd.h"

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
