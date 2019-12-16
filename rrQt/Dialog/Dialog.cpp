#include "Dialog.h"
#include "ui_Dialog.h"

#include <QtCore/QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog {parent},
    ui {new Ui::Dialog}
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_Dialog_accepted()
{
    qInfo() << __func__ << '(' << ')';
}

void Dialog::on_Dialog_finished(int result)
{
    qInfo() << __func__ << '(' << result << ')';
}

void Dialog::on_Dialog_rejected()
{
    qInfo() << __func__ << '(' << ')';
}
