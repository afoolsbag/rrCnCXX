#include "DialogButtonsRight.h"
#include "ui_DialogButtonsRight.h"

#include <QtCore/QDebug>

DialogButtonsRight::DialogButtonsRight(QWidget *parent) :
    QDialog {parent},
    ui {new Ui::DialogButtonsRight}
{
    ui->setupUi(this);
}

DialogButtonsRight::~DialogButtonsRight()
{
    delete ui;
}

void DialogButtonsRight::on_DialogButtonsRight_accepted()
{
    qInfo() << __func__ << '(' << ')';
}

void DialogButtonsRight::on_DialogButtonsRight_finished(int result)
{
    qInfo() << __func__ << '(' << result << ')';
}

void DialogButtonsRight::on_DialogButtonsRight_rejected()
{
    qInfo() << __func__ << '(' << ')';
}

void DialogButtonsRight::on_buttonBox_accepted()
{
    qInfo() << __func__ << '(' << ')';
}

void DialogButtonsRight::on_buttonBox_clicked(QAbstractButton *button)
{
    qInfo() << __func__ << '(' << button << ')';
}

void DialogButtonsRight::on_buttonBox_helpRequested()
{
    qInfo() << __func__ << '(' << ')';
}

void DialogButtonsRight::on_buttonBox_rejected()
{
    qInfo() << __func__ << '(' << ')';
}
