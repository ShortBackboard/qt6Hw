/*
 *  signal handler attributes
 *
 *  Attached properties and ListView :example 03
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-28
 *
*/

//Main.qml


import QtQuick
import QtQuick.Controls

ListView{//ListView 类型有一个 attached property: isCurrentItem
    width: 240; height: 320
    spacing: 2

    model: ListModel{//数量
        id:lm
        Component.onCompleted: {
            lm.append({"name":"A"});
            lm.append({"name":"B"});
            lm.append({"name":"C"});
            lm.append({"name":"D"});
            lm.append({"name":"E"});
            lm.append({"name":"F"});
        }
    }

    delegate:Text {//如何显示
        width: 240; height: 30
        color: ListView.isCurrentItem ? "red":"black"
        text:name

        TapHandler{
           onTapped: {
               currentIndex = index
           }
        }
    }

    highlight: Rectangle{color:"lightgrey"}
}














