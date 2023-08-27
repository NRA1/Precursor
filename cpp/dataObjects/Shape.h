#ifndef PRECURSOR_SHAPE_H
#define PRECURSOR_SHAPE_H


#include <QObject>
#include <QPoint>
#include <QColor>
#include <QPainterPath>
#include "Path.h"

class Shape : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QColor strokeColor MEMBER stroke_color NOTIFY strokeColorChanged)
    Q_PROPERTY(int strokeWidth MEMBER stroke_width NOTIFY strokeWidthChanged)
    Q_PROPERTY(QColor fillColor MEMBER fill_color NOTIFY fillColorChanged)
    Q_PROPERTY(Path *path MEMBER path NOTIFY pathChanged)

public:
    Shape();
    Shape(QObject *parent);

    ~Shape() override;

    QColor stroke_color = QColor();
    int stroke_width = 0;
    QColor fill_color = QColor();
    Path *path = nullptr;

    signals:
    void strokeColorChanged();
    void strokeWidthChanged();
    void fillColorChanged();
    void pathChanged();
};


#endif //PRECURSOR_SHAPE_H
