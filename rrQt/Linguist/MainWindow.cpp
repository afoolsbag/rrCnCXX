#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QtCore/QRegularExpression>
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

    reloadLanguagesMenu();

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

void MainWindow::reloadLanguagesMenu()
{
    for (const auto &action : switchLanguageActionGroup->actions())
        switchLanguageActionGroup->removeAction(action);
    ui->languagesMenu->clear();

    const auto locales = TranslatorSwitcher::instance()->scanLanguages();
    for (const auto &locale : locales) {
        const auto action = new QAction(locale.nativeLanguageName(), ui->languagesMenu);
        action->setData(locale);
        ui->languagesMenu->addAction(action);
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
