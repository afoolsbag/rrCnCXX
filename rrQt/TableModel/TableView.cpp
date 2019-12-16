#include "TableView.h"
#include "ui_TableView.h"

#include <QtCore/QDebug>

TableView::TableView(QTableView *parent) :
    QTableView {parent},
    ui {new Ui::TableView}
{
    ui->setupUi(this);
}

TableView::~TableView()
{
    delete ui;
}

void TableView::on_TableView_activated(const QModelIndex &index)
{
    qInfo() << __func__ << '(' << index << ')';
}

void TableView::on_TableView_clicked(const QModelIndex &index)
{
    qInfo() << __func__ << '(' << index << ')';
}

void TableView::on_TableView_doubleClicked(const QModelIndex &index)
{
    qInfo() << __func__ << '(' << index << ')';
}

void TableView::on_TableView_entered(const QModelIndex &index)
{
    qInfo() << __func__ << '(' << index << ')';
}

void TableView::on_TableView_iconSizeChanged(const QSize &size)
{
    qInfo() << __func__ << '(' << size << ')';
}

void TableView::on_TableView_pressed(const QModelIndex &index)
{
    qInfo() << __func__ << '(' << index << ')';
}

void TableView::on_TableView_viewportEntered()
{
    qInfo() << __func__ << '(' << ')';
}
