//MyButton.qml


import QtQuick
import QtQuick.Controls
import "my_button_impl.js" as Logic //A new instance of this JavaScript resource
                                    //is loaded for each instance of MyButton.qml

Rectangle{
    id:rect
    width: 200
    height: 100
    color: "red"

    TapHandler{
        id:mousearea
        onTapped: {
            Logic.onClicked(rect)
            console.log(Logic.clickCount)
        }
    }
}




















