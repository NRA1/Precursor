#include <QPoint>
#include <iostream>
#include <QGuiApplication>
#include <QFont>
#include <QFontMetrics>
#include "NodesModel.h"
#include "cpp/ViewModel.h"
#include "cpp/dataObjects/Shape.h"
#include "PropertyValuePath.h"
#include "PropertyNamePath.h"

NodesModel::NodesModel() : nodes_(new QList<Node *>()), node_bounds_(new Size(this))
{
}

int NodesModel::rowCount(const QModelIndex &parent) const
{
    return nodes_->count();
}

QHash<int, QByteArray> NodesModel::roleNames() const
{
    QHash<int, QByteArray> map;
    map[Roles::PosX] = "posX";
    map[Roles::PosY] = "posY";
    map[Roles::Display] = "display";
    map[Roles::Shape] = "shape";
    return map;
}

QVariant NodesModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || index.parent().isValid() || index.column() != 0 || index.row() > nodes_->count() - 1)
        return QVariant();
    if(role == Roles::PosX) return QVariant(nodes_->at(index.row())->x());
    else if(role == Roles::PosY) return QVariant(nodes_->at(index.row())->y());
    else if(role == Roles::Display) return QVariant(nodes_->at(index.row())->text());
    else if(role == Roles::Shape) return QVariant::fromValue<QObject *>(nodes_->at(index.row())->shape());
    else if(role == Roles::Type) return QVariant::fromValue<Node::NodeTypeEnum>(nodes_->at(index.row())->nodeType());
    return QVariant();
}

bool NodesModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid() || index.parent().isValid() || index.column() != 0 || index.row() > nodes_->count() - 1)
        return false;

    if(role == Roles::PosX && value.canConvert<int>())
    {
        nodes_->at(index.row())->setX(value.toInt());
        emit dataChanged(index, index, QList<int>(1, Roles::PosX));
        recalculateNodeBounds();
        return true;
    }
    else if(role == Roles::PosY && value.canConvert<int>())
    {
        nodes_->at(index.row())->setY(value.toInt());
        emit dataChanged(index, index, QList<int>(1, Roles::PosY));
        recalculateNodeBounds();
        return true;
    }
    else if(role == Roles::Display && value.canConvert<QString>())
    {
        Node *node = nodes_->at(index.row());
        node->setText(value.toString());
        if(node->shape() != nullptr && node->shape()->path() != nullptr)
            node->shape()->path()->resize(calculateBoundingRect(value.toString()));
        QList<int> roles;
        roles.push_back(Roles::Display);
        roles.push_back(Roles::Shape);
        emit dataChanged(index, index, roles);
        recalculateNodeBounds();
        return true;
    }
    else if(role == Roles::Shape && value.canConvert<Shape *>())
    {
        Node *node = nodes_->at(index.row());
        node->setShape(value.value<Shape*>());
        if(node->shape()->path() != nullptr)
            node->shape()->path()->resize(calculateBoundingRect(node->text()));
        emit dataChanged(index, index, QList<int>(1, Roles::Shape));
        recalculateNodeBounds();
        return true;
    }
    else if(role == Roles::Type && value.canConvert<Node::NodeTypeEnum>())
    {
        nodes_->at(index.row())->setNodeType(value.value<Node::NodeTypeEnum>());
        emit dataChanged(index, index, QList<int>(1, Roles::Type));
        return true;
    }
    return false;
}

void NodesModel::tabPressed(int nodeIndex)
{
    Node *parentNode = nodes_->at(nodeIndex);
    QMap<int, QVariant> map;
    if(parentNode->nodeType() == Node::Entity)
    {
        map[Roles::PosX] = parentNode->x() + 150;
        map[Roles::PosY] = parentNode->y() + 100;

        Shape *shape = new Shape("#1BB7F7", 2, "#050A2E", new PropertyNamePath());

        map[Roles::Shape] = QVariant::fromValue<QObject*>(shape);
        map[Roles::Type] = QVariant::fromValue<Node::NodeTypeEnum>(Node::PropertyName);
    }
    else
    {
        if(parentNode->nodeType() == Node::PropertyName)
        {
            map[Roles::PosX] = parentNode->x() + 125;
            map[Roles::PosY] = parentNode->y();
        }
        else //PropertyValue
        {
            map[Roles::PosX] = parentNode->x();
            map[Roles::PosY] = parentNode->y() + 75;
        }

        Shape *shape = new Shape("#1BB7F7", 2, "#050A2E", new PropertyValuePath());

        map[Roles::Shape] = QVariant::fromValue<QObject*>(shape);
        map[Roles::Type] = QVariant::fromValue<Node::NodeTypeEnum>(Node::PropertyValue);
    }
    map[Roles::Display] = "Test4";
    insertRow(rowCount());
    QModelIndex index = this->index(nodes_->count() - 1);
    setItemData(index, map);
}

void NodesModel::deletePressed(int nodeIndex)
{
    removeRow(nodeIndex, QModelIndex());
}

bool NodesModel::insertRows(int row, int count, const QModelIndex &parent)
{
    if(parent.isValid() || row > nodes_->count()) return false;
    beginInsertRows(parent, row, row + count - 1);
    for (int i = 0; i < count; ++i)
        nodes_->insert(row + i, new Node(this));
    endInsertRows();
    recalculateNodeBounds();
    return true;
}

bool NodesModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if (parent.isValid() || row + count > nodes_->count()) return false;
    beginRemoveRows(parent, row, row + count);
    for (int i = 0; i < count; ++i)
    {
        Node *node = nodes_->at(row + count - 1 - i);
        nodes_->remove(row + count - 1 - i);
        delete node;
    }
    endRemoveRows();
    recalculateNodeBounds();
    return true;
}

NodesModel::~NodesModel()
{
    delete nodes_;
}

QSizeF NodesModel::calculateBoundingRect(const QString &text)
{
    QFont font = QGuiApplication::font();
    QFontMetrics metrics(font);
    QRectF rect = metrics.boundingRect(text);
    return rect.size();
}

void NodesModel::recalculateNodeBounds()
{
    int width = 0;
    int height = 0;
    for (int i = 0; i < nodes_->count(); ++i)
    {
        Node *node = nodes_->operator[](i);
        if(width < node->x() + node->width()) width = node->x() + node->width();
        if(height < node->y() + node->height()) height = node->y() + node->height();
    }
    setNodeBounds(new Size(width, height, this));
}

Size *NodesModel::nodeBounds() const
{
    return node_bounds_;
}

void NodesModel::setNodeBounds(Size *nodeBounds)
{
    if(node_bounds_ != nullptr) delete node_bounds_;
    node_bounds_ = nodeBounds;
    emit nodeBoundsChanged();
}
