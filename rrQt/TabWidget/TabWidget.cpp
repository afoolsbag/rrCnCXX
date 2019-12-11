#include "TabWidget.h"
#include "ui_TabWidget.h"

TabWidget::TabWidget(QTabWidget *parent):
    QTabWidget {parent},
    ui {new Ui::TabWidget}
{
    ui->setupUi(this);
}

TabWidget::~TabWidget()
{
    delete ui;
}
