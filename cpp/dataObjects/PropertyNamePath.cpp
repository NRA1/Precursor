#include "PropertyNamePath.h"

PropertyNamePath::PropertyNamePath(QObject *parent) : Path(parent), base_size_(QSize(0, 0))
{
    this->addRect(0, 0, 70, 50);
}

void PropertyNamePath::resize(const QSizeF &size)
{
    this->setElementPositionAt(1, 70 + size.width() - base_size_.width(), 0);
    this->setElementPositionAt(2, 70 + size.width() - base_size_.width(), 50);
    base_size_ = size;
    emit resized();
}
