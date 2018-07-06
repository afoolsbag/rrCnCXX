//! \copyright The MIT License

#include <QtCore/QTimer>

#include "ComMnWnd.h"
#include "ui_ComMnWnd.h"

namespace rrqt {
namespace mainwindow {

CompactMainWindow::
CompactMainWindow(QWidget *parent):
    QMainWindow(parent), ui {new Ui::CompactMainWindow}
{
    Q_CHECK_PTR(ui);
    ui->setupUi(this);
}

void CompactMainWindow::initialize()
{
    Q_ASSERT(!initialized);

    setWindowFlags(Qt::CustomizeWindowHint);

    initialized = true;
}

CompactMainWindow::
~CompactMainWindow()
{
    delete ui;
    ui = Q_NULLPTR;
}

void CompactMainWindow::
on_titleBarMinimizeButton_clicked() const
{
    Q_ASSERT(initialized);

    if (isMinimized()) {
        QTimer::singleShot(0, this, &QWidget::showNormal);
    } else {
        QTimer::singleShot(0, this, &QWidget::showMinimized);
    }
}

void CompactMainWindow::
on_titleBarMaximizeButton_clicked() const
{
    Q_ASSERT(initialized);

    if (isMaximized()) {
        ui->titleBarMaximizeButton->setText("Maximize");
        QTimer::singleShot(0, this, &QWidget::showNormal);
    } else {
        ui->titleBarMaximizeButton->setText("Restore");
        QTimer::singleShot(0, this, &QWidget::showMaximized);
    }
}

void CompactMainWindow::
on_titleBarCloseButton_clicked() const
{
    Q_ASSERT(initialized);

    QTimer::singleShot(0, this, &QWidget::close);
}

}//namespace mainwindow
}//namespace rrqt
