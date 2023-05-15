import QtQuick

Row {
//    property LabeledImage selectedImage: before

    //有名内部组件:LabeledImage
    component LabeledImage: Column{
        property alias source: image.source
        property alias caption: text.text

        spacing: 5
        Image { id: image; width: 50; height: 50}
        Text { id: text; font.bold: true; color:"royalblue"}
    }

//    LabeledImage { id:before; source: "back.png"; caption: "Back"}
//    LabeledImage { id:after; source: "forward.png"; caption: "Forward"}
}
