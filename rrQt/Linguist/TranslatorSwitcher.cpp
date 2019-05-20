//! \copyright Unlicense

#include "TranslatorSwitcher.h"

#include <QtCore/QLocale>
#include <QtCore/QRegularExpression>

TranslatorSwitcher::TranslatorSwitcher(const QString &languageDirectoryPath, QCoreApplication *application)
    : QObject {application}, application {application}
{
    Q_ASSERT(application);
    Q_ASSERT(!self);

    if (QDir(languageDirectoryPath).isAbsolute())
        languageDirectory = languageDirectoryPath;
    else
        languageDirectory = application->applicationDirPath() + QStringLiteral("/") + languageDirectoryPath;

    self = this;
}

TranslatorSwitcher *TranslatorSwitcher::self {Q_NULLPTR};

QList<QLocale> TranslatorSwitcher::scanLanguages()
{
    static const QRegularExpression re {QStringLiteral(R"(([a-z]{2}(_[A-Z]{2})?)\.qm$)")};

    QList<QLocale> rv;

    const auto files {languageDirectory.entryList()};
    for (const auto &file : files) {
        const auto match = re.match(file);
        if (!match.hasMatch())
            continue;

        QLocale locale {match.captured(1)};

        const auto &included = [&] {
            for (const auto &tmp : rv)
                if (tmp == locale)
                    return true;
            return false;
        };
        if (included())
            continue;

        rv.append(locale);
    }

    return rv;
}

void TranslatorSwitcher::switchLanguage(const QLocale &locale)
{
    while (!installedTranslators.empty()) {
        const auto translator {installedTranslators.first()};
        installedTranslators.removeFirst();
        application->removeTranslator(translator);
        delete translator;
    }

    const QRegularExpression re {locale.name() + QStringLiteral(R"(\.qm$)")};
    const auto files {languageDirectory.entryList()};
    for (const auto &file : files) {
        if (!re.match(file).hasMatch())
            continue;
        const auto translator = new QTranslator(application);
        translator->load(languageDirectory.path() + "/" + file);
        application->installTranslator(translator);
        installedTranslators.append(translator);
    }
}
