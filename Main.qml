/*
 *
 * anthor:2019051604044liChengYang
 *
 *  States and Transitions 示例
 *
 * date:2023-5-30
 *
 *
*/

//Main.qml

import QtQuick
import QtQuick.Controls


Item{
    id:root; width: 260; height: 50

    Rectangle{
        id:slot; x:15; y:7; height: 36; width: 230; radius: 20; color:"grey"
        TapHandler{onTapped: root.state === "" ? root.state = "on" : root.state = ""}
    }

    Rectangle{
        id:ball; radius: 50; width: 50; height: 50;
        gradient: Gradient{
            GradientStop {position: 0.0; color: "red"}
            GradientStop {position: 0.5; color: "yellow"}
            GradientStop {position: 1.0; color: "green"}
        }
    }

    states:[
        State {
            name:"on"
            PropertyChanges {ball.x: 210}
            PropertyChanges {slot.color: "black"}
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "on"
            NumberAnimation{properties: "x,y"; duration: 3000}
            ColorAnimation {properties: "color"; duration: 5000}
        }
    ]
}















