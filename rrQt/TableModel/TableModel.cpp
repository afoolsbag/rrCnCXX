#include "TableModel.h"

int TableModel::rowCount(const QModelIndex &) const
{
    return 5;
}

int TableModel::columnCount(const QModelIndex &) const
{
    return 5;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case Qt::DisplayRole:
        return QString::number(index.row()) + '-' + QString::number(index.column());
    case Qt::DecorationRole:
    case Qt::EditRole:
    case Qt::ToolTipRole:
    case Qt::StatusTipRole:
    case Qt::WhatsThisRole:
    case Qt::FontRole:
    case Qt::TextAlignmentRole:
    case Qt::BackgroundRole:
    case Qt::ForegroundRole:
    case Qt::CheckStateRole:
    case Qt::AccessibleTextRole:
    case Qt::AccessibleDescriptionRole:
    case Qt::SizeHintRole:
    case Qt::InitialSortOrderRole:
    case Qt::DisplayPropertyRole:
    case Qt::DecorationPropertyRole:
    case Qt::ToolTipPropertyRole:
    case Qt::StatusTipPropertyRole:
    case Qt::WhatsThisPropertyRole:
    default:
        return QVariant {};
    }
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch (role) {
    case Qt::DisplayRole: {
        if (orientation == Qt::Horizontal) {
            return "column " + QString::number(section);
        } else /*Vertical*/ {
            return "raw " + QString::number(section);
        }
    }
    case Qt::DecorationRole:
    case Qt::EditRole:
    case Qt::ToolTipRole:
    case Qt::StatusTipRole:
    case Qt::WhatsThisRole:
    case Qt::FontRole:
    case Qt::TextAlignmentRole:
    case Qt::BackgroundRole:
    case Qt::ForegroundRole:
    case Qt::CheckStateRole:
    case Qt::AccessibleTextRole:
    case Qt::AccessibleDescriptionRole:
    case Qt::SizeHintRole:
    case Qt::InitialSortOrderRole:
    case Qt::DisplayPropertyRole:
    case Qt::DecorationPropertyRole:
    case Qt::ToolTipPropertyRole:
    case Qt::StatusTipPropertyRole:
    case Qt::WhatsThisPropertyRole:
    default:
        return QVariant {};
    }
}

