import QtQuick 2.15

Item {
    id:root

    property string message: "From A"
    component MyType : Rectangle{//有名内部组件
            width: 50
            height: 20
            color: "blue"
            Component.onCompleted:
                console.log(root.message)
    }
}
