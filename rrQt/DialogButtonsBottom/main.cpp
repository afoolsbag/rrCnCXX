//===-- Dialog with Buttons Bottom Widget -----------------------*- C++ -*-===//
//!
//! \file
//! \brief Qt 带下侧标准按钮的对话框小部件。
//!
//! \version 2019-12-11
//! \sinve 2019-12-11
//! \authors zhengrr
//! \copyright Unlicense
//!
//===----------------------------------------------------------------------===//

#include <QtCore/QDebug>
#include <QtCore/QTimer>
#include <QtWidgets/QApplication>

#include "DialogButtonsBottom.h"

int main(int argc, char *argv[])
{
    QApplication app {argc, argv};

    DialogButtonsBottom dlg;
    switch (dlg.exec()) {
    case QDialog::Rejected:
        qInfo() << "rejected";
        break;
    case QDialog::Accepted:
        qInfo() << "accepted";
        break;
    default:
        qInfo() << "unexpected";
        break;
    }

    QTimer::singleShot(0, &app, &QApplication::quit);

    return app.exec();
}
