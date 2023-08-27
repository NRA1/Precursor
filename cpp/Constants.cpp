#include "Constants.h"

Shape *Constants::entity_shape = nullptr;
Shape *Constants::property_name_shape = nullptr;
Shape *Constants::property_value_shape = nullptr;

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
    shape->stroke_color = "#1BB7F7";
    shape->stroke_width = 2;
    shape->fill_color = "#050A2E";
    path.clear();
    path.addRect(0, 0, 100, 50);
    shape->path = path;
    property_name_shape = shape;

    shape = new Shape();
    shape->stroke_color = "#1BB7F7";
    shape->stroke_width = 2;
    shape->fill_color = "#050A2E";
    path.clear();
    path.addRoundedRect(0, 0, 100, 50, 10, 10);
    shape->path = path;
    property_value_shape = shape;
}
