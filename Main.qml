/*
 *
 *  enumeration attributes
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-28
 *
*/

//Main.qml


import QtQuick
import QtQuick.Controls

Text {
    width: 200
    height: 200
    text: qsTr("text")

//    枚举类型和值必须以大写字母开头
    enum TextTpye{//枚举类型
        Normal, //0
        Heading //1
    }

    property int textType: Main.Normal  //引用枚举类型 Main.qml

    font.bold: textType === Main.Heading    //false
//    font.bold: textType === 1    //false
    font.pixelSize: textType === Main.Heading ? 24:12   //false
}













