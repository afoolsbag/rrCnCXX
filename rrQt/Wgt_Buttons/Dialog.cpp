#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent):
    QWidget(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->showDebugPanel, &QCheckBox::toggled,
            ui->debugPanel, &QPlainTextEdit::setVisible);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked(bool checked)
{
    ui->debugPanel->appendPlainText(
        QString("%1(%2)").arg(__func__, QString::number(checked))
    );
}

void Dialog::on_pushButton_pressed()
{
    ui->debugPanel->appendPlainText(
        QString("%1()").arg(__func__)
    );
}

void Dialog::on_pushButton_released()
{
    ui->debugPanel->appendPlainText(
        QString("%1()").arg(__func__)
    );
}

void Dialog::on_toolButton_triggered(QAction *action)
{
    ui->debugPanel->appendPlainText(
        QString("%1(0x%2)").arg(__func__, QString::number(quintptr(action), 16))
    );
}

void Dialog::on_radioButton1_clicked(bool checked)
{
    ui->debugPanel->appendPlainText(
        QString("%1(%2)").arg(__func__, QString::number(checked))
    );
}

void Dialog::on_radioButton2_clicked(bool checked)
{
    ui->debugPanel->appendPlainText(
        QString("%1(%2)").arg(__func__, QString::number(checked))
    );
}

void Dialog::on_radioButton3_clicked(bool checked)
{
    ui->debugPanel->appendPlainText(
        QString("%1(%2)").arg(__func__, QString::number(checked))
    );
}

void Dialog::on_checkBox_toggled(bool checked)
{
    ui->debugPanel->appendPlainText(
        QString("%1(%2)").arg(__func__, QString::number(checked))
    );
}

void Dialog::on_checkBox_stateChanged(int state)
{
    ui->debugPanel->appendPlainText(
        QString("%1(%2)").arg(__func__, QString::number(state))
    );
}

void Dialog::on_commandLinkButton_clicked(bool checked)
{
    ui->debugPanel->appendPlainText(
        QString("%1(%2)").arg(__func__, QString::number(checked))
    );
}

void Dialog::on_dialogButtonBox_accepted()
{
    ui->debugPanel->appendPlainText(
        QString("%1()").arg(__func__)
    );
}

void Dialog::on_dialogButtonBox_clicked(QAbstractButton *button)
{
    ui->debugPanel->appendPlainText(
        QString("%1(0x%2)").arg(__func__, QString::number(quintptr(button), 16))
    );
}

void Dialog::on_dialogButtonBox_helpRequested()
{
    ui->debugPanel->appendPlainText(
        QString("%1()").arg(__func__)
    );
}

void Dialog::on_dialogButtonBox_rejected()
{
    ui->debugPanel->appendPlainText(
        QString("%1()").arg(__func__)
    );
}
