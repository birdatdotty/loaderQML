
function t(root) {
    console.log("Function t()");

    Qt.createQmlObject (
                "import QtQuick 2.5;" +
                " Rectangle { " +
                " x: 100; y: 100;" +
                " width: 100;" +
                " height: 200;" +
                " color: \"blue\"" +
                "}", root, "dynamicItem");
}
