//===-- TableModel Class ----------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief Qt 表模型类。
//!
//! \version 2019-12-16
//! \sinve 2019-12-16
//! \authors zhengrr
//! \copyright Unlicense
//!
//===----------------------------------------------------------------------===//

#include <QtWidgets/QApplication>

#include "TableModel.h"
#include "TableView.h"

int main(int argc, char *argv[])
{
    QApplication app {argc, argv};

    TableView view;
    TableModel *model = new TableModel {&view};
    view.setModel(model);
    view.resizeColumnsToContents();
    view.show();

    return app.exec();
}
