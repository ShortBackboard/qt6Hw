/*
 *  Loader QML 类型
 *
 *  动态加载:
 * 加载一个 QML document 文件 ( 使用 source 特性 )
   加载一个 Component 对象 ( 使用 sourceComponent 特性 )
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
            l1.item.color = "blue"
            l1.item.width = 100
            l1.item.height = 100

            l2.item.font.bold = true
        }
    }

}












