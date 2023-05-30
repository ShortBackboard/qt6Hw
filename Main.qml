/*
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-30
 *
 *
*/

//Main.qml

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle{
    id:r; width: 400;height: 200
    Rectangle{
        id:sig; width: 200; height: 100; state: "NORMAL"
        states: [
            State {
                name: "NORMAL"
                PropertyChanges {sig{color:"green";width:200}}
            },
            State {
                name: "CRITICAL"
                PropertyChanges {sig{color:"red";width:sig.height}}
                PropertyChanges {taph.onLongPressed: console.log("override")}
            }
        ]

        TapHandler{
            id:taph
            onTapped: sig.state === "NORMAL" ? sig.state = "CRITICAL" : sig.state = "NORMAL"
            onLongPressed: console.log("origin")
        }
    }
}














