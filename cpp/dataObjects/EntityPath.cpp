#include <iostream>
#include "EntityPath.h"

EntityPath::EntityPath(QObject *parent) : Path(parent)
{
    this->addRoundedRect(0, 0, 70, 50, 25, 25);
}

void EntityPath::resize(const QSizeF &size)
{
    for(int i = 4; i <= 10; ++i)
    {
        QPainterPath::Element el = this->elementAt(i);
        this->setElementPositionAt(i, el.x + size.width() - base_size_.width(), el.y);
    }
    base_size_ = size;
    emit resized();
}
