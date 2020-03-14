#include "Pkg2.h"
#include "Pkgs2.h"
#include "TestQML.h"

#include <QQmlContext>
#include <QQuickView>


TestQML::TestQML()
    : QObject(nullptr)
{

}

void TestQML::t2() {
    qInfo() << "Q_INVOKABLE void t2()";
}

void TestQML::t3(QQuickItem *comp) {
    qInfo() << __LINE__ << "Q_INVOKABLE void t3()";
    qInfo() << comp;

    //        QQmlEngine *engine = comp->engine();
    //Qt.createQmlObject("import QtQuick 2.5; Rectangle { x: 100; y: 100; width: 100; height: 100; color: \"blue\" }", root, "dynamicItem");
    //QQmlComponent comp;
    //        comp->loadUrl("/tmp/main2.qml");
    //        comp->create("import QtQuick 2.5; Rectangle { x: 100; y: 100; width: 100; height: 100; color: \"blue\" }");
    //        comp->setData("import QtQuick 1.0; Rectangle {color: \"red\"; width: 20; height: 20}", QUrl("dynamicPath"));
    qInfo() << __LINE__ << "Q_INVOKABLE void t3()";
    qInfo() << engine;
    //        engine->
    //        comp->create();
}

void TestQML::t4(QQuickItem *comp) {
    qInfo() << __LINE__ << "Q_INVOKABLE void t3()";
    qInfo() << comp;

    //                QQmlEngine *engine = comp->engine();
    //Qt.createQmlObject("import QtQuick 2.5; Rectangle { x: 100; y: 100; width: 100; height: 100; color: \"blue\" }", root, "dynamicItem");
    QQmlComponent *ncomp = new QQmlComponent(comp);
    qInfo() << ncomp->parent();
    //        ncomp->loadUrl(QUrl("/tmp/main2.qml"));
    //        comp->create("import QtQuick 2.5; Rectangle { x: 100; y: 100; width: 100; height: 100; color: \"blue\" }");
    //        comp->setData("import QtQuick 1.0; Rectangle {color: \"red\"; width: 20; height: 20}", QUrl("dynamicPath"));
    qInfo() << __LINE__ << "Q_INVOKABLE void t3()";
    qInfo() << engine;
    //        engine->
    //        comp->create();
}

QString TestQML::t5(QString str) {
    //        qInfo() << str; return "ss";

    if (str == "b4")
        return "import QtQuick 2.5; Rectangle { x: 100; y: 100; width: 100; height: 100; color: \"blue\" }";

    return "import QtQuick 2.5; Rectangle { x: 100; y: 100; width: 100; height: 100; color: \"red\" }";
}

void TestQML::t6(QObject *comp) {
    qInfo() << __LINE__ << engine;
    QQmlComponent *q = new QQmlComponent(engine,
                                         "/tmp/main2.qml",
                                         comp);
    qInfo() << __LINE__ << q;
    QObject*a = q->create();
    qInfo() << __LINE__ << q;
    qInfo() << __LINE__ << a;
    q->setParent(comp);
    qInfo() << __LINE__ << q;
}

void TestQML::init(QQuickItem *comp)
{
    qInfo() << __LINE__ << comp;
    //        QQmlEngine *engine = qmlEngine(this);
    // Or:
    // QQmlEngine *engine = qmlContext(this)->engine();
    QQmlComponent component(engine, QUrl::fromLocalFile("/tmp/main2.qml"));
    QQuickItem *childItem = qobject_cast<QQuickItem*>(component.create());
//    qInfo() << __LINE__ << childItem;
    childItem->setParentItem(comp);
}

void TestQML::init2(QQuickItem *comp)
{
    QString qml;// = "import QtQuick 2.0; Item{}";
    QQmlComponent component(engine);
    QFile f("/tmp/main2.qml");
    if (f.open(QIODevice::ReadOnly)){
        qml = f.readAll();
        qInfo() << "qml: " + qml;
        f.close();
    }


    qInfo() << qml;

    component.setData(qml.toUtf8(), QUrl());
    QQuickItem *childItem = qobject_cast<QQuickItem*>(component.create());
    childItem->setParentItem(comp);
}

void TestQML::install()
{
    QString qml = "import Pkgs 1.0\n"
        "Pkgs {\n"
        "Pkg {\n"
            "name: 'TestPkgs'\n"
            "color: 'green'\n"
            "dir: \"ss\"\n"
        "}\n"
        "Pkg {\n"
        "name: \"TestPkgs2111\"\n"
                "color: 'green'\n"
                        "dir: 'ss'\n"
        "}\n"
    "}\n";
    QQmlComponent component(engine, QUrl::fromLocalFile("/tmp/install.qml"));
//    QQmlComponent component(engine, qml);
    Pkgs2*a = qobject_cast<Pkgs2*>(component.create());
    int i = a->pkgCount();
    qInfo() << "i:" << i;
    qInfo() << a->pkg(1)->getName();
    delete a;
}

#include <QFile>
void TestQML::install2()
{
    QString qml = "import Pkgs 1.0\n"
                  "Pkgs {\n"
                  "Pkg {\n"
                  "name: 'TestPkgs'\n"
                  "color: 'green'\n"
                  "dir: \"ss\"\n"
                  "}\n"
                  "Pkg {\n"
                  "name: \"TestPkgs2222222222229999999111\"\n"
                  "color: 'green'\n"
                  "dir: 'ss'\n"
                  "}\n"
                  "}\n";
    QQmlComponent component(engine);
    QFile f("/tmp/install.qml");
    if (f.open(QIODevice::ReadOnly)){
        qml = f.readAll();
        qInfo() << "qml: " + qml;
        f.close();
    }
//    QQmlContext *context = new QQmlContext(engine->rootContext());
    component.setData(qml.toUtf8(), QUrl());
    Pkgs2*a = qobject_cast<Pkgs2*>(component.create());
    qInfo() << a->pkg(1)->getName();

//    component.
//    Pkgs2*a = qobject_cast<Pkgs2*>(component.create(qml));
//    QQmlContext *ctx = new QQmlContext();

//    int i = a->pkgCount();
//    qInfo() << "i:" << i;
//    qInfo() << a->pkg(1)->getName();
}

