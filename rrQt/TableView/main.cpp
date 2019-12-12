//===-- TableView Widget ----------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief Qt 表视图小部件。
//!
//! \version 2019-12-12
//! \sinve 2019-12-12
//! \authors zhengrr
//! \copyright Unlicense
//!
//===----------------------------------------------------------------------===//

#include <QtWidgets/QApplication>

#include "TableViewContainer.h"

int main(int argc, char *argv[])
{
    QApplication app {argc, argv};

    TableViewContainer con;
    con.show();

    return app.exec();
}
