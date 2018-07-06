//! \copyright The MIT License

#include "MnWnd.h"

#include "Tsk.h"

#include <QtCore/QTimer>
#include <QtCore/QThread>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

namespace rrqt {
namespace threadlcd {

MainWindow::
MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    QWidget *wgt {new QWidget(this)};
    QVBoxLayout *lay {new QVBoxLayout};
    wgt->setLayout(lay);

    QLCDNumber *lcd {new QLCDNumber(this)};
    lay->addWidget(lcd);
    QPushButton *btn {new QPushButton(tr("Start"), this)};
    lay->addWidget(btn);

    setCentralWidget(wgt);

    Task *task {new Task};
    QThread *thrd {new QThread(this)};
    task->moveToThread(thrd);

    QObject::connect(thrd, &QThread::started, task, &Task::task);
    QObject::connect(task, &Task::step, [lcd](const uint progress, const uint total) {
        lcd->display(QString::number(progress));
    });
    QObject::connect(task, &Task::completed, thrd, &QThread::quit);
    //QObject::connect(thrd, &QThread::finished, task, &Task::deleteLater);
    //QObject::connect(thrd, &QThread::finished, thrd, &QThread::deleteLater);

    connect(btn, &QPushButton::clicked, [thrd]() {
        thrd->start();
    });
}

}//namespace mainwindow
}//namespace rrqt
