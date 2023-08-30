#ifndef PRECURSOR_ADDMENUMODEL_H
#define PRECURSOR_ADDMENUMODEL_H


#include <QObject>

class AddMenuModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int posX READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(int posY READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(bool visible READ visible WRITE setVisible NOTIFY visibleChanged)

public:
    AddMenuModel();

    Q_INVOKABLE void open(int x, int y);
    Q_INVOKABLE void focusLost();

    int x() const;
    void setX(int x);
    int y() const;
    void setY(int y);
    bool visible() const;
    void setVisible(bool visible);

signals:
    void xChanged();
    void yChanged();
    void visibleChanged();

private:
    int x_;
    int y_;
    bool visible_;
};


#endif //PRECURSOR_ADDMENUMODEL_H
