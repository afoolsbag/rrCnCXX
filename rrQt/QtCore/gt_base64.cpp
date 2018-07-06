//===-- Base64 --------------------------------------------------*- C++ -*-===//
//!
//! \defgroup gBase64 Base64
//! \ingroup gCore
//!
//! \sa <https://wikipedia.org/wiki/Base64>
//! \sa <https://doc.qt.io/qt-5/qbytearray.html>
//!
//! \version 2018-07-06
//! \since 2016-12-08
//! \authors zhengrr
//! \copyright The MIT License
//!
//===----------------------------------------------------------------------===//

#include <gtest/gtest.h>

#include <QtCore/QString>

//!
//! \brief 标准的Base64转换。
//!
TEST(base64, toBase64)
{
    QByteArray raw {"<p>Hello?</p>"};
    ASSERT_STRCASEEQ(
        raw.toBase64(),
        "PHA+SGVsbG8/PC9wPg==");
}

//!
//! \brief 忽略尾部`=`的Base64转换。
//!
TEST(base64, toBase64Omit)
{
    QByteArray raw {"<p>Hello?</p>"};
    ASSERT_STRCASEEQ(
        raw.toBase64(QByteArray::OmitTrailingEquals),
        "PHA+SGVsbG8/PC9wPg");
}

//!
//! \brief 适配URL的Base64转换。
//! \details 将`+`替换为`-`、`/`替换为`_`。
//!
TEST(base64, toBase64Url)
{
    QByteArray raw {"<p>Hello?</p>"};
    ASSERT_STRCASEEQ(
        raw.toBase64(QByteArray::Base64UrlEncoding),
        "PHA-SGVsbG8_PC9wPg==");
}

//!
//! \brief 适配URL且忽略尾部`=`的Base64转换。
//!
TEST(base64, toBase64UrlOmit)
{
    QByteArray raw {"<p>Hello?</p>"};
    ASSERT_STRCASEEQ(
        raw.toBase64(QByteArray::Base64UrlEncoding | QByteArray::OmitTrailingEquals),
        "PHA-SGVsbG8_PC9wPg");
}
