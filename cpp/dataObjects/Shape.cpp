#include "Shape.h"

Shape::Shape(QColor stroke_color, int stroke_width, QColor fill_color, Path *path)
    : stroke_color_(stroke_color), stroke_width_(stroke_width), fill_color_(fill_color), path_(path)
{

}

Shape::Shape(QObject *parent) : QObject(parent)
{

}

Shape::~Shape()
{
    delete path_;
}

const QColor &Shape::strokeColor() const
{
    return stroke_color_;
}

void Shape::setStrokeColor(const QColor &strokeColor)
{
    stroke_color_ = strokeColor;
    emit strokeColorChanged();
}

int Shape::strokeWidth() const
{
    return stroke_width_;
}

void Shape::setStrokeWidth(int strokeWidth)
{
    stroke_width_ = strokeWidth;
    emit strokeWidthChanged();
}

const QColor &Shape::fillColor() const
{
    return fill_color_;
}

void Shape::setFillColor(const QColor &fillColor)
{
    fill_color_ = fillColor;
    emit fillColorChanged();
}

Path *Shape::path() const
{
    return path_;
}

void Shape::setPath(Path *path)
{
    Shape::path_ = path;
    emit pathChanged();
}

