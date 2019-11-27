//===-- Transaction ---------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 事务
/// \details 对于大批量小尺寸数据的存取，可以使用事务减少数据交换频次，大幅优化速度。
///
/// \version 2019-11-27
/// \since 2019-11-27
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <memory>

#include <gtest/gtest.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include <sqlite3.h>

using namespace std;

namespace rrsqlite {

/// \details 事务的 RAII 包装，若其在析构时仍未提交，则进行回滚。
TEST(transaction, sqlitecpp)
{
    SQLite::Database db {"rrsqlitecpp.sqlite3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE};

    SQLite::Transaction txn {db};

    // ...

    txn.commit();
}

}
