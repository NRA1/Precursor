#include "PropertyValuePath.h"

PropertyValuePath::PropertyValuePath(QObject *parent) : Path(parent)
{
    this->addRoundedRect(0, 0, 70, 50, 10, 10);
}

void PropertyValuePath::resize(const QSizeF &size)
{
    for(int i = 4; i <= 11; ++i)
    {
        QPainterPath::Element el = this->elementAt(i);
        this->setElementPositionAt(i, el.x + size.width() - base_size_.width(), el.y);
    }
    base_size_ = size;
    emit resized();
}
