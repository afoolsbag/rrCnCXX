#pragma once
#ifndef TABLE_VIEW_CONTAINER_H_
#define TABLE_VIEW_CONTAINER_H_

#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TableViewContainer; }
QT_END_NAMESPACE

class TableViewContainer : public QWidget {
    Q_OBJECT

public:
    explicit TableViewContainer(QWidget *parent = nullptr);
    ~TableViewContainer();

private slots:
    void on_queryAction_triggered(bool checked);

private:
    Ui::TableViewContainer *ui;
};

#endif
