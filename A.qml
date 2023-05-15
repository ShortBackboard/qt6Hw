import QtQuick 2.15
//inline 组件环境的创建环境
Item {
    id:root
    property Component mycomponent: MyType{}
    property string message: "From A"
    component MyType : Rectangle{//有名内部组件
            width: 50
            height: 20
            color: "blue"
            Component.onCompleted:
                console.log(root.message)
    }
}
