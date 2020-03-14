import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

//import TestQML 1.0

import Pkgs 1.0

import "test.js" as My

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    Button {
        text: "BUTTON1"
        onClicked: My.t(root)
        function createItem() {
            Qt.createQmlObject("import QtQuick 2.5; Rectangle { x: 100; y: 100; width: 100; height: 100; color: \"blue\" }", root, "dynamicItem");
        }
    }
    Button {
        x: 100
        text: "BUTTON2"
        onClicked: testQML.t2();
//        onClicked: testQML.t3();
    }

    Button {
        x: 200
        text: "BUTTON3"
        onClicked: myObject.test();
//        onClicked: testQML.t3();
    }
    Button {
        x: 300
        id: b4
        text: "BUTTON4"
        onClicked: myObject
//        onClicked: testQML.t3();
    }
    Button {
        x: 400
        text: "BUTTON5"
        onClicked: testQML.t3(b4)
//        onClicked: testQML.t3();
    }
    Button {
        x: 500
        text: "BUTTON6"
        onClicked: testQML.t4(b4)
    }
    Button {
        y: 50
        text: "BUTTON7"
//        onClicked: console.log(testQML.t5("b4"))
        onClicked: Qt.createQmlObject (testQML.t5("b4"), root, "dynamicItem");
//        onClicked: Qt.createQmlObject("import QtQuick 2.5; Rectangle { x: 100; y: 100; width: 100; height: 100; color: \"red\" }", root, "dynamicItem")
    }
    Button {
        x:100
        y: 50

        property Pkgs t: Qqq{}
//        property Pkg t1: t.pkg(1)

        text: "t[1].dir"
//        onClicked: console.log(testQML.t5("b4"))
        onClicked: {
            var a = testQML.t6(root);
            console.log("cat a = ", a)
        }
//        onClicked: Qt.createQmlObject("import QtQuick 2.5; Rectangle { x: 100; y: 100; width: 100; height: 100; color: \"red\" }", root, "dynamicItem")
        Component.onCompleted: {
//            console.log(t.rowCount())
//            for (var i = 0; i < t.rowCount(); t++)
//                console.log(i)
////                console.log(i + ": " + t.pkg(i).name)
//            console.log(t1.name)
//            t.clearPkg();
//            console.log(t.rowCount())
        }
    }
    Button {
        x: 200
        y: 50
        text: "init"
        onClicked: testQML.init(ss)
    }
    Button {
        x: 300
        y: 50
        text: "INSTALL"
        onClicked: testQML.install()
    }
    Button {
        x: 400
        y: 50
        text: "INSTALL2"
        onClicked: testQML.install2()
    }
    Button {
        x: 500
        y: 50
        text: "init2"
        onClicked: testQML.init2(ss)
    }

    Rectangle
    {
      id:ss
      x: 300
      y: 150
      width: 200;
      height: 200;
      color: "#bb6262"
    }


}
