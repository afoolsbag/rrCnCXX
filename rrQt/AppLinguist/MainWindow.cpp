#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QtCore/QDir>
#include <QtCore/QTranslator>
#include <QtWidgets/QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow {parent},
    ui {new Ui::MainWindow},
    actionGroupLanguages {new QActionGroup(this)},
    languagesDirectory {QApplication::applicationDirPath() + QStringLiteral("/lang")}
{
    ui->setupUi(this);

    connect(actionGroupLanguages, &QActionGroup::triggered,
            this, &MainWindow::on_actionGroupLanguages_triggered);

    loadLanguage(QLocale::system());
    loadMenuLanguages();
}

MainWindow::~MainWindow()
{
    disconnect(actionGroupLanguages, &QActionGroup::triggered,
               this, &MainWindow::on_actionGroupLanguages_triggered);

    delete ui;
}

void MainWindow::loadLanguage(const QLocale &locale)
{
    while (!translators.empty()) {
        const auto translator {translators.first()};
        translators.removeFirst();
        qApp->removeTranslator(translator);
        delete translator;
    }

    const auto qms {QDir(languagesDirectory).entryList()};
    const QRegularExpression re {locale.name() + QStringLiteral("[.]qm$")};

    for (const auto &qm : qms) {
        if (!re.match(qm).hasMatch())
            continue;
        const auto translator = new QTranslator(this);
        translator->load(qm);
        qApp->installTranslator(translator);
        translators.append(translator);
    }

    ui->retranslateUi(this);
    ui->statusBar->showMessage(tr("Current Language changed to %1").arg(locale.nativeLanguageName()));
}

void MainWindow::loadMenuLanguages()
{
    for (const auto &action : actionGroupLanguages->actions())
        actionGroupLanguages->removeAction(action);
    ui->menuLanguages->clear();

    const auto qms {QDir(languagesDirectory).entryList()};
    const QRegularExpression re {QStringLiteral("([a-z]{2}(_[A-Z]{2})?)[.]qm$")};

    for (const auto &qm : qms) {
        const auto rem {re.match(qm)};
        if (!rem.hasMatch())
            continue;

        QLocale locale {rem.captured(1)};

        const auto &localeIncluded = [&] {
            for (const auto &action : ui->menuLanguages->actions())
                if (action->data().toLocale() == locale)
                    return true;
            return false;
        };

        if (localeIncluded())
            continue;

        const auto action = new QAction(locale.nativeLanguageName(), ui->menuLanguages);
        action->setData(locale);
        ui->menuLanguages->addAction(action);
        actionGroupLanguages->addAction(action);
    }
}

void MainWindow::on_actionGroupLanguages_triggered(QAction *action)
{
    if (!action)
        return;
    loadLanguage(action->data().toLocale());
}

void MainWindow::on_popAMessageBox_clicked(bool)
{
    QMessageBox::information(this, tr("A message Box"), tr("A message."));
}
