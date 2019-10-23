// All QML Modules              https://doc.qt.io/qt-5/modules-qml.html
import QtQuick 2.13           // Qt Quick QML Types           https://doc.qt.io/qt-5/qtquick-qmlmodule.html
import QtQuick.Window 2.13    // Qt Quick Window QML Types    https://doc.qt.io/qt-5/qtquick-window-qmlmodule.html
import QtQuick.Controls 2.13  // Qt Quick Controls QML Types  https://doc.qt.io/qt-5/qtquick-controls2-qmlmodule.html
import QtQuick.Layouts 1.13   // Qt Quick Layouts QML Types   https://doc.qt.io/qt-5/qtquick-layouts-qmlmodule.html

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("hello, world")


    GridLayout {
        id: rowLayout
        anchors.fill: parent

        Button {
            id: button
            text: qsTr("hello, world")
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            onClicked: console.log("hello, world");
        }
    }

}
