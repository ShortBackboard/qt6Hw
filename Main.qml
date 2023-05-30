/*
 *
 * anthor:2019051604044liChengYang
 *
 *
 * date:2023-5-30
 *
 *
*/

//Main.qml

import QtQuick
import QtQuick.Controls


Image {
    width: 384; height: 1024
    source: "background.jpg"

    TapHandler{
        onTapped: anim.start();//点击运行
    }

    SequentialAnimation{//顺序执行
        id:anim
        ScriptAction{script: image.goalSprite = "falling"}
//        设置 goalSprite
//        将导致它忽略任何路径权重 ( 包括 0) ,并且朝着最快到达 goalSprite
//        的路径前进 ( 最少的动画 ) 。它将通过该路径上的中间状态,并在其
//        持续时间内动画它们。

        NumberAnimation{target: image; property: "y"; to:480; duration: 12000;}//向下落下
        ScriptAction{script: {image.goalSprite = ""; image.jumpTo("still");}}//落下后站立
        PropertyAction{target: image; property: "y"; value: 0}//返回到顶部
    }

    SpriteSequence {//顺序
        id:image; width:256; height:256;
        anchors.horizontalCenter: parent.horizontalCenter

        Sprite{//第一个为初始状态
            name:"still"; source: "BearSheet.png"
            frameCount: 1;frameWidth: 256; frameHeight: 256; frameDuration: 100
            to:{"still":1, "blink":0.1, "floating":0}//权重
        }

        Sprite{
            name:"blink"; source: "BearSheet.png"
            frameCount: 3; frameX:256; frameY: 1536; frameWidth: 256; frameHeight: 256; frameDuration: 100
            to:{"still":1}
        }

        Sprite{
            name:"floating"; source: "BearSheet.png"
            frameCount: 9; frameX:0; frameY: 0; frameWidth: 256; frameHeight: 256; frameDuration: 160
            to:{"still":0, "flailing":1}
        }

        Sprite{
            name:"flailing"; source: "BearSheet.png"
            frameCount: 8; frameX:0; frameY: 768; frameWidth: 256; frameHeight: 256; frameDuration: 160
            to:{"falling":1}
        }

        Sprite{
            name:"falling"; source: "BearSheet.png"
            frameCount: 5; frameX:0; frameY: 1280; frameWidth: 256; frameHeight: 256; frameDuration: 160
            to:{"falling":1}
        }
    }
}
















