/** \file
 *  \brief 日志支持。
 *  \sa <http://doc.qt.io/qt-5/qtglobal.html#qInstallMessageHandler>
 *  \author zhengrr
 *  \date 2016-1-9 – 11-15
 *  \copyright The MIT License
 */
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QMutex>
#include <QString>
#include <QTextStream>

namespace {
QMutex logFileMutex;
QMutex logOutputMutex;

void MessageHandler(QtMsgType type,
                    const QMessageLogContext &context,
                    const QString &message)
{
    // logFile
    static QFile *logfile {nullptr};
    if (!logfile) {
        logFileMutex.lock();
        if (!logfile) {
            logfile = new QFile(QStringLiteral("log.txt"));
            logfile->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
        }
        logFileMutex.unlock();
    }

    QString logtext;

    // logText: time
    logtext += QDateTime::currentDateTime().toString(QStringLiteral("yy-MM-dd HH:mm:ss.zzz"));

    // logText: type
    switch (type) {
    case QtDebugMsg:     logtext += QStringLiteral(" [D]");  break;
    case QtWarningMsg:   logtext += QStringLiteral(" [W]");  break;
    case QtCriticalMsg:  logtext += QStringLiteral(" [C]");  break;
    case QtFatalMsg:     logtext += QStringLiteral(" [F]");  break;
    case QtInfoMsg:      logtext += QStringLiteral(" [I]");  break;
    default: Q_ASSERT(false);
    }

    // logText: message
    logtext += QString(" %1").arg(message);

    // logText: local
    switch (type) {
    case QtDebugMsg:     break;
    case QtWarningMsg:   break;
    case QtCriticalMsg:  // break through
    case QtFatalMsg:
        logtext += QString(" @%1:%2: %3")
            .arg(QFileInfo(context.file).fileName())
            .arg(context.line)
            .arg(context.function);
        break;
    case QtInfoMsg:      break;
    default: Q_ASSERT(false);
    }

    // logText: "yy-MM-dd HH:mm:ss.zzz [*] message @file:line: function"
    logOutputMutex.lock();
    QTextStream stream(logfile);
    stream << logtext << endl;  // CR/LF and flush
    logOutputMutex.unlock();
}

int altmain(int, char *[])
{
    qInstallMessageHandler(MessageHandler);

    qDebug("Debug message.");
    qWarning("Warning message.");
    qInfo("Info message.");
    qCritical("Critical message.");
    qFatal("Fatal message.");

    return EXIT_SUCCESS;
}
}// namespace

#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return altmain(argc, argv); }
#endif// ENTRY SWITCH
