/*
 *  signal handler attributes
 *
 *  信号的发射 - 手工指定
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
    width: 200; height: 200

    Grey{
        id:grey
        Text { id:show }

        onHeightChanged: activated(2,2) //拥有信号的对象发射信号

        //信号的定义以及添加信号处理的内容
        onActivated: (x,y)=>{
                         show.text = qsTr("clicked at("+x+","+y+")")
                         console.log("Main.qml: Activated at "+x+","+y)
                     }
    }

    Rectangle{
        anchors.bottom: parent.bottom
        color: "LightBlue";width: 200;height: 60;radius: 10
        TapHandler{
            onTapped: (eventPoint)=>
                      grey.activated(eventPoint.position.x,
                                eventPoint.position.y)   //在其他对象中发射信号

            onLongPressed: {
                grey.width=100  //在其他对象中发射信号,改变宽度事件发射信号
            }
        }
    }
}















