/** \file
 *  \sa <http://doc.qt.io/qt-5/qnetworkaccessmanager.html>
 *  \sa <http://doc.qt.io/qt-5/qnetworkrequest.html>
 *  \sa <http://doc.qt.io/qt-5/qnetworkreply.html>
 *  \author zhengrr
 *  \date 2016-12-7 – 8
 *  \copyright The MIT License
 */
#include <QCoreApplication>
#include <QNetworkReply>

namespace {
int altmain(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QNetworkAccessManager manager(&app);
    QNetworkReply *reply {manager.get(QNetworkRequest(QUrl(
        QStringLiteral("http://info.cern.ch/hypertext/WWW/TheProject.html"))))};

    // ready read
    QObject::connect(reply, &QIODevice::readyRead,
                     [=]() {
        qInfo("Network Data: %s", reply->readAll().data());
    });

    // error
    QObject::connect(reply, static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),
                     [=](const QNetworkReply::NetworkError /*error*/) {
        qInfo("Network Error %d: %s",
              reply->error(), reply->errorString().toUtf8().data());
    });

    // ssl errors
    QObject::connect(reply, &QNetworkReply::sslErrors,
                     [](const QList<QSslError> &errors) {
        for (const auto error : errors) {
            qInfo("Network SSL Error %d: %s",
                  error.error(), error.errorString().toUtf8().data());
        }
    });

    return app.exec();
}
}// namespace

#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return altmain(argc, argv); }
#endif// ENTRY SWITCH
