#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include "ViewModel.h"
#include "cpp/dataObjects/Shape.h"
#include "NodeShape.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<NodeShape>("Precursor.NodeShape", 1, 0, "NodeShape");
    qmlRegisterSingletonInstance("ViewModel", 1, 0, "ViewModel", ViewModel::instance);

    QQmlApplicationEngine engine("qrc:/qml/Main.qml");
    return QGuiApplication::exec();
}
