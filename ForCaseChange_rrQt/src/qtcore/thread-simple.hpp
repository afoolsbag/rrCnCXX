/** \file
 *  \sa <http://doc.qt.io/qt-5/qthread.html>
 *  \author zhengrr
 *  \date 2016-3-3 – 11-15
 *  \copyright The MIT License
 */
#ifndef _RRDEMOCDOMQT_THREADSIMPLE_HPP
#define _RRDEMOCDOMQT_THREADSIMPLE_HPP

#include <QObject>

namespace rrdemo {
namespace cdom {
namespace qt {

class Task : public QObject {
    Q_OBJECT

public:
    explicit Task(QObject *parent = Q_NULLPTR) : QObject(parent) {}
    explicit Task(const Task &)Q_DECL_EQ_DELETE;
    explicit Task(Task &&)Q_DECL_EQ_DELETE;
    Task &operator=(const Task &)Q_DECL_EQ_DELETE;
    Task &operator=(Task &&)Q_DECL_EQ_DELETE;
    ~Task() Q_DECL_EQ_DEFAULT;

public Q_SLOTS:
    void task();

Q_SIGNALS:
    void completed();
};// class Task

}// namespace qt
}// namespace cdom
}// namespace rrdemo

#endif// _RRDEMOCDOMQT_THREADSIMPLE_HPP
