/** \file
 *  \sa <http://doc.qt.io/qt-5/qsqltablemodel.html>
 *  \author zhengrr
 *  \date 2016-12-9
 *  \copyright The MIT License
 */
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>

namespace {
int altmain(int, char *[])
{
    QSqlDatabase db {QSqlDatabase::addDatabase(QStringLiteral("QSQLITE"))};
    db.setDatabaseName(QStringLiteral("db.sqlite"));
    if (!db.open()) {
        qWarning("Open error: %s", db.lastError().text().toUtf8().data());
        return EXIT_FAILURE;
    }

    QSqlTableModel model;
    
    return EXIT_SUCCESS;
}
}// namespace

#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return altmain(argc, argv); }
#endif// ENTRY SWITC
