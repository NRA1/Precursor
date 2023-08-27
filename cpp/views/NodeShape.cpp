#include "NodeShape.h"

#include <QPainter>
#include <QPoint>

NodeShape::NodeShape()
{
    QObject::connect(this, &NodeShape::shapeChanged, this, &NodeShape::onShapeChanged);
}

void NodeShape::paint(QPainter *painter)
{
    painter->setPen(*pen_);
    painter->setBrush(*brush_);
    painter->drawPath(shape_->path);
}

void NodeShape::onShapeChanged()
{
    recalculateSize();
    rebuildCachedFields();
    update();
}

void NodeShape::recalculateSize()
{
    if(shape_ == nullptr) return;
    this->setSize(shape_->path.boundingRect().size());
}

void NodeShape::rebuildCachedFields()
{
    if(shape_ == nullptr) return;
    pen_ = new QPen(shape_->stroke_color);
    pen_->setWidth(shape_->stroke_width);
    brush_ = new QBrush(shape_->fill_color);
}

