#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Pkg2.h"
#include "Pkgs2.h"

#include "TestQML.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);



    QQmlApplicationEngine engine;

    qmlRegisterType<TestQML>("TestQML", 1,0, "TestQML");
    TestQML testQML;
    testQML.setEngine(&engine);
//    testQML.t2();
    engine.rootContext()->setContextProperty("testQML", &testQML);

    qmlRegisterType<Pkg2>("Pkgs", 1,0, "Pkg");
    qmlRegisterType<Pkgs2>("Pkgs", 1,0, "Pkgs");


    QQmlComponent component(&engine, QUrl::fromLocalFile("/tmp/main.qml"));
    QObject *myObject = component.create();
    engine.rootContext()->setContextProperty("myObject", myObject);

//        "testQML", testQML);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
