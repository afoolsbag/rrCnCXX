//===------------------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 一个小玩意儿，用于测试 `.trk` 数据文件
///
/// \version 2019-10-22
/// \since 2019-10-21
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <exception>
#include <iostream>
#include <gsl/gsl>

#include <SQLiteCpp/SQLiteCpp.h>

using namespace std;
using namespace gsl;

int main(int argc, char *argv[]) noexcept
{
    try {
        if (argc != 2) {
            cerr << "failure: argc != 2\n";
            system("PAUSE");
            return EXIT_FAILURE;
        }

        SQLite::Database db {argv[1], SQLite::OPEN_READONLY};
        SQLite::Statement stmt {db,""
            "SELECT frame, left, top, right, bottom, id "
            "  FROM tracks; "};

        size_t cnt {};

        cout << "frame\tleft\ttop\tright\tbottom\tid\n";
        while (stmt.executeStep()) {
            cout << stmt.getColumn(0) << '\t' << stmt.getColumn(1) << '\t' << stmt.getColumn(2) << '\t' << stmt.getColumn(3) << '\t' << stmt.getColumn(4) << '\t' << stmt.getColumn(5) << '\n';
            ++cnt;
        }
        cout << "total: " << cnt << " rows.\n";

        system("PAUSE");
        return EXIT_SUCCESS;

    } catch (const exception &e) {
        cerr << "failure: exception: " << e.what() << '\n';
        system("PAUSE");
        return EXIT_FAILURE;

    } catch (...) {
        cerr << "failure: exception: ...\n";
        system("PAUSE");
        return EXIT_FAILURE;

    }
}
