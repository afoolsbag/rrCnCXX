#include "DialogButtonsRight.h"
#include "ui_DialogButtonsRight.h"

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
