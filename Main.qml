/*
 *
 *  completed() 和 destruction() 的示例
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-28
 *
*/

//Main.qml


import QtQuick
import QtQuick.Controls

Rectangle{
    Component.onCompleted: console.log("Parent Completed")
    Component.onDestruction: console.log("Parent Destruction")

    Rectangle{
        Component.onCompleted: console.log("Child Completed")
        Component.onDestruction: console.log("Child Destruction")
    }
}












