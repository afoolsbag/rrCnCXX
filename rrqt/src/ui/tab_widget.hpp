/** \file
 *  \author zhengrr
 *  \date 2016-10-21 – 11-15
 *  \copyright The MIT License
 */
#ifndef _RRDEMOCDOMQT_TABWIDGET_HPP
#define _RRDEMOCDOMQT_TABWIDGET_HPP

#include <QTabWidget>

namespace rrdemo {
namespace cdom {
namespace qt {

namespace Ui {
class TabWidget;
}

class TabWidget : public QTabWidget {
    Q_OBJECT

public:
    explicit TabWidget(QWidget *parent = Q_NULLPTR);
    ~TabWidget();

private:
    Q_DISABLE_COPY(TabWidget);
    explicit TabWidget(TabWidget &&) Q_DECL_EQ_DELETE;
    TabWidget &operator=(TabWidget &&)Q_DECL_EQ_DELETE;

    Ui::TabWidget *ui {Q_NULLPTR};

};// TabWidget

}// namespace qt
}// namespace cdom
}// namespace rrdemo

#endif// _RRDEMOCDOMQT_TABWIDGET_HPP
