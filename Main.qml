/*
 * A program : 匿名组件
 *
 * anthor:2019051604044liChengYang
 * date:2023-5-13
 *
 * 匿名组件的定义用于支持:在一个 document 中重用一个小的组件,
或者定义一个逻辑上属于该 document 的组件。
 *
 * 可通过其唯一需要定义的 id 来引用
 *
 * 使用TapHandler事件处理与Loader的id的关联，使匿名组件点击后才被Loader动态创建显示
*/

import QtQuick

Item {

    width: 150; height: 150

    //该匿名组件直到请求时才会被加载并实例化 ( 如将 id 指定给 2 个 Loader对象的 sourceComponent )
    Component {
        id: redSquare

        Rectangle {
            color: "red"
            width: 50
            height: 50
        }
    }

//    Loader { sourceComponent: redSquare}
//    Loader { sourceComponent: redSquare; x:100}

    Loader { id : newLoader}


    TapHandler{//事件处理对象
        onTapped: {
            newLoader.sourceComponent = redSquare
        }
    }

}
