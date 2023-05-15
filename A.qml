import QtQuick 2.15

Item {
    id:root
    property Component mycomponent: myType
    property string message: "From A"
    Component {
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
