#pragma once
#ifndef DIALOGBUTTONSRIGHT_H_
#define DIALOGBUTTONSRIGHT_H_

#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE
class QAbstractButton;
namespace Ui { class DialogButtonsRight; }
QT_END_NAMESPACE

class DialogButtonsRight : public QDialog {
    Q_OBJECT

public:
    explicit DialogButtonsRight(QWidget *parent = nullptr);
    ~DialogButtonsRight();

private slots:
    void on_DialogButtonsRight_accepted();
    void on_DialogButtonsRight_finished(int result);
    void on_DialogButtonsRight_rejected();

    void on_buttonBox_accepted();
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_buttonBox_helpRequested();
    void on_buttonBox_rejected();

private:
    Ui::DialogButtonsRight *ui;
};

#endif
