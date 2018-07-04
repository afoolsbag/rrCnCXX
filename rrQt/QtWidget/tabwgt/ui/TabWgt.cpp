//! \copyright The MIT License

#include "TabWgt.h"
#include "ui_TabWgt.h"

namespace rrqt {
namespace tabwidget {

TabWidget::
TabWidget(QWidget *parent):
    QTabWidget(parent), ui(new Ui::TabWidget)
{
    Q_CHECK_PTR(ui);
    ui->setupUi(this);
}

TabWidget::
~TabWidget()
{
    delete ui;
    ui = Q_NULLPTR;
}

}//namespace tabwidget
}//namespace rrqt
