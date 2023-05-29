/*
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-29
 *
 *有几种 text 类型可供选择。

 TextInput 提供了一个无样式的单行可编辑文本

 TextField 更适合应用中的窗体区域

 TextEdit 可以处理多行可编辑的文本

 TextArea 是一个更好的选择,因为它添加了样式。

*
*/

//Main.qml

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


Item {
    width: 300
    height: 400
    ColumnLayout{
        anchors.fill: parent
        TextField{//singleline
            id:s1
            text: "s1 TextField"
            Layout.alignment: Qt.AlignHCenter
            Layout.margins: 5
            background: Rectangle{
                implicitWidth: 200
                implicitHeight: 40
                border.color: s1.focus ? "red":"lightgray"
                color: s1.focus ? "lightgrey":"transparent"
            }
        }

        TextField{
            id:s2
            text: "s2 TextField"
            Layout.alignment: Qt.AlignHCenter
            Layout.margins: 5
            background: Rectangle{
                implicitWidth: 200
                implicitHeight: 40
                border.color: s2.focus ? "red":"lightgray"
                color: s2.focus ? "lightgrey":"transparent"
            }
        }

        TextArea{
            id:multiline
            placeholderText: "<b>TextArea<\b> \n...\n...\n"//hint text
            Layout.alignment: Qt.AlignLeft
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: 5
            background: Rectangle{
                border.color: multiline.focus ? "red":"lightgray"
                color: multiline.focus ? "lightgrey":"transparent"
            }
        }

        TextInput{
            width: 200
            height: 40
            text: "single TextInput"
        }

        TextEdit{
            width: 200
            height: 40
            text: "<b>multiply TextInput</b>\n no style"
        }
    }
}
