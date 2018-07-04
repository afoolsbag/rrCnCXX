//! \copyright The MIT License

#include <QApplication>

#include "ui/Wgt.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    rrqt::widget::Widget wnd;
    wnd.show();

    return app.exec();
}
