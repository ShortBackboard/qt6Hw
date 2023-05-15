/*
 *  A program: 使用自定义模块以及不同版本的导入
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-14
 *
*/


import QtQuick 2.15 as Project
import se.qt.mymodule 1 as Project
//import se.qt.mymodule 2 as Project
//import se.qt.mymodule 2.1 as Project



Project.Column{
    spacing: 2

    Project.MyTextConstants{id:constants}
    Project.MyClock{}
    Project.MyTextBox{id:textBox}
    Project.MyButton{
        text: qsTr("OK")
        onClicked: {
            textBox.textColor = "red"
            textBox.text = constants.welcomeText.arg(textBox.text)
            textBox.width = 200
        }
    }
}














