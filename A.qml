import QtQuick 2.15

Item {
    id:root
    property Component mycomponent: MyType{}
    property string message: "From A"
    component MyType:Rectangle{
            width: 50
            height: 20
            color: "blue"
            Component.onCompleted:
                console.log(root.message)
    }

}
