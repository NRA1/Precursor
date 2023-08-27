#ifndef PRECURSOR_PROPERTYNAMEPATH_H
#define PRECURSOR_PROPERTYNAMEPATH_H


#include "Path.h"

class PropertyNamePath : public Path
{
public:
    PropertyNamePath(QObject *parent = nullptr);

    void resize(const QSizeF &size);

private:
    QSizeF base_size_;
};


#endif //PRECURSOR_PROPERTYNAMEPATH_H
