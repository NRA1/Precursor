#ifndef PRECURSOR_ADDMENUMODEL_H
#define PRECURSOR_ADDMENUMODEL_H


#include <QObject>

class AddMenuModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int posX MEMBER x NOTIFY xChanged)
    Q_PROPERTY(int posY MEMBER y NOTIFY yChanged)
    Q_PROPERTY(bool visible MEMBER visible NOTIFY visibleChanged)

public:
    AddMenuModel();

    Q_INVOKABLE void open(int x, int y);
    Q_INVOKABLE void focusLost();

    int x;
    int y;
    bool visible;

signals:
    void xChanged();
    void yChanged();
    void visibleChanged();
};


#endif //PRECURSOR_ADDMENUMODEL_H
