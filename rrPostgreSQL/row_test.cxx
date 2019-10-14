//===-- Row Test ------------------------------------------------*- C++ -*-===//
///
/// \file
///
/// \version 2019-10-14
/// \since 2019-10-14
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>
#include <memory>

#include <gtest/gtest.h>
#include <pqxx/pqxx>

using namespace std;

namespace rrpostgresql {

/// \sa [Connection Strings](https://postgresql.org/docs/current/libpq-connect.html#LIBPQ-CONNSTRING)
class row_test :public testing::Test {
protected:
    static void SetUpTestCase()
    {
        try {

            con = make_unique<pqxx::connection>(
                "hostaddr=127.0.0.1 "
                "port=5432 "
                "dbname=postgres "
                "user=postgres "
                "password= ");

            pqxx::work txn {*con};
            txn.exec0(
                "DROP TABLE IF EXISTS row_test_table; ");
            txn.exec0(
                "CREATE TABLE row_test_table ( "
                "    id                      SERIAL            PRIMARY KEY, "
                "    boolean_column          BOOLEAN, "
                "    smallint_column         SMALLINT, "                       // 2 bytes
                "    integer_column          INTEGER, "                        // 4 bytes
                "    bigint_column           BIGINT, "                         // 8 bytes
                "    real_column             REAL, "                           // 4 bytes
                "    double_precision_column DOUBLE PRECISION, "               // 8 bytes
                "    text_column             TEXT, "
                "    bytea_column            BYTEA "
                "); ");
            txn.exec0(
                "INSERT INTO row_test_table (boolean_column, integer_column) "
                "VALUES (TRUE, 666); ");
            txn.commit();

        } catch (const exception &e) {
            FAIL() << "Set up failed: " << e.what();

        }
    }

    static void TearDownTestCase()
    {
        con.reset();
    }

    static unique_ptr<pqxx::connection> con;
};
unique_ptr<pqxx::connection> row_test::con {nullptr};

TEST_F(row_test, prepared_statements)
{
    con->prepare(
        "TheStatement",
        "SELECT * "
        "  FROM row_test_table "
        " WHERE id = $1; ");

    pqxx::work txn {*con};
    const auto results = txn.exec_prepared("TheStatement", 1);

    for (const auto &result : results) {
        for (const auto &column : result) {
            cout << column.name() << "=" << column.c_str() << "\n";
        }
        cout << "\n";
    }

    txn.commit();
}

}
