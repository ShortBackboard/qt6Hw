import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    title: qsTr("setting a context property")
    Text {
        anchors.centerIn: parent
        text: p1//from main.cpp set
        color: "red"
    }
}
