//===-- Linguist Application ------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief Qt 多语言应用程序。
//!
//! \sa <https://doc.qt.io/qt-5/i18n-source-translation.html>
//!
//! \author zhengrr
//! \version 2019-05-15
//! \sinve 2017-12-25
//! \copyright Unlicense
//!
//===----------------------------------------------------------------------===//

#include <QtWidgets/QApplication>

#include "TranslatorSwitcher.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app {argc, argv};
    TranslatorSwitcher switcher {QStringLiteral("lang"), &app};

    MainWindow wnd;
    wnd.show();

    return app.exec();
}
