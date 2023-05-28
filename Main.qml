/*
 * GridView test 01
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-28
 *
*/

//Main.qml


import QtQuick
import QtQuick.Controls



GridView {
    width: 400; height: 100

    model: ContactModel {} //4张图片  from ContactModel.qml

    delegate: Column { //how to display
        Image { source: portrait; anchors.horizontalCenter: parent.horizontalCenter }
        Text { text: name; anchors.horizontalCenter: parent.horizontalCenter }
    }
}
















