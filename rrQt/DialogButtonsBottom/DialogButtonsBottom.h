#pragma once
#ifndef DIALOGBUTTONSBOTTOM_H_
#define DIALOGBUTTONSBOTTOM_H_

#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class DialogButtonsBottom; }
QT_END_NAMESPACE

class DialogButtonsBottom : public QDialog {
    Q_OBJECT

public:
    explicit DialogButtonsBottom(QWidget *parent = nullptr);
    ~DialogButtonsBottom();

private:
    Ui::DialogButtonsBottom *ui;
};

#endif
