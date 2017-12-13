/** \file
 *  \sa <http://doc.qt.io/qt-5/qobject.html#Q_OBJECT>
 *  \author zhengrr
 *  \date 2016-10-21 – 12-5
 *  \copyright The MIT License
 */
#ifndef _RRDEMOCDOMQT_CLASS_HPP
#define _RRDEMOCDOMQT_CLASS_HPP

#include <QObject>

namespace rrdemo {
namespace cdom {
namespace qt {

/// Qt 类。
/**
 */
class Class : public QObject {
    Q_OBJECT

public:
    explicit Class(QObject *parent = Q_NULLPTR);
    ~Class() Q_DECL_EQ_DEFAULT;

private:
    Q_DISABLE_COPY(Class);
    explicit Class(Class &&) Q_DECL_EQ_DELETE;
    Class &operator=(Class &&)Q_DECL_EQ_DELETE;

};// class Class

}// namespace qt
}// namespace cdom
}// namespace rrdemo

#endif// _RRDEMOCDOMQT_CLASS_HPP
