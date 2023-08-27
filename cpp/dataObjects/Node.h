#ifndef PRECURSOR_NODE_H
#define PRECURSOR_NODE_H

#include <QObject>
#include "Shape.h"

class Node : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int posX MEMBER x NOTIFY xChanged)
    Q_PROPERTY(int posY MEMBER y NOTIFY yChanged)
    Q_PROPERTY(QString text MEMBER text NOTIFY textChanged)
    Q_PROPERTY(Shape *shape MEMBER shape NOTIFY shapeChanged)
    Q_PROPERTY(NodeTypeEnum type MEMBER node_type NOTIFY nodeTypeChanged)

public:
    enum NodeTypeEnum
    {
        Entity,
        PropertyName,
        PropertyValue
    };
    Q_ENUM(NodeTypeEnum)

    Node(QObject *parent);

    int x = 0;
    int y = 0;
    QString text = "";
    Shape *shape = nullptr;
    NodeTypeEnum node_type;

    signals:
    void xChanged();
    void yChanged();
    void textChanged();
    void shapeChanged();
    void nodeTypeChanged();
};


#endif //PRECURSOR_NODE_H
