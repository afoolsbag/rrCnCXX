/** \file
 *  \author zhengrr
 *  \date 2016-11-30
 *  \copyright The MIT License
 */
#ifndef _RRDEMOCDOMQT_THREADLCD_HPP
#define _RRDEMOCDOMQT_THREADLCD_HPP

#include <QObject>
#include <QMainWindow>

namespace rrdemo {
namespace cdom {
namespace qt {

class ThreadLcdMainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ThreadLcdMainWindow(QWidget *parent = Q_NULLPTR);
    explicit ThreadLcdMainWindow(const ThreadLcdMainWindow &) Q_DECL_EQ_DELETE;
    explicit ThreadLcdMainWindow(ThreadLcdMainWindow &&) Q_DECL_EQ_DELETE;
    ThreadLcdMainWindow &operator=(const ThreadLcdMainWindow &)Q_DECL_EQ_DELETE;
    ThreadLcdMainWindow &operator=(ThreadLcdMainWindow &&)Q_DECL_EQ_DELETE;
    ~ThreadLcdMainWindow() Q_DECL_EQ_DEFAULT;

};// class ThreadLcdMainWindow

class ThreadLcdTask : public QObject {
    Q_OBJECT

public:
    explicit ThreadLcdTask(QObject *parent = Q_NULLPTR) : QObject(parent) {}
    explicit ThreadLcdTask(const ThreadLcdTask &) Q_DECL_EQ_DELETE;
    explicit ThreadLcdTask(ThreadLcdTask &&) Q_DECL_EQ_DELETE;
    ThreadLcdTask &operator=(const ThreadLcdTask &)Q_DECL_EQ_DELETE;
    ThreadLcdTask &operator=(ThreadLcdTask &&)Q_DECL_EQ_DELETE;
    ~ThreadLcdTask() Q_DECL_EQ_DEFAULT;

public Q_SLOTS:
    void task();

Q_SIGNALS:
    void step(int progress, int all);
    void completed();
};// class ThreadLcdTask

}// namespace qt
}// namespace cdom
}// namespace rrdemo

#endif// _RRDEMOCDOMQT_THREADLCD_HPP
