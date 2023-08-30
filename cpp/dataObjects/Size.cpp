#include "Size.h"

Size::Size(int width, int height, QObject *parent) : QObject(parent), width_(width), height_(height)
{

}

Size::Size(QObject *parent) : QObject(parent)
{

}

int Size::width() const
{
    return width_;
}

void Size::setWidth(int width)
{
    width_ = width;
    emit widthChanged();
}

int Size::height() const
{
    return height_;
}

void Size::setHeight(int height)
{
    height_ = height;
    emit heightChanged();
}
