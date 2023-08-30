#include "ViewModel.h"
#include "EntityPath.h"
#include <QPointF>

ViewModel *ViewModel::instance = new ViewModel();

ViewModel::ViewModel() : nodes(new NodesModel()), add_menu(new AddMenuModel())
{
}

void ViewModel::sceneTapped(const QPointF &point)
{
    if(!nodes->insertRow(nodes->rowCount())) return;
    QModelIndex index = nodes->index(nodes->rowCount() - 1);
    QMap<int, QVariant> data;
    data[NodesModel::Roles::PosX] = point.x();
    data[NodesModel::Roles::PosY] = point.y();
    data[NodesModel::Roles::Display] = "Test4";

    Shape *shape = new Shape("#d367eb", 3, "#6151ea", new EntityPath());
    data[NodesModel::Roles::Shape] = QVariant::fromValue<QObject*>(shape);
    data[NodesModel::Roles::Type] = QVariant::fromValue<Node::NodeTypeEnum>(Node::NodeTypeEnum::Entity);
    nodes->setItemData(index, data);
}

