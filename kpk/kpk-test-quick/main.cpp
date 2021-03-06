#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDateTime>

#include "kpk-data/Person.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qRegisterMetaType<kpk::data::Person*>("kpk::data::Person*");

    /*qRegisterMetaType<kpk::data::Person>("kpk::data::Person");*/

    //kpk::data::Person* p = new kpk::data::Person(QDateTime::currentDateTime(), std::make_shared<User>());


    QQmlApplicationEngine engine;

    //engine.rootContext()->setContextProperty("person", p);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));



    return app.exec();
}
