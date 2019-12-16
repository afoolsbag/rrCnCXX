#include "DialogButtonsBottom.h"
#include "ui_DialogButtonsBottom.h"

#include <QtCore/QDebug>

DialogButtonsBottom::DialogButtonsBottom(QWidget *parent) :
    QDialog {parent},
    ui {new Ui::DialogButtonsBottom}
{
    ui->setupUi(this);
}

DialogButtonsBottom::~DialogButtonsBottom()
{
    delete ui;
}

void DialogButtonsBottom::on_DialogButtonsBottom_accepted()
{
    qInfo() << __func__ << '(' << ')';
}

void DialogButtonsBottom::on_DialogButtonsBottom_finished(int result)
{
    qInfo() << __func__ << '(' << result << ')';
}

void DialogButtonsBottom::on_DialogButtonsBottom_rejected()
{
    qInfo() << __func__ << '(' << ')';
}

void DialogButtonsBottom::on_buttonBox_accepted()
{
    qInfo() << __func__ << '(' << ')';
}

void DialogButtonsBottom::on_buttonBox_clicked(QAbstractButton *button)
{
    qInfo() << __func__ << '(' << button << ')';
}

void DialogButtonsBottom::on_buttonBox_helpRequested()
{
    qInfo() << __func__ << '(' << ')';
}

void DialogButtonsBottom::on_buttonBox_rejected()
{
    qInfo() << __func__ << '(' << ')';
}
