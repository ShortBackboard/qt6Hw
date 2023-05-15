import QtQuick 2.15
//匿名组件环境的创建环境
Item {
    id:root
    property Component mycomponent: myType
    property string message: "From A"
    Component{
        id:myType
        Rectangle{
            width: 50
            height: 20
            color: "blue"
            Component.onCompleted:
                console.log(root.message)
        }
    }
}
