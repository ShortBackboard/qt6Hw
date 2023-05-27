/*
 *  signal handler attributes
 *
 *
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-27
 *
*/

//Main.qml


import QtQuick
import QtQuick.Controls

Rectangle{
    id:rect
    width: 200
    height: 200
    Button{
        id:button
        anchors.centerIn: parent
        text: "change color"
    }

    Connections{
        target: button
        function onClicked(){
            rect.color = Qt.rgba(Math.random(),
                                 Math.random(),
                                 Math.random(),
                                 1)
        }
    }
}













