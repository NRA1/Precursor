#ifndef PRECURSOR_NODE_H
#define PRECURSOR_NODE_H

#include <QObject>
#include "Shape.h"

class Node : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int posX READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(int posY READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(int width READ width)
    Q_PROPERTY(int height READ height)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(Shape *shape READ shape WRITE setShape NOTIFY shapeChanged)
    Q_PROPERTY(NodeTypeEnum type READ nodeType WRITE setNodeType NOTIFY nodeTypeChanged)

public:
    enum NodeTypeEnum
    {
        Entity,
        PropertyName,
        PropertyValue
    };
    Q_ENUM(NodeTypeEnum)

    Node(QObject *parent);

    int x() const;
    void setX(int x);
    int y() const;
    void setY(int y);
    int width() const;
    int height() const;
    const QString &text() const;
    void setText(const QString &text);
    Shape *shape() const;
    void setShape(Shape *shape);
    NodeTypeEnum nodeType() const;
    void setNodeType(NodeTypeEnum nodeType);

signals:
    void xChanged();
    void yChanged();
    void textChanged();
    void shapeChanged();
    void nodeTypeChanged();

private:
    int x_ = 0;
    int y_ = 0;
    QString text_ = "";
    Shape *shape_ = nullptr;
    NodeTypeEnum node_type_;
};


#endif //PRECURSOR_NODE_H
