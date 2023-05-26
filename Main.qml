/*
 *  signal handler attributes
 *
 * anthor:2019051604044liChengYang
 *
 * date:2023-5-26
 *
*/

//Main.qml


import QtQuick
import QtQuick.Controls

Rectangle{
    width: 200
    height: 200
    TapHandler{
        onTapped: (handlerPoint)=>{
                      console.log(handlerPoint.position.x,
                                  handlerPoint.position.y)
                  }
    }
}
















