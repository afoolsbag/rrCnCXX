#pragma once
#ifndef TABLEVIEW_H_
#define TABLEVIEW_H_

#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE
namespace Ui { class TableView; }
QT_END_NAMESPACE

class TableView : public QTableView {
    Q_OBJECT

public:
    explicit TableView(QTableView *parent = nullptr);
    ~TableView();

private slots:
    void on_TableView_activated(const QModelIndex &index);
    void on_TableView_clicked(const QModelIndex &index);
    void on_TableView_doubleClicked(const QModelIndex &index);
    void on_TableView_entered(const QModelIndex &index);
    void on_TableView_iconSizeChanged(const QSize &size);
    void on_TableView_pressed(const QModelIndex &index);
    void on_TableView_viewportEntered();

private:
    Ui::TableView *ui;
};

#endif
