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

NodesModel::NodesModel() : nodes_(new QList<Node *>())
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
    if(role == Roles::PosX) return QVariant(nodes_->at(index.row())->x);
    else if(role == Roles::PosY) return QVariant(nodes_->at(index.row())->y);
    else if(role == Roles::Display) return QVariant(nodes_->at(index.row())->text);
    else if(role == Roles::Shape) return QVariant::fromValue<QObject *>(nodes_->at(index.row())->shape);
    else if(role == Roles::Type) return QVariant::fromValue<Node::NodeTypeEnum>(nodes_->at(index.row())->node_type);
    return QVariant();
}

bool NodesModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid() || index.parent().isValid() || index.column() != 0 || index.row() > nodes_->count() - 1)
        return false;

    if(role == Roles::PosX && value.canConvert<int>())
    {
        nodes_->at(index.row())->x = value.toInt();
        emit dataChanged(index, index, QList<int>(1, Roles::PosX));
        return true;
    }
    else if(role == Roles::PosY && value.canConvert<int>())
    {
        nodes_->at(index.row())->y = value.toInt();
        emit dataChanged(index, index, QList<int>(1, Roles::PosY));
        return true;
    }
    else if(role == Roles::Display && value.canConvert<QString>())
    {
        Node *node = nodes_->at(index.row());
        node->text = value.toString();
        if(node->shape != nullptr && node->shape->path != nullptr)
            node->shape->path->resize(calculateBoundingRect(value.toString()));
        QList<int> roles;
        roles.push_back(Roles::Display);
        roles.push_back(Roles::Shape);
        emit dataChanged(index, index, roles);
        return true;
    }
    else if(role == Roles::Shape && value.canConvert<Shape *>())
    {
        Node *node = nodes_->at(index.row());
        node->shape = value.value<Shape*>();
        if(node->shape->path != nullptr)
            node->shape->path->resize(calculateBoundingRect(node->text));
        emit dataChanged(index, index, QList<int>(1, Roles::Shape));
        return true;
    }
    else if(role == Roles::Type && value.canConvert<Node::NodeTypeEnum>())
    {
        nodes_->at(index.row())->node_type = value.value<Node::NodeTypeEnum>();
        emit dataChanged(index, index, QList<int>(1, Roles::Type));
        return true;
    }
    return false;
}

void NodesModel::tabPressed(int nodeIndex)
{
    Node *parentNode = nodes_->at(nodeIndex);
    QMap<int, QVariant> map;
    if(parentNode->node_type == Node::Entity)
    {
        map[Roles::PosX] = parentNode->x + 150;
        map[Roles::PosY] = parentNode->y + 100;

        Shape *shape = new Shape();
        shape->stroke_color = "#1BB7F7";
        shape->stroke_width = 2;
        shape->fill_color = "#050A2E";
        Path *path = new PropertyNamePath();
        shape->path = path;

        map[Roles::Shape] = QVariant::fromValue<QObject*>(shape);
        map[Roles::Type] = QVariant::fromValue<Node::NodeTypeEnum>(Node::PropertyName);
    }
    else
    {
        if(parentNode->node_type == Node::PropertyName)
        {
            map[Roles::PosX] = parentNode->x + 125;
            map[Roles::PosY] = parentNode->y;
        }
        else //PropertyValue
        {
            map[Roles::PosX] = parentNode->x;
            map[Roles::PosY] = parentNode->y + 75;
        }

        Shape *shape = new Shape();
        shape->stroke_color = "#1BB7F7";
        shape->stroke_width = 2;
        shape->fill_color = "#050A2E";
        Path *path = new PropertyValuePath();
        shape->path = path;

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
    return true;
}

bool NodesModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if (parent.isValid() || row + count > nodes_->count() - 1) return false;
    beginRemoveRows(parent, row, row + count);
    for (int i = 0; i < count; ++i)
    {
        Node *node = nodes_->at(row + count - 1 - i);
        nodes_->remove(row + count - 1 - i);
        delete node;
    }
    endRemoveRows();
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
