/*
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-29
 *
 * 对于简单的按键处理,您可以将某个 item 的 focus 设置为 true ,并在
其中执行所有的按键处理。
 *
*/

//Main.qml

import QtQuick
import QtQuick.Controls


Rectangle {

    width: 400;height: 200;
    color: "#272822"

    Rectangle{
        id:r
        width: 20
        height: 20
        color: "blue"

        focus: true
        Keys.onUpPressed: r.y -=10
        Keys.onDownPressed: r.y +=10
        Keys.onLeftPressed: r.x -=10
        Keys.onRightPressed: r.x +=10
    }


}
