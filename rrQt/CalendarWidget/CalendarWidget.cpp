#include "CalendarWidget.h"
#include "ui_CalendarWidget.h"

#include <QtCore/QDebug>

CalendarWidget::CalendarWidget(QCalendarWidget *parent) :
    QCalendarWidget {parent},
    ui {new Ui::CalendarWidget}
{
    ui->setupUi(this);
}

CalendarWidget::~CalendarWidget()
{
    delete ui;
}

void CalendarWidget::on_CalendarWidget_activated(const QDate &date)
{
    qInfo() << __func__ << '(' << date << ')';
}

void CalendarWidget::on_CalendarWidget_clicked(const QDate &date)
{
    qInfo() << __func__ << '(' << date << ')';
}

void CalendarWidget::on_CalendarWidget_currentPageChanged(int year, int month)
{
    qInfo() << __func__ << '(' << year << ',' << month << ')';
}

void CalendarWidget::on_CalendarWidget_selectionChanged()
{
    qInfo() << __func__;
}
