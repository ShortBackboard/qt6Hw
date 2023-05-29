/*
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-29
 *
 *
*/

//Main.qml

import QtQuick
import QtQuick.Controls


Rectangle {
    width: 100
    height: 100
    color: "lightsteelblue"

    TapHandler {
        onTapped: console.log("left clicked")
        onLongPressed: console.log("long clicked")
        onDoubleTapped: console.log("double clicked")
    }

    TapHandler {
        acceptedButtons: Qt.RightButton
        onTapped: console.log("right clicked")
    }

}
