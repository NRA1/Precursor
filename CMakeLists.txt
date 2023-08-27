cmake_minimum_required(VERSION 3.26)
project(Precursor VERSION 0.0.1 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH $ENV{HOME}/.qt/6.5.2/gcc_64)

find_package(Qt6 6.5.2 COMPONENTS Quick Gui REQUIRED)
qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(${PROJECT_NAME} cpp/Main.cpp
        cpp/ViewModel.cpp
        cpp/ViewModel.h
        cpp/models/NodesModel.cpp
        cpp/models/NodesModel.h
        cpp/dataObjects/Node.cpp
        cpp/dataObjects/Node.h
        cpp/models/AddMenuModel.cpp
        cpp/models/AddMenuModel.h
        cpp/dataObjects/Shape.cpp
        cpp/dataObjects/Shape.h
        cpp/views/NodeShape.cpp
        cpp/views/NodeShape.h
        cpp/dataObjects/Path.cpp
        cpp/dataObjects/Path.h
        cpp/dataObjects/EntityPath.cpp
        cpp/dataObjects/EntityPath.h
        cpp/dataObjects/PropertyNamePath.cpp
        cpp/dataObjects/PropertyNamePath.h
        cpp/dataObjects/PropertyValuePath.cpp
        cpp/dataObjects/PropertyValuePath.h)

target_include_directories(${PROJECT_NAME} PUBLIC cpp/dataObjects cpp/views)

qt_add_qml_module(${PROJECT_NAME}
    URI qml
    RESOURCE_PREFIX "/"
    NO_RESOURCE_TARGET_PATH
    QML_FILES
        qml/Main.qml
        qml/Scene/Scene.qml
        qml/Scene/Node/Node.qml
    RESOURCES)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Gui Qt6::Quick)

