//! \copyright Unlicense

#pragma once
#ifndef GLOBALTRANSLATORS_H
#define GLOBALTRANSLATORS_H

#include <QtCore/QCoreApplication>
#include <QtCore/QDir>
#include <QtCore/QObject>
#include <QtCore/QTranslator>

//! \brief 全局翻译器
class TranslatorSwitcher : public QObject {
    Q_OBJECT

public:
    static TranslatorSwitcher *instance() { return self; }

    TranslatorSwitcher(const QString &languageDirectoryPath = QStringLiteral("lang"), QCoreApplication *application = qApp);

    QList<QLocale> scanLanguages();
    void switchLanguage(const QLocale &locale);

private:
    static TranslatorSwitcher *self;

    QCoreApplication    *application;
    QDir                 languageDirectory;
    QList<QTranslator *> installedTranslators;
};

#endif//GLOBALTRANSLATORS_H
