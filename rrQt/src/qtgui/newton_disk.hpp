/** \file
 *  \author zhengrr
 *  \date 2016-12-12
 *  \copyright The MIT License
 */
#ifndef _RRDEMOCDOMQT_NEWTONDISK_HPP
#define _RRDEMOCDOMQT_NEWTONDISK_HPP

#include <QWidget>

namespace rrdemo {
namespace cdom {
namespace qt {

class NewtonDisk : public QWidget {
    Q_OBJECT

public:
    explicit NewtonDisk(QWidget *parent = Q_NULLPTR);
    ~NewtonDisk() Q_DECL_EQ_DEFAULT;

private:
    Q_DISABLE_COPY(NewtonDisk);
    explicit NewtonDisk(NewtonDisk &&) Q_DECL_EQ_DELETE;
    NewtonDisk &operator=(NewtonDisk &&)Q_DECL_EQ_DELETE;

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

};// class NewtonDisk

}// namespace qt
}// namespace cdom
}// namespace rrdemo

#endif// _RRDEMOCDOMQT_NEWTONDISK_HPP
