//MyItem.qml

import QtQuick

Rectangle{
    id:root
    //信号的声明
    signal message(string msg)

    width: 100
    height: 100
    color:"red"

    TapHandler{
        onTapped: root.message("clicked from MyItem.qml")
    }
}
