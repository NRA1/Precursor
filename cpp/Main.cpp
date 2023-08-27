#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include "ViewModel.h"
#include "cpp/dataObjects/Shape.h"
#include "NodeShape.h"
#include "Constants.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    Constants::initialize();

    qmlRegisterType<NodeShape>("Precursor.NodeShape", 1, 0, "NodeShape");
    qmlRegisterSingletonInstance("ViewModel", 1, 0, "ViewModel", ViewModel::instance);

    QQmlApplicationEngine engine("qrc:/qml/Main.qml");
    return QGuiApplication::exec();
}
