/** \file
 *  \sa <http://doc.qt.io/qt-5/qcryptographichash.html>
 *  \author zhengrr
 *  \date 2016-11-15 – 12-8
 *  \copyright The MIT License
 */
#include <QCryptographicHash>

namespace {
int Main(int argc, char *argv[])
{
    QByteArray data;
    if (2 <= argc)
        data = argv[2 - 1];
    else
        data = "1337";

    QCryptographicHash md4parser(QCryptographicHash::Md4);
    QCryptographicHash md5parser(QCryptographicHash::Md5);
    QCryptographicHash sha1parser(QCryptographicHash::Sha1);
    QCryptographicHash sha224parser(QCryptographicHash::Sha224);
    QCryptographicHash sha256parser(QCryptographicHash::Sha256);
    QCryptographicHash sha384parser(QCryptographicHash::Sha384);
    QCryptographicHash sha512parser(QCryptographicHash::Sha512);
    QCryptographicHash sha3224parser(QCryptographicHash::Sha3_224);
    QCryptographicHash sha3256parser(QCryptographicHash::Sha3_256);
    QCryptographicHash sha3384parser(QCryptographicHash::Sha3_384);
    QCryptographicHash sha3512parser(QCryptographicHash::Sha3_512);

    md4parser.addData(data);
    md5parser.addData(data);
    sha1parser.addData(data);
    sha224parser.addData(data);
    sha256parser.addData(data);
    sha384parser.addData(data);
    sha512parser.addData(data);
    sha3224parser.addData(data);
    sha3256parser.addData(data);
    sha3384parser.addData(data);
    sha3512parser.addData(data);

    qInfo("Input: %s", data.data());
    qInfo("MD4: %s", md4parser.result().toHex().toUpper().data());
    qInfo("MD5: %s", md5parser.result().toHex().toUpper().data());
    qInfo("SHA1: %s", sha1parser.result().toHex().toUpper().data());
    qInfo("SHA2-224: %s", sha224parser.result().toHex().toUpper().data());
    qInfo("SHA2-256: %s", sha256parser.result().toHex().toUpper().data());
    qInfo("SHA2-384: %s", sha384parser.result().toHex().toUpper().data());
    qInfo("SHA2-512: %s", sha512parser.result().toHex().toUpper().data());
    qInfo("SHA3-224: %s", sha3224parser.result().toHex().toUpper().data());
    qInfo("SHA3-256: %s", sha3256parser.result().toHex().toUpper().data());
    qInfo("SHA3-384: %s", sha3384parser.result().toHex().toUpper().data());
    qInfo("SHA3-512: %s", sha3512parser.result().toHex().toUpper().data());

    return EXIT_SUCCESS;
}
}// namespace

#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return Main(argc, argv); }
#endif// ENTRY SWITCH
