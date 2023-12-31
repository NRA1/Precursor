#include "PropertyNamePath.h"

PropertyNamePath::PropertyNamePath(QObject *parent) : Path(parent)
{
    this->addRect(0, 0, 70, 50);
}

void PropertyNamePath::resize(const QSizeF &size)
{
    this->setElementPositionAt(1, 70 + size.width(), 0);
    this->setElementPositionAt(2, 70 + size.width(), 50);
    emit resized();
}
