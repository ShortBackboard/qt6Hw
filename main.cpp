/*
 * A program : C++ module import
 *
 * anthor:2019051604044liChengYang
 * date:2023-5-14
 *
 *
 *
*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    const QUrl url(u"qrc:/Main.qml"_qs);

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
        },Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
