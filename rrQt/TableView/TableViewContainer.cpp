#include "TableViewContainer.h"
#include "ui_TableViewContainer.h"

#include <QtCore/QDebug>
#include <QtWidgets/QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

TableViewContainer::TableViewContainer(QWidget *parent) :
    QWidget {parent},
    ui {new Ui::TableViewContainer}
{
    ui->setupUi(this);
    this->addAction(ui->queryAction);
}

TableViewContainer::~TableViewContainer()
{
    delete ui;
}

void TableViewContainer::on_queryAction_changed()
{
    qInfo() << __func__;
}

void TableViewContainer::on_queryAction_hovered()
{
    qInfo() << __func__;
}

void TableViewContainer::on_queryAction_toggled(bool checked)
{
    qInfo() << __func__ << '(' << checked << ')';
}

void TableViewContainer::on_queryAction_triggered(bool checked)
{
    qInfo() << __func__ << '(' << checked << ')';

    if (QSqlDatabase::contains()) {
        if (QSqlDatabase::database().isValid() && QSqlDatabase::database().isOpen())
            QSqlDatabase::database().close();
        QSqlDatabase::removeDatabase(QLatin1String {QSqlDatabase::defaultConnection});
    }

    QSqlDatabase db = QSqlDatabase::addDatabase(QStringLiteral("QPSQL"));
    db.setHostName(ui->hostNameLineEdit->text());
    db.setPort(ui->hostPortLineEdit->text().toInt());
    db.setUserName(ui->usernameLineEdit->text());
    db.setPassword(ui->passwordLineEdit->text());
    db.setDatabaseName(ui->databaseLineEdit->text());
    db.open();
    if (!db.isOpen()) {
        QMessageBox::warning(this, QStringLiteral("SQL Database Error"), db.lastError().text());
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel {this};
    model->setQuery(ui->codePlainTextEdit->toPlainText(), db);
    if (model->lastError().isValid()) {
        QMessageBox::warning(this, QStringLiteral("SQL Query Error"), model->lastError().text());
        return;
    }

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}
