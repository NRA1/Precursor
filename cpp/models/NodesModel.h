#ifndef PRECURSOR_NODESMODEL_H
#define PRECURSOR_NODESMODEL_H


#include <QAbstractListModel>
#include "cpp/dataObjects/Node.h"

class NodesModel : public QAbstractListModel
{
    Q_OBJECT

public:

    struct Roles
    {
        enum RolesEnum
        {
            Display = Qt::ItemDataRole::DisplayRole,
            PosX = Qt::ItemDataRole::UserRole,
            PosY = Qt::ItemDataRole::UserRole + 1,
            Shape = Qt::ItemDataRole::UserRole + 2,
            Type = Qt::ItemDataRole::UserRole + 3
        };
    };

    explicit NodesModel();

    Q_INVOKABLE void tabPressed(int nodeIndex);
    Q_INVOKABLE void deletePressed(int nodeIndex);

    ~NodesModel();

    [[nodiscard]] int rowCount(const QModelIndex &parent = QModelIndex()) const override;
protected:
    QHash<int, QByteArray> roleNames() const override;
    [[nodiscard]] QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

private:
    static QSizeF calculateBoundingRect(const QString &text);

    QList<Node*> *nodes_;
};


#endif //PRECURSOR_NODESMODEL_H
