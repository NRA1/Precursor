#ifndef PRECURSOR_NODESHAPE_H
#define PRECURSOR_NODESHAPE_H

#include <QQuickPaintedItem>
#include "Shape.h"

class NodeShape : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(Shape *shape MEMBER shape_ NOTIFY shapeChanged)

public:
    NodeShape();

    void paint(QPainter *painter) override;

    signals:
    void shapeChanged();

private slots:
    void onShapeChanged();

private:
    void recalculateSize();
    void rebuildCachedFields();

    Shape *shape_ = nullptr;

    QPen *pen_ = nullptr;
    QBrush *brush_ = nullptr;
};


#endif //PRECURSOR_NODESHAPE_H
