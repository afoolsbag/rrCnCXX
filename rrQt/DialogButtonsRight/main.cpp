//===-- Dialog with Buttons Right Widget ------------------------*- C++ -*-===//
//!
//! \file
//! \brief Qt 带右侧标准按钮的对话框小部件。
//!
//! \version 2019-12-16
//! \sinve 2019-12-11
//! \authors zhengrr
//! \copyright Unlicense
//!
//===----------------------------------------------------------------------===//

#include <QtCore/QDebug>
#include <QtCore/QTimer>
#include <QtWidgets/QApplication>

#include "DialogButtonsRight.h"

int main(int argc, char *argv[])
{
    QApplication app {argc, argv};

    DialogButtonsRight dlg;
    switch (dlg.exec()) {
    case QDialog::Rejected:
        qInfo() << "returns code rejected";
        break;
    case QDialog::Accepted:
        qInfo() << "returns code accepted";
        break;
    default:
        qInfo() << "returns code unexpected";
        break;
    }

    QTimer::singleShot(0, &app, &QApplication::quit);

    return app.exec();
}
