//===-- Cryptographic Hash --------------------------------------*- C++ -*-===//
//!
//! \defgroup gCryptoHash 密码散列
//! \ingroup gCore
//!
//! \sa <https://wikipedia.org/wiki/Cryptographic_hash_function>
//! \sa <http://doc.qt.io/qt-5/qcryptographichash.html>
//!
//! \version 2018-07-05
//! \since 2016-11-15
//! \authors zhengrr
//! \copyright The MIT License
//!
//===----------------------------------------------------------------------===//

#include <gtest/gtest.h>

#include <QCryptographicHash>

//!
//! \brief 第四代消息摘要
//!        Message Digest 4
//! \details 摘要128位（32字节）。
//!
//! \deprecated 已发现碰撞。
//!
TEST(cryptohash, md4)
{
    ASSERT_STRCASEEQ(
        QCryptographicHash::hash("", QCryptographicHash::Md4).toHex(),
        "31d6cfe0d16ae931b73c59d7e0c089c0");
}

//!
//! \brief 第五代消息摘要
//!        Message Digest 5
//! \details 摘要128位（32字节）。
//!
//! \deprecated 已发现碰撞。
//!
TEST(cryptohash, md5)
{
    ASSERT_STRCASEEQ(
        QCryptographicHash::hash("", QCryptographicHash::Md5).toHex(),
        "d41d8cd98f00b204e9800998ecf8427e");
}

//!
//! \brief 第一代安全散列算法
//!        Secure Hash Algorithm 1
//! \details 摘要160位（40字节）。
//!
//! \deprecated 已发现碰撞。
//!
TEST(cryptohash, sha1)
{
    ASSERT_STRCASEEQ(
        QCryptographicHash::hash("", QCryptographicHash::Sha1).toHex().data(),
        "da39a3ee5e6b4b0d3255bfef95601890afd80709");
}

//!
//! \brief 第二代安全散列算法（224位）
//!        Secure Hash Algorithm 2 - 224bit
//! \details 摘要224位（56字节）。
//!
TEST(cryptohash, sha224)
{
    ASSERT_STRCASEEQ(
        QCryptographicHash::hash("", QCryptographicHash::Sha224).toHex().data(),
        "d14a028c2a3a2bc9476102bb288234c415a2b01f828ea62ac5b3e42f");
}

//!
//! \brief 第二代安全散列算法（256位）
//!        Secure Hash Algorithm 2 - 256bit
//! \details 摘要256位（64字节）。
//!
TEST(cryptohash, sha256)
{
    ASSERT_STRCASEEQ(
        QCryptographicHash::hash("", QCryptographicHash::Sha256).toHex().data(),
        "e3b0c44298fc1c149afbf4c8996fb924"
        "27ae41e4649b934ca495991b7852b855");
}

//!
//! \brief 第二代安全散列算法（384位）
//!        Secure Hash Algorithm 2 - 384bit
//! \details 摘要384位（96字节）。
//!
TEST(cryptohash, sha384)
{
    ASSERT_STRCASEEQ(
        QCryptographicHash::hash("", QCryptographicHash::Sha384).toHex().data(),
        "38b060a751ac96384cd9327eb1b1e36a"
        "21fdb71114be07434c0cc7bf63f6e1da"
        "274edebfe76f65fbd51ad2f14898b95b");
}

//!
//! \brief 第二代安全散列算法（512位）
//!        Secure Hash Algorithm 2 - 512bit
//! \details 摘要512位（128字节）。
//!
TEST(cryptohash, sha512)
{
    ASSERT_STRCASEEQ(
        QCryptographicHash::hash("", QCryptographicHash::Sha512).toHex().data(),
        "cf83e1357eefb8bdf1542850d66d8007"
        "d620e4050b5715dc83f4a921d36ce9ce"
        "47d0d13c5d85f2b0ff8318d2877eec2f"
        "63b931bd47417a81a538327af927da3e");
}

//!
//! \brief 第三代安全散列算法（224位）
//!        Secure Hash Algorithm 3 - 224bit
//! \details 摘要224位（56字节）。
//!
TEST(cryptohash, sha3_224)
{
    ASSERT_STRCASEEQ(
        QCryptographicHash::hash("", QCryptographicHash::Sha3_224).toHex().data(),
        "6b4e03423667dbb73b6e15454f0eb1abd4597f9a1b078e3f5b5a6bc7");
}

//!
//! \brief 第三代安全散列算法（256位）
//!        Secure Hash Algorithm 3 - 256bit
//! \details 摘要256位（64字节）。
//!
TEST(cryptohash, sha3_256)
{
    ASSERT_STRCASEEQ(
        QCryptographicHash::hash("", QCryptographicHash::Sha3_256).toHex().data(),
        "a7ffc6f8bf1ed76651c14756a061d662"
        "f580ff4de43b49fa82d80a4b80f8434a");
}

//!
//! \brief 第三代安全散列算法（384位）
//!        Secure Hash Algorithm 3 - 384bit
//! \details 摘要384位（96字节）。
//!
TEST(cryptohash, sha3_384)
{
    ASSERT_STRCASEEQ(
        QCryptographicHash::hash("", QCryptographicHash::Sha3_384).toHex().data(),
        "0c63a75b845e4f7d01107d852e4c2485"
        "c51a50aaaa94fc61995e71bbee983a2a"
        "c3713831264adb47fb6bd1e058d5f004");
}

//!
//! \brief 第三代安全散列算法（512位）
//!        Secure Hash Algorithm 3 - 512bit
//! \details 摘要512位（128字节）。
//!
TEST(cryptohash, sha3_512)
{
    ASSERT_STRCASEEQ(
        QCryptographicHash::hash("", QCryptographicHash::Sha3_512).toHex().data(),
        "a69f73cca23a9ac5c8b567dc185a756e"
        "97c982164fe25859e0d1dcc1475c80a6"
        "15b2123af1f5f94c11e3e9402c3ac558"
        "f500199d95b6d3e301758586281dcd26");
}
