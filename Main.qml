/*
 *  State use test.
 *
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-26
 *
*/

//Main.qml

import QtQuick
import QtQuick.Controls

Rectangle {
    id: myRect
    width: 100; height: 100
    state: "released"   //默认state为空 ' '

    TapHandler{
        onTapped:myRect.state === "clicked" ? myRect.state = "released" : myRect.state = "clicked";
    }


    states: [
        State {
            name: "clicked" //点击
            PropertyChanges { target: myRect; color: "red" }
        },

        State {
            name: "released" //释放
            PropertyChanges {target: myRect; color:"blue"}
        }
    ]
}















