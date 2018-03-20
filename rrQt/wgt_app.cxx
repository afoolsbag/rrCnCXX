//===-- Widgets Application -------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief Qt小部件应用程序入口
//!
//! \author zhengrr
//! \version 2018-03-19
//! \sinve 2016-02-14
//! \copyright The MIT License
//!
//===----------------------------------------------------------------------===//

#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>

//! \brief Qt小部件应用程序入口
//!
//! \param argc 参数计数（argument count）
//! \param argv 参数矢量（argument vector）
//! \return 返回退出状态（exit status）
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel label(QStringLiteral("Hello, world."));
    label.show();

    return app.exec();
}
