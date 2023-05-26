/*
 *  test in PPT
 *
 *  id Attribute use test
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-26
 *
*/

//Main.qml
import QtQuick 2.0




Column{
    width: 200
    height: 200

    TextInput{//Displays an editable line of text
        id:input;text: "hello,world"
    }

    Text {
        text: input.text
    }

    TextEdit{
        width: 100
        height: 20
        color: "green"
    }
}















