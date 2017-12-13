/** \file
 *  \author zhengrr
 *  \date 2016-10-21 – 12-5
 *  \copyright The MIT License
 */
#ifndef _RRDEMOCDOMQT_TABWINDOWMERGETITLEBAR_HPP
#define _RRDEMOCDOMQT_TABWINDOWMERGETITLEBAR_HPP

#include <QMainWindow>

namespace rrdemo {
namespace cdom {
namespace qt {

namespace Ui {
class TabWindowMergeTitleBar;
}

/// 合并标题栏的标签窗口。
/**
 */
class TabWindowMergeTitleBar : public QMainWindow {
    Q_OBJECT

public:
    explicit TabWindowMergeTitleBar(QWidget *parent = Q_NULLPTR);
    void initialize();
    ~TabWindowMergeTitleBar();

private:
    Q_DISABLE_COPY(TabWindowMergeTitleBar);
    explicit TabWindowMergeTitleBar(TabWindowMergeTitleBar &&) Q_DECL_EQ_DELETE;
    TabWindowMergeTitleBar &operator=(TabWindowMergeTitleBar &&)Q_DECL_EQ_DELETE;

    bool initialized {false};

private Q_SLOTS:
    /// 标题栏最小化按钮。
    void on_titleBarMinimizeButton_clicked() const;
    /// 标题栏最大化按钮。
    void on_titleBarMaximizeButton_clicked() const;
    /// 标题栏关闭按钮。
    void on_titleBarCloseButton_clicked() const;

private:
    Ui::TabWindowMergeTitleBar *ui {Q_NULLPTR};

};// class TabWindowMergeTitleBar

}// namespace qt
}// namespace cdom
}// namespace rrdemo

#endif// _RRDEMOCDOMQT_TABWINDOWMERGETITLEBAR_HPP
