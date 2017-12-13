/** \file
 *  \sa <http://doc.qt.io/qt-5/qbytearray.html>
 *  \author zhengrr
 *  \date 2016-12-8
 *  \copyright The MIT License
 */
#include <QString>

namespace {
int Main(int argc, char *argv[])
{
    QByteArray raw;
    if (2 <= argc)
        raw = argv[2 - 1];
    else
        raw = "1337";

    qInfo("Encode %s to Base64: %s",
          raw.data(), raw.toBase64().data());
    qInfo("Decode %s from Base64: %s",
          raw.data(), QByteArray::fromBase64(raw).data());
    return EXIT_SUCCESS;
}
}// namespace
#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return Main(argc, argv); }
#endif// ENTRY SWITCH
