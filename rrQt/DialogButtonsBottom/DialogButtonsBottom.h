#pragma once
#ifndef DIALOGBUTTONSBOTTOM_H_
#define DIALOGBUTTONSBOTTOM_H_

#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE
class QAbstractButton;
namespace Ui { class DialogButtonsBottom; }
QT_END_NAMESPACE

class DialogButtonsBottom : public QDialog {
    Q_OBJECT

public:
    explicit DialogButtonsBottom(QWidget *parent = nullptr);
    ~DialogButtonsBottom();

private slots:
    void on_DialogButtonsBottom_accepted();
    void on_DialogButtonsBottom_finished(int result);
    void on_DialogButtonsBottom_rejected();

    void on_buttonBox_accepted();
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_buttonBox_helpRequested();
    void on_buttonBox_rejected();

private:
    Ui::DialogButtonsBottom *ui;
};

#endif
