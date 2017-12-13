/** \copyright The MIT License */
#include "string_list_model_dialog.hpp"
#include "ui_string_list_model_dialog.h"

#include <QApplication>
#include <QInputDialog>
#include <QSpinBox>

namespace {
Q_CONSTEXPR QStringList DEFAULT_DATA {
    "-1", "-2", "-3"};
}// namespace

namespace rrdemo {
namespace cdom {
namespace qt {

StringListModelDialog::StringListModelDialog(QWidget *parent) :
QDialog(parent), ui {new Ui::StringListModelDialog}
{
    Q_CHECK_PTR(ui);
    ui->setupUi(this);
}

void StringListModelDialog::initialize()
{
    Q_ASSERT(!initialized);

    Q_ASSERT(!model);
    model = new QStringListModel(this);  Q_CHECK_PTR(model);
    model->setStringList(DEFAULT_DATA);

    ui->listView->setModel(model);
    ui->comboBox->setModel(model);

    ui->listView->setItemDelegate(
        new StringListModelDialogCellDelegete(ui->listView));

    initialized = true;
}


StringListModelDialog::~StringListModelDialog()
{
    delete ui;  ui = Q_NULLPTR;
}

void StringListModelDialog::on_insertButton_clicked()
{
    Q_ASSERT(initialized);

    bool ok;
    QString data {
        QInputDialog::getText(this,
        tr("Insert"),
        tr("Number (-100 ~ 100):"),
        QLineEdit::Normal, QString(), &ok)};
    if (ok) {
        int row {ui->listView->currentIndex().isValid() ?
            ui->listView->currentIndex().row() : 0};
        model->insertRow(row);
        model->setData(model->index(row), data);
    }
}

void StringListModelDialog::on_deleteButton_clicked() const
{
    Q_ASSERT(initialized);

    if (ui->listView->currentIndex().isValid())
        model->removeRow(ui->listView->currentIndex().row());
}

QWidget *StringListModelDialogCellDelegete::createEditor(
    QWidget *parent,
    const QStyleOptionViewItem &,
    const QModelIndex &) const
{
    QSpinBox *editor {new QSpinBox(parent)};
    editor->setMinimum(-100);
    editor->setMaximum(100);
    return editor;
}

void StringListModelDialogCellDelegete::setEditorData(
    QWidget *editor,
    const QModelIndex &index) const
{
    static_cast<QSpinBox *>(editor)->setValue(
        index.model()->data(index, Qt::EditRole).toInt());
}

void StringListModelDialogCellDelegete::updateEditorGeometry(
    QWidget* editor,
    const QStyleOptionViewItem& option,
    const QModelIndex&) const
{
    editor->setGeometry(option.rect);
}

void StringListModelDialogCellDelegete::setModelData(
    QWidget* editor,
    QAbstractItemModel* model,
    const QModelIndex& index) const
{
    model->setData(index,
                   static_cast<QSpinBox *>(editor)->value(),
                   Qt::EditRole);
    Q_EMIT const_cast<StringListModelDialogCellDelegete *>(
        this)->closeEditor(editor);
}

}// namespace qt
}// namespace cdom
}// namespace rrdemo

namespace {
int altmain(int argc, char *argv[])
{
    QApplication app(argc, argv);

    rrdemo::cdom::qt::StringListModelDialog mw;
    mw.initialize();
    mw.show();

    return app.exec();
}
}// namespace

#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return altmain(argc, argv); }
#endif// ENTRY SWITCH
