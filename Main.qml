/*
 *  Property Modifier Objects use test
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-26
 *
*/

//Main.qml

import QtQuick
import QtQuick.Controls


Item {
    width: 500
    height: 500

    Rectangle{
        width: 20
        height: 20
        color: "pink"

        NumberAnimation on x {
            from: 0
            to:300
            loops: Animation.Infinite
            duration: 2000
        }
        NumberAnimation on y {
            from: 0
            to:300
            loops: Animation.Infinite
            duration: 2000
        }
    }
}
















