/*
 *  signal handler attributes
 *
 *  手工连接信号 - 使用 connect 函数
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-28
 *
*/

//Main.qml


import QtQuick
import QtQuick.Controls

Rectangle{
    width: 200
    height: 200

    //信号的声明
    signal send()

    //信号的定义
    onSend: console.log("signal: Send clicked")

    //自定义方法
    function say() {
        console.log("function: say()")
    }

    //使用信号对象的 disconnect() 函数可以解除与信号处理的连接
    //自定义方法,用于 disconnect
    function removeSay() {
        mousearea.clicked.disconnect(say)
    }

    MouseArea {
        id:mousearea
        anchors.fill: parent
        onClicked: console.log("MouseArea clicked")
    }

    Component.onCompleted: {
//        QML 的信号对象还提供了 connect() 函数,支持将信号与一个方法或
//        者另外的信号连接起来。

//        鼠标点击事件信号连接另外的信号
        mousearea.clicked.connect(send)

//        鼠标点击事件信号连接另外的方法
        mousearea.clicked.connect(say)

//        使用信号对象的 disconnect() 函数可以解除与信号或方法处理的连接
//        mousearea.clicked.connect(removeSay())
    }
}















