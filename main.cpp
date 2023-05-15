/*
 * A program : QtQuick 项目中通过 context 传递数据
 *
 * anthor:2019051604044liChengYang
 * date:2023-5-13
 *
 *
 *
*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    double d = 10.5;
    engine.rootContext()->setContextProperty("p1",d);

    const QUrl url("qrc:/Main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
        },Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
