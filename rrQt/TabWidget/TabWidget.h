#pragma once
#ifndef TABWIDGET_H_
#define TABWIDGET_H_

#include <QtWidgets/QTabWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TabWidget; }
QT_END_NAMESPACE

class TabWidget : public QTabWidget {
    Q_OBJECT

public:
    explicit TabWidget(QTabWidget *parent = nullptr);
    ~TabWidget();

private slots:
    void on_TabWidget_currentChanged(int index);
    void on_TabWidget_tabBarClicked(int index);
    void on_TabWidget_tabBarDoubleClicked(int index);
    void on_TabWidget_tabCloseRequested(int index);

private:
    Ui::TabWidget *ui;
};

#endif
