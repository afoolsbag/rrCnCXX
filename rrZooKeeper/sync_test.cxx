//===-- Synchronous CRUD ----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 同步增删改查。
///
/// \version 2020-06-17
/// \since 2018-12-30
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#define _CRT_SECURE_NO_WARNINGS

#include <string>

#include <gtest/gtest.h>
#include "rrzookeeper/rrzookeeper.hxx"

using namespace std;

static const string root_path {"/rrzookeeper_test"};
static const string base_path {root_path + "/sync"};
static const string null_node_path {base_path + "/null_node"};
static const string value_node_path {base_path + "/value_node"};
static const string value_node_value {"value"};
static const string value_node_eulav {"eulav"};
static const string dangling_node_path {base_path + "/nonexistent/dangling_node"};
static const string eph_node_path {base_path + "/eph"};
static const string seq_node_path {base_path + "/seq"};
static const string both_node_path {base_path + "/eph_seq"};

class sync_test : public testing::Test {
protected:
    static rrzookeeper::client client;
    static void event_callback(rrzookeeper::client *self, const rrzookeeper::client::event &type, const rrzookeeper::client::state &state, const optional<string> &path, void *p_user_data)
    {
        (void)self;
        (void)p_user_data;
        cout << "event: type=" << static_cast<int>(type) << " state=" << static_cast<int>(state) << " path=" << path.value_or("<null>") << endl;
    }
    static void SetUpTestCase()
    {
        client.set_event_callback(event_callback, nullptr);
        client.connect("127.0.0.1:2181");
        client.deleta(base_path, rrzookeeper::client::deleta::force);
        client.create(base_path, std::nullopt, rrzookeeper::client::create::force);
    }
    static void TearDownTestCase()
    {
        client.disconnect();
    }
};
rrzookeeper::client sync_test::client;

/// \brief 创建节点。
TEST_F(sync_test, create)
{
    // 创建空节点
    ASSERT_NO_THROW(client.create(null_node_path));

    // 创建值节点
    ASSERT_NO_THROW(client.create(value_node_path, value_node_value));

    // 不允许跨级创建节点
    ASSERT_ANY_THROW(client.create(dangling_node_path));
}

/// \brief 读取节点。
TEST_F(sync_test, read)
{
    // 检查节点存在
    ASSERT_TRUE(client.exists(null_node_path));

    // 检查节点不存在
    ASSERT_FALSE(client.exists(dangling_node_path));

    // 读取节点值
    const auto val = client.get(value_node_path);
    ASSERT_EQ(val, value_node_value);

    // 获取子节点
    const auto subs = client.get_children(base_path);
    cout << base_path << "s sub-nodes: \n";
    for (const auto &sub : subs)
        cout << "  " << sub << "\n";
}

/// \brief 变更节点。
TEST_F(sync_test, update)
{
    // 变更节点
    client.set(value_node_path, value_node_eulav);

    const auto val = client.get(value_node_path);
    ASSERT_EQ(val, value_node_eulav);
}

/// \brief 同步删除节点。
TEST_F(sync_test, deleta)
{
    // 不允许跨级删除节点
    ASSERT_ANY_THROW(client.deleta(root_path));
}

/// \brief 创建临时节点
TEST_F(sync_test, eph)
{
    client.create(eph_node_path, nullopt, rrzookeeper::client::create::ephemeral | rrzookeeper::client::create::force);
}

/// \brief 创建顺序节点
TEST_F(sync_test, seq)
{
    client.create(seq_node_path, nullopt, rrzookeeper::client::create::sequence | rrzookeeper::client::create::force);
}

/// \brief 创建临时、顺序节点
TEST_F(sync_test, eph_seq)
{
    client.create(both_node_path, nullopt, rrzookeeper::client::create::ephemeral | rrzookeeper::client::create::sequence | rrzookeeper::client::create::force);
}
