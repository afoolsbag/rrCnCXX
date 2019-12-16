#pragma once
#ifndef TABLEMODEL_H_
#define TABLEMODEL_H_

#include <QtCore/QAbstractTableModel>

class TableModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit TableModel(QObject *parent = nullptr) : QAbstractTableModel {parent} {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};

#endif
