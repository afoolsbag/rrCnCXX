#pragma once
#ifndef DIALOGBUTTONSRIGHT_H_
#define DIALOGBUTTONSRIGHT_H_

#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class DialogButtonsRight; }
QT_END_NAMESPACE

class DialogButtonsRight : public QDialog {
    Q_OBJECT

public:
    explicit DialogButtonsRight(QWidget *parent = nullptr);
    ~DialogButtonsRight();

private:
    Ui::DialogButtonsRight *ui;
};

#endif
