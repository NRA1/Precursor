#include "Constants.h"

Shape *Constants::entity_shape = nullptr;
Shape *Constants::property_shape = nullptr;

void Constants::initialize()
{
    Shape *shape = new Shape();
    shape->fill_color = "#d367eb";
    shape->stroke_width = 1;
    shape->stroke_color = "#6151ea";
    QPainterPath path;
    path.addRoundedRect(0, 0, 100, 50, 25, 25);
    shape->path = path;
    entity_shape = shape;

    shape = new Shape();
    shape->stroke_color = "#1f1f1f";
    shape->stroke_width = 10;
    shape->fill_color = "#f42355";
    path.clear();
    path.addRect(0, 0, 100, 50);
    shape->path = path;
    property_shape = shape;
}
