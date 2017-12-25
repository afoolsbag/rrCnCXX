/** \file
 *  \author zhengrr
 *  \date 2016-10-21 – 12-5
 *  \copyright The MIT License
 */
#ifndef _RRDEMOCDOMQT_WIDGET_HPP
#define _RRDEMOCDOMQT_WIDGET_HPP

#include <QWidget>

namespace rrdemo {
namespace cdom {
namespace qt {

namespace Ui {
class Widget;
}

/// 部件。
/**
*/
class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = Q_NULLPTR);
    ~Widget();

private:
    Q_DISABLE_COPY(Widget);
    explicit Widget(Widget &&) Q_DECL_EQ_DELETE;
    Widget &operator=(Widget &&)Q_DECL_EQ_DELETE;

    Ui::Widget *ui {Q_NULLPTR};

};// class Widget

}// namespace qt
}// namespace cdom
}// namespace rrdemo

#endif// _RRDEMOCDOMQT_WIDGET_HPP
