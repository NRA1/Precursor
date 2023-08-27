#ifndef PRECURSOR_VIEWMODEL_H
#define PRECURSOR_VIEWMODEL_H

#include <QObject>
#include <QQmlEngine>
#include "cpp/dataObjects/Node.h"
#include "cpp/models/NodesModel.h"
#include "cpp/models/AddMenuModel.h"

class ViewModel : public QObject
{
Q_OBJECT

    Q_PROPERTY(NodesModel *nodes MEMBER nodes NOTIFY nodesChanged)
    Q_PROPERTY(AddMenuModel *addMenu MEMBER add_menu NOTIFY addMenuChanged)

public:
    static ViewModel *instance;

    NodesModel *nodes;
    AddMenuModel *add_menu;

    Q_INVOKABLE void sceneTapped(const QPointF &point);

signals:

    void nodesChanged();
    void addMenuChanged();

private:
    ViewModel();
};

#endif //PRECURSOR_VIEWMODEL_H