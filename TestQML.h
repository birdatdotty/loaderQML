#ifndef TESTQML_H
#define TESTQML_H

#include <QObject>
#include <QDebug>
#include <QQmlComponent>
#include <QQuickItem>

#include <QQuickView>

class TestQML : public QObject
{
    Q_OBJECT
public:
    explicit TestQML();
    Q_INVOKABLE void t2();
    Q_INVOKABLE void t3(QQuickItem  *comp);
    Q_INVOKABLE void t4(QQuickItem  *comp);
    Q_INVOKABLE QString t5(QString str);
    Q_INVOKABLE void t6(QObject* comp);
    Q_INVOKABLE void init(QQuickItem* comp);
    Q_INVOKABLE void init2(QQuickItem* comp);
    Q_INVOKABLE void install();
    Q_INVOKABLE void install2();

    void setEngine(QQmlEngine* newEngine) {engine = newEngine;}

signals:

private:
  QQmlEngine *engine;


};

#endif // TESTQML_H
