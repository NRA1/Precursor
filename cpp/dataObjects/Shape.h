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

    Q_PROPERTY(QColor strokeColor READ strokeColor WRITE setStrokeColor NOTIFY strokeColorChanged)
    Q_PROPERTY(int strokeWidth READ strokeWidth WRITE setStrokeWidth NOTIFY strokeWidthChanged)
    Q_PROPERTY(QColor fillColor READ fillColor WRITE setFillColor NOTIFY fillColorChanged)
    Q_PROPERTY(Path *path READ path WRITE setPath NOTIFY pathChanged)

public:
    Shape(QObject *parent = nullptr);
    Shape(QColor stroke_color, int stroke_width, QColor fill_color, Path *path);

    ~Shape() override;

    const QColor &strokeColor() const;
    void setStrokeColor(const QColor &strokeColor);
    int strokeWidth() const;
    void setStrokeWidth(int strokeWidth);
    const QColor &fillColor() const;
    void setFillColor(const QColor &fillColor);
    Path *path() const;
    void setPath(Path *path);

signals:
    void strokeColorChanged();
    void strokeWidthChanged();
    void fillColorChanged();
    void pathChanged();

private:
    QColor stroke_color_ = QColor();
    int stroke_width_ = 0;
    QColor fill_color_ = QColor();
    Path *path_ = nullptr;
};


#endif //PRECURSOR_SHAPE_H
