/*
 *  Loader QML 类型
 *  Loader: dynamically load example02: loader and destroy
 * 动态加载对象的访问和销毁
 *
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
    width: 300
    height: 200

    Component{
        id:redSquare
        Rectangle{
            color:"red"
            width: 50
            height: 50
        }
    }

    Loader{id:l1;sourceComponent: redSquare}
    Loader{id:l2;source:"MyLabel.qml";x:100}

    TapHandler{
        onTapped: {
//            item property 容纳了当前加载对象的顶层对象。
            l1.sourceComponent = undefined
            l2.source = ""

            l1.source = "MyLabel.qml"
            l2.sourceComponent = redSquare

            l2.item.x = 60
            l2.item.color = "blue"
        }
    }

}












