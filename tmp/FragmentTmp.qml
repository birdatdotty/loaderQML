    import QtQuick 2.5
     
    Rectangle {
        anchors.fill: parent
        color: "green"
     
        Text {
            text: "Fragment /tmp"
            color: "white"
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.margins: 50
            font.pixelSize: 30
     
            renderType: Text.NativeRendering
        }
     
    }
