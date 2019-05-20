#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QtCore/QDir>
#include <QtCore/QRegularExpression>
#include <QtCore/QTranslator>
#include <QtWidgets/QMessageBox>

#include "TranslatorSwitcher.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow {parent},
    ui {new Ui::MainWindow},
    switchLanguageActionGroup {new QActionGroup(this)}
{
    ui->setupUi(this);

    connect(switchLanguageActionGroup, &QActionGroup::triggered,
        this, &MainWindow::on_switchLanguageActionGroup_triggered);

    reloadMenuLanguages();

    switchLanguage(QLocale::system());
}

MainWindow::~MainWindow()
{
    disconnect(switchLanguageActionGroup, &QActionGroup::triggered,
        this, &MainWindow::on_switchLanguageActionGroup_triggered);

    delete ui;
}

void MainWindow::switchLanguage(const QLocale &locale)
{
    TranslatorSwitcher::instance()->switchLanguage(locale);
    ui->retranslateUi(this);
    ui->statusBar->showMessage(tr("Current Language changed to %1").arg(locale.nativeLanguageName()));
}

void MainWindow::reloadMenuLanguages()
{
    for (const auto &action : switchLanguageActionGroup->actions())
        switchLanguageActionGroup->removeAction(action);
    ui->menuLanguages->clear();

    const auto locales = TranslatorSwitcher::instance()->scanLanguages();
    for (const auto &locale : locales) {
        const auto action = new QAction(locale.nativeLanguageName(), ui->menuLanguages);
        action->setData(locale);
        ui->menuLanguages->addAction(action);
        switchLanguageActionGroup->addAction(action);
    }
}

void MainWindow::on_popAMessageBox_clicked(bool)
{
    QMessageBox::information(this, tr("A message Box"), tr("A message."));
}

void MainWindow::on_switchLanguageActionGroup_triggered(QAction* action)
{
    if (!action)
        return;
    switchLanguage(action->data().toLocale());
}
