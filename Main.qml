/*
 *  signal handler attributes
 *
 *  Attached properties and ListView :example 02
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-28
 *
*/

//Main.qml


import QtQuick
import QtQuick.Controls

ListView{
    width: 240; height: 320
    model: 15
    currentIndex: 2; spacing: 2

    delegate: Rectangle{
        width: 100
        height: 30
        color:ListView.isCurrentItem ? "blue" : "green"
    }
}















