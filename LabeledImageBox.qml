import QtQuick

Rectangle {
    property alias source: labelImage.source
    property alias caption: labelImage.caption

    border.width: 2;width: 100; height: 100
    border.color: "royalblue"

    //在其他文件中,必须使用它所在组件的名字作为前缀。
    // @disable-check M300
    Images.LabeledImage{//使用其他文件中的有名内部组件
        id:labelImage
        anchors.centerIn: parent
    }

}
