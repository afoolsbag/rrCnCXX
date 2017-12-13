/** \file
 *  \author zhengrr
 *  \date 2016-12-5 – 7
 *  \copyright The MIT License
 */
#ifndef _RRDEMOCDOMQT_STRINGLISTMODELDIALOG_HPP
#define _RRDEMOCDOMQT_STRINGLISTMODELDIALOG_HPP

#include <QDialog>
#include <QItemDelegate>
#include <QStringListModel>

namespace rrdemo {
namespace cdom {
namespace qt {

namespace Ui {
class StringListModelDialog;
}

class StringListModelDialog : public QDialog {
    Q_OBJECT

public:
    explicit StringListModelDialog(QWidget *parent = Q_NULLPTR);
    void initialize();
    ~StringListModelDialog();

private:
    Q_DISABLE_COPY(StringListModelDialog);
    explicit StringListModelDialog(StringListModelDialog &&) Q_DECL_EQ_DELETE;
    StringListModelDialog &operator=(StringListModelDialog &&)Q_DECL_EQ_DELETE;

    bool initialized {false};

private Q_SLOTS:
    void on_insertButton_clicked();
    void on_deleteButton_clicked() const;

private:
    Ui::StringListModelDialog *ui {Q_NULLPTR};

    QStringListModel *model {Q_NULLPTR};

};// class StringListModelDialog

class StringListModelDialogCellDelegete : public QItemDelegate {
    Q_OBJECT

public:
    explicit StringListModelDialogCellDelegete(QObject *parent = Q_NULLPTR) :
        QItemDelegate(parent)
    {}
    ~StringListModelDialogCellDelegete() Q_DECL_EQ_DEFAULT;

private:
    Q_DISABLE_COPY(StringListModelDialogCellDelegete);
    explicit StringListModelDialogCellDelegete(
        StringListModelDialogCellDelegete &&) Q_DECL_EQ_DELETE;
    StringListModelDialogCellDelegete &operator=(
        StringListModelDialogCellDelegete &&)Q_DECL_EQ_DELETE;

public:
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const Q_DECL_OVERRIDE;

    void setEditorData(QWidget *editor,
                       const QModelIndex &index) const Q_DECL_OVERRIDE;

    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const Q_DECL_OVERRIDE;

    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index) const Q_DECL_OVERRIDE;

};// class StringListModelDialogCellDelegete

}// namespace qt
}// namespace cdom
}// namespace rrdemo

#endif// _RRDEMOCDOMQT_STRINGLISTMODELDIALOG_HPP
