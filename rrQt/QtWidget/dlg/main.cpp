//! \copyright The MIT License

#include <QApplication>

#include "ui/Dlg.h"
#include "ui/DlgRtBtn.h"
#include "ui/DlgBtBtn.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    rrqt::dialog::Dialog wnd;
    wnd.show();

    rrqt::dialog::DialogWithRightButtons wnd2;
    wnd2.show();

    rrqt::dialog::DialogWithBottomButtons wnd3;
    wnd3.show();

    return app.exec();
}
