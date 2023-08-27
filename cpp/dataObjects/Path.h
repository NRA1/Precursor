#ifndef PRECURSOR_PATH_H
#define PRECURSOR_PATH_H


#include <QObject>
#include <QPainterPath>

class Path : public QObject, public QPainterPath
{
    Q_OBJECT

public:
    Path(QObject *parent = nullptr);

    virtual void resize(const QSizeF &size) = 0;


    virtual ~Path();

    signals:
    void resized();
};


#endif //PRECURSOR_PATH_H
