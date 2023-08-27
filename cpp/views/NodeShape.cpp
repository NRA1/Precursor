#include "NodeShape.h"

#include <QPainter>
#include <QPoint>

NodeShape::NodeShape()
{
    QObject::connect(this, &NodeShape::shapeChanged, this, &NodeShape::onShapeChanged);
    if(this->shape_ != nullptr)
        QObject::connect(this->shape_, &Shape::pathChanged, this, &NodeShape::onPathChanged);
}

void NodeShape::paint(QPainter *painter)
{
    painter->setPen(*pen_);
    painter->setBrush(*brush_);
    painter->drawPath(*(shape_->path));
}

void NodeShape::onShapeChanged()
{
    recalculateSize();
    rebuildCachedFields();
    if(this->shape_ != nullptr && this->shape_->path != nullptr)
        QObject::connect(this->shape_->path, &Path::resized, this, &NodeShape::onPathResized);
    update();
}

void NodeShape::recalculateSize()
{
    if(shape_ == nullptr) return;
    this->setSize(shape_->path->boundingRect().size());
    update();
}

void NodeShape::rebuildCachedFields()
{
    if(shape_ == nullptr) return;
    pen_ = new QPen(shape_->stroke_color);
    pen_->setWidth(shape_->stroke_width);
    brush_ = new QBrush(shape_->fill_color);
}

void NodeShape::onPathResized()
{
    recalculateSize();
}

void NodeShape::onPathChanged()
{
    if(this->shape_ != nullptr && this->shape_->path != nullptr)
        QObject::connect(this->shape_->path, &Path::resized, this, &NodeShape::onPathResized);
    recalculateSize();
}

