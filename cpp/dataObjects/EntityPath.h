#ifndef PRECURSOR_ENTITYPATH_H
#define PRECURSOR_ENTITYPATH_H


#include "Path.h"

class EntityPath : public Path
{
public:
    EntityPath(QObject *parent = nullptr);

    void resize(const QSizeF &size) override;

private:
    QSizeF base_size_;
};


#endif //PRECURSOR_ENTITYPATH_H
