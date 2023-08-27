#include "ViewModel.h"
#include "Constants.h"
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
    data[NodesModel::Roles::Shape] = QVariant::fromValue<QObject*>(Constants::entity_shape);
    nodes->setItemData(index, data);
}
