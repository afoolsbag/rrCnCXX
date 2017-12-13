/** \file
 *  \sa <http://doc.qt.io/qt-5/qsettings.html>
 *  \author zhengrr
 *  \date 2016-2-14 – 11-15
 *  \copyright The MIT License
 */
#include <QSettings>

namespace {
int altmain(int, char *[])
{
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.sync();
    settings.setValue("category/item",
                      settings.value("category/item", 0).toInt() + 1);
    settings.sync();

    return EXIT_SUCCESS;
}
}// namespace

#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return altmain(argc, argv); }
#endif// ENTRY SWITC
