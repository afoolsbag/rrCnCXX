/** \file
 *  \sa <http://doc.qt.io/qt-5/sql-driver.html>
 *  \sa <http://doc.qt.io/qt-5/qsqldatabase.html>
 *  \sa <http://doc.qt.io/qt-5/qsqlquery.html>
 *  \sa <http://stackoverflow.com/questions/2319280>
 *  \author zhengrr
 *  \date 2016-11-16 – 12-9
 *  \copyright The MIT License
 */
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

namespace {
int altmain(int, char *[])
{
    QSqlDatabase db {QSqlDatabase::addDatabase(QStringLiteral("QSQLITE"))};
    db.setDatabaseName(QStringLiteral("db.sqlite"));
    if (!db.open()) {
        qWarning("Open error: %s", db.lastError().text().toUtf8().data());
        return EXIT_FAILURE;
    }

    // create
    QSqlQuery createQuery;
    if (!createQuery.exec(
        "CREATE TABLE IF NOT EXISTS 'table' ("
        "  id    INTEGER CONSTRAINT pk_table_id PRIMARY KEY AUTOINCREMENT,"
        "  intc  INTEGER,"
        "  realc REAL,"
        "  txtc  TEXT,"
        "  blobc BLOB"
        ");")) {
        qWarning("Create error: %s", db.lastError().text().toUtf8().data());
        return EXIT_FAILURE;
    }

    // insert
    QSqlQuery insertQuery;
    insertQuery.prepare(
        "INSERT OR IGNORE INTO 'table' (intc, realc, txtc) VALUES"
        "  (:fibonacci, :pi, :alphabet);");
    insertQuery.bindValue(QStringLiteral(":fibonacci"), QVariantList {
        0, 1, 1, 2, 3, 5, 8,
        13, 21, 34, 55, 89,
        114, 233, 377, 610, 987,
        1597, 2584, 4181, 6765,
        10946, 17711, 28657});
    insertQuery.bindValue(QStringLiteral(":pi"), QVariantList {
        3., 3.1,
        3.14, 3.142,
        3.1416, 3.14159,
        3.141593, 3.1415927,
        3.14159265, 3.141592654,
        3.1415926536, 3.14159265359,
        3.141592653590, 3.1415926535898,
        3.14159265358979, 3.141592653589793,
        3.1415926535897932, 3.14159265358979324,
        3.141592653589793238, 3.1415926535897932385,
        3.14159265358979323846, 3.141592653589793238463,
        3.1415926535897932384626, 3.14159265358979323846264
    });
    insertQuery.bindValue(QStringLiteral(":alphabet"), QVariantList {
        "Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Zeta",
        "Eta", "Theta", "Iota", "Kappa", "Lambda", "Mu",
        "Nu", "Xi", "Omicron", "Pi", "Rho", "Sigma",
        "Tau", "Upsilon", "Phi", "Chi", "Psi", "Omega"
    });
    if (!insertQuery.execBatch()) {
        qWarning("Insert error: %s", db.lastError().text().toUtf8().data());
        return EXIT_FAILURE;
    }

    // select
    QSqlQuery selectQuery;
    if (!selectQuery.exec(
        "SELECT * FROM 'table';")) {
        qWarning("Select Error: %s", db.lastError().text().toUtf8().data());
        return EXIT_FAILURE;
    }
    const int fibonnacciIndex {
        selectQuery.record().indexOf(QStringLiteral("intc"))};
    const int piIndex {
        selectQuery.record().indexOf(QStringLiteral("realc"))};
    const int alphabetIndex {
        selectQuery.record().indexOf(QStringLiteral("txtc"))};
    while (selectQuery.next()) {
        qInfo("%d, %lg, %s",
              selectQuery.value(fibonnacciIndex).toInt(),
              selectQuery.value(piIndex).toDouble(),
              selectQuery.value(alphabetIndex).toString().toUtf8().data());
    }

    return EXIT_SUCCESS;
}
}// namespace

#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return altmain(argc, argv); }
#endif// ENTRY SWITC
