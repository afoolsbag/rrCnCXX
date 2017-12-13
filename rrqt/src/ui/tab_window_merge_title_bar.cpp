/** \copyright The MIT License */
#include "tab_window_merge_title_bar.hpp"
#include "ui_tab_window_merge_title_bar.h"

#include <QTimer>

namespace rrdemo {
namespace cdom {
namespace qt {

TabWindowMergeTitleBar::TabWindowMergeTitleBar(QWidget *parent) :
QMainWindow(parent), ui {new Ui::TabWindowMergeTitleBar}
{
    Q_CHECK_PTR(ui);
    ui->setupUi(this);
}

void TabWindowMergeTitleBar::initialize()
{
    Q_ASSERT(!initialized);

    setWindowFlags(Qt::CustomizeWindowHint);

    initialized = true;
}

TabWindowMergeTitleBar::~TabWindowMergeTitleBar()
{
    delete ui;  ui = Q_NULLPTR;
}

void TabWindowMergeTitleBar::on_titleBarMinimizeButton_clicked() const
{
    Q_ASSERT(initialized);

    if (isMinimized()) {
        QTimer::singleShot(0, this, &QWidget::showNormal);
    } else {
        QTimer::singleShot(0, this, &QWidget::showMinimized);
    }
}

void TabWindowMergeTitleBar::on_titleBarMaximizeButton_clicked() const
{
    Q_ASSERT(initialized);

    if (isMaximized()) {
        QTimer::singleShot(0, this, &QWidget::showNormal);
    } else {
        QTimer::singleShot(0, this, &QWidget::showMaximized);
    }
}

void TabWindowMergeTitleBar::on_titleBarCloseButton_clicked() const
{
    Q_ASSERT(initialized);

    QTimer::singleShot(0, this, &QWidget::close);
}

}// namespace qt
}// namespace cdom
}// namespace rrdemo
