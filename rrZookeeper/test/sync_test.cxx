//===-- Synchronous CRUD ----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 同步增删改查。
///
/// \version 2019-05-28
/// \since 2018-12-30
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#define _CRT_SECURE_NO_WARNINGS

#include <string>

#include <gtest/gtest.h>
#include "rrzookeeper_client.hxx"

using namespace std;
using client = rrzookeeper::client;

static const string root_path {"/rrzookeeper"};
static const string base_path {root_path + "/sync"};
static const string nnode_path {base_path + "/null_node"};
static const string vnode_path {base_path + "/value_node"};
static const string dnode_path {base_path + "/nonexistent/dangling_node"};
static const string enode_path {base_path + "/eph"};
static const string snode_path {base_path + "/seq"};
static const string bnode_path {base_path + "/eph_seq"};
static const string vnode_value {"value"};
static const string vnode_eulav {"eulav"};

class sync_test : public testing::Test {
protected:
    static rrzookeeper::client client;
    static void SetUpTestCase()
    {
        client.connect("127.0.0.1:2181");
        client.deleta(base_path, client::df_force);
        client.create(base_path, std::nullopt, client::cf_force);
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
    ASSERT_NO_THROW(client.create(nnode_path));

    // 创建值节点
    ASSERT_NO_THROW(client.create(vnode_path, vnode_value));

    // 不允许跨级创建节点
    ASSERT_ANY_THROW(client.create(dnode_path));
}

/// \brief 读取节点。
TEST_F(sync_test, read)
{
    // 检查节点存在
    ASSERT_TRUE(client.exists(nnode_path));

    // 检查节点不存在
    ASSERT_FALSE(client.exists(dnode_path));

    // 读取节点值
    const auto val = client.get(vnode_path);
    ASSERT_EQ(val, vnode_value);

    // 获取子节点
    const auto subs = client.get_children(base_path);
    cout << base_path << "s sub-nodes: \n";
    for (const auto sub : subs)
        cout << "  " << sub << "\n";
}

/// \brief 变更节点。
TEST_F(sync_test, update)
{
    // 变更节点
    client.set(vnode_path, vnode_eulav);

    const auto val = client.get(vnode_path);
    ASSERT_EQ(val, vnode_eulav);
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
    client.create(enode_path, client::cf_ephemeral | client::cf_force);
}

/// \brief 创建顺序节点
TEST_F(sync_test, seq)
{
    client.create(snode_path, client::cf_sequence | client::cf_force);
}

/// \brief 创建临时、顺序节点
TEST_F(sync_test, eph_seq)
{
    client.create(bnode_path, client::cf_ephemeral | client::cf_sequence | client::cf_force);
}

TEST(custom, temp)
{
    rrzookeeper::client clt;
    //clt.connect("172.16.0.16:2181,172.16.0.17:2181,172.16.0.18:2181");
    clt.connect("127.0.0.1:2181");
    clt.create("/YLSER/172.16.0.225", R"(
{
        "ivsListener" : "http://172.16.0.225:8089/ylser/listenerDevData",
        "ivsLogin" : "http://172.16.0.225:8089/ylser/ivslogin",
        "logoutUrl" : "http://172.16.0.225:8089/ylser/ivslogout"
}
)", client::cf_force);
}
