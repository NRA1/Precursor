#include "NodeShape.h"

#include <QPainter>
#include <QPoint>

NodeShape::NodeShape()
{
    this->setAntialiasing(true);
    QObject::connect(this, &NodeShape::shapeChanged, this, &NodeShape::onShapeChanged);
    if(this->shape_ != nullptr)
        QObject::connect(this->shape_, &Shape::pathChanged, this, &NodeShape::onPathChanged);
}

void NodeShape::paint(QPainter *painter)
{
    painter->setPen(*pen_);
    painter->setBrush(*brush_);
    float margin = (float)(shape_->strokeWidth()) / (float)2;
    painter->drawPath(shape_->path()->translated(margin, margin));
}

void NodeShape::onShapeChanged()
{
    recalculateSize();
    rebuildCachedFields();
    if(this->shape_ != nullptr && this->shape_->path() != nullptr)
        QObject::connect(this->shape_->path(), &Path::resized, this, &NodeShape::onPathResized);
    update();
}

void NodeShape::recalculateSize()
{
    if(shape_ == nullptr) return;
    float margin = (float)(shape_->strokeWidth()) / (float)2;
    this->setSize(shape_->path()->boundingRect().size().grownBy(QMarginsF(margin, margin, margin, margin)));
    update();
}

void NodeShape::rebuildCachedFields()
{
    if(shape_ == nullptr) return;
    pen_ = new QPen(shape_->strokeColor());
    pen_->setWidth(shape_->strokeWidth());
    brush_ = new QBrush(shape_->fillColor());
}

void NodeShape::onPathResized()
{
    recalculateSize();
}

void NodeShape::onPathChanged()
{
    if(this->shape_ != nullptr && this->shape_->path() != nullptr)
        QObject::connect(this->shape_->path(), &Path::resized, this, &NodeShape::onPathResized);
    recalculateSize();
}

