#include "Shape.h"

Shape::Shape()
{

}

Shape::Shape(QObject *parent) : QObject(parent)
{

}

Shape::~Shape()
{
    delete path;
}
