#pragma once
#ifndef WIDGET_H_
#define WIDGET_H_

#include <QtWidgets/QCalendarWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CalendarWidget; }
QT_END_NAMESPACE

class CalendarWidget : public QCalendarWidget {
    Q_OBJECT

public:
    explicit CalendarWidget(QCalendarWidget *parent = nullptr);
    ~CalendarWidget();

private slots:
    void on_CalendarWidget_activated(const QDate &date);
    void on_CalendarWidget_clicked(const QDate &date);
    void on_CalendarWidget_currentPageChanged(int year, int month);
    void on_CalendarWidget_selectionChanged();


private:
    Ui::CalendarWidget *ui;
};

#endif
