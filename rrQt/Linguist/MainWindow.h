//! \copyright Unlicense

#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>

class QActionGroup;
class QTranslator;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void switchLanguage(const QLocale &locale);

private:
    void reloadMenuLanguages();
    Ui::MainWindow *ui;
    QActionGroup *switchLanguageActionGroup;

private slots:
    void on_popAMessageBox_clicked(bool checked);
    void on_switchLanguageActionGroup_triggered(QAction *action);
};

#endif//MAINWINDOW_H
