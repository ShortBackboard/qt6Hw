//Grey.qml

import QtQuick

Rectangle{
    //信号的声明
    signal activated(real xPosition, real yPosition)
    signal deactivated



    //信号的定义
    onActivated: (x,y)=>{
                     console.log("Grey.qml: Activated at "+x+","+y)
                 }

    onDeactivated: console.log("Deactivated!")



    width: 200
    height: 80
    radius: 10  //圆角
    color: "LightGrey"

    onWidthChanged: activated(1,1)  //拥有信号的对象发射信号

    TapHandler{
        onTapped: (eventPoint)=>
                    activated(eventPoint.position.x,
                              eventPoint.position.y)   //在其他对象中发射信号

        onLongPressed: deactivated()
    }
}
