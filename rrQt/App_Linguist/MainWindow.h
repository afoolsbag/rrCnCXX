#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>

class QActionGroup;
class QTranslator;

namespace Ui {
class MainWindow;
}

class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void loadLanguage(const QLocale &locale);
    void loadMenuLanguages();

    Ui::MainWindow *ui;

    QActionGroup *actionGroupLanguages;
    QList<QTranslator *> translators;

    const QString languagesDirectory;

private slots:
    void on_actionGroupLanguages_triggered(QAction *action);
    void on_popAMessageBox_clicked(bool checked);
};

#endif//MAINWINDOW_H
