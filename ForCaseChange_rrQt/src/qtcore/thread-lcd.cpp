/** \copyright The MIT License */
#include "thread-lcd.hpp"

#include <QApplication>
#include <QPushButton>
#include <QThread>
#include <QTimer>
#include <QVBoxLayout>
#include <QLCDNumber>

namespace rrdemo {
namespace cdom {
namespace qt {

ThreadLcdMainWindow::ThreadLcdMainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    QWidget *widget {new QWidget(this)};

    QVBoxLayout *layout {new QVBoxLayout};
    widget->setLayout(layout);

    QLCDNumber *lcdNumber {new QLCDNumber(this)};
    layout->addWidget(lcdNumber);

    QPushButton *button {new QPushButton(tr("Start"), this)};
    layout->addWidget(button);

    setCentralWidget(widget);

    QTimer *timer {new QTimer(this)};
    connect(timer, &QTimer::timeout, [=]() {
        static int sec {0};
        lcdNumber->display(QString::number(sec++));
    });

    ThreadLcdTask *task {new ThreadLcdTask};
    QThread *thread {new QThread(this)};
    task->moveToThread(thread);

    connect(thread, &QThread::started, task, &ThreadLcdTask::task);
    connect(task, &ThreadLcdTask::completed, thread, &QThread::quit);
    connect(task, &ThreadLcdTask::completed, timer, &QTimer::stop);
    connect(thread, &QThread::finished, task, &ThreadLcdTask::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    connect(button, &QPushButton::clicked, [=]() {
        timer->start(1);
        thread->start();
    });
}

void ThreadLcdTask::task()
{
    static Q_CONSTEXPR int ALL {1000000000};

    for (int i {0}; i < ALL; i++)
        Q_EMIT step(i, ALL);

    Q_EMIT completed();
}

}// namespace qt
}// namespace cdom
}// namespace rrdemo

namespace {
int altmain(int argc, char *argv[])
{
    QApplication app(argc, argv);

    rrdemo::cdom::qt::ThreadLcdMainWindow main_window;
    main_window.show();

    return app.exec();
}
}// namespace

#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return altmain(argc, argv); }
#endif// ENTRY SWITC
