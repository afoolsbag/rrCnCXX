#include "DialogButtonsBottom.h"
#include "ui_DialogButtonsBottom.h"

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
