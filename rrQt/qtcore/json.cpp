/** \file
 *  \sa <http://doc.qt.io/qt-5/qjsondocument.html>
 *  \author zhengrr
 *  \date 2016-11-28
 *  \copyright The MIT License
 */
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

namespace {

void CouldNotOpenTheFileWarningAndExitFailure(const QString &filePath)
{
    qWarning("Couldn't open the file \"%s\".", filePath.toUtf8().data());
    exit(EXIT_FAILURE);
}

void FileIsPossiblyCorruptWarningAndExitFailure(const QString &filePath)
{
    qWarning("The file \"%s\" is possibly corrupt.", filePath.toUtf8().data());
    exit(EXIT_FAILURE);
}

void WriteJSON(const QString &filePath, const bool binary = false)
{
    QJsonObject root;
    root[QStringLiteral("string")] = QStringLiteral("string");
    root[QStringLiteral("number")] = 1234.5678;
    root[QStringLiteral("object")] = QJsonObject();
    root[QStringLiteral("array")] = QJsonArray();
    root[QStringLiteral("boolean")] = true;
    root[QStringLiteral("null")];

    QJsonDocument doc(root);

    QFile file(filePath);
    if (!file.open(binary ?
        QIODevice::WriteOnly | QIODevice::Truncate :
        QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
        CouldNotOpenTheFileWarningAndExitFailure(filePath);
    file.write(binary ? doc.toBinaryData() : doc.toJson());
    file.close();
}

void ReadJSON(const QString &filePath, const bool binary = false)
{
    QFile file(filePath);
    if (!file.open(binary ?
        QIODevice::ReadOnly :
        QIODevice::ReadOnly | QIODevice::Text))
        CouldNotOpenTheFileWarningAndExitFailure(filePath);
    QByteArray data {file.readAll()};

    QJsonDocument doc {binary ? QJsonDocument::fromBinaryData(data) : QJsonDocument::fromJson(data)};

    QJsonObject root {doc.object()};

    if (!root[QStringLiteral("string")].isString()) FileIsPossiblyCorruptWarningAndExitFailure(filePath);
    else qInfo("string: %s", root[QStringLiteral("string")].toString().toUtf8().data());
    if (!root[QStringLiteral("number")].isDouble()) FileIsPossiblyCorruptWarningAndExitFailure(filePath);
    else qInfo("number: %lf", root[QStringLiteral("number")].toDouble());
}

Q_CONSTEXPR QString FILE_PATH {"json.json"};
Q_CONSTEXPR bool BINARY {false};
int altmain(int, char *[])
{
    WriteJSON(FILE_PATH, BINARY);
    ReadJSON(FILE_PATH, BINARY);

    return EXIT_SUCCESS;
}
}// namespace
#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return altmain(argc, argv); }
#endif// ENTRY SWITCH
