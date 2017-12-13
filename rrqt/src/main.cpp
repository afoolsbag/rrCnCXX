/** \file
 *  \author zhengrr
 *  \date 2016-2-14 – 11-15
 *  \copyright The MIT License
 */
#include <QApplication>

#include "ui/main_window.hpp"

namespace {
/// Qt程序入口。
/** \param argc 参数计数。
 *  \param argv 参数向量。
 *  \return 退出状态。
 */
int Main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    rrdemo::cdom::qt::MainWindow mwd;
    mwd.show();

    return app.exec();
}
}// namespace
#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return Main(argc, argv); }
#endif// ENTRY SWITCH
