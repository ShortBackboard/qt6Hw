/*
 *
 * anthor:2019051604044liChengYang
 *
 *
 * date:2023-5-30
 *
 *
*/

//Main.qml

import QtQuick
import QtQuick.Controls

Item{
    width: 200; height: 200
    Rectangle{
        id:mix; width: 100; height: 100; color:"green"
        ParallelAnimation{

            ColorAnimation {
                target: mix
                property: "color"
                from: "green"
                to: "steelblue"
                duration: 2000
            }

            ScaleAnimator{//缩放
                target:mix
                from: 1; to:3; duration: 10000
            }

            running: true
        }

    }
}

















