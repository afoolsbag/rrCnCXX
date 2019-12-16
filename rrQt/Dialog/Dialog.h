#pragma once
#ifndef DIALOG_H_
#define DIALOG_H_

#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog {
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_Dialog_accepted();
    void on_Dialog_finished(int result);
    void on_Dialog_rejected();

private:
    Ui::Dialog *ui;
};

#endif
