#include "TabWidget.h"
#include "ui_TabWidget.h"

#include <QtCore/QDebug>

TabWidget::TabWidget(QTabWidget *parent) :
    QTabWidget {parent},
    ui {new Ui::TabWidget}
{
    ui->setupUi(this);
}

TabWidget::~TabWidget()
{
    delete ui;
}

void TabWidget::on_TabWidget_currentChanged(int index)
{
    qInfo() << __func__ << '(' << index << ')';
}

void TabWidget::on_TabWidget_tabBarClicked(int index)
{
    qInfo() << __func__ << '(' << index << ')';
}

void TabWidget::on_TabWidget_tabBarDoubleClicked(int index)
{
    qInfo() << __func__ << '(' << index << ')';
}

void TabWidget::on_TabWidget_tabCloseRequested(int index)
{
    qInfo() << __func__ << '(' << index << ')';
}
