//! \copyright The MIT License

#include <QApplication>

#include "ui/MnWnd.hxx"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    rrqt::qtmainwindow::MainWindow wnd;
    wnd.show();

    return app.exec();
}
