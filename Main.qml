/*
 *  signal handler attributes
 *
 *  Attached properties example 01
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-28
 *
*/

//Main.qml


import QtQuick
import QtQuick.Controls

Item {
    width: 200; height: 200

    focus: true
    Keys.enabled: true //enables key handling
    Keys.onDigit0Pressed: console.log("Digit0 clicked")


}















