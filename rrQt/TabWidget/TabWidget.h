#pragma once
#ifndef WIDGET_H_
#define WIDGET_H_

#include <QtWidgets/QTabWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TabWidget; }
QT_END_NAMESPACE

class TabWidget : public QTabWidget {
    Q_OBJECT

public:
    explicit TabWidget(QTabWidget *parent = nullptr);
    ~TabWidget();

private:
    Ui::TabWidget *ui;
};

#endif
