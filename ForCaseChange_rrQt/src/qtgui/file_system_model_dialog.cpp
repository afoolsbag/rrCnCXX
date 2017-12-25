/** \copyright The MIT License */
#include "file_system_model_dialog.hpp"
#include "ui_file_system_model_dialog.h"

#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>

namespace {

}

namespace rrdemo {
namespace cdom {
namespace qt {

FileSystemModelDialog::FileSystemModelDialog(QWidget* parent) :
QDialog(parent), ui {new Ui::FileSystemModelDialog}
{
    Q_CHECK_PTR(ui);
    ui->setupUi(this);
}

void FileSystemModelDialog::initialize()
{
    Q_ASSERT(!initialized);

    Q_ASSERT(!model);
    model = new QFileSystemModel(this);  Q_CHECK_PTR(model);
    model->setRootPath(QDir::currentPath());

    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(QDir::currentPath()));

    ui->treeView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->treeView->header()->setStretchLastSection(true);

    ui->treeView->setSortingEnabled(true);
    ui->treeView->header()->setSortIndicator(0, Qt::AscendingOrder);

    initialized = true;
}


FileSystemModelDialog::~FileSystemModelDialog()
{
    delete ui;  ui = Q_NULLPTR;
}

void FileSystemModelDialog::on_mkdirButton_clicked()
{
    Q_ASSERT(initialized);
    qInfo("User clicks the main:mkdir button.");

    QModelIndex curIdx {ui->treeView->currentIndex()};
    if (!curIdx.isValid())
        return;

    QString dirName {
        QInputDialog::getText(this,
        tr("Create Directory"),
        tr("Directory Name:"))};
    if (dirName.isEmpty()) {
        qInfo(": User cancels the operation (main:mkdir).");
        return;
    }

    if (!model->mkdir(curIdx, dirName).isValid()) {
        QMessageBox::information(this,
                                 tr("Create Directory"),
                                 tr("Failed to create the directory."));
        qInfo(": The execution (main:mkdir) failed.");
        return;
    }

    qInfo(": The execution (main:mkdir) succeed.");
}

void FileSystemModelDialog::on_rmButton_clicked()
{
    Q_ASSERT(initialized);
    qInfo("User clicks the main:rm button.");

    QModelIndex curIdx {ui->treeView->currentIndex()};
    if (!curIdx.isValid())
        return;

    if (QMessageBox::Yes != QMessageBox::question(this,
        tr("Remove"),
        tr("Sure you want to delete %1 ?")
        .arg(model->fileName(curIdx)))) {
        qInfo(": User cancels the operation (main:rm).");
        return;
    }

    if (!(model->fileInfo(curIdx).isDir() ?
        model->rmdir(curIdx) : model->remove(curIdx))) {
        QMessageBox::information(this,
                                 tr("Remove"),
                                 tr("Failed to remove %1")
                                 .arg(model->fileName(curIdx)));
        qInfo(": The execution (main:rm) failed.");
    }

    qInfo(": The execution (main:rm) succeed.");
}


}// namespace qt
}// namespace cdom
}// namespace rrdemo

namespace {
int altmain(int argc, char *argv[])
{
    QApplication app(argc, argv);

    rrdemo::cdom::qt::FileSystemModelDialog mw;
    mw.initialize();
    mw.show();

    return app.exec();
}
}// namespace

#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return altmain(argc, argv); }
#endif// ENTRY SWITCH
