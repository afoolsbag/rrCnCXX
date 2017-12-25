/** \file
 *  \author zhengrr
 *  \date 2016-10-20 – 12-5
 *  \copyright The MIT License
 */
#ifndef _RRDEMOCDOMQT_MAINWINDOW_HPP
#define _RRDEMOCDOMQT_MAINWINDOW_HPP

#include <QMainWindow>

namespace rrdemo {
namespace cdom {
namespace qt {

namespace Ui {
class MainWindow;
}

/// 主界面。
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();

private:
    Q_DISABLE_COPY(MainWindow);
    explicit MainWindow(MainWindow &&) Q_DECL_EQ_DELETE;
    MainWindow &operator=(MainWindow &&)Q_DECL_EQ_DELETE;

    Ui::MainWindow *ui {Q_NULLPTR};

};// class MainWindow

}// namespace qt
}// namespace cdom
}// namespace rrdemo

#endif// _RRDEMOCDOMQT_MAINWINDOW_HPP
