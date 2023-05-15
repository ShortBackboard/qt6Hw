import QtQuick
import message

Window{
    visible: true; width: 400; height: 50
    title: qsTr("register an instantiable object type")

    Message{
        id:m;
        author: "lcy"
        creationDate: new Date()
    }

    Column{
        Text{ text: m.author; color: "red"}
        Text{ text: m.creationDate; color: "blue"}
    }
}
