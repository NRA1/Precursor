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

public:
    Node(QObject *parent);

    int x = 0;
    int y = 0;
    QString text = "";
    Shape *shape = nullptr;

    signals:
    void xChanged();
    void yChanged();
    void textChanged();
    void shapeChanged();
};


#endif //PRECURSOR_NODE_H
