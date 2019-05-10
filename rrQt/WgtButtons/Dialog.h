#pragma once
#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>

class QAbstractButton;

namespace Ui {
class Dialog;
}

class Dialog: public QWidget {
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked(bool checked);
    void on_pushButton_pressed();
    void on_pushButton_released();

    void on_toolButton_triggered(QAction *action);

    void on_radioButton1_clicked(bool checked);
    void on_radioButton2_clicked(bool checked);
    void on_radioButton3_clicked(bool checked);

    void on_checkBox_toggled(bool checked);
    void on_checkBox_stateChanged(int state);

    void on_commandLinkButton_clicked(bool checked);

    void on_dialogButtonBox_accepted();
    void on_dialogButtonBox_clicked(QAbstractButton *button);
    void on_dialogButtonBox_helpRequested();
    void on_dialogButtonBox_rejected();

    void on_showDebugPanel_toggled(bool checked);

private:
    Ui::Dialog *ui;
};

#endif//DIALOG_H
