//! \copyright The MIT License

#include "ui/Wgt.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    rrqt::widget::Widget wnd;
    wnd.show();

    return app.exec();
}