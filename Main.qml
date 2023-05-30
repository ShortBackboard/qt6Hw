/*
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-30
 *
 *
*/

//Main.qml

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

GroupBox {
    id:gridBox
    title: "Grid Layout"
    Layout.fillWidth:true

    GridLayout{
        id:gridLayout
        rows:3
        flow:GridLayout.TopToBottom
        anchors.fill: parent
        Label{text:"Line 1"}
        Label{text:"Line 2"}
        Label{text:"Line 3"}

        TextField{} TextField{} TextField{}
        TextField{} TextField{} TextField{}

        TextArea{
            text: "This widget spans over 3 rows in the GridLayout.\n"
                +"All items in the GridLayout are implicitly positioned from top to bottom";
            Layout.rowSpan: 3
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}














