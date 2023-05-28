/*
 * 任何被加载对象发射的信号都可以使用 Connections 类型进行接收。
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
    Loader{
        id:myLoader
        source: "MyItem.qml"
    }

    Connections{
        target: myLoader.item

        //信号的定义
        function onMessage(m:string){
            console.log(m)
        }
    }
}













