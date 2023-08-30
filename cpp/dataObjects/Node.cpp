#include "Node.h"
#include "cpp/ViewModel.h"

Node::Node(QObject *parent) : QObject(parent)
{

}

int Node::x() const
{
    return x_;
}

void Node::setX(int x)
{
    x_ = x;
    emit xChanged();
}

int Node::y() const
{
    return y_;
}

void Node::setY(int y)
{
    y_ = y;
    emit yChanged();
}

int Node::width() const
{
    if(shape_ != nullptr && shape_->path() != nullptr)
        return shape_->path()->boundingRect().width();
    return 0;
}

int Node::height() const
{
    if(shape_ != nullptr && shape_->path() != nullptr)
        return shape_->path()->boundingRect().height();
    return 0;
}

const QString &Node::text() const
{
    return text_;
}

void Node::setText(const QString &text)
{
    text_ = text;
    emit textChanged();
}

Shape *Node::shape() const
{
    return shape_;
}

void Node::setShape(Shape *shape)
{
    shape_ = shape;
    emit shapeChanged();
}

Node::NodeTypeEnum Node::nodeType() const
{
    return node_type_;
}

void Node::setNodeType(Node::NodeTypeEnum nodeType)
{
    node_type_ = nodeType;
    emit nodeTypeChanged();
}
